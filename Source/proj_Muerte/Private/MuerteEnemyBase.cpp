// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.


#include "MuerteEnemyBase.h"

// Sets default values
AMuerteEnemyBase::AMuerteEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMuerteEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMuerteEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMuerteEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

