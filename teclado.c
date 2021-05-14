/*
 * File:   teclado.c
 * Author: 20185147
 *
 * Created on 5 de Maio de 2021, 14:22
 */


#include <xc.h>
#include "config.h"
#include "teclado.h"
#include "delay.h"


void teclado_init (void)
{
    ANSELH = 0x00;
    TRISB = 0xF0;
    PORTB = 0; 
}
#define MASK 0x10

char tabela[4][4] = {{'1','2','3','A'},
                  {'4','5','6','B'},
                  {'7','8','3','C'},
                  {'*','0','#','D'}};
char teclado (void)
{
    char tecla = 0;
    char i; 
    PORTB = 0x01;
   
    for( i=0; i<4; i++ ) if( PORTB & MASK<<i ) tecla = tabela[0][i];
    
    PORTB = 0x02;
    for( i=0; i<4; i++ ) if( PORTB & MASK<<i ) tecla = tabela[1][i];
    
    PORTB = 0x04;
    for( i=0; i<4; i++ ) if( PORTB & MASK<<i ) tecla = tabela[2][i];
    
    PORTB = 0x08;
    for( i=0; i<4; i++ ) if( PORTB & MASK<<i ) tecla = tabela[3][i];
    
    return(tecla);
}           