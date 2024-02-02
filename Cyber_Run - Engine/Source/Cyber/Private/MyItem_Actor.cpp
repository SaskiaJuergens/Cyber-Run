// Item_Actor.cpp


#include "MyItem_Actor.h"

// Sets default values
AMyItem_Actor::AMyItem_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyItem_Actor::BeginPlay()
{
	Super::BeginPlay();

    //Random Item Generator
    int Item = FMath::RandRange(1, 4);
    if (Item == 1) {
        ActorToSpawn = ScoreB;
    }
    if (Item == 2) {
        ActorToSpawn = xBP;
    }
    if (Item == 3) {
        ActorToSpawn = plusTimerBP;
    }
    if (Item >= 5) {
        ActorToSpawn = EmtyBP;
    }

    SpawnItem();
}

// Called every frame
void AMyItem_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyItem_Actor::SpawnItem() {
    //Random Location in einem bestimmten Bereich
    const FVector Location = GetActorLocation();
    //Rotation für die ansicht (Konstant!)
    const FRotator Rotation = GetActorRotation();

     //Spawn Item
     GetWorld()->SpawnActor<AActor>(ActorToSpawn, Location, Rotation);

}

FVector AMyItem_Actor::GetActorLocation()
{
    // Generiert den Spawn-Bereich
    // zufällige X - und Y - Koordinaten zwischen MinSpawnX und MaxSpawnX bzw.MinSpawnY 
    //und MaxSpawnY generiert.Der Wert der Z - Koordinate ist dagegen festgelegt(SpawnZ).   

    FVector SpawnLocation;
    // Generate random values between MinSpawnX and MaxSpawnX for the X coordinate
    SpawnLocation.X = FMath::RandRange(MinSpawnX, MaxSpawnX);

    // Generate random values between MinSpawnY and MaxSpawnY for the Y coordinate
    SpawnLocation.Y = FMath::RandRange(MinSpawnY, MaxSpawnY);

    // Assign a fixed value for the Z coordinate
    SpawnLocation.Z = SpawnZ;
    return SpawnLocation;
}

FRotator AMyItem_Actor::GetActorRotation()
{
    //Dreht die Objecte um konstante variablen, sodass sie sichbar sind als 2D Object im 3 dimensionalen Raum
    FRotator CurrentRotation = Super::GetActorRotation();
    CurrentRotation.Yaw = 90.f;                             //Rotation nach x
    CurrentRotation.Pitch += 180.f;                         //Rotation nach y
    CurrentRotation.Roll -= 90.f;                           //Rotation nach z
    return CurrentRotation;
}