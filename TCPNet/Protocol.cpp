#include "Constants.h"
#include "Protocol.h"
#include <string> 


namespace TCPNet
{

	bool Protocol::IsHeaderReady(const char* buf, unsigned int sz)
	{
		return sz;
	}
	int Protocol::IsMessageComplete(const char* buf, unsigned int sz)
	{
		//??????
		if (buf[sz - 1] == 0x0A && buf[sz - 2] == 0x0D)
		{
			return sz;
		}
		else
			return 0;
	}
	int Protocol::ProcessMessage(const char* buf, unsigned int sz)
	{
		//??????
		if (buf[sz - 1] == 0x0A && buf[sz - 2] == 0x0D)
		{
			return 0;
		}
		else
			return -1;
	}
	int Protocol::PrepareResponse(const char* buf, unsigned int sz, std::vector<char>& out_buf)
	{
		std::string temp_sz = std::to_string(sz);
		out_buf = {};

		for (int i = 0; i < temp_sz.size(); i++)
		{
			out_buf.push_back(temp_sz[i]);

		}
		out_buf.push_back(0x0D);
		out_buf.push_back(0x0A);


		/*while (temp_sz > 0)
		{
			
			out_buf.push_back(temp_sz % 10);
			temp_sz / 10;
		}*/
		return 1;
	}

}