// Copyright 2021, João P. B. Socas. All Rights Reserved.

#include "DumpExample.h"
#include "../Plugins/Marketplace/VarDump/Source/VarDump/Public/VarDump.h"

// Sets default values
ADumpExample::ADumpExample()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ADumpExample::BeginPlay()
{
	Super::BeginPlay();

	int8 MyChar = 1;
	int32 MyInt = 21321;
	int64 MyLong = LONGLONG_MAX;
	bool MyBool = true;
	FString MyFString = "My FString";
	FName MyFName = "My FName";
	FText MyText = FText::FromString("My FText");
	float MyFloat = 0.1234567; // decimal-binary conversion digits may not be precise on string conversion
	double MyDouble = 0.123456789101112; // decimal-binary conversion digits may not be precise on string conversion
	FVector MyFVector = FVector(0, 0, 0);
	FVector2D MyFVector2D = FVector2D(0, 0);
	FVector4 MyFVector4 = FVector4(0, 0, 0, 0);
	FRotator MyRotator = FRotator(0, 0, 0);
	FQuat MyFQuat = FQuat(0, 0, 0, 1);
	FTransform MyTransform = GetTransform(); 
	TArray<TArray<TArray<int32>>> MyNestedTarray{ {{1,2},{0}}, {{55}} };

	VARDUMP("My const char*");
	VARDUMP(MyChar);
	VARDUMP(MyInt);
	VARDUMP(MyLong);
	VARDUMP(MyBool);
	VARDUMP(MyFString);
	VARDUMP(MyFName);
	VARDUMP(MyText);
	VARDUMP(MyFloat);
	VARDUMP(MyDouble);
	VARDUMP(MyFVector);
	VARDUMP(MyFVector2D);
	VARDUMP(MyFVector4);
	VARDUMP(MyRotator);
	VARDUMP(MyFQuat);
	VARDUMP(MyTransform);
	VARDUMP(MyNestedTarray);
}

// Called every frame
void ADumpExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

