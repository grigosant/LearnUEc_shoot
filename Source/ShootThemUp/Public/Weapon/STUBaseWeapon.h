// ShootThemUp game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUBaseWeapon.generated.h"

class USkeletalMeshComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUBaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	ASTUBaseWeapon();

	virtual void StartFire();
	virtual void StopFire();
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent *WeaponMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FName MazzleSocketName = "MazzleSocket";

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TraceMaxDistance = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DamageAmount = 10.0f;

	
	virtual void BeginPlay() override;

	virtual void MakeShot();
	void MakeDamage(const FHitResult& HitResult);
	APlayerController* ASTUBaseWeapon::GetPlayerController() const;
	bool GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRotation) const;
	FVector GetMuzzleWorldLocation() const;
	virtual bool GetTraceData(FVector &TraceStart, FVector &TraceEnd) const;
	void MakeHit(FHitResult &HitResult, const FVector &TraceStart, const FVector &TraceEnd);
};
