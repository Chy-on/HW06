// Fill out your copyright notice in the Description page of Project Settings.


#include "HW06GameStateBase.h"

#include "SpawnVolume.h"
#include "Kismet/GameplayStatics.h"

void AHW06GameStateBase::BeginPlay()
{
	Super::BeginPlay();
	StartLevel();
}

void AHW06GameStateBase::StartLevel()
{
	TArray<AActor*> FoundVolumes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
		ASpawnVolume::StaticClass(),FoundVolumes);

	const int32 ActorToSpawn = 50;
	for (int32 i=0; i<ActorToSpawn; i++)
	{
		if (FoundVolumes.Num()>0)
		{
			ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]);
			if (SpawnVolume)
			{
				AActor* SpawnedActor = SpawnVolume->SpawnRandomActor();
			}
		}
	}
}