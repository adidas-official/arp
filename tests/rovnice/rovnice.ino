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

int d = 0;
int x[2];
int r = 1;

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

int* getParams()
{
	int a, b, c;
	String coefs[] = {'a', 'b', 'c'}; 
	int params[3] = {};

	for (int i = 0; i < 3; i++)
	{
		Serial.print("Zadejte ");
		Serial.print(coefs[i]);
		Serial.println(":");
		while (!Serial.available()) {	}
		a = Serial.parseInt();
		Serial.print(coefs[i]);
		Serial.print(" = ");
		Serial.println(a);
		params[i] = a;	
	}

	return params;

}

void loop() {

	int* params = getParams();
	int a = params[0];
	int b = params[1];
	int c = params[2];

	d = b*b - 4*a*c;

	if (d < 0)
	{
		Serial.println("Nema reseni v R");
		lcd.print("Nema reseni v R");
		r = 0;
	}
	else if (d == 0)
	{
		x[0] = -b/2*a;
		r = 1;
	}
	else
	{
		x[0] = (-b + sqrt(d))/2*a;
		x[1] = (-b - sqrt(d))/2*a;
		r = 2;
	}

	if (r)
	{
		for (int i = 0; i < r; i++)
		{	
			Serial.print("X");
			Serial.print(i+1);
			Serial.print("=");
			Serial.println(x[i]);
			
			lcd.setCursor(0, i);
			lcd.print("X");
			lcd.print(i+1);
			lcd.print("=");
			lcd.println(x[i]);
		}
	}
}
