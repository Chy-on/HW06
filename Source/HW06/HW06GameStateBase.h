#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "HW06GameStateBase.generated.h"


UCLASS()
class HW06_API AHW06GameStateBase : public AGameStateBase
{
	GENERATED_BODY()
public:
	
	virtual void BeginPlay() override;
	void StartLevel();
};
