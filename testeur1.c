/* Déclaration des Variable */
int info;   //variable de  lecture du port série
int i=0;    //compteur
/* Déclaration des Variable */

/* PROGRAMME PRINCIPALE */
void main() {
     TRISB=0x00;  //PORTB on sortie
     TRISA=0x00;  //PORTA on sortie
     /* Configuration d'interruption à la reception voir datasheet */
     INTCON=0xC0;
     RCSTA=0xD0;
     TXSTA.SYNC=0;
     PIR1.RCIF=0;
     PIE1=0x20;
     /* Configuration d'interruption à la reception voir datasheet */
     UART1_Init(9615);     //MISE EN MARCHE DE LA COMMUNICATION SERIE
     PORTB=0x01;
     Delay_ms(100);
     while(1){}
}
/* PROGRAMME PRINCIPALE */

/* INTERRUPTION POUR CHAQUE RECEPTION D'UN NOUVEAUX MESSAGE */
void interrupt(){
     if(PIR1.RCIF==1){

                         PIE1.RCIE=0;   //DISABLE INTERRUPTION
                         RCSTA.CREN=0;  //DISABLE LA LECTURE
                         info = UART1_Read();
                         if(info==0x01){
                                        PORTB.F2=1;    
                                        }
                         if(info==0x02){
                                        PORTB.F3=1;
                                        }
                         if(info==0x03){
                                        PORTB.F4=1;
                                        }
                         if(info==0x04){
                                          while(i<3){
                                                     PORTA=0X0F;
                                                     Delay_ms(300);
                                                     PORTA=0X00;
                                                     Delay_ms(300);
                                                     i++;
                                                     }
                                        }
                         RCSTA.CREN=1;


                        }
PIR1.RCIF=0;       //REINITIALISATION DU CAPTEUR D'INTERRUPTION
PIE1.RCIE=1;       //REENABLE D'INTERRUPTION
UART1_Init(9615);  //REINITIOALISATION DU PORT DE COMMUNICATION
                   
                   }
/* INTERRUPTION POUR CHAQUE RECEPTION D'UN NOUVEAUX MESSAGE */