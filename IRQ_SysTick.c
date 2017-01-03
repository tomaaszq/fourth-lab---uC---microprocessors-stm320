/**
 * @file:					IRQ_SysTick.c
 * @author:				Imie i Nazwisko autora tego programu
 * @purpose: 			procedura obslugi przerwania od SysTick Timera
 * @version:			This software may only be used under the terms of a valid, current,
 * 								end user licence from KEIL for a compatible version of KEIL software
 * 								development tools. Nothing else gives you the right to use this software.
 *
 * 								This software is supplied "AS IS" without warranties of any kind.
 *
 * @date:					2010 Keil - An ARM Company. All rights reserved.
 * 
 * @Description:	- procedura obslugi przerwania od SysTick Timer-a zwieksza 
 *								  o 1 zmienna ticks (inkrementacja zmiennej ticks)
*/

/* dolaczenie deklaracji:
	 [1] nazw, typow i adresów rejestrów procesora
	 [2] nazw i prototypow funkcji obslugi GPIO
	 [3] deklaracji stalych uzytkownika							*/
#include <LPC11xx.h>													// [1]
#include "gpio.h"															// [2]
#include "user_LPC1114.h"											// [3]

extern volatile uint32_t ticks;					/* zmienna uzyta w przerwaniu */
static volatile uint16_t val=0;

void SysTick_Handler (void) {	
	ticks++;		

			if(ticks > 45){
					GPIOSetValue( PORT0, 7, 0 );            		// Wylaczenie diody
			}
	
			if(ticks>105) {
				LPC_ADC->CR     |= (1<<24);                 //Rozpoczecie konwersji A/D (Str. 411  -  A/D Control Register)
				GPIOSetValue( PORT0, 7, 1 );            		// Wlaczenie diody
				ticks=0;
			}
}
