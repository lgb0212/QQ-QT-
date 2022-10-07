#include "protocol.h"
#include "quiwidget.h"
ProtocolCMD::ProtocolCMD(QObject *parent) : QObject(parent)
{

}

const char DeviceCode[6]={'2','0','0','9','0','9'};
const char DeviceVersion[3] = {'1','1','1'};

//uint16_t DeviceVersion = 100;	/*设备版本：1.00*/
uint16_t table_16[] = {
                0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
        0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
        0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81, 0x0E40,
        0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
        0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40,
        0x1E00, 0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41,
        0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641,
        0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
        0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240,
        0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0, 0x3480, 0xF441,
        0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41,
        0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840,
        0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41,
        0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40,
        0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
        0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041,
        0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240,
        0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480, 0xA441,
        0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41,
        0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840,
        0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41,
        0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
        0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640,
        0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041,
        0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241,
        0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440,
        0x9C01, 0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40,
        0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841,
        0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
        0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41,
        0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641,
        0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040};


//和校验
uint8_t ProtocolCMD::getCheckSum(uint8_t *p1, short size)
{
    uint8_t CheckSum =0;
    while(size>0)
    {
        CheckSum += *p1;
        p1++;
        size--;
    }
    return CheckSum;
}
//函数功能：计算CRC16
//参数1：*data 16位CRC校验数据，
//参数2：len   数据流长度
//参数3：init  初始化值
//参数4：table 16位CRC查找表

//逆序CRC计算
uint16_t ProtocolCMD::getRevCrc_16(uint8_t *data, int len, uint16_t init, const uint16_t *table)
{
    uint16_t cRc_16 = init;
    uint8_t temp;

    while(len-- > 0) {
        temp = cRc_16 >> 8;
        cRc_16 = (cRc_16 << 8) ^ table[(temp ^ *data++) & 0xff];
    }

    return cRc_16;
}
//正序CRC计算
uint16_t ProtocolCMD::getCrc_16(uint8_t *data, int len, uint16_t init, const uint16_t *table)
{
    uint16_t cRc_16 = init;
    uint8_t temp;

    while(len-- > 0) {
        temp = cRc_16 & 0xff;
        cRc_16 = (cRc_16 >> 8) ^ table[(temp ^ *data++) & 0xff];
    }

    return cRc_16;
}
//Modbus CRC16-MODBUS校验  X16+X12+X5+1
uint16_t ProtocolCMD::getModbus16CRC(uint8_t *data, int len)
{
     return getCrc_16(data, len, 0xFFFF, table_16);
	
	
}

