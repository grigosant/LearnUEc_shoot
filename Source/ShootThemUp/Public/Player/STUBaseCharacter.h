// ShootThemUp game

#pragma once

#include "CoreMinimal.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"

#include "STUBaseCharacter.generated.h"

class UCameraComponent;
class USTUHealthComponent;
class UTextRenderComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUBaseCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    ASTUBaseCharacter(const FObjectInitializer &ObjectInitializer);

protected:

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
    UCameraComponent *CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
    USpringArmComponent *SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
    USTUHealthComponent *HealthComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
    UTextRenderComponent *HealthTextComponent;

    UPROPERTY(EditDefaultsOnly, Category= "Animation")
    UAnimMontage *DeathAnimMontage;

    UPROPERTY(EditDefaultsOnly, Category= "Damage")
    FVector2D LandedDamageVelocity = FVector2D(900.0f, 1200.0f);
    
    UPROPERTY(EditDefaultsOnly, Category= "Damage")
    FVector2D LandedDamage = FVector2D(10.0f, 100.0f);

    UPROPERTY(EditDefaultsOnly, Category= "Damage")
    float LifeSpanOnDeath = 5.0f;
    
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UFUNCTION(BlueprintCallable, Category= "Movement")
    bool IsRunning() const;

    UFUNCTION(BlueprintCallable, Category= "Movement")
    float GetMovementDirection() const;
    
private:
    bool WantToRun;
    bool IsMovingForward = false;
    
    void MoveForward(float Amount);
    void MoveRight(float Amount);

    void OnStartRunning();
    void OnStopRunning();

    void OnDeath();
    void OnHealthChanged(float Health);

    UFUNCTION()
    void OnGroundLanded(const FHitResult& Hit);
};
