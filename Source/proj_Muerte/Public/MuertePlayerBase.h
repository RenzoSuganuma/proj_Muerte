// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "MuertePlayerBase.generated.h"

// 主観視点プレイヤーのベース
UCLASS()
class PROJ_MUERTE_API AMuertePlayerBase : public ACharacter
{
	GENERATED_BODY()

private:
	// 主観視点のカメラのコンポーネント
	TObjectPtr<UCameraComponent> m_cameraComponent;

	UPROPERTY(EditAnywhere)
	float m_fovDefault = 70.0f;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> m_inputActionMove;
	
	FVector2D m_input;

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
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	// WASD移動の入力が入った時
	void ActionMove(const FInputActionValue& in_actionValue);
	// 入力→入力なしの状態になった時
	void OnMoveCanceled(const FInputActionValue& in_actionValue);
};