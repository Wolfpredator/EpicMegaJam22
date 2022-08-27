// EpicMagaJam2022

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Dev/MG22InteractionInterface.h"
#include "GameFramework/Character.h"
#include "MG22BaseCharacter.generated.h"

class UCameraComponent;

UCLASS()
class EPICMEGAJAM2022_API AMG22BaseCharacter : public ACharacter {
  GENERATED_BODY()

public:
  // Sets default values for this character's properties
  AMG22BaseCharacter();

protected:
  
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Interaction")
  UBoxComponent *InteractionZone;
  
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
  UCameraComponent *CameraComponent;
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

public:

  void OnInteract();
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  // Called to bind functionality to input

  virtual void SetupPlayerInputComponent(
      class UInputComponent *PlayerInputComponent) override;
private:

    UFUNCTION()
        void OnBoxBeingOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    UFUNCTION()
        void OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);



IMG22InteractionInterface* InteractibleActor = nullptr;
  
  void MoveForward(float Amount);
  void MoveStrafe(float Amount);
};
