//Design and Write CCS code to display numbers: 0000, 1111, 2222, 3333, 4444,5555, 6666, 7777, 8888 and 9999 every 1 second
#include <16F887.h>
#use delay (clock=20000000)
#fuses HS,NOWDT,PUT,NOLVP,NOPROTECT,BROWNOUT
#byte PORTD=0x08
Char maso[10] = 
{
   //CATHODE CHUNG
   0b00111111,//0
   0b00000110, //1
   0b01011011, //2
   0b01001111,//3
   0b01100110, //4
   0b01101101, //5
   0b01111101, //6
   0b00000111, //7
   0b01111111,//8
   0b01101111//9
};
int i, nghin, tram, chuc, donvi;
int16 j;
int16 hien[10] = {0000,1111,2222,3333,4444,5555,6666,7777,8888,9999};
void hienthi(int16 a)
{
   nghin=a/1000;
   a=a%1000;
   tram=a/100;
   a=a%100;
   chuc=a/10;
   donvi=a%10;
   output_C(0b11111101);
   output_D(maso[nghin]);
   delay_us(300);
   output_C(0b11111011);
   output_D(maso[tram]);
   delay_us(300);
   output_C(0b11110111);
   output_D(maso[chuc]);
   delay_us(300);
   output_C(0b11101111);
   output_D(maso[donvi]);
   delay_us(300);
}
void main()
{
   i=0;
   output_C(0b11111111);
   while (1)
   {
      for (j=0;j<=666;j++)
      {
         hienthi(hien[i]);
      }
   i++;
   if(i>9)
      {
         i=0;
      }
   }
}
