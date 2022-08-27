// EpicMagaJam2022

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "MG22BaseRoomRotator.generated.h"

class ATriggerBase;

UCLASS()
class EPICMEGAJAM2022_API AMG22BaseRoomRotator : public AActor{
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  AMG22BaseRoomRotator();

protected:
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
  UBoxComponent *TriggerBox;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RotationSettings")
  float RotationSpeed = 2;

  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

public:
  
  void FlipRoom();
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  void Rotate181(float DeltaTime);

private:

	void StopPhysics();
	void ContinueSimylationPhysics();
 
  double DestinationAngle = 0;
  bool WantToRotate = false;
  bool IsRotation;


};
