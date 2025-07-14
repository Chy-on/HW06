#include "HW06GameState.h"

#include "SpawnVolume.h"
#include "Kismet/GameplayStatics.h"

AHW06GameState::AHW06GameState()
{
	
}

void AHW06GameState::BeginPlay()
{
	Super::BeginPlay();
	StartLevel();
}

void AHW06GameState::StartLevel()
{
	TArray<AActor*> FoundVolumes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
		ASpawnVolume::StaticClass(),FoundVolumes);

	const int32 ActorToSpawn = 40;
	for (int32 i=0; i<ActorToSpawn; i++)
	{
		if (FoundVolumes.Num()>0)
		{
			ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]);
			if (SpawnVolume)
			{
				AActor* SpawnedActor = SpawnVolume->SpawnRandomActor();
			}
		}
	}
}