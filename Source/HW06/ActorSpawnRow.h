#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ActorSpawnRow.generated.h"

USTRUCT(BlueprintType)
struct FActorSpawnRow: public FTableRowBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FName ActorName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TSubclassOf<AActor> ActorClass;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float SpawnChance;
};
