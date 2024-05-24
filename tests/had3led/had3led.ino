/*
Vytvorte elektronického hada pomocí 8 LED, který bude pracovat následovne:
3 LED budou prebíhat z vrchu dolu a pak ze zdola nahoru 
(na konci nebo pri odrazu nebude deformace porád to budou 3 LED).
Dej se bude opakovat. Cas bude možné nastavovat pomocí 2 prepínacu,
a to v následujících intervalech. (200, 400, 600, 800) ms.
*/

int pins[] = {3, 4, 5, 6, 7, 8, 9, 10};

unsigned static int pins_l = 8;
unsigned static int snake_l = 3;

int time_delay[] = {200, 400, 600, 800};
unsigned int gear = 0;

static int faster = 14;
static int slower = 15;
unsigned int pos = 0;

unsigned long t0 = 0;
unsigned long t1 = 0;

int up;
int down;

void setup()
{
	pinMode(faster, INPUT);
	pinMode(slower, INPUT);
	for (int i = 0; i < pins_l; i++)
	{
		pinMode(pins[i], OUTPUT);		
		digitalWrite(pins[i], HIGH);		
	}
	digitalWrite(pins[0], LOW);
	digitalWrite(pins[1], LOW);
	digitalWrite(pins[2], LOW);
}

void loop()
{
	t0 = millis();
	up = digitalRead(faster);
	if (up) 
	{
		if (gear < 3) gear++;
	}

	down = digitalRead(slower);
	if (down)
	{
		if (gear > 0) gear--;
	}

	while (pos < pins_l - snake_l)
	{		
		digitalWrite(pins[pos], HIGH);
		digitalWrite(pins[pos+3], LOW);

		pos++;	
		delay(time_delay[gear]);
	}
	while (pos > 0)
	{

		pos--;
		digitalWrite(pins[pos], LOW);
		digitalWrite(pins[pos+3], HIGH);				
		delay(time_delay[gear]);

	}

}
