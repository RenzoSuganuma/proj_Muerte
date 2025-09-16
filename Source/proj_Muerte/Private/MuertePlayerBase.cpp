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

	TArray<USceneComponent*> components;
	GetRootComponent()->GetChildrenComponents(true, components);
	for (auto c : components)
	{
		UCameraComponent* camera = Cast<UCameraComponent>(c);
		if (IsValid(camera))
		{
			m_cameraComponent = camera;
		}
	}

	if (IsValid(m_cameraComponent))
	{
		m_cameraComponent->SetFieldOfView(m_fovDefault);
	}
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
