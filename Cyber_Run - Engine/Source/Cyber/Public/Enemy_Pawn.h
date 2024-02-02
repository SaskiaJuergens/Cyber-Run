// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Enemy_Pawn.generated.h"

UCLASS()
class CYBER_API AEnemy_Pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemy_Pawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UWorld* World;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*UFUNCTION(BlueprintCallable, Category = "AI")
		void SpawnEnemy();

	UFUNCTION(BlueprintCallable, Category = "AI")
		void MoveToRandomLocation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		TSubclassOf<class AEnemy> EnemyBlueprint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		float SpawnRadius = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		float MoveRadius = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		int32 NumberOfEnemies = 2;*/


};
