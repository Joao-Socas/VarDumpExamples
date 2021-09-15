// Copyright 2021, João P. B. Socas. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DumpExample.generated.h"

UCLASS()
class VARDUMPEXAMPLES_API ADumpExample : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADumpExample();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	static bool LastCall;

private:
	TArray<int32> AdressStorage;
	FVector FVectorExample;
	bool BooleanExample;
	float FloatExample;
	TArray<FTransform> TArrayExample;
	//TArray<TArray<TArray<int32>>> MyNestedTarray{ {{1,2},{0}}, {{55}} };
	
};
bool ADumpExample::LastCall = false;