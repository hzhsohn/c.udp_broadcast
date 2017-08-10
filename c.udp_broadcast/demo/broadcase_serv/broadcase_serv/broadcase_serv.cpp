// broadcase_serv.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "broadcast.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int broad_len;
	struct sockaddr_in addr;
	unsigned char broad_buf[2048];

	//----------------------------------------------------
	//��ʼ���㲥����
	switch(broadcast_startup(BROADCAST_PORT))
	{
	case 0:
		printf("broadcast service startup successful. port=%d\r\n",BROADCAST_PORT);
		break;
	case 1:
		printf("broadcast service reuse addr fail. port=%d\r\n",BROADCAST_PORT);
		break;
	case 2:
		printf("broadcast bind port fail port=%d\r\n",BROADCAST_PORT);
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
			case tzhBroadcastServInfo:
				{
					zhPackWriteInit(&pack);
					zhPackWriteShort(&pack,tzhBroadcastServInfo_ret);
					broadcast_send(addr,&pack);
					printf("get server info\r\n");
				}
				break;
			}
		}	
	}
	return 0;
}

