void CAN_SendData2GUI(uint8_t u8Daughter)
{

	uint16_t u16bagID = 0;
	uint16_t FCData[4];
	uint8_t flexcan_senddata[8];


	//StackVoltage & CellVoltage & Temperature
	for(u16bagID = 0; u16bagID < 25; u16bagID+=4)
	{
		FCData[0] = BatPack.u16RawCell[u8Daughter][u16bagID+0];
		FCData[1] = BatPack.u16RawCell[u8Daughter][u16bagID+1];
		FCData[2] = BatPack.u16RawCell[u8Daughter][u16bagID+2];
		FCData[3] = BatPack.u16RawCell[u8Daughter][u16bagID+3];

		flexcan_senddata[0] = (FCData[0]>>8)&0xFF;
		flexcan_senddata[1] = (FCData[0]>>0)&0xFF;
		flexcan_senddata[2] = (FCData[1]>>8)&0xFF;
		flexcan_senddata[3] = (FCData[1]>>0)&0xFF;
		flexcan_senddata[4] = (FCData[2]>>8)&0xFF;
		flexcan_senddata[5] = (FCData[2]>>0)&0xFF;
		flexcan_senddata[6] = (FCData[3]>>8)&0xFF;
		flexcan_senddata[7] = (FCData[3]>>0)&0xFF;

		SendCANData(0x18810000 +(u8Daughter+0)*0x100 +u16bagID , flexcan_senddata);
		Delayus(500);
		if(u8Daughter<16)
		{
			SendCANData(0x18801000 +(u8Daughter+0)*0x100 +u16bagID , flexcan_senddata);
			Delayus(500);
		}

	}
	//Current
	FCData[0] = (BatPack.i32RawCurrent[u8Daughter] >> 16)& 0xFFFF;
	FCData[1] = BatPack.i32RawCurrent[u8Daughter] & 0xFFFF;

	flexcan_senddata[0] = (FCData[0]>>8)&0xFF;
	flexcan_senddata[1] = (FCData[0]>>0)&0xFF;
	flexcan_senddata[2] = (FCData[1]>>8)&0xFF;
	flexcan_senddata[3] = (FCData[1]>>0)&0xFF;
	flexcan_senddata[4] = (FCData[2]>>8)&0xFF;
	flexcan_senddata[5] = (FCData[2]>>0)&0xFF;
	flexcan_senddata[6] = (FCData[3]>>8)&0xFF;
	flexcan_senddata[7] = (FCData[3]>>0)&0xFF;

	SendCANData(0x18820000 + (u8Daughter+0)*0x100, flexcan_senddata);
	Delayus(500);
	if(u8Daughter<16)
	{
		SendCANData(0x18802000 + (u8Daughter+0)*0x100, flexcan_senddata);
		Delayus(500);
	}

}