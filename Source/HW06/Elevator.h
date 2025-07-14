#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Elevator.generated.h"

UCLASS()
class HW06_API AElevator : public AActor
{
	GENERATED_BODY()
	
public:	
	AElevator();

protected:
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;
	
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	FVector MoveSpeed;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Properties")
	float MaxRange;
	
public:	
	virtual void Tick(float DeltaTime) override;

};
