// Copyright 2021, Jo�o P. B. Socas. All Rights Reserved.

#include "DumpObjectExample.h"
#include "NestedDumpObject.h"
#include "../Plugins/Marketplace/VarDumpPlus/Source/VarDump/Public/VarDump.h"

void GenerateRandomArray(TArray<TArray<TArray<int32>>>& RandomArray);
void GenerateRandomDouble(double& RandomDouble);

// Sets default values
ADumpObjectExample::ADumpObjectExample()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ADumpObjectExample::BeginPlay()
{
	Super::BeginPlay();
	GenerateRandomArray(RandomArray);
	MyInternalObject = TSharedPtr<SomeInternalClass>(new SomeInternalClass); // For dumping objects that are not UObjects you must use a TSharedPtr
	MyInternalObject->APublicFVector4Member = FVector4(0, 0, 0, 0);
	MyInternalObject->APublicDoubleMember = 0;
	if (MySubobject)
	{
#if WITH_EDITOR // With editor we can use GetActorLabel
		VARDUMPOBJECT(this, "Example", UpdatedTimes, RandomArray,
			VARDUMPOBJECT(MySubobject, MySubobject->GetActorLabel(), MySubobject->MyTransform, MySubobject->SomeString),
			VARDUMPOBJECT(MyInternalObject, "MyInternalObject", MyInternalObject->APublicDoubleMember, MyInternalObject->APublicFVector4Member)
		);
#else // Without editor we have to use the GetName from UObjects
		VARDUMPOBJECT(this, "Example", UpdatedTimes, RandomArray,
			VARDUMPOBJECT(MySubobject, MySubobject->GetName(), MySubobject->MyTransform, MySubobject->SomeString),
			VARDUMPOBJECT(MyInternalObject, "MyInternalObject", MyInternalObject->APublicDoubleMember, MyInternalObject->APublicFVector4Member)
		);
#endif // WITH_EDITOR

	}
	else
	{
		VARDUMP("You need to attribute a ANestedDumpObject to this Actor->MySubobject");
	}
}

void ADumpObjectExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SecondsCounter += DeltaTime;
	if (SecondsCounter > 6)
	{
		UpdatedTimes++;
		SecondsCounter -= 6;
		GenerateRandomArray(RandomArray);
		if (MySubobject)
		{
			UPDATEOBJECTDUMP(this);
		}
	}
	GenerateRandomDouble(MyInternalObject->APublicDoubleMember);
	UPDATEOBJECTDUMP(MyInternalObject); // You can also update just the nested dump
}

void GenerateRandomArray(TArray<TArray<TArray<int32>>>& RandomArray)
{
	RandomArray.Empty();
	for (int32 i = 0; i < FMath::RandRange(0, 3); i++)
	{
		RandomArray.Add(TArray<TArray<int32>>{});
		for (int32 j = 0; j < FMath::RandRange(0, 3); j++)
		{
			RandomArray[i].Add(TArray<int32>{});
			for (int32 k = 0; k < FMath::RandRange(0, 3); k++)
			{
				RandomArray[i][j].Add(FMath::RandRange(0, 10));
			}
		}
	}
}

void GenerateRandomDouble(double& RandomDouble)
{
	RandomDouble = 0;
	for (int32 i = 0; i < 16; i++)
	{
		RandomDouble += FMath::RandRange(0, 10) / (pow(10, i));
	}
}
