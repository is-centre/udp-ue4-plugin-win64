# UDPCommunication for UE4 #

UDPCommunication is a plugin for UE4 that implements simple UDP communication. It is very simple and lightweight, but can be used for demanding applications like real-time communication.

In Alpha Control Lab (https://a-lab.ee/) and Re:creation VR&AR Lab (https://recreation.ee/) the plugin is used primarily for real-time communication with MATLAB/Simulink software.

Application example: https://recreation.ee/r/about/2018-11-ut/02/

## Installation and usage ##

See these videos:
* https://www.youtube.com/watch?v=db6Myy9R2OI (for UE4.17, UE4.21, and UE4.26 only atm!)
* https://www.youtube.com/watch?v=Avj8T6RGyPo


Quick rundown:
* Create a **Plugins** folder in your UE4 project root. The plugin can be used even in case of purely blueprint-based projects.
* Copy the UDPCommunication folder from **4.xx** into the new folder where **xx** is your UE4.xx engine version.
* The plugin is automatically activated and its contents can now be used.
* Create an **Actor** blueprint. In the parent class field, choose either UDPReceiver or UDPSender depending on what you intend to use the plugin for.
* Using the reference to the new blueprint instance, initialize the UDP socket in, e.g., Level Blueprint.
* On the other hand, you can initialize the socket in the Actor blueprint itself using the On Begin Play event. This makes it much more convenient to use in the sense of modularity of actors without dependence on the Level Blueprint (which is considered a poor BP programming practice in general). To see an example of this in action, have a look at this repo: https://github.com/is-centre/Crane3D-simple-visualization-ue4
* Use the receive/send functions, break the incoming data as needed, use it in your new Actor blueprint.

## Changing the data structure ##

By default, The plugin uses 20 float and 3 uint8 data structures. This structure can be changed as needed by changing the struct FUDPData located in \UDPCommunication\Source\UDPCommunication\Classes\UDPData.h
For example to send and receive strings we can add FString to the structure as follows:
```
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
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		FString fstring1 = "";
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		FString fstring2 = "";
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UDPCommunication")
		FString fstring3 = "";
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
	Ar << Structure.fstring1;
	Ar << Structure.fstring2;
	Ar << Structure.fstring3;
	return Ar;
}
```
 
## Next steps ##

* Clean up repo, setup a pipeline for releases.
* Documentation!

## Credits ##

Original code: UE4 user Rama (see https://wiki.unrealengine.com/UDP_Socket_Sender_Receiver_From_One_UE4_Instance_To_Another)

Update for real-time communication: Ralf Anari, TalTech University

Plugin format, packaging, and further updates: Aleksei Tepljakov, TalTech University
