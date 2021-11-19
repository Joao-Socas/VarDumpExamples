// Copyright 2021, João P. B. Socas. All Rights Reserved.

#include "MultiInstancesExample.h"
#include "DrawDebugHelpers.h"
//#include "../Plugins/Marketplace/VarDump/Source/VarDump/Public/VarDump.h"
#include "VarDump.h"

// Sets default values
AMultiInstancesExample::AMultiInstancesExample()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMultiInstancesExample::BeginPlay()
{
	Super::BeginPlay();
	MyTransform = GetTransform();
	FString MyActorName = GetActorLabel();
	DrawDebugString(GetWorld(), MyTransform.GetLocation() + FVector(-80, 0 , 100), MyActorName, nullptr, FColor::Blue); // #include "DrawDebugHelpers.h"

	VARDUMP(MyTransform, VARDUMP(MyActorName));
}

// Called every frame
void AMultiInstancesExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FTransform NewTransform = GetTransform();
	if (!MyTransform.Equals(NewTransform))
	{
		MyTransform = NewTransform;
		UPDATEDUMP(MyTransform);
	}
}

