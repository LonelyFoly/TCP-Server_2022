#pragma once
#include <vector>

using namespace TCPNet;

namespace TCPNet
{
	class Protocol
	{

	public:
		Protocol() {}
		virtual bool IsHeaderReady(const char* buf, unsigned int sz);
		virtual int IsMessageComplete(const char* buf, unsigned int sz);
		virtual int ProcessMessage(const char* buf, unsigned int sz);
		int PrepareResponse(const char* buf, unsigned int sz, std::vector<char>& out_buf);
	};
}

