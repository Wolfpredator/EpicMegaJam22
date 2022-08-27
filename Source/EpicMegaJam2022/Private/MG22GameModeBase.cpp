// EpicMagaJam2022


#include "MG22GameModeBase.h"
#include "Player/MG22BaseCharacter.h"
#include "Player/MG22PlayerController.h"

AMG22GameModeBase::AMG22GameModeBase() {

  DefaultPawnClass = AMG22BaseCharacter::StaticClass();
  PlayerControllerClass = AMG22PlayerController::StaticClass();
}
