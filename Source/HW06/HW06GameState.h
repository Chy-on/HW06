#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "HW06GameState.generated.h"


UCLASS()
class HW06_API AHW06GameState : public AGameState
{
	GENERATED_BODY()

public:
	AHW06GameState();

	virtual void BeginPlay() override;
	void StartLevel();
};
