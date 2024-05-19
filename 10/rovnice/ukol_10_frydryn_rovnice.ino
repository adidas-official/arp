#include "Native_LiquidCrystal.h"
/* Definice komunikacnich pinu. Zde je potreba dat pozor na datove piny, protoze UnoArduSim
ma pouze jedno okenko pro nejnizsi dat. pin (DB4) a potom bere, ze dalsi tri nasledujici piny jsou DB5, DB6 a DB7.
   Take je mozne vynechat pin R/W - coz delam, protože muj realny displej ho ma natvrdo na GND.
*/
#define RS_PIN   7
#define EN_PIN   6
#define D4_PIN   2
#define D5_PIN   3
#define D6_PIN   4
#define D7_PIN   5

int a = 0;
int b = 0;
int c = 0;
int d, x, x1, x2;

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

	Serial.println("Zadejte a");
	while(Serial.available() == 0) {	}
	a = Serial.parseInt();

	lcd.clear();                       //vymazani displeje
	lcd.setCursor(0, 0);

	Serial.println("Zadejte b");
	while(Serial.available() == 0) {	}
	b = Serial.parseInt();

	Serial.println("Zadejte c");
	while(Serial.available() == 0) {	}
	c = Serial.parseInt();

	d = b*b-4*a*c;

	if(d < 0) 
	{
		Serial.print(a);
		Serial.print("x^2+");
		Serial.print(b);
		Serial.print("x+");
		Serial.print(c);
		Serial.print("=0");
		Serial.println(" Nema reseni v R");

		lcd.print(a);
		lcd.print("x^2+");
		lcd.print(b);
		lcd.print("x+");
		lcd.print(c);
		lcd.print("=0");
		lcd.setCursor(0, 1);
		lcd.print(" Nema reseni v R");

	}
	else if (d == 0 )
	{	
		Serial.print("X = ");
		x = (-b)/2*a;
		Serial.println(x);
		
		lcd.print(a);
		lcd.print("x^2+");
		lcd.print(b);
		lcd.print("x+");
		lcd.print(c);
		lcd.print("=0");
		lcd.setCursor(0, 1);

		lcd.print("X = ");
		lcd.print(x);
	}
	else 
	{
		x1 = (-b - sqrt(d))/2*a;
		x2 = (-b + sqrt(d))/2*a;

		Serial.print("X1 = ");
		Serial.println(x1);
		Serial.print("X2 = ");
		Serial.println(x2);
		
		lcd.print(a);
		lcd.print("x^2+");
		lcd.print(b);
		lcd.print("x+");
		lcd.print(c);
		lcd.print("=0");
		lcd.setCursor(0, 1);

		lcd.print("X1 = ");
		lcd.println(x1);
		lcd.setCursor(0, 1);
		lcd.print("X2 = ");
		lcd.println(x2);
	}

}
