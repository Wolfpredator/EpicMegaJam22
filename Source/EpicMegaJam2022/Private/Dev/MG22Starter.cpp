// EpicMagaJam2022


#include "Dev/MG22Starter.h"

// Sets default values
AMG22Starter::AMG22Starter() {
  // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
  SetRootComponent(StaticMesh);
  
  BoxCollider = CreateDefaultSubobject<UBoxComponent>("BoxCollider");
  BoxCollider->SetupAttachment(StaticMesh);


}

// Called when the game starts or when spawned
void AMG22Starter::BeginPlay() {
  Super::BeginPlay();

}

// Called every frame
void AMG22Starter::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);

}

void AMG22Starter::InteractWithMe() {
    if (Rotator) {
        Rotator->FlipRoom();
    }
}
