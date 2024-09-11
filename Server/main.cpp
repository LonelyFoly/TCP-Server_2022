//Server Code [Tutorial 10] [Nonblocking] [Winsock]
//Author: Jacob Preston 2019-06-28

#include "DemoServer.h"
#include <iostream>

int main()
{
	if (Network::Initialize())
	{
		DemoServer server;
		if (server.Initialize(IPEndpoint("::", 6112)))// 127.0.0.1 : 6112
		{
			while (true)
			{
				server.Frame();
			}
		}
	}
	Network::Shutdown();
	return 0;
}