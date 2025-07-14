#include "RotatingActor.h"


ARotatingActor::ARotatingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	RotationSpeed = 30.0f;
}


void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}


void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0, RotationSpeed*DeltaTime, 0));
}

