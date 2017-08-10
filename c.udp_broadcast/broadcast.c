/*

作者:韩智鸿

*/

#include "broadcast.h"


//广播的SOCKET
SOCKET g_broadcast_socket=NULL;

/*
	组播使用的初始化
*/
int broadcast_startup(int port)
{
	zhSockInit(&g_broadcast_socket,ZH_SOCK_UDP);
	if(zhSockSetReuseAddr(g_broadcast_socket,true))
	{ 
		if(zhSockBindAddr(g_broadcast_socket,NULL,port))
		{			
			//缓冲区默认8K 
			//zhSockSetSendBufferSize(g_broadcast_socket,32*1024);
			//zhSockSetRecvBufferSize(g_broadcast_socket,32*1024);
		}
		else
		{			
			return 2;
		}
	}
	else
	{
		return 1;
	}

	return 0;
}

/*
   循环调用
*/
int broadcast_thread(unsigned char *dst_buf,int buf_len,struct sockaddr_in *dst_addr)
{
	int addr_len;
	
	//接收
	addr_len=sizeof(struct sockaddr_in);
	return zhUdpRecvFrom(g_broadcast_socket,dst_buf,buf_len,dst_addr,&addr_len);
}

//接收处理数据包
int broadcast_send(struct sockaddr_in addr,TzhPacket *pack)
{
	return zhUdpSendTo(g_broadcast_socket,pack->btBuf,pack->wSize,&addr);
}


//接收处理数据包
int broadcast_sendbuf(struct sockaddr_in addr,unsigned char *str,int len)
{
	return zhUdpSendTo(g_broadcast_socket,str,len,&addr);
}
