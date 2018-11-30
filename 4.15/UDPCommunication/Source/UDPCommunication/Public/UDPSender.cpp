#include "UDPCommunication.h"
#include "UDPSender.h"

// Sets default values
AUDPSender::AUDPSender(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)

{
	SenderSocket = NULL;
}

bool AUDPSender::StartUDPSender(const FString & SocketName, const FString & TheIP, const int32 ThePort)
{
	//Create Remote Address
	RemoteAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();

	bool bIsValid;
	RemoteAddr->SetIp(*TheIP, bIsValid);
	RemoteAddr->SetPort(ThePort);

	if (!bIsValid)
	{
		UE_LOG(LogTemp, Warning, TEXT("Wrong IP address supplied."));
		return false;
	}

	SenderSocket = FUdpSocketBuilder(*SocketName)
		.AsReusable()
		.WithBroadcast()
		;

	//Set Send Buffer Size
	int32 SendSize = 2 * 1024 * 1024;
	SenderSocket->SetSendBufferSize(SendSize, SendSize);
	SenderSocket->SetReceiveBufferSize(SendSize, SendSize);

	return true;
}

bool AUDPSender::UDPSendArray(FUDPData data)
{
	if (!SenderSocket)
	{
		UE_LOG(LogTemp, Log, TEXT("There is no socket."));
		return false;
	}
	int32 BytesSent = 0;

	FArrayWriter Writer;
	Writer << data;
	SenderSocket->SendTo(Writer.GetData(), Writer.Num(), BytesSent, *RemoteAddr);

	if (BytesSent <= 0) {
		UE_LOG(LogTemp, Error, TEXT("Socket exists, but receiver did not accept any packets."));
		return false;
	}

	return true;
}

void AUDPSender::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (SenderSocket)
	{
		SenderSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(SenderSocket);
	}
}
