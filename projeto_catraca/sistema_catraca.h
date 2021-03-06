#include <16F877A.h>
#device ADC=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#priority INT_RDA, INT_RB 
#use delay(crystal=20000000)
#use FIXED_IO(B_outputs=PIN_B3,PIN_B2,PIN_B1,PIN_B0)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,stream=PORT1)

