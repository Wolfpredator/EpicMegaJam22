// EpicMagaJam2022

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MG22BaseCharacter.generated.h"

UCLASS()
class EPICMEGAJAM2022_API AMG22BaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMG22BaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
