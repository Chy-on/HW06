#include "Elevator.h"

// Sets default values
AElevator::AElevator()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	

	StartLocation  = FVector(0, 0, 0);
	MoveSpeed = FVector(0,0,300.00f);
	MaxRange = 1920.00f;
	
	PrimaryActorTick.bCanEverTick = true;

}


void AElevator::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AElevator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector CurrentLocation = GetActorLocation();
	FVector NewLocation = CurrentLocation + MoveSpeed * DeltaTime;
	if (NewLocation.Z>=StartLocation.Z+MaxRange || NewLocation.Z <= StartLocation.Z)
	{
		MoveSpeed.Z *= -1;
	}
	SetActorLocation(NewLocation);
}