//int getCRC(const unsigned char *pcRec,unsigned int iLen,unsigned char *pcCRC)
//{
//	unsigned int IX,IY,iCRC;
//	iCRC=0xFFFF;//set all 1
//	if (iLen<=0){
//		pcCRC[0] =0;//¸ßÎ»Ö Ã
//		pcCRC[1] =0; //µÍÎ»Ö Ã
//		return -1;
//	}
//	else{
//			iLen--;
//			for (IX=0;IX<=iLen;IX++){
//				iCRC=iCRC^(unsigned int)(pcRec[IX]);
//				for(IY=0;IY<=7;IY++){
//					if ((iCRC&1)!=0 )
//					iCRC=(iCRC>>1)^0xA001;
//					else
//					iCRC=iCRC>>1; //
//			}
//		}
//	}
//	pcCRC[0] = (unsigned char)((iCRC & 0xff00)>>8);//¸ßÎ»Ö Ã
//	pcCRC[1] = (unsigned char)(iCRC & 0x00ff); //µÍÎ»Ö Ã
//	return 0;
//}
uint8_t* ProtocolCMD::sendProtocol(uint16_t *Str,uint8_t lenth)
{
    uint8_t Add[2];
    uint8_t *bufdata;
    int i=0;
    while(lenth)
    {
        Add[0] = *Str >> 0x08;    //取地址高8位
        Add[1] = *Str & (uint16_t)0x01FF;	//取地址低8位
        //Usart1_Transmit(Add,2);
        Str++;
        lenth--;
    }
    return bufdata;
}
void ProtocolCMD::ShortTobyteRec(uint16_t *Str16, uint8_t *Str8, uint8_t lenth)
{
    uint8_t Add[2];
    int i=0;
    while(lenth)
    {
        Add[0] = *Str16 >> 0x08;    //取地址高8位
        Add[1] = *Str16 & (uint16_t)0x01FF;	//取地址低8位
        Str8[i] = Add[0];
        i++;
        Str8[i] = Add[1];
        i++;
        Str16++;
        lenth--;
    }
}
void ProtocolCMD::sendSerialUp(UpLoadCmd  LoadCmd)
{
    Protocol    protocol;
    memset((uint8_t*)&protocol,0x00,sizeof(protocol));	//清空数据
    protocol.uiHead = SM_HEAD;
    protocol.uiCmdID = SM_UPLOAD_CMD;
    protocol.uiPyloadLen = sizeof(LoadCmd)/sizeof(uint8_t);
    protocol.uiCmdNum = SM_CMDNUM;
    memcpy(protocol.ucPyLoad ,&LoadCmd,sizeof(LoadCmd));
    protocol.uiEnd = SM_END;
    //protocol.uichecksum = getCheckSum((uint8_t *)&protocol ,sizeof(protocol)/sizeof(uint8_t));
    protocol.uicheckCRC = getModbus16CRC((uint8_t *)&protocol ,sizeof(protocol)/sizeof(uint8_t));
    //Usart1_Transmit((uint8_t *)&protocol,sizeof(protocol));	//16位的数据发送码是反的，需要解码的时候进行处理
}
void ProtocolCMD::sendSerialInfo(InfoLoadCmd  LoadCmd)
{
    Protocol    protocol;
    memset((uint8_t*)&protocol,0x00,sizeof(protocol));	//清空数据
    protocol.uiHead = SM_HEAD;
    protocol.uiCmdID = SM_UPLOAD_CMD;
    protocol.uiPyloadLen = sizeof(LoadCmd)/sizeof(uint8_t);
    protocol.uiCmdNum = CMD_ENVER;
    memcpy(protocol.ucPyLoad ,&LoadCmd,sizeof(LoadCmd));
    protocol.uiEnd = SM_END;
    //protocol.uichecksum = getCheckSum((uint8_t *)&protocol ,sizeof(protocol)/sizeof(uint8_t));
    protocol.uicheckCRC = getModbus16CRC((uint8_t *)&protocol ,sizeof(protocol)/sizeof(uint8_t));
    //Usart1_Transmit((uint8_t *)&protocol,sizeof(protocol));	//16位的数据发送码是反的，需要解码的时候进行处理
}
void ProtocolCMD::sendSerialControlCmd(ControlCmd  LoadCmd)
{
    Protocol    protocol;
    memset((uint8_t*)&protocol,0x00,sizeof(protocol));	//清空数据
    protocol.uiHead = SM_HEAD;
    protocol.uiCmdID = SM_CTL_CMD;
    protocol.uiPyloadLen = sizeof(LoadCmd)/sizeof(uint8_t);
    protocol.uiCmdNum = SM_CMDNUM;
    memcpy(protocol.ucPyLoad ,&LoadCmd,sizeof(LoadCmd));
    protocol.uiEnd = SM_END;
    //protocol.uichecksum = getCheckSum((uint8_t *)&protocol ,sizeof(protocol)/sizeof(uint8_t));
    protocol.uicheckCRC = getModbus16CRC((uint8_t *)&protocol ,sizeof(protocol)/sizeof(uint8_t));
    //Usart1_Transmit((uint8_t *)&protocol,sizeof(protocol));	//16位的数据发送码是反的，需要解码的时候进行处理
    emit sendProtocolCMD((uint8_t *)&protocol,sizeof(protocol));
}
//UPS协议装载
void ProtocolCMD::sendSerialUPS(uint8_t  LoadCmd)
{
    //ab cd 0 3 0 0 0 93 11
    ProtocolUPS    protocol;
    uint16_t uicheckCRC;
    memset((uint8_t*)&protocol,0x00,sizeof(protocol));	//清空数据
    protocol.uiHeadH = 0xAB;
    protocol.uiHeadL = 0xCD;
    protocol.uiSlaveAddr = 0x00;
    protocol.uiModel = 0x03;
    protocol.uiAddr = LoadCmd;  //寄存器地址
    protocol.uiValueH = 0x00;
    protocol.uiValueL = 0x00;
    uicheckCRC = getModbus16CRC((uint8_t *)&protocol ,(sizeof(protocol)/sizeof(uint8_t)) -2);
    protocol.uicheckCRCH = uicheckCRC  >>  0x08;
    protocol.uicheckCRCL = uicheckCRC & (uint16_t)0x01FF;

    emit sendProtocolUPSCMD((uint8_t *)&protocol,sizeof(protocol));

}

