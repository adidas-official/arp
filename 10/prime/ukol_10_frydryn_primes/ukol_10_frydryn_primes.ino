#include "Native_LiquidCrystal.h"
/* Definice komunikacnich pinu. Zde je potreba dat pozor na datove piny, protoze UnoArduSim
ma pouze jedno okenko pro nejnizsi dat. pin (DB4) a potom bere, ze dalsi tri nasledujici piny jsou DB5, DB6 a DB7.
   Take je mozne vynechat pin R/W - coz delam, protoe muj realny displej ho ma natvrdo na GND.
*/
#define RS_PIN   7
#define EN_PIN   6
#define D4_PIN   2
#define D5_PIN   3
#define D6_PIN   4
#define D7_PIN   5

int vstup;
unsigned long time0;
unsigned long time1;
bool prime = true;

/* Instance lcd displeje, podle toho jakou si vyberu knihovnu */
Native_LiquidCrystal lcd(RS_PIN, EN_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

void setup() {
/* Init displeje */
	lcd.begin(20, 4);
/* Tohle tu musi byt */
	lcd.setCursor(0, 0);
/* Staticky vypis */
	Serial.begin(9600);      //inicializace sériová linky

}
void loop() {

	Serial.println("Zadejte cislo mezi 2 a 10000");
	while (Serial.available() == 0) {	}
	while (true) 
	{
		vstup = Serial.parseInt();
		if (vstup >= 2 && vstup <= 10000) break;	
	}

	lcd.clear();                       //vymazani displeje
	lcd.setCursor(0, 0);

	prime = true;

	// start
	time0 = micros();
	for ( int i = 2; i*i <= vstup; i++ )
	{
		if (vstup % i == 0)
		{	
			prime = false;
			time1 = micros();
			break;
		}
	}
	time1 = micros();
	// end

	// print
	lcd.print("Cislo ");
	lcd.print(vstup);
	lcd.setCursor(0, 1);	
	if (prime)
	{
		lcd.print("je prvocislo");
	}
	else 
	{
		lcd.print("neni prvocislo");
	}

	lcd.setCursor(0, 2);	
	lcd.print("Cas vypoctu: ");
	lcd.print((time1 - time0));
	lcd.print("ms"); 	
}
