#include <16f877a.h>
#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NOCPD ,NODEBUG
#use delay(clock=4M)
#use rs232(baud=9600 ,xmit=pin_c6, rcv=pin_c7, parity=N, stop=1)
int sonuc=0,sayi1,sayi2;
char operator;
void aritmetic(void);
void main()
{
   set_tris_b(0xff);
   set_tris_c(0xff);
   output_c(0x00);
   output_b(0x00);
   output_high(pin_c2);
   while(TRUE)
   {
      aritmetic();
      delay_ms(300);
   }

}
void aritmetic(void)
{
     if(input(pin_c4)==1)
     {
         printf("+");
         operator='+';
         sayi2=sayi1;
        
     }
     else if(input(pin_d2)==1)
     {
         printf("-");
          operator='-';
         sayi2=sayi1;
     }
     if(input(pin_d1)==1)
     {
         if(operator=='+')
            sonuc=sayi1+sayi2;
         else
            sonuc=sayi2-sayi1;
         printf("=%d  ",sonuc);
         sonuc=0;
     }
     else if(input(pin_b7)==1)
     {
         sayi1=1;
         printf("%d",sayi1);
     }
     else if(input(pin_b5)==1)
     {
         sayi1=2;
         printf("%d",sayi1);
     }
     else if(input(pin_b3)==1)
     {
         sayi1=3;
         printf("%d",sayi1);
     }
     else if(input(pin_b1)==1)
     {
         sayi1=4;
         printf("%d",sayi1);
     }
     else if(input(pin_d6)==1)
     {
         sayi1=5;
         printf("%d",sayi1);
     }
      
}