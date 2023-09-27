#include <16f877.h>
#use delay (clock=20000000)
#include <stdlib.h>
#include <string.h>
void main ()
{
   output_high (PIN_B1);
   delay_ms (2000);
   output_low (PIN_B1);
   delay_ms (2000);
   output_bit (PIN_B1,1);
}
