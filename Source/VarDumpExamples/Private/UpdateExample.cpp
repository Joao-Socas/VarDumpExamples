// Copyright 2021, Jo�o P. B. Socas. All Rights Reserved.

#include "UpdateExample.h"
#include "../Plugins/Marketplace/VarDump/Source/VarDump/Public/VarDump.h"

// Sets default values
AUpdateExample::AUpdateExample()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUpdateExample::BeginPlay()
{
	Super::BeginPlay();
	MyTransform = GetTransform();
	VARDUMP(MyTransform);
	VARDUMP(MyTransform); // Dumping two times, just the last updates

	bool TogleEveryFiveSeconds = TogleKeeper;
	VARDUMP(TogleEveryFiveSeconds);
}

// Called every frame
void AUpdateExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FTransform NewTransform = GetTransform();
	if (!MyTransform.Equals(NewTransform))
	{
		MyTransform = NewTransform;
		UPDATEDUMP(MyTransform);
	}

	SecondsCounter += DeltaTime;
	bool TogleEveryFiveSeconds;
	if (SecondsCounter > 4)
	{
		SecondsCounter -= 4;
		TogleKeeper = !TogleKeeper;
		TogleEveryFiveSeconds = TogleKeeper;
		UPDATEDUMP(TogleEveryFiveSeconds); //Even though updating a local variable, it updates because of the same name of a dump
	}
}

