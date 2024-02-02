// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Pawn.h"

// Sets default values
AEnemy_Pawn::AEnemy_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//Emilys Code
/*
public:
    UFUNCTION(BlueprintCallable, Category = "AI")
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
        int32 NumberOfEnemies = 2;

private:
    UWorld* World;
};

void ARandomSpawnEnemy::SpawnEnemy()
{
    World = GetWorld();

    for (int i = 0; i < NumberOfEnemies; i++)
    {
        FVector SpawnLocation = GetPawn()->GetActorLocation() + FMath::VRand() * SpawnRadius;

        AEnemy* SpawnedEnemy = World->SpawnActor<AEnemy>(EnemyBlueprint, SpawnLocation, FRotator::ZeroRotator);

        if (SpawnedEnemy)
        {
            MoveToRandomLocation();
        }
    }
}

void ARandomSpawnEnemy::MoveToRandomLocation()
{
    FVector Destination = GetPawn()->GetActorLocation() + FMath::VRand() * MoveRadius;

    UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
    if (NavSys)
    {
        FNavLocation NextLocation;
        NavSys->GetRandomPointInNavigableRadius(GetPawn()->GetActorLocation(), MoveRadius, NextLocation);
        Destination = NextLocation.Location;
    }
    MoveToLocation(Destination);
}*/