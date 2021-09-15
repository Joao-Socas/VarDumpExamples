// Copyright 2021, João P. B. Socas. All Rights Reserved.

#include "MultiObjectExample.h"
#include "DrawDebugHelpers.h"
#include "VarDump.h" // for installed plugin, use "../Plugins/Marketplace/VarDump/Source/VarDump/Public/VarDump.h"

// Sets default values
AMultiObjectExample::AMultiObjectExample()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMultiObjectExample::BeginPlay()
{
	Super::BeginPlay();
	MyTransform = GetTransform();
	FString MyActorName = GetName();
	DrawDebugString(GetWorld(), MyTransform.GetLocation() + FVector(-80, 0 , 100), MyActorName, nullptr, FColor::Blue); // #include "DrawDebugHelpers.h"

	TArray<int32> NameDumpAdress = VARDUMP(MyActorName);
	TransformDumpAdress = VARDUMP(MyTransform, NameDumpAdress);


}

// Called every frame
void AMultiObjectExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FTransform NewTransform = GetTransform();
	if (!MyTransform.Equals(NewTransform))
	{
		MyTransform = NewTransform;
		UPDATEDUMP(MyTransform, TransformDumpAdress);
	}
}

