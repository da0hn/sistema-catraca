#include <sistema_catraca.h>
#include <math.h>
#include <stdio.h>
#INCLUDE<2404.C>
#include "lib/lcd_util.c"
#include "lib/teclado_util.c"
#include "lib/memoria_util.c"

unsigned char tmp;
char senha[4];
int posicaoSenha = 0;
int tipoTela = 0;
int comandoAdmin = 0;
#INT_RB
void RB_isr(void) 
{
   disable_interrupts(INT_RB);
   clear_interrupt(INT_RB);
   
    tmp = tc_tecla();
   
   if (tipoTela == 0){
      printf(lcd_escreve, "\f Academia C & G\n"); 
      printf(lcd_escreve, "\r  Senha: %s", senha);      
      if(tmp!= 255){
         if(posicaoSenha == 4){
            posicaoSenha = 0;
         }      
         if(tmp == 'D'){    
            if(verificaUsuario(senha) == 1){
               tipoTela = 1;
            }else if(verificaUsuario(senha) == 0){
               //liberar catraca com rele
                output_high(PIN_C0);
                printf(lcd_escreve, "\f Bem Vindo! ");           
                delay_ms(4000);
                output_low(PIN_C0);
                tipoTela = 0;
            }else if(verificaUsuario(senha) == (-1)){
               printf(lcd_escreve, "\f Senha invalida!! "); 
               delay_ms(2000);
               tipoTela = 0;
            }
            senha[0] = senha[1] = senha[2] = senha[3] = '\0';
         }else{
            senha[posicaoSenha] = tmp;
            posicaoSenha++;
         }                  
      }       
   }else if(tipoTela == 1){
      printf(lcd_escreve, "\f1- Incluir\n\r2- Excluir"); 
      if(tmp!= 255){
         comandoAdmin = tmp - '0';  
      }      
      if(comandoAdmin == 1){
         printf(lcd_escreve, "\f Incluir Pessoa"); 
         tipoTela = 2;
         senha[0] = senha[1] = senha[2] = senha[3] = '\0';
         delay_ms(2000);       
      }else if(comandoAdmin == 2){
         printf(lcd_escreve, "\fExcluir Pessoa"); 
         tipoTela = 3;
         senha[0] = senha[1] = senha[2] = senha[3] = '\0';
         delay_ms(2000);     
      }
   }else if (tipoTela == 2){
      printf(lcd_escreve, "\fInf. p/ incluir\n\rSenha: %s", senha);
      if(tmp!= 255){
         if(posicaoSenha == 4){
            posicaoSenha = 0;
         } 
         if(tmp == 'A'){
            novoUsuario(senha);  
            printf(lcd_escreve, "\fCadastro Realizado");
            delay_ms(2000);
            senha[0] = senha[1] = senha[2] = senha[3] = '\0';
            tipoTela = 0;
         }else{
            senha[posicaoSenha] = tmp;
            posicaoSenha++;
         }
      }
   }else if (tipoTela == 3){
    printf(lcd_escreve, "\fInf. p/ excluir\n\rSenha: %s", senha);
    if(tmp!= 255){
        if(posicaoSenha == 4){
            posicaoSenha = 0;
         } 
         if(tmp == 'B'){
            excluiUsuario(senha); 
            printf(lcd_escreve, "\fExclusao Realizada");
            delay_ms(2000);
            senha[0] = senha[1] = senha[2] = senha[3] = '\0';
            tipoTela = 0;
         }else{
            senha[posicaoSenha] = tmp;
            posicaoSenha++;
         }
    }    
  }
   
 
   
   clear_interrupt(INT_RB);
   enable_interrupts(INT_RB);

   output_low(PIN_B0);
   output_low(PIN_B1);
   output_low(PIN_B2);
   output_low(PIN_B3);
}

void main()
{
   
   init_ext_eeprom();
   apagaMemoria();
   carregaMemoria();
   configuracaoMemoria();
   
   
   lcd_ini();
   delay_ms(10);
 
   printf(lcd_escreve, "\f Teclado");
   delay_ms(1000);
   
   set_tris_b(0xF0);
   port_B_pullups(true);
   enable_interrupts(INT_RB);
   enable_interrupts(GLOBAL);
   output_low(PIN_B0);output_low(PIN_B1);output_low(PIN_B2);output_low(PIN_B3);
  

   while(TRUE){  
      
   
   }
}
