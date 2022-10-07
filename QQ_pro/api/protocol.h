#ifndef __PROTOCOL_H
#define __PROTOCOL_H
#include <QObject>
#include "stdint.h"
#define MAX_PROTOCOL_LEN	12

#define SM_CTL_CMD				0X0001   /*控制下位机命令，暂无控制需求*/
#define SM_UPLOAD_CMD			0X0002   /*下位机数据上传命令*/
#define SM_HEAD					0X7EE7
#define SM_END					0X5AA5
#define SM_LEN					0x0014
#define SM_CMDNUM 				0x0001

//命令编号
#define CMD_NULL			  0x0000		//状态查询
#define CMD_ENGPSON			  0x0001
#define CMD_ENGPSOFF		  0x0002
#define CMD_EN5VON			  0x0003
#define CMD_EN5VOFF			  0x0004
#define CMD_ENVER			  0x0005
#define CMD_ENOFF			  0x0006
/*UPS电源模块通信协议*/
typedef struct tagProtocolUPS
{
    uint8_t uiHeadH;/*起始码 高*/
    uint8_t uiHeadL;/*起始码 低*/
    uint8_t uiSlaveAddr;/*从机地址*/
    uint8_t uiModel; /*功能码*/
    uint8_t uiAddr;   /*寄存器地址*/
    uint8_t uiValueH;   /*寄存器值 高*/
    uint8_t uiValueL;   /*寄存器值 低*/
    uint8_t uicheckCRCH;		//CRC16-module检验 高
    uint8_t uicheckCRCL;		//CRC16-module检验 低
}ProtocolUPS;
/*UPS模块返回的实际数据*/
typedef struct tagUpLoadCmdUPS
{
    uint8_t Addr;
    uint16_t Value;
}UpLoadCmdUPS;
typedef struct tagProtocol
{
    uint16_t uiHead;/*0x7ee7*/
    uint16_t uiCmdID;/*命令ID*/
    uint16_t uiPyloadLen;/*装载长度*/
    uint16_t uiCmdNum; /*命令编号*/
    uint8_t  ucPyLoad[MAX_PROTOCOL_LEN];
    uint16_t uicheckCRC;		//CRC16-CCITT检验
    uint16_t uiEnd;/*0x5aa5*/
}Protocol;
/*协议外框架*/

/*PC界面到下位机的命令负载*/
typedef struct tagControlCmd
{
    uint16_t uiControCmd;
    /*控制命令：uiControCmd */
}ControlCmd;

/*下位机到上位机的命令装载,
主要上报当前状态和按键*/
typedef struct tagUpLoadCmd
{
    uint16_t uiModel;		/*当前模式：按键1,编码器2,空闲0 三种状态*/
    uint16_t uiValue;   /*按键值，编码器值*/
    uint16_t uiADC1;
    uint16_t uiADC2;
    uint16_t uiENGPS;
}UpLoadCmd;

/*版本信息*/
typedef struct tagInfoCmdLoadCmd
{
    char uiDeviceCode[6];		/*设备编号：*/
    char uiDeviceVersion[3];	/*设备版本：*/
}InfoLoadCmd;
/*该命令未下位机周期发送大约1秒中一次。*/



class ProtocolCMD : public QObject
{
    Q_OBJECT
public:
    explicit ProtocolCMD(QObject *parent = 0);

private:
    uint8_t getCheckSum(uint8_t *p1, short size);
    uint16_t getRevCrc_16(uint8_t *data, int len, uint16_t init, const uint16_t *table);
    uint16_t getCrc_16(uint8_t *data, int len, uint16_t init, const uint16_t *table);
    uint16_t getModbus16CRC(uint8_t *data, int len);
    uint8_t* sendProtocol(uint16_t *Str,uint8_t lenth);
    void ShortTobyteRec(uint16_t *Str16, uint8_t *Str8, uint8_t lenth);
public slots:
    //状态信息装载
    void sendSerialUp(UpLoadCmd  LoadCmd);
    //版本信息装载
    void sendSerialInfo(InfoLoadCmd  LoadCmd);
    //控制命令装载
    void sendSerialControlCmd(ControlCmd  LoadCmd);
    //UPS协议装载
    void sendSerialUPS(uint8_t LoadCmd);
    //协议装载内容解析
    void unLoadCmd(uint8_t *LoadCmd, tagUpLoadCmd &UpLoadCmd);
    //版本信息解析
    void unLoadCmdVer(uint8_t *LoadCmd);
    //MCU协议外框架解析
    void unLoadProtocolCmd(uint8_t *ProtocolCmd, uint8_t lenth, tagUpLoadCmd &UpLoadCmd);
    //UPS协议外框架解析
    void unLoadProtocolCmdUPS(uint8_t *ProtocolCmd, uint8_t lenth,UpLoadCmdUPS &LoadCmdUPS);
    void sendLoadVersion();
    void sendLoadNULL();


signals:
    void sendProtocolCMD(uint8_t *,uint8_t);
    void sendProtocolUPSCMD(uint8_t *,uint8_t);
    void sendProtocolMCUCMD(uint8_t *,uint8_t);

};

#endif
