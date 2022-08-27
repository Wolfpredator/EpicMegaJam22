// EpicMagaJam2022

#pragma once

#include "CoreMinimal.h"
#include "MG22BaseRoomRotator.h"
#include "MG22InteractionInterface.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "MG22Starter.generated.h"

UCLASS()
class EPICMEGAJAM2022_API AMG22Starter : public AActor, public IMG22InteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMG22Starter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
  virtual void InteractWithMe() override;

  UPROPERTY(EditAnywhere)
  AMG22BaseRoomRotator* Rotator;

  UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
  UStaticMeshComponent* StaticMesh;

private:


 UPROPERTY(VisibleAnywhere)
  UBoxComponent* BoxCollider;
  
};
