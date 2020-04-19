void main() {
UART1_Init(9615);
Delay_ms(100);
 /*Configuration PORTA EN SORTIE ET PORTB EN ENTREE*/
TRISB=0xff;
TRISA=0x00;
while(1){
          while(PORTB.F1==0){
                     PORTA=0x00;
                     UART1_Write(0x00);

                     }
          if (PORTB.F1==1){
                     PORTA=0x01;
                     delay_ms(50);
                     UART1_Write(0x01);
                     }
          while(PORTB.F6==0){
                     UART1_Write(0x00);
                     }
          if(PORTB.F6==1){
                     UART1_Write(0x02);
                     PORTA=0x03;
                    }
          while(PORTB.F5==0){
                     UART1_Write(0x00);
                    }
          if(PORTB.F5==1){
                    UART1_Write(0x03);
                    PORTA=0x07;
                    }
          while(PORTB.F7==0){
                    UART1_Write(0x00);
                    }
          if(PORTB.F7==1){
                    UART1_Write(0x04);
                    PORTA=0x0F;
                    }
          break;  //POUR L'ARRET DU BOUCLE APRER LA FIN DU TEST
        }
}