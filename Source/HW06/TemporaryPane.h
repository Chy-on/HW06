#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TemporaryPane.generated.h"

UCLASS()
class HW06_API ATemporaryPane : public AActor
{
	GENERATED_BODY()
	
public:	

	ATemporaryPane();

protected:

	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	float SpawnDelay;
	FTimerHandle SpawnTimerHandle;

public:	
	virtual void Tick(float DeltaTime) override;
	void DespawnActor();
	void SpawnActor();

};
