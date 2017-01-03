/**
 * @file:					Szkielet_main.c
 * @author:				Imie i Nazwisko autora tego programu
 * @purpose: 			przyklad uzycia SysTick Timer-a i GPIO w procesorze LPC1114/302 firmy NXP
 * @version:			v?.?
 * @date:					data utworzenia
 * 
 * @Description:	- czestotliwosc taktowania mikrokontrolera XTAL = 12 MHz (wartosc domyslna)
 *								- czestotliwosc taktowania rdzenia SystemCoreClock = 48 MHz
 *								
*/


#include <LPC11xx.h>											
#include "gpio.h"														
#include "user_LPC1114.h"									

volatile uint32_t ticks;	
volatile uint16_t val=0;


int main (void) {
	
		//ustawienie czestotliwosci probkowania
 		SysTick_Config(SystemCoreClock / TIMER_PERIOD);
	
	
    LPC_SYSCON->PDRUNCFG &= ~(1UL<<4);  			//wlaczenie przetwornika A/C (Str. 43  -  Wake-up configuration register
																							// 1 - off : 0 - on)
	
    LPC_SYSCON->SYSAHBCLKCTRL |= (1UL<<16);			//uruchomienie zegara do bloku IO. s.33
		LPC_SYSCON->SYSAHBCLKCTRL |= (1UL<<13);			//uruchomienie zegara dla ADC(przetwornik A/C)	s.33
	
    LPC_IOCON->PIO1_4 = 0x1;    			  			//w PIO1_4 ustawia sie AD0. select function AD0, s.99 + ADMODE = 0, tzn analog-input mode
																								//czyli analogowe wejscie na 0.
	
    LPC_ADC->CR = 0x0A20;      								//Wybór kanalu AD5, ustawienie wartosci CLKDIV na 10
																							// Zegar ADC = Zegar PLk / CLKDIV + 1 ,s.411

		LPC_ADC->INTEN = (1<<8);                   //Uruchomione przerwanie od DONE(AD conversion complete)	
		LPC_ADC->INTEN |= (1<<5);										// Wybor kanalu 5 dla przerwan
	
		NVIC_EnableIRQ(ADC_IRQn);																//uruchomienie przerwania od adc s.406

 
			GPIOInit();
			GPIOSetDir( PORT0, 7, 1 );
  	
			while(1);
	}	
	
	void ADC_IRQHandler(void)
		{
      LPC_ADC->CR &= ~(1<<24); 										//Wyczyszczenie bitu konwersji w rejestrze (Str. 411  -  A/D Control Register)
			val  = ((LPC_ADC->DR[0] & 0xFFC0) >> 6);    //Przypisanie do zmiennej val 10 najstarszych bitów
		}
