// ShootThemUp game


#include "Weapon/STURiffleWeapon.h"
#include <Engine/World.h>
#include "DrawDebugHelpers.h"

void ASTURiffleWeapon::StartFire()
{
	MakeShot();
	GetWorldTimerManager().SetTimer(ShootTimerHandle, this, &ASTURiffleWeapon::MakeShot, TimeBetweenShot, true);
}

void ASTURiffleWeapon::StopFire()
{
	GetWorldTimerManager().ClearTimer(ShootTimerHandle);
}

void ASTURiffleWeapon::MakeShot()
{
	if(!GetWorld())
		return;

	FVector TraceStart, TraceEnd;
	if(!GetTraceData(TraceStart, TraceEnd))
		return;

	FHitResult HitResult;

	MakeHit(HitResult, TraceStart, TraceEnd);
	
	if(HitResult.bBlockingHit)
	{
		MakeDamage(HitResult);
		DrawDebugLine(GetWorld(), GetMuzzleWorldLocation(), HitResult.ImpactPoint, FColor::Red, false, 3.0f, 0, 3.0f);
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 24.0f, FColor::Red,  false, 5.0f);
	}
	else
	{
		DrawDebugLine(GetWorld(), GetMuzzleWorldLocation(), TraceEnd, FColor::Red, false, 3.0f, 0, 3.0f);
	}
}

bool ASTURiffleWeapon::GetTraceData(FVector &TraceStart, FVector &TraceEnd) const
{
	FVector ViewLocation;
	FRotator ViewRotation;
	if(!GetPlayerViewPoint(ViewLocation, ViewRotation))
		return false;

	TraceStart = 	ViewLocation;
	const auto HalfRad = FMath::DegreesToRadians(BulletSpread);
	const FVector Direction = FMath::VRandCone(ViewRotation.Vector(), HalfRad);
	TraceEnd = TraceStart + Direction * TraceMaxDistance;
	return true;
}
