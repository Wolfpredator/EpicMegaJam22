// EpicMagaJam2022

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MG22InteractionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMG22InteractionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class EPICMEGAJAM2022_API IMG22InteractionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
  virtual void InteractWithMe();
};
