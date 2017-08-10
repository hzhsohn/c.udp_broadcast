/*

����:���Ǻ�

*/

#ifndef _ZH_CK_BROADCAST_SERVICE_H_

#include "broad_define.h"
#include "packet.h"
#include "udpprocess.h"

#ifdef __cplusplus
extern "C"{
#endif

/*
	�鲥ʹ�õĳ�ʼ��
	return 
	0=�ɹ�
	1=���ö˿�ʧ��
	2=�˿ڰ�ʧ��
*/
int broadcast_startup(int port);

/*
    ѭ������
	����ֵ
		���ݰ��Ĵ�С
*/
int broadcast_thread(unsigned char *dst_buf,int buf_len,struct sockaddr_in *dst_addr);

/*
	�ظ��㲥���ݵķ���,packΪTzhBroadcastProtocol����
*/
int broadcast_send(struct sockaddr_in addr,TzhPacket *pack);
int broadcast_sendbuf(struct sockaddr_in addr,unsigned char *str,int len);

#ifdef __cplusplus
}
#endif
#define _ZH_CK_BROADCAST_SERVICE_H_
#endif
