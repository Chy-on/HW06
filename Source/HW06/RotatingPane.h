#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPane.generated.h"

UCLASS()
class HW06_API ARotatingPane : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingPane();

protected:
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	FRotator RotationSpeed;

public:	
	virtual void Tick(float DeltaTime) override;

};
