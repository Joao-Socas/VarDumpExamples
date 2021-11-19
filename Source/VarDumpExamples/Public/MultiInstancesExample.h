// Copyright 2021, João P. B. Socas. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MultiInstancesExample.generated.h"

UCLASS()
class VARDUMPEXAMPLES_API AMultiInstancesExample : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMultiInstancesExample();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FTransform MyTransform;
	TArray<int32> TransformDumpAdress;


};
