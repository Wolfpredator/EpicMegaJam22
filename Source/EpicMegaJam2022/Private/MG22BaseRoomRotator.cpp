// EpicMagaJam2022


#include "MG22BaseRoomRotator.h"

// Sets default values
AMG22BaseRoomRotator::AMG22BaseRoomRotator() {
  // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  TriggerBox = CreateDefaultSubobject<UBoxComponent>("TriggerBox");
  TriggerBox->SetupAttachment(GetRootComponent());

  

}




// Called when the game starts or when spawned
void AMG22BaseRoomRotator::BeginPlay() {
  Super::BeginPlay();

}

void AMG22BaseRoomRotator::FlipRoom() {

  WantToRotate = true;
  DestinationAngle = DestinationAngle == 0?180:0;
  IsRotation = true;
  StopPhysics();
}

void AMG22BaseRoomRotator::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);
  if(IsRotation)Rotate181(DeltaTime);
}

void AMG22BaseRoomRotator::Rotate181(float DeltaTime) {
		FRotator NewRotation = FMath::RInterpConstantTo(GetActorRotation(), FRotator(0.f, 0.f, DestinationAngle), DeltaTime, RotationSpeed);
		SetActorRotation(NewRotation);
		float xAngle = GetActorRotation().Roll;
		UE_LOG(LogTemp, Display, TEXT("%d"), xAngle);
		if (xAngle == 0.f || xAngle == 180.f) {
			IsRotation = false;
			ContinueSimylationPhysics();
		}
}

void AMG22BaseRoomRotator::StopPhysics()
{
	TArray<AActor*> Result;
	GetOverlappingActors(Result, AActor::StaticClass());
	for (AActor* overlapActor : Result) {
		Cast<UPrimitiveComponent>(overlapActor->GetRootComponent())->SetSimulatePhysics(false);
		overlapActor->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepWorld, true));
	}
}

void AMG22BaseRoomRotator::ContinueSimylationPhysics()
{
	TArray<AActor*> Result;
	GetOverlappingActors(Result, AActor::StaticClass());
	for (AActor* overlapActor : Result) {
		Cast<UPrimitiveComponent>(overlapActor->GetRootComponent())->SetSimulatePhysics(true);
	}
}


