// Copyright 2021, João P. B. Socas. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DumpObjectExample.generated.h"

class ANestedDumpObject;

class SomeInternalClass
{
public:
	FVector4 APublicFVector4Member;
	double APublicDoubleMember;
};

UCLASS()
class VARDUMPEXAMPLES_API ADumpObjectExample : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADumpObjectExample();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = MyCategory)
	ANestedDumpObject* MySubobject;

	TSharedPtr<SomeInternalClass> MyInternalObject;

	float SecondsCounter = 0;
	int64 UpdatedTimes = 0;
	TArray<TArray<TArray<int32>>> RandomArray;
};
