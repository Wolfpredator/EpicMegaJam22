// EpicMagaJam2022


#include "Player/MG22BaseCharacter.h"

// Sets default values
AMG22BaseCharacter::AMG22BaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMG22BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMG22BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMG22BaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

