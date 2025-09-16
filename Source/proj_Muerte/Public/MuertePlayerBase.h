// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "MuertePlayerBase.generated.h"

UCLASS()
class PROJ_MUERTE_API AMuertePlayerBase : public ACharacter
{
	GENERATED_BODY()

private:
	// 主観視点のカメラのコンポーネント
	TObjectPtr<UCameraComponent> m_cameraComponent;

	UPROPERTY(EditAnywhere)
	float m_fovDefault = 70.0f;

public:
	// Sets default values for this character's properties
	AMuertePlayerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
