#include "TemporaryPane.h"


ATemporaryPane::ATemporaryPane()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	SpawnDelay = 20.0f;
	PrimaryActorTick.bCanEverTick = false;

}


void ATemporaryPane::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(
		SpawnTimerHandle,
		this,
		&ATemporaryPane::DespawnActor,
		SpawnDelay,
		false
	);
}

void ATemporaryPane::DespawnActor()
{
	this->Destroy();
}

void ATemporaryPane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

