/*************************************************

作者:韩智鸿

*UDP的广播协议
*
*帧格式:
*	原始数据格式: 发送内容 + 两字节CRC16校验
*
*内容:
*	格式: 0x0B + TzhMulticastProtocol(协议标识和参数)
*************************************************/

//广播绑定的端口
#define BROADCAST_PORT			5989
#define BROADCAST_PORT_CLIENT	5990

typedef enum _TzhBroadcastProtocol{
	tzhBroadcastServInfo			=1,			//请求服务器IP,广播功能		:[short 协议标识]
	tzhBroadcastServInfo_ret		=2			//返回服务器信息			:[short 协议标识][int tcp监听端口][Bool 是否加载Porject][string project_text]
}TzhBroadcastProtocol;
