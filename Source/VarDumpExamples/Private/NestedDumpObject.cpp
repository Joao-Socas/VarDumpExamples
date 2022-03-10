// Copyright 2021, João P. B. Socas. All Rights Reserved.

#include "NestedDumpObject.h"
#include "../Plugins/Marketplace/VarDump/Source/VarDump/Public/VarDump.h"

// Sets default values
ANestedDumpObject::ANestedDumpObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANestedDumpObject::BeginPlay()
{
	Super::BeginPlay();
	MyTransform = GetTransform();
}

// Called every frame
void ANestedDumpObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FTransform NewTransform = GetTransform();
	if (!MyTransform.Equals(NewTransform))
	{
		MyTransform = NewTransform;
	}
}

