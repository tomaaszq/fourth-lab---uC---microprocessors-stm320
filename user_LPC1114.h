/**
 * @file:					user_LPC1114.h
 * @author:		
 * @purpose: 			deklaracje ustawien portu setrujacego dioda LED
 * @version:			v2.0
 * @date:					6 marzec 2016
 * 
 * @Description:	dioda LED dolaczona do linii PIO0_7
 *								klawisz dolaczony do linii PIO0_8
*/

#define PORT_LED 					0			// numer portu dla diody LED
#define PORT_UserButton		0			// numer portu klawisza

#define PIN_LED 					7			// linia portu sterujaca dioda LED
#define PIN_UserButton		8			// linia portu z dolaczonym klawiszem

#define	PORT_MODE_IN			0			// wejsciowy tryb pracy linii 
#define PORT_MODE_OUT			1			// wyjsciowy tryb pracy linii 

#define LED_OFF 					0			// stan linii przy wylaczonej diodzie LED
#define LED_ON 						1			// stan linii przy wlaczonej diodzie LED
#define LED_CZAS_ON			 10			// czas wlaczenia diody LED w 10 ms
#define LED_CZAS_OFF		  5			// czas wylaczenia diody LED w 10 ms

#define UserButton_ON			0			// stan linii po nacisnieciu klawisza
#define UserButton_OFF		1			// stan linii przy braku nacisnietego klawisza

#define TIMER_PERIOD	 1000			// czestotliwosc przerwan, wyszla 9.5238 ale dzielimy przy wywolaniu przez 1000 -> po to zeby bylo dokladniej
#define TEST_PERIOD				4			// co 4 ms testowany stan klawisza
