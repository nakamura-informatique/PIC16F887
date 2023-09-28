//Uses a microcontroller to control an output pin (D0) based on a signal from a push button connected to an external interrupt pin (EXT)
#include <16F887.h> //preprocessor directive to include the library for the PIC16F887 microcontroller.
#fuses HS, NOPROTECT //preprocessor guide for configuring program-based options. In this case, it sets the clock to High-Speed ??(HS) and does not enable memory protection (NOPROTECT).
#use delay(clock=20000000) 
#byte PORTD=0x08 //name PORTD as a variable to easily access its output pins
#bit D0=0x08.0 //name PORTD as a variable to easily access its output pins
int1 i; //boolean variable give only 0 or 1
#INT_EXT //interrupts external
void Nut_Nhan() 
{ 
   i= ~i;//This function inverts the value of variable i. If i is 0, it becomes 1 and vice versa.
} 

void main() 
{ 
   SET_TRIS_D(0); //portD are output
   enable_interrupts(GLOBAL); //This function enables a global interrupt for the microcontroller
   enable_interrupts(INT_EXT); //This function enables a peripheral interrupt.
   ext_int_edge(H_to_L); //This function configures the falling edge of the peripheral interrupt. When the button is pressed, an interrupt event occurs.
   i= 0; //initial value
   while(TRUE) 
      { 
         D0 = i;  
      } 
}
