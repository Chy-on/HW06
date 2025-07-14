#include "SpawnVolume.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"

ASpawnVolume::ASpawnVolume()
{
	PrimaryActorTick.bCanEverTick = false;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	SpawningBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawningBox"));
	SpawningBox->SetupAttachment(Scene);

	ActorDataTable = nullptr;
}

AActor* ASpawnVolume::SpawnRandomActor()
{
	if (const FActorSpawnRow* SelectedRow = GetRandomActor())
	{
		if (UClass* ActualClass = SelectedRow->ActorClass.Get())
		{
			return SpawnActor(ActualClass);
		}
	}
	return nullptr;
}


FVector ASpawnVolume::GetRandomPointInVolume() const
{
	FVector BoxExtent = SpawningBox->GetScaledBoxExtent();
	FVector BoxOrigin = SpawningBox->GetComponentLocation();

	return BoxOrigin + FVector(
		FMath::FRandRange(- BoxExtent.X, BoxExtent.X),
		FMath::FRandRange(- BoxExtent.Y, BoxExtent.Y),
		FMath::FRandRange(- BoxExtent.Z, BoxExtent.Z)
	);
}

const FActorSpawnRow* ASpawnVolume::GetRandomActor() const
{
	if (!ActorDataTable) return nullptr;

	TArray<FActorSpawnRow*> AllRows;
	static const FString ContextString(TEXT("ActorSpawnContext"));
	ActorDataTable->GetAllRows(ContextString, AllRows);

	if (AllRows.IsEmpty()) return nullptr;

	float TotalChance = 0.0f;
	for (const FActorSpawnRow* Row : AllRows)
	{
		if (Row)
		{
			TotalChance +=Row->SpawnChance;
		}
	}

	const float RandValue = FMath::FRandRange(0, TotalChance);
	float AccumulateChance = 0.0f;
	for (const FActorSpawnRow* Row : AllRows)
	{
		AccumulateChance += Row->SpawnChance;
		if (RandValue <= AccumulateChance)
		{
			return Row;
		}
	}
	return nullptr;
}

AActor* ASpawnVolume::SpawnActor(TSubclassOf<AActor> ActorClass)
{
	if (!ActorClass) return nullptr;

	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(
		ActorClass,
		GetRandomPointInVolume(),
		FRotator::ZeroRotator
		);

	return SpawnedActor;
}




void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

