#pragma once

#include "Serialization/Archive.h"
#include "UDPData.generated.h"

USTRUCT(BlueprintType)
struct FUDPData {
	GENERATED_USTRUCT_BODY()
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float1 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float2 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float3 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float4 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float5 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float6 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float7 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float8 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float9 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float10 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float11 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float12 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float13 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float14 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float15 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float16 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float17 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float18 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float19 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		float float20 = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		uint8 uint1 = 0;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		uint8 uint2 = 0;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		uint8 uint3 = 0;
	FUDPData() {
	}
};

FORCEINLINE FArchive& operator<<(FArchive &Ar, FUDPData &Structure)
{
	Ar << Structure.float1;
	Ar << Structure.float2;
	Ar << Structure.float3;
	Ar << Structure.float4;
	Ar << Structure.float5;
	Ar << Structure.float6;
	Ar << Structure.float7;
	Ar << Structure.float8;
	Ar << Structure.float9;
	Ar << Structure.float10;
	Ar << Structure.float11;
	Ar << Structure.float12;
	Ar << Structure.float13;
	Ar << Structure.float14;
	Ar << Structure.float15;
	Ar << Structure.float16;
	Ar << Structure.float17;
	Ar << Structure.float18;
	Ar << Structure.float19;
	Ar << Structure.float20;
	Ar << Structure.uint1;
	Ar << Structure.uint2;
	Ar << Structure.uint3;
	return Ar;
}