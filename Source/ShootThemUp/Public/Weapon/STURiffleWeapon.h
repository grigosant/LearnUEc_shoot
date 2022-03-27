// ShootThemUp game

#pragma once

#include "CoreMinimal.h"
#include "Weapon/STUBaseWeapon.h"
#include "STURiffleWeapon.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API ASTURiffleWeapon : public ASTUBaseWeapon
{
	GENERATED_BODY()

public:
	virtual void StartFire() override;
	virtual void StopFire() override;
protected:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeBetweenShot = 0.1f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BulletSpread = 1.5f;
	
	virtual void MakeShot() override;
	virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const override;
private:
	FTimerHandle ShootTimerHandle;
};
