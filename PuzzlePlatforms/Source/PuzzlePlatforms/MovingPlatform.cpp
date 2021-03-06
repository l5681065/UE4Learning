// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	 
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}	
	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation= GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority()) 
	{
		FVector Location = GetActorLocation(); 		
		
		float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
		float JournTravelled = (Location-GlobalStartLocation).Size();
		 if (JournTravelled>=JourneyLength)
		 {
			 FVector Swap = GlobalStartLocation;
			 GlobalStartLocation = GlobalTargetLocation;
			 GlobalTargetLocation = Swap;
		 }
		//TagrgetLoaction 这里为局部坐标即为相对Actor位置的坐标  TransformPosition 转为世界坐标 
		FVector Direction = (GlobalTargetLocation - Location).GetSafeNormal();
		Location += Speed * DeltaTime*Direction;
		SetActorLocation(Location);
	}

	
}
