#include "MovingPane.h"


AMovingPane::AMovingPane()
{

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	

	StartLocation  = FVector(0, 0, 0);
	MoveSpeed = FVector(
		FMath::RandRange(-200,200),
		FMath::RandRange(-200,200),0);
	MaxRange = FVector(FMath::RandRange(600,1200));
	
	PrimaryActorTick.bCanEverTick = true;

}


void AMovingPane::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AMovingPane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	FVector NewLocation = CurrentLocation + MoveSpeed * DeltaTime;
	if (NewLocation.X>=StartLocation.X+MaxRange.X || NewLocation.X <= StartLocation.X)
	{
		MoveSpeed.X *= -1;
	}
	if (NewLocation.Y>=StartLocation.Y+MaxRange.Y || NewLocation.Y <= StartLocation.Y)
	{
		MoveSpeed.Y *= -1;
	}
	if (NewLocation.Z>=StartLocation.Z+MaxRange.Z || NewLocation.Z <= StartLocation.Z)
	{
		MoveSpeed.Z *= -1;
	}
	SetActorLocation(NewLocation);
}

