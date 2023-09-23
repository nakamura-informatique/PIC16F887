#include <16f877.h>
#fuses HS,NOWDT,PUT,NOLVP,NOPROTECT,BROWNOUT
#use delay (clock = 20000000)

//!char count_0_to_9 [10] = 
//!{
//!   //cathode (�m chung)
//!   //dp-g-f-e-d-c-b-a, programming �l�ve
//!   //abcdefgdp
//!   0b00111111, // 0 cathode
//!   0b00000110, // 1 cathode
//!   0b01011011, // 2 cathode
//!   0b01001111, // 3 cathode
//!   0b01100110, // 4 cathode
//!   0b01101101, // 5 cathode
//!   0b01111101, // 6 cathode
//!   0b00000111, // 7 cathode
//!   0b01111111, // 8 cathode
//!   0b01101111  // 9 cathode
//!   
   //anode (duong chung)
//!   0b11000000, // 0
//!   0b11111001,// 1
//!   0b10100100, // 2
//!   0b10110000, // 3
//!   0b10011001, // 4
//!   0b10010010, // 5
//!   0b10000010, //6
//!   0b11111000, //7
//!   0b10000000, //8
//!   0b10010000 //9
//!};

void xuat (int n)
{
   output_b(n);
}
//!
void main()
{
   int tong=0;
   while(1)
   {
      xuat(tong);
      tong=tong+1;
      delay_ms(100);
      if(tong>=9)
      {
         tong=0;
      }
   }
}
