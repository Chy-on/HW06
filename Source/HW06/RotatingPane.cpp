#include "RotatingPane.h"


ARotatingPane::ARotatingPane()
{

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	RotationSpeed = FRotator(
		FMath::FRandRange(-30.0f,30.0f),
		FMath::FRandRange(-30.0f,30.0f),
		FMath::FRandRange(-30.0f,30.0f));
	PrimaryActorTick.bCanEverTick = true;

}


void ARotatingPane::BeginPlay()
{
	Super::BeginPlay();
	
}


void ARotatingPane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(RotationSpeed.Pitch*DeltaTime, RotationSpeed.Yaw*DeltaTime,RotationSpeed.Roll*DeltaTime));
}


