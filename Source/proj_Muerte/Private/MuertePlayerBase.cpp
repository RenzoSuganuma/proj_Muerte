// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.


#include "MuertePlayerBase.h"

// Sets default values
AMuertePlayerBase::AMuertePlayerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMuertePlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMuertePlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMuertePlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

