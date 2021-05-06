/*
 * File:   main.c
 * Author: 20185147
 *
 * Created on 5 de Maio de 2021, 14:11
 */


#include <xc.h>
#include "config.h"
#include "delay.h"
#include "dispLCD4vias.h"
#include "teclado.h"



void main(void) 
{
   char str[] = "Tecla:               ";
   dispLCD_init(); 
   teclado_init();
   
   dispLCD(0,0, "Senai");
   while( 1 )        
   {
       str [7] = teclado();
       if (str [7] == 0 )
           str [7] = ' ';
       dispLCD(1,0, str); 
   } 
}

