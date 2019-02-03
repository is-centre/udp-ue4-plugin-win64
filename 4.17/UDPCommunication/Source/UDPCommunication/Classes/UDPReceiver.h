#pragma once

#include "GameFramework/Actor.h"
#include "Networking.h"
#include "UDPData.h"
#include "UDPReceiver.generated.h"

UCLASS()
class UDPCOMMUNICATION_API AUDPReceiver : public AActor
{
	GENERATED_UCLASS_BODY()
public:
	FUDPData MyData;
	bool UpdateInterest = true;
	bool got_new_data = false;

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "UDPCommunication")
		void BPEvent_DataReceived(const FUDPData& data);
public:
	
	FSocket* ListenSocket;
	FUdpSocketReceiver* Receiver = nullptr;
	void Recv(const FArrayReaderPtr& ArrayReaderPtr, const FIPv4Endpoint& EndPt);
	virtual void Archive(const FArrayReaderPtr & ArrayReaderPtr);
	virtual void UpdateReceiverData(FUDPData data);
	
	UFUNCTION(BlueprintCallable, Category = "UDPCommunication")
		FUDPData GetData();
	
	UFUNCTION(BlueprintCallable, Category = "UDPCommunication")
		bool IsNewDataReady();
	
	UFUNCTION(BlueprintCallable, Category = "UDPCommunication")
		bool StartUDPReceiver(const FString& SocketName,
			const FString& IP,
			const int32 Port);

public:

	/** Called whenever this actor is being removed from a level */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

};