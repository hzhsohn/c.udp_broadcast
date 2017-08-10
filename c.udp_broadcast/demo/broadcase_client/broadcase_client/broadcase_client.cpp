// broadcase_client.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "broadcast.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int broad_len;
	struct sockaddr_in addr;
	unsigned char broad_buf[2048];

	//----
	time_t dwTmp=NULL;

	//----------------------------------------------------
	//��ʼ���㲥����
	switch(broadcast_startup(BROADCAST_PORT_CLIENT))
	{
	case 0:
		printf("broadcast service startup successful. port=%d\r\n",BROADCAST_PORT_CLIENT);
		break;
	case 1:
		printf("broadcast service reuse addr fail. port=%d\r\n",BROADCAST_PORT_CLIENT);
		break;
	case 2:
		printf("broadcast bind port fail port=%d\r\n",BROADCAST_PORT_CLIENT);
		break;
	}


	while(1)
	{
		//�㲥�����ݰ�
		broad_len=broadcast_thread(broad_buf,sizeof(broad_buf),&addr);
		if (broad_len>0)
		{
			TzhPacket pack;
			short rCmd;

			zhPackReadInit(&pack,broad_buf,broad_len);
			zhPackReadShort(&pack,&rCmd);
			switch(rCmd)
			{
			case tzhBroadcastServInfo_ret:
				{
						printf("get info ok.\r\n");
				}
				break;
			}
		}

		//2��һ��
		if(zhPlatGetTime()-dwTmp>2000)
		{
			TzhPacket pack;
			dwTmp=zhPlatGetTime();

			printf("send.\r\n");
			zhPackWriteInit(&pack);
			zhPackWriteShort(&pack,tzhBroadcastServInfo);
			zhSockPramToAddr("200.200.3.1",BROADCAST_PORT,&addr);
			broadcast_send(addr,&pack);
		}
	}

	return 0;
}

