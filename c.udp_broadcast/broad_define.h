/*************************************************

����:���Ǻ�

*UDP�Ĺ㲥Э��
*
*֡��ʽ:
*	ԭʼ���ݸ�ʽ: �������� + ���ֽ�CRC16У��
*
*����:
*	��ʽ: 0x0B + TzhMulticastProtocol(Э���ʶ�Ͳ���)
*************************************************/

//�㲥�󶨵Ķ˿�
#define BROADCAST_PORT			5989
#define BROADCAST_PORT_CLIENT	5990

typedef enum _TzhBroadcastProtocol{
	tzhBroadcastServInfo			=1,			//���������IP,�㲥����		:[short Э���ʶ]
	tzhBroadcastServInfo_ret		=2			//���ط�������Ϣ			:[short Э���ʶ][int tcp�����˿�][Bool �Ƿ����Porject][string project_text]
}TzhBroadcastProtocol;
