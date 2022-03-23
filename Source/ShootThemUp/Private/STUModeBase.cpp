// ShootThemUp game


#include "STUModeBase.h"
#include "Player/STUBaseCharacter.h"
#include "Player/STUPlayerController.h"

ASTUModeBase::ASTUModeBase()
{
    DefaultPawnClass = ASTUBaseCharacter::StaticClass();
    PlayerControllerClass = ASTUPlayerController::StaticClass();
}
