// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyBallPawn.generated.h"

// forward declarations
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

UCLASS()
class MYPROJECT_API AMyBallPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyBallPawn();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputMappingContext* MappingContext;


	UStaticMeshComponent* SphereMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void OnMovement(const FInputActionValue& value);
};
