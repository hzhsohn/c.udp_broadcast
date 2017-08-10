/*

作者:韩智鸿

*/

#ifndef _ZH_CK_BROADCAST_SERVICE_H_

#include "broad_define.h"
#include "packet.h"
#include "udpprocess.h"

#ifdef __cplusplus
extern "C"{
#endif

/*
	组播使用的初始化
	return 
	0=成功
	1=重置端口失败
	2=端口绑定失败
*/
int broadcast_startup(int port);

/*
    循环调用
	返回值
		数据包的大小
*/
int broadcast_thread(unsigned char *dst_buf,int buf_len,struct sockaddr_in *dst_addr);

/*
	回复广播数据的发送,pack为TzhBroadcastProtocol内容
*/
int broadcast_send(struct sockaddr_in addr,TzhPacket *pack);
int broadcast_sendbuf(struct sockaddr_in addr,unsigned char *str,int len);

#ifdef __cplusplus
}
#endif
#define _ZH_CK_BROADCAST_SERVICE_H_
#endif
