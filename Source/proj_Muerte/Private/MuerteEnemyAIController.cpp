// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.


#include "MuerteEnemyAIController.h"

#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AMuerteEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	if (m_behaviourTree)
	{
		RunBehaviorTree(m_behaviourTree);
		auto player = UGameplayStatics::GetPlayerPawn(this, 0);
		GetBlackboardComponent()->SetValueAsObject(FName(TEXT("TargetActor")), player);
	}
}
