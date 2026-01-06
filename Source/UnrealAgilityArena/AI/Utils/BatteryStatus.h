#pragma once
UENUM(BlueprintType)
enum class EBatteryStatus : uint8
{
	EBS_Empty = 0 UMETA(DisplayName = "Empty"),
	EBS_Low = 1 UMETA(DisplayName = "Low"),
	EBS_Medium = 2 UMETA(DisplayName = "Medium"),
	EBS_Full = 3 UMETA(DisplayName = "Full"),
};