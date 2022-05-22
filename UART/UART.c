#include "../lib/include.h"
extern void Configurar_UART2(uint32_t Baudrate)
{
    SYSCTL->RCGCUART = (1<<8); //PÁG 344
    SYSCTL->RCGCGPIO |= (1<<8);  //PÁG 340

    GPIOD->DIR =(1<<1)|(0<<0); //PÁG 653
    GPIOD->AFSEL = (1<<6)|(1<<7); //PÁG 344
    GPIOD->PCTL =(GPIOD->PCTL&0XFFFFFF00)|(0X00000011);
    GPIOD->DEN =(1<<1)|(0<<0);

    UART2->CTL = (0<<8)|(0<<9)|(0<<0); //PÁG 918
    //PARA LA TIVA CHICA LA FRECUENCIA ES DE 20 MHZ PARA EL RELOJ DEL SISTEMA
    //BDR =20,000,000/(16*115200)
    //A TODOS NOS ASIGNO EL DE 16 EN VEZ DEL DE 8
    //16 MHz reloj
    //FDBR = INTEGER(X*64+0.5)
    //X ES EL VALOR QUE SALE DE LA OPERACIÓN BDR
    UART2->IBRD = 10; // SALIO 10
    UART2->FBRD = 55; //SALE 54.9444 COLOCAMOS 55
    //PÁG 916 LINEA DE CONTROL
    UART2->LCRH = (0X3<<5) | (0<<4);
    //PARA DESABILITAR LA PILA
    UART2->CC = 0X0;

    UART2->CTL = (1<<8) | (1<<9) | (1<<0); //PÁG 918 SE HABILITA EL UART

}
extern char readChar(void)
{

    //UART FR FLAG COLOCAR BANDERA EN ALTO PÁG 911
    //UART DR DATA PÁG 906

    int v;
    char c;
    while((UART2->FR & (1<<4)) !=0 );
    v = UART2->DR& 0XFF;
    c=v;
    return c;

}