//协议外框架解析
void ProtocolCMD::unLoadProtocolCmdUPS(uint8_t *ProtocolCmd, uint8_t lenth, UpLoadCmdUPS &LoadCmdUPS)
{
    ProtocolUPS    protocol;
    uint16_t uicheckCRC;
    uint16_t buffcheckCRC;
    if(lenth != sizeof(protocol))
        return;
    buffcheckCRC = ((uint16_t)ProtocolCmd[lenth-1] << 8) | (uint16_t)ProtocolCmd[lenth-2];
    uicheckCRC = getModbus16CRC(ProtocolCmd,sizeof(protocol)-2);
    if(uicheckCRC != buffcheckCRC)	//校验出错返回
        return;
    LoadCmdUPS.Addr = ProtocolCmd[4];
    protocol.uiValueH = ProtocolCmd[5];
    protocol.uiValueL = ProtocolCmd[6];
    LoadCmdUPS.Value = ((uint16_t)ProtocolCmd[5] << 8) | (uint16_t)ProtocolCmd[6];


}
//协议外框架解析
void ProtocolCMD::unLoadProtocolCmd(uint8_t *ProtocolCmd,uint8_t lenth,tagUpLoadCmd &UpLoadCmd)
{
    Protocol    protocol;
    uint16_t    buffcheckCRC;
    uint8_t bufCmd[sizeof(protocol)];
    if(lenth != sizeof(protocol))
        return;

    buffcheckCRC = ((uint16_t)ProtocolCmd[lenth-3] << 8) | (uint16_t)ProtocolCmd[lenth-4];

    memcpy(bufCmd,ProtocolCmd,lenth);
    ProtocolCmd[lenth-3] = 0x00;		//还原发送的校验初始值
    ProtocolCmd[lenth-4] = 0x00;
    protocol.uicheckCRC = getModbus16CRC(ProtocolCmd,sizeof(protocol));

    if(protocol.uicheckCRC != buffcheckCRC)	//校验出错返回
        return;

    ShortTobyteRec((uint16_t *)bufCmd,bufCmd,sizeof(protocol)/sizeof(uint16_t));
    //Usart1_Transmit(bufCmd,lenth);	//16位的数据发送码是反的，需要解码的时候进行处理

    protocol.uiHead = ((uint16_t)bufCmd[0] << 8) | (uint16_t)bufCmd[1];
    protocol.uiCmdID = ((uint16_t)bufCmd[2] << 8) | (uint16_t)bufCmd[3];
    protocol.uiPyloadLen = ((uint16_t)bufCmd[4] << 8) | (uint16_t)bufCmd[5];
    protocol.uiCmdNum = ((uint16_t)bufCmd[6] << 8) | (uint16_t)bufCmd[7];
    protocol.uiEnd = ((uint16_t)bufCmd[lenth-2] << 8) | (uint16_t)bufCmd[lenth-1];

    if(protocol.uiCmdID != SM_UPLOAD_CMD)	//下位机到PC控制命令
        return;

//	Usart1_Transmit(bufCmd,lenth);	//16位的数据发送码是反的，需要解码的时候进行处理
    int loadLenstart = 8;		//装载内容起始地址
    for(int i = 0 ; i < protocol.uiPyloadLen ; i++)
    {
        protocol.ucPyLoad[i] = bufCmd[loadLenstart];
        loadLenstart++;
    }
    //Usart1_Transmit(protocol.ucPyLoad,protocol.uiPyloadLen);	//16位的数据发送码是反的，需要解码的时候进行处理
    if(protocol.uiCmdNum == SM_CMDNUM)	//命令编号：0x0001		地址1的控制命令
        unLoadCmd(protocol.ucPyLoad,UpLoadCmd);
    if(protocol.uiCmdNum == CMD_ENVER)
     {
        //此数据类型是8位的， 需要将数据在反转一下
        ShortTobyteRec((uint16_t *)protocol.ucPyLoad,protocol.ucPyLoad,sizeof(protocol.ucPyLoad)/sizeof(uint16_t));
        unLoadCmdVer(protocol.ucPyLoad);
     }



}
//协议命令解析
void ProtocolCMD::unLoadCmd(uint8_t *LoadCmd,tagUpLoadCmd &UpLoadCmd)
{
   // tagUpLoadCmd UpLoadCmd;
    UpLoadCmd.uiModel = ((uint16_t)LoadCmd[0] << 8) | (uint16_t)LoadCmd[1];
    UpLoadCmd.uiValue = ((uint16_t)LoadCmd[2] << 8) | (uint16_t)LoadCmd[3];
    UpLoadCmd.uiADC1 = ((uint16_t)LoadCmd[4] << 8) | (uint16_t)LoadCmd[5];
    UpLoadCmd.uiADC2 = ((uint16_t)LoadCmd[6] << 8) | (uint16_t)LoadCmd[7];
    UpLoadCmd.uiENGPS = ((uint16_t)LoadCmd[8] << 8) | (uint16_t)LoadCmd[9];

}
//协议命令解析
void ProtocolCMD::unLoadCmdVer(uint8_t *LoadCmd)
{
    //ControlCmd controlCmd;
   // controlCmd.uiControCmd = ((uint16_t)LoadCmd[0] << 8) | (uint16_t)LoadCmd[1];

    QString DeviceCodestr;
    QString DeviceVersionstr;
    for(int i =0 ; i <6 ; i++)
    DeviceCodestr+= QString().sprintf("%d", LoadCmd[i] - '0');
    for(int i = 6 ; i<9 ; i++)
    DeviceVersionstr+= QString().sprintf("%d", LoadCmd[i] - '0');
    qDebug()<<DeviceCodestr;
    App::MCUDeviceCode = DeviceCodestr;
    App::MCUDeviceVersion = DeviceVersionstr;

}
void ProtocolCMD::sendLoadVersion()
{
    InfoLoadCmd LoadCmd;
    memcpy(LoadCmd.uiDeviceCode,&DeviceCode,sizeof(DeviceCode));
    memcpy(LoadCmd.uiDeviceVersion,&DeviceVersion,sizeof(DeviceVersion));
    sendSerialInfo(LoadCmd);
}
void ProtocolCMD::sendLoadNULL()
{
    UpLoadCmd LoadCmd;
    LoadCmd.uiModel = 0x0000;
    LoadCmd.uiValue = 0x0000;
    LoadCmd.uiADC1 = 0x0000;
    LoadCmd.uiADC2 = 0x0000;
  //  LoadCmd.uiENGPS = AppDC5VEnable;
    sendSerialUp(LoadCmd);
}
