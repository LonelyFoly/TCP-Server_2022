#pragma once
#include "Constants.h"
#include "SocketHandle.h"
#include "Result.h"
#include "IPVersion.h"
#include "SocketOption.h"
#include "IPEndpoint.h"
#include "Packet.h"

namespace TCPNet
{
	class Socket
	{
	public:
		Socket(	IPVersion ipversion = IPVersion::IPv4,
				SocketHandle handle = INVALID_SOCKET);
		Result Create();
		Result Close();
		Result Bind(IPEndpoint endpoint);
		Result Listen(IPEndpoint endpoint, int backlog = 5);
		Result Accept(Socket & outSocket, IPEndpoint * endpoint = nullptr);
		Result Connect(IPEndpoint endpoint);
		Result Send(const void * data, int numberOfBytes, int & bytesSent);
		Result Recv(void * destination, int numberOfBytes, int & bytesReceived);
		Result SendAll(const void * data, int numberOfBytes);
		Result RecvAll(void * destination, int numberOfBytes);
		Result Send(Packet & packet);
		Result Recv(Packet & packet);
		SocketHandle GetHandle();
		IPVersion GetIPVersion();
		Result SetBlocking(bool isBlocking);
	private:
		Result SetSocketOption(SocketOption option, BOOL value);
		IPVersion ipversion = IPVersion::IPv4;
		SocketHandle handle = INVALID_SOCKET;
	};
}