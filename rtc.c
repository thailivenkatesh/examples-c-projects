/*
 * rtc.c
 *
 *  Created on: Aug 10, 2021
 *      Author: Vishnu M
 */


//#include "i2c.h"
#include "rtc.h"

 //struct write_buffer write_dt_time;

uint8_t seconds, minutes,hours,date,month,year,oscillator,hour;
uint8_t mon;

//    For Reading
struct read_buffer{
		//uint8_t hundredth_sec;
	    uint8_t hours;
		uint8_t minutes;
		uint8_t seconds;
		//uint8_t time_format;
		uint8_t date;
		uint8_t month;
		uint8_t year;
		uint8_t weekday;
};

 struct read_buffer read_dt_time;

 struct bin_bcd_buffer{
		//uint8_t hundredth_sec;
	    uint8_t hours;
	    uint8_t minutes;
		uint8_t seconds;
		//uint8_t time_format;
		uint8_t date;
		uint8_t month;
		uint8_t year;
		uint8_t weekday;

};
struct bin_bcd_buffer bin_bcd;


 void RTC_WRITE(int format_12_24,int am_pm, write_buffer write_dt_time)
{
	LPI2C0_write(PCF85263_WRITE,PCF85263_REG_FUNCTION,0X00);        // RTCM =0//   RTC Mode.
	LPI2C0_write(PCF85263_WRITE, PCF85263_REG_STOPENABLE, 0X01);   // To set STOP Bit.
	LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RESET,0xA4);    	   // clear prescaler

	if(format_12_24 == 24)
	{  // 24 hrs format
		LPI2C0_write(PCF85263_WRITE,PCF85263_REG_OSC,0x00);
	}
	else
	{                   // 12 hrs format
		LPI2C0_write(PCF85263_WRITE,PCF85263_REG_OSC,0x20);  // oscillator register 12_24 h mode is set
	}


	if(write_dt_time.seconds > 9)
	{
		seconds=binary_to_bcd(write_dt_time.seconds);
		LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_SC,seconds);
	}
	else
	{
		LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_SC,write_dt_time.seconds);
	}


	if(write_dt_time.minutes > 9)
	{
		minutes=binary_to_bcd(write_dt_time.minutes);
		LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_MN,minutes);
	}
	else
	{
		LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_MN,write_dt_time.minutes);
	}


	if(format_12_24 == 12)  // 12 Hours Format
	{

        if(am_pm == 1)     // In PM Mode
         {
			if(write_dt_time.hours > 9)
			{

			hours=binary_to_bcd(write_dt_time.hours);
			LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_HR,hours+32);
			}
			else
			{
			LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_HR,write_dt_time.hours+32);
			}
         }
        else            // In AM Mode
         {
			if(write_dt_time.hours > 9)
			{
				hours=binary_to_bcd(write_dt_time.hours);
				LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_HR,hours);
			}
			else
			{
				LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_HR,write_dt_time.hours);
			}
         }
	  }
	else      // 24 Hours Format
	{
		if(write_dt_time.hours > 9)
		{
			hours=binary_to_bcd(write_dt_time.hours);
			LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_HR,hours);

		}
		else
		{
			LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_HR,write_dt_time.hours);
		}
	 }


	if(write_dt_time.date > 9)
	{
		date=binary_to_bcd(write_dt_time.date);
		LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_DT,date);
    }
	else
	{
    	LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_DT,write_dt_time.date);
    }


	if(write_dt_time.month > 9)
	{
		month=binary_to_bcd(write_dt_time.month);
		LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_MO,month);
	}
	else
	{
		LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_MO,write_dt_time.month);
	}


	if(write_dt_time.year > 9)
	{
		year=binary_to_bcd(write_dt_time.year);
		LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_YR,year);
	}
	else
	{
		LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_YR,write_dt_time.year);
	}


	LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_DW,write_dt_time.weekday);


	LPI2C0_write(PCF85263_WRITE, PCF85263_REG_STOPENABLE, 0X00);              // To clear STOP Bit.

}



  void RTC_READ(int format_12_24,int am_pm)
{


	LPI2C0_read(PCF85263_READ,PCF85263_REG_RTC_SC,&read_dt_time.seconds,1);
	read_dt_time.seconds &= ~(1<<7);    //clear the 7th bit
	bin_bcd.seconds= bcd_to_binary(read_dt_time.seconds);

	LPI2C0_read(PCF85263_READ,PCF85263_REG_RTC_MN,&read_dt_time.minutes,1);
	read_dt_time.minutes &= ~(1<<7);    //clear  the 7th bit
	bin_bcd.minutes= bcd_to_binary(read_dt_time.minutes);


	LPI2C0_read(PCF85263_READ,PCF85263_REG_RTC_HR,&read_dt_time.hours,1);
	LPI2C0_read(PCF85263_READ,PCF85263_REG_OSC,&oscillator,1);    //oscillator register
	if (oscillator != 0)
	{  //12 hours  format

		bin_bcd.hours = pcf85263_bcd12h_to_bin24h(read_dt_time.hours);
		LPI2C0_read(PCF85263_READ,PCF85263_REG_RTC_HR,&hour,1);



	}
	else
	{   // 24 hrs format
		bin_bcd.hours = bcd_to_binary(read_dt_time.hours & 0x3f);
	}


	LPI2C0_read(PCF85263_READ,PCF85263_REG_RTC_DT,&read_dt_time.date,1);
	bin_bcd.date=bcd_to_binary(read_dt_time.date);


	LPI2C0_read(PCF85263_READ,PCF85263_REG_RTC_MO,&read_dt_time.month,1);
	bin_bcd.month=bcd_to_binary(read_dt_time.month);


	LPI2C0_read(PCF85263_READ,PCF85263_REG_RTC_YR,&read_dt_time.year,1);
	bin_bcd.year=bcd_to_binary(read_dt_time.year);


	LPI2C0_read(PCF85263_READ,PCF85263_REG_RTC_DW,&read_dt_time.weekday,1);

	void _month(uint8_t _mon){
		switch(_mon)
		{
			case 1:
			PRINTF("Jan");
			break;
			case 2:
			PRINTF("Feb");
			break;
			case 3:
			PRINTF("Mar");
			break;
			case 4:
			PRINTF("Apr");
			break;
			case 5:
			PRINTF("May");
			break;
			case 6:
			PRINTF("Jun");
			break;
			case 7:
			PRINTF("Jul");
			break;
			case 8:
			PRINTF("Aug");
			break;
			case 9:
			PRINTF("Sep");
			break;
			case 10:
			PRINTF("Oct");
			break;
			case 11:
			PRINTF("Nov");
			break;
			case 12:
			PRINTF("Dec");
			break;
		}
	}


	if(format_12_24 == 12)  // 12 Hours Format
	{

		int ampm = (hour & (1<<5)) ? 1 : 0;     //  Check In  hours register AM_PM Bit whether it is 0 AM Mode , 1 PM Mode.
		if(ampm == 1)     // In PM Mode
		{
			char pm[] ="PM";

			PRINTF("Time = %d",bin_bcd.hours);PRINTF(":");
			PRINTF("%02i",bin_bcd.minutes);PRINTF(":");
			PRINTF("%02i",bin_bcd.seconds);PRINTF(" ");PRINTF("%s\r\n",pm);
			PRINTF("Date = %d",bin_bcd.date);PRINTF(":");
			_month(bin_bcd.month);PRINTF(":");
			PRINTF("20%d\r\n",bin_bcd.year);
			//PRINTF("current time  = %d:%d:%d %s \r\n",bin_bcd.hours,bin_bcd.minutes,bin_bcd.seconds,pm);
			///PRINTF("current date  = %d/%d/20%d\r\n",bin_bcd.date,bin_bcd.month,bin_bcd.year);
		}
		else
		{
			char pm[] ="AM";

			PRINTF("Time = %d",bin_bcd.hours);PRINTF(":");
			PRINTF("%02i",bin_bcd.minutes);PRINTF(":");
			PRINTF("%02i",bin_bcd.seconds);PRINTF(" ");PRINTF("%s\r\n",pm);
			PRINTF("Date = %d",bin_bcd.date);PRINTF(":");
			_month(bin_bcd.month);PRINTF(":");
			PRINTF("20%d\r\n",bin_bcd.year);
			//PRINTF("current time  = %d:%d:%d %s\r\n",bin_bcd.hours,bin_bcd.minutes,bin_bcd.seconds,pm);
			//PRINTF("current date  = %d/%d/20%d\r\n",bin_bcd.date,mon,bin_bcd.year);
		}
	}
	else    // 24 Hours Format
	{

		PRINTF("Time = %d",bin_bcd.hours);PRINTF(":");
		PRINTF("%02i",bin_bcd.minutes);PRINTF(":");
		PRINTF("%02i",bin_bcd.seconds);PRINTF(" \r\n");
		PRINTF("Date = %d",bin_bcd.date);PRINTF(":");
		_month(bin_bcd.month);PRINTF(":");
		PRINTF("20%d\r\n",bin_bcd.year);
	//PRINTF("current time  = %d:%d:%d\r\n",bin_bcd.hours,bin_bcd.minutes,bin_bcd.seconds);
	//PRINTF("current date  = %d/%d/20%d\r\n",bin_bcd.date,bin_bcd.month,bin_bcd.year);
	}


	switch(read_dt_time.weekday)
	{
	case 0:PRINTF("Weekday: Sunday\r\n");
			break;
	case 1:PRINTF("Weekday: Monday\r\n");
			break;
	case 2:PRINTF("Weekday: Tuesday\r\n");
			break;
	case 3:PRINTF("Weekday: Wednesday\r\n");
			break;
	case 4:PRINTF("Weekday: Thursday\r\n");
			break;
	case 5:PRINTF("Weekday: Friday\r\n");
			break;
	case 6:PRINTF("Weekday: Saturday\r\n");
			break;
	default:PRINTF("Invalid weekday\r\n");

	}

}



uint8_t bcd_to_binary( uint8_t value)
{
	  uint8_t m,n;
	  m=(uint8_t)((value>>4)* 10);
	  n=value & (uint8_t)0X0F;
	  return m+n;
}


uint8_t binary_to_bcd( uint8_t value)
{
	  uint8_t m,n;
	  uint8_t bcd=0;

	  if(value >=10)
	  {
		  m=value/10;
		  n=value%10;
		  bcd=( uint8_t) ((m<<4) | n) ;
	  }

	  return bcd;
}



 int pcf85263_bcd12h_to_bin24h(int regval)
{
	 int hr = bcd_to_binary(regval);
	 if(hr>20)
	 {
	 hr-=20;
	 }
		//int hr = bcd_to_binary(regval & 0x1f);
		//regval+=PCF85263_HR_PM;
	// hr |=(1<<5);
		bool pm = regval & PCF85263_HR_PM;
		//return hr;
		if (hr == 12)
		{
		  //return pm ? 1 : 12 ;
			return hr;

		}
		else
		{
			if(pm)
			{
				if(hr>12)
				{
					hr-=12;
					return hr;
				}
				else
					return hr;
			}
			else
				 return hr;
			//return pm ?  hr + 12 : hr;

		}

}




