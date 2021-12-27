/*DISPLAY LIBRARY FOR A 16X4 LCD DISPLAY*/

//#include <xc.h>
//#include <string.h>
#include <math.h> 
//#define _XTAL_FREQ 20000000      // Tell the compiler that we are useing 16MHz

#define   l   PORTD & 0xf0; // used to retain the upper bit of portD.
#define FIRSTROW 8   // first row starts with 08H.
#define SECONDROW 12 // second row starts with 0CH.
#define THIRDROW 9  // third row starts with 09H.
#define FOURTHROW 13  // forth row starts with 0DH.

char logo[] = "ELECTRONICS";

long NUM;

/*
void ALA ()
     {
        PORTE = 2;
        PORTD= 4;
        CLOCK();
        PORTD= 1;
        CLOCK();
    }
*/

void delay1()
{
    __delay_ms(2);
    
    return ;
}

void delay2()
{
    __delay_ms(2);
    
    return ;
}

void CLOCK()
{
    PORTDbits.RD5 =1;     //ENABLE ON  
    delay2();
    PORTDbits.RD5 =0;       //ENABLE OFF
    delay2();
    
    return ;
}

void LCDWRITE( const char* P) ////subroutine to read a string from the program
{  
    unsigned char i ,j,k;
    for(i=0; P[i]!='\0'; i++)
    {
        k = (0x0f  &  (P[i] >> 4)) ;
        j = ( 0x0f &   P[i] );
        PORTDbits.RD4 =1;  //R/S = 1
        
        PORTD =  k | l ;
        CLOCK();
        PORTD =  j | l ;
        CLOCK();
    }
    return ;
}

void addition(long i)
{
    long k , m , n ,o ;
    int j= 1 ;
    o = i ;
    
   
    
    while(o >= 1 )
    {
        j++;
        o = o/10;
    }
    j--;
    
    for (j-- ; j>=0 ; j-- )
    {
        m =  pow (10 , j);
        k = i / m;
        n = k % 10;
                
        PORTDbits.RD4 =1;  //R/S = 1
        PORTD= 3|l;
        CLOCK();
        PORTD = n|l ;
        CLOCK();
    }
    return;
}


void NUMDISP (long  i)    /////to display more than one digit number.
{
    long k , m , n ,o ;
    int j= 1 ;
    o = i ;
    
     if(o == 0)
       {
        PORTDbits.RD4 =1;    /////R/S = 1
        PORTD= 3|l;
        CLOCK();
        PORTD = 0|l ;
        CLOCK();
        return;
       }          
    
    while(o >= 1)
    {
        j++;
        o = o/10;
    }
    j--;
    
    for (j-- ; j>=0 ; j-- )
    {
        m =  pow (10 , j);
        k = i / m;
        n = k % 10;
                
        PORTDbits.RD4 =1;  //R/S = 1
        PORTD= 3|l;
        CLOCK();
        PORTD = n|l ;
        CLOCK();
    }
    return;
}

void NUMDISP2 (char  i)   ///// to display numbers single numbers of alphabets.
{
    char k , m , n ,o ;
    int j= 1 ;
    o = i ;
   if(i> 50)                   
   {
       n = i - 64;
        PORTDbits.RD4 =1;    /////R/S = 1
        PORTD= 4|l;
        CLOCK();
        PORTD = n|l ;
        CLOCK();
    }                                           /////to single display alphabets.        
    
   else
   {
       if(o == 0)
       {
        PORTDbits.RD4 =1;    /////R/S = 1
        PORTD= 3|l;
        CLOCK();
        PORTD = 0|l ;
        CLOCK();
        return;
       }                                  ///////to single display numbers
           
    while(o >= 1 )
    {
        j++;
        o = o/10;
    }
    j--;
    
    for (j-- ; j>=0 ; j-- )
    {
        m =  pow (10 , j);
        k = i / m;
        n = k % 10;
                
        PORTDbits.RD4 =1;  //R/S = 1
        PORTD= 3|l;
        CLOCK();
        PORTD = n|l ;
        CLOCK();
    }
   }
    return;
}
/*
void DISP()
{
        PORTE = 2;
        PORTD= 3;
        CLOCK();
        PORTD = M2;
        CLOCK();
}
 */

void CURSOR(char a, char b )
{
            RD4 = RD5 = 0;  //CLEAR RD4 and RD5
            PORTD= a|l ;
            CLOCK();
            PORTD= b|l ;
            CLOCK();
            
            return ;
}

void CLRDISP()
{
    RD4 = RD5 = 0 ;   // CLEAR DISPISPLAY
    PORTD= 0 | l;  //
    CLOCK();    //
    PORTD= 0x1 | l ;    //
    CLOCK();    //
    delay1();   // 
    
    return;
}

void SETCURSORTYPE()
{
    RD4 = RD5 = 0 ;   // SET THE CURSOR CHARACTERISTICS...
    PORTD= 0 | l;  //
    CLOCK();    //
    PORTD= 0xE | l ;    //
    CLOCK();    //
    delay1();   //
    
    return;
}
void config()
{
    PORTD= 3;
    CLOCK();
    delay1();

    PORTD= 2;
    CLOCK();
    delay1();

    PORTD= 2;
    CLOCK();
    delay1();

    PORTD= 8;
    CLOCK();
    delay1();

    PORTD= 0;
    CLOCK();
    PORTD= 0X0C;
    CLOCK();
    delay1();

    PORTD= 0;
    CLOCK();
    PORTD= 6;
    CLOCK();
    
    return ;
}


