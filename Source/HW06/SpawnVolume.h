#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorSpawnRow.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;

UCLASS()
class HW06_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawnVolume();

	AActor* SpawnRandomActor();
	

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	UBoxComponent* SpawningBox;
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="Spawning")
	UDataTable* ActorDataTable;

	FVector GetRandomPointInVolume() const;
	const FActorSpawnRow* GetRandomActor() const;
	AActor* SpawnActor(TSubclassOf<AActor> ActorClass);
	
	virtual void Tick(float DeltaTime) override;

};
