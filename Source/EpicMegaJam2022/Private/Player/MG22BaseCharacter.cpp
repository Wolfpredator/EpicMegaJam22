// EpicMagaJam2022


#include "Player/MG22BaseCharacter.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMG22BaseCharacter::AMG22BaseCharacter() {
  // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
  CameraComponent->SetupAttachment(GetRootComponent());

  InteractionZone = CreateDefaultSubobject<UBoxComponent>("InteractionBox");
  InteractionZone->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AMG22BaseCharacter::BeginPlay() {
  Super::BeginPlay();
  InteractionZone->OnComponentBeginOverlap.AddDynamic(
      this, &AMG22BaseCharacter::OnBoxBeingOverlap);
  InteractionZone->OnComponentEndOverlap.AddDynamic(
      this, &AMG22BaseCharacter::OnBoxEndOverlap);
  
}

// Called every frame

void AMG22BaseCharacter::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);
}

// Called to bind functionality to in

void AMG22BaseCharacter::SetupPlayerInputComponent(
    UInputComponent *PlayerInputComponent) {
  Super::SetupPlayerInputComponent(PlayerInputComponent);

  PlayerInputComponent->BindAxis("MoveForward", this,
                                 &AMG22BaseCharacter::MoveForward);
  PlayerInputComponent->BindAxis("MoveStrafe", this,
                                 &AMG22BaseCharacter::MoveStrafe);
  PlayerInputComponent->BindAxis("LookUp", this,
                                 &AMG22BaseCharacter::AddControllerPitchInput);
  PlayerInputComponent->BindAxis("TurnAround", this,
                                 &AMG22BaseCharacter::AddControllerYawInput);
  PlayerInputComponent->BindAction("Interact", IE_Pressed, this,
                                   &AMG22BaseCharacter::OnInteract);

}



void AMG22BaseCharacter::OnBoxBeingOverlap(
    UPrimitiveComponent *OverlappedComponent, AActor *OtherActor,
    UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
    const FHitResult &SweepResult) {
  InteractibleActor = Cast<IMG22InteractionInterface>(OtherActor);
}

void AMG22BaseCharacter::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
    InteractibleActor = nullptr;
}




void AMG22BaseCharacter::OnInteract() {
  if(InteractibleActor){
    InteractibleActor->InteractWithMe();
        }
}

void AMG22BaseCharacter::MoveForward(float Amount) {
  AddMovementInput(GetActorForwardVector(), Amount);
}

void AMG22BaseCharacter::MoveStrafe(float Amount) {
  AddMovementInput(GetActorRightVector(), Amount);
}
