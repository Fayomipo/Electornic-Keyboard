#include<xc.h> 
#define _XTAL_FREQ 4000000
#include<LCDLIBRARY1.h>
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

void lcd(){
       switch(PORTB + (PORTA << 8)){
       case 1:   CURSOR(FIRSTROW,0);
                 LCDWRITE("261.63, C4 ");
                 break;
       case 2:   CURSOR(FIRSTROW,0);
                 LCDWRITE("277.18, C4#");
                 break;
       case 4:   CURSOR(FIRSTROW,0);
                 LCDWRITE("293.66, D4 ");
                 break;
       case 8192:   CURSOR(FIRSTROW,0);
                 LCDWRITE("311.13, D4#");
                 break;
       case 16:  CURSOR(FIRSTROW,0);
                 LCDWRITE("329.63, E4 ");
                 break;
       case 32:  CURSOR(FIRSTROW,0);
                 LCDWRITE("349.23, F4 ");
                 break;
       case 64:  CURSOR(FIRSTROW,0);
                 LCDWRITE("369.99, F4#");
                 break;
       case 128: CURSOR(FIRSTROW,0);
                 LCDWRITE("392.00, G4 ");
                 break;       
       case 256: CURSOR(FIRSTROW,0);
                 LCDWRITE("415.30, A4b");
                 break;       
       case 512: CURSOR(FIRSTROW,0);
                 LCDWRITE("440.00, A4 ");
                 break;
       case 1024:CURSOR(FIRSTROW,0);
                 LCDWRITE("466.16, A4#");
                 break;  
       case 2048:CURSOR(FIRSTROW,0);
                 LCDWRITE("493.88, B4 ");
                 break;
       case 4096:CURSOR(FIRSTROW,0);
                 LCDWRITE("523.25, C5 ");
                 break;
       default : CURSOR(FIRSTROW,0);
                 LCDWRITE("0.0000");
                 break;
    }
}
void main(void)
{   
    ADCON1=0b00000110;
    TRISA=0x3F;
    TRISB=0xFF;
    TRISC=0;
    TRISD=0;
    TRISE = 0;
    PORTA = PORTB = PORTC = PORTD = PORTE = 0;
    //nRBPU = 1;
    T2CON=0x02;
    CCP1CON=0b00001100;
    //PR2=255;
    CCPR1L = 119.45;
    config();
  while(1){
   TMR2 = 0;
//   if(RB0==1)
//    { 
//        PR2=238.89;
//        TMR2ON = 1;
//        while(RB0);
//   }
   
   RC3 = 1;
   switch(PORTB + (PORTA << 8)){
       case 1:  PR2=239;
                TMR2ON = 1;
                 while(RB0)
                 {    
                     lcd();
                     RD7=1;
               }     RD7=0; 
                break;
       case 2:  PR2=225;
                TMR2ON = 1;
                while(RB1) 
                    {    
                     lcd();
                     RD7=1;
               }     RD7=0;
                break;
       case 4:  PR2= 213;
                TMR2ON = 1;
                while(RB2) 
                {    
                     lcd();
                     RD7=1;
               }     RD7=0;
                break;
       case 8192:  PR2=201;
                TMR2ON = 1;
                while(RA5)
                    {    
                     lcd();
                     RD7=1;
               }     RD7=0;
                break;
       case 16:  PR2=190;
                TMR2ON = 1;
                while(RB4) 
                    {    
                     lcd();
                     RD7=1;
               }     RD7=0;
                break;
       case 32:  PR2=179;
                TMR2ON = 1;
                while(RB5)
                    {    
                     lcd();
                     RD7=1;
               }     RD7=0;
                break;
       case 64:  PR2=169;
                TMR2ON = 1;
                while(RB6) {    
                     lcd();
                     RD7=1;
               }     RD7=0;
                break;
       case 128:  PR2=159;
                TMR2ON = 1;
                while(RB7) 
                {    
                     lcd();
                     RD7=1;
               }     RD7=0;
                break;         
       case 256:  PR2=150;
                TMR2ON = 1;
                while(RA0)
                    {    
                     lcd();
                     RD7=1;
               }     RD7=0;
                break;         
       case 512:  PR2=142;
                TMR2ON = 1;
                while(RA1)
                    {    
                     lcd();
                     RD7=1;
               }     RD7=0;
                break;
       case 1024: PR2=134;
                TMR2ON = 1;
                while(RA2)
                    {    
                     lcd();
                     RD7=1;
               }     RD7=0;
                break;         
       case 2048: PR2=127;
                TMR2ON = 1;
                while(RA3) 
                    {    
                     lcd();
                     RD7=1;
               }     RD7=0;
                break;         
       case 4096: PR2=119.45;
                TMR2ON = 1;
                while(RA4)
                    {    
                     lcd();
                     RD7=1;
               }     RD7=0;
                break;
       default: TMR2ON = 0;
                break;
   }
   CLRDISP();
   TMR2ON = 0;
   } 
  return;
}


