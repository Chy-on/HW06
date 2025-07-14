#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPane.generated.h"

UCLASS()
class HW06_API AMovingPane : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingPane();

protected:
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;
	
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	FVector MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	FVector MaxRange;
	
public:	
	virtual void Tick(float DeltaTime) override;

};
