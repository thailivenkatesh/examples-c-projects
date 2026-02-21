
//1 sec led on off using timer 1  interrupt 
#include <xc.h>
#define _XTAL_FREQ 10000000
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

unsigned int ADC_SAMPLE[20],cnt,cnt1;
 #define lcd PORTD
#define RSE PORTE
#include<math.h>
#define ACV_CALIBCONST    216
unsigned long int y,i,j;
unsigned int zerocross_op,zerocross_ip,sample_cnt,sample_cnt1;
unsigned long int RY_Adc_Cnt_01,RY_Adc_Cnt_02;
signed int AC_Current_Cnt1,Ac_Voltage_cnt1;
unsigned long int Ac_I_Adc_sum_cnt,Ac_I_Adc_Cnt2;
unsigned int previes_sample,present_sample;
unsigned long int AC_V_Adc_Cnt3,AC_Vol_AVG_CNT,AC_V_Adc_Cnt33;
unsigned int avg_count=216,AC_Voltage,Ac_CURRENT;
unsigned long int Ac_I_Adc_Cnt3,Ac_CURR_AVG_CNT;

void __interrupt(high_priority) tcInt(void)
{
        INTCONbits.GIE=0; //Global Interrupt Enable bit

    if(PIR1bits.TMR1IF==1)
    {    
      PIR1bits.TMR1IF=0; //TMR1 Overflow Interrupt Flag bit
      T1CONbits.TMR1ON=0;
      //ADC CALCULATION SINE
        GO_nDONE=1;
        while(GO_nDONE);
        i=ADRESL;
        j=ADRESH;
        j=j<<8;
        i=i+j;
         Ac_Voltage_cnt1=(unsigned long )i;//AC_V   
        
         previes_sample=present_sample;
         present_sample=(unsigned int)Ac_Voltage_cnt1;
         
        if((previes_sample<512)&&(present_sample>=512)) // i/p zerocross detection
                {
                        zerocross_ip=1;    // software interrupt(20ms
                        
                }        
    
                if(zerocross_ip==1)
                {                    
                        RY_Adc_Cnt_01=Ac_Voltage_cnt1;//adc vales like for 2v we have 248
                        RY_Adc_Cnt_02+=(unsigned long int)(RY_Adc_Cnt_01*RY_Adc_Cnt_01); 
                        sample_cnt++;
                }
           if(sample_cnt>=20)
        {
         AC_V_Adc_Cnt3=RY_Adc_Cnt_02;
         AC_V_Adc_Cnt3=(unsigned long int)(AC_V_Adc_Cnt3/sample_cnt);
         AC_V_Adc_Cnt33=AC_V_Adc_Cnt3;
         AC_Vol_AVG_CNT=(unsigned long int)(sqrt((double)AC_V_Adc_Cnt3));
         
         //AC_Voltage=(unsigned int)((AC_Vol_AVG_CNT*26)/ACV_CALIBCONST);
         RY_Adc_Cnt_02=0;
         sample_cnt1=sample_cnt;
        sample_cnt=0;
        
        }
         
      TMR1H=0xF6;
	  TMR1L=0x3B;
      T1CONbits.TMR1ON=1;
      INTCONbits.GIE=1;
    }
 }
 
 void timer_sec()
{ 
    TMR1H=0X00;
	TMR1L=0X00;
    PIR1=0;
    PIE1=0;
    PIE1bits.TMR1IE=1;  //TMR1 Overflow Interrupt Enable bit
    INTCONbits.PEIE=1;  //Peripheral Interrupt Enable bit
    INTCONbits.GIE=1;   //Global Interrupt Enable bit
    T1CON=0;
    T1CONbits.T1CKPS0=0;  //Timer1 Input Clock Prescale Select bits
    T1CONbits.T1CKPS1=0;
    TMR1H=0xF6;//63035
	TMR1L=0x3B;
    T1CONbits.TMR1ON=1;    //Timer1 On bit
    PIR1bits.TMR1IF=0;    //TMR1 Overflow Interrupt Flag bit
  
}  


void write_lampexlcd(unsigned char c)
{
    unsigned char Temp=0;
    Temp=c;
    lcd&=(0X0F);
    lcd|=(Temp&0xF0); //lsb
    __delay_ms(5);
    RSE=0x06;
    __delay_ms(5);
     RSE=0x02;
    lcd&=(0X0F);
    lcd =(c<<4); //msb
    __delay_ms(5);
    RSE=0x06;
    __delay_ms(5);
     RSE=0x02;
    __delay_ms(5);
 return;
}
void cmd_lampexlcd(unsigned char c)
{
    unsigned char Temp=0;
    Temp=c;
    lcd &=(0X0F);
    lcd |=(Temp&0xF0); //lsb
    __delay_ms(5);
    RSE=0x04;
    __delay_ms(5);
    RSE=0x00;
    lcd &=(0X0F);
    lcd =(c<<4); //msb
    __delay_ms(5);
    RSE=0x04;
    __delay_ms(5);
    RSE=0x00;
    __delay_ms(5);
return;
}

void display_lampexlcd(unsigned char *s)
{
char dt;        
       
         for(dt=0;dt<8;dt++)
   {
                         write_lampexlcd(*s++);
                         __delay_ms(10);
   }
} 
void lampexlcd_integer1(unsigned int n)
{   
                unsigned char c[6],i=0;
                if(n==0)
                write_lampexlcd('0');
                while(n>0)
                {
                        c[i++] = ((n%10)+48);
                        n = (n/10);
                }
                while(i-->=1)
                write_lampexlcd(c[i]);
                return;        
}

void lampexlcd_float(unsigned int n)
{
         unsigned long temp1;   
  temp1=n;
  n=(n/10);
  temp1=(temp1%10);
  lampexlcd_integer1(n);
  write_lampexlcd('.');
  lampexlcd_integer1(temp1);
        return;        
}

  void LAMPEXLCD_Init(void)
{
    cmd_lampexlcd(0x38); 
    cmd_lampexlcd(0x02);
    cmd_lampexlcd(0x0c);
    cmd_lampexlcd(0x06);
    cmd_lampexlcd(0x01); 
} 
  

 void main(void)
{
    TRISA = 0x00; 
    TRISB = 0x00; 
    TRISC= 0x00; 
    INTCON=0X90;
    PORTC=0X00;
    timer_sec();
    TRISD = 0x00;
    TRISEbits.TRISE0= 0;
    TRISEbits.TRISE1= 0;
    TRISEbits.TRISE2= 0;
    TRISA=0X04;
    ADCON0=0X91;
    ADCON1=0X82;
 
    __delay_ms(10);
    LAMPEXLCD_Init();
    while(1)
    {
        cmd_lampexlcd(0x01);
        cmd_lampexlcd(0x80);
        display_lampexlcd("EMBEDDED");
        __delay_ms(1000);
        cmd_lampexlcd(0x01);
        cmd_lampexlcd(0x80);
      
        lampexlcd_integer1(AC_Vol_AVG_CNT);
        
        cmd_lampexlcd(0x88);
      
        lampexlcd_integer1(sample_cnt1);
        __delay_ms(1000);

    }
 }
