// Item_Actor.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyItem_Actor.generated.h"

UCLASS()
class CYBER_API AMyItem_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyItem_Actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Variablen für den Bereich, indem das Item erscheinen kann
	int MinSpawnX = -1850;
	int MaxSpawnX = 1070;
	int MinSpawnY = -1470;
	int MaxSpawnY = 1470;
	int SpawnZ = 180;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> ScoreB;			//Score Blueprint verweis
	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> xBP;			//2x Item BLueprint verweis
	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> plusTimerBP;	//plusTimer Blueprint verweis
	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> EmtyBP;	//plusTimer Blueprint verweis

private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> ActorToSpawn;

	//Funktionen
	void SpawnItem();
	FVector GetActorLocation();
	FRotator GetActorRotation();
};
