int pins[] = {2, 3, 4, 5, 6, 7, 8, 9};
unsigned static int pins_l = 8;
unsigned static int p0, p1 = 1;
unsigned int dir0 = 1;
unsigned int dir1 = 0;
int pos0 = 0;
int pos1 = pins_l -1;

void setup()
{
	for (int i = 0; i < 8; i++)
	{
		pinMode(pins[i], OUTPUT);
		digitalWrite(pins[i], HIGH);
	}
	digitalWrite(pins[pos0], LOW);
	digitalWrite(pins[pos1], LOW);
	pinMode(A2, INPUT);
	pinMode(A3, INPUT);

}

int getDelay()
{
	p0 = digitalRead(A2);
	p1 = digitalRead(A3);

	if(!p0 && !p1) return 200;
	if(p0 && !p1) return 400;
	if(!p0 && p1) return 600;
	if(p0 && p1) return 800;

}

void loop()
{

	if (dir0)
	{
		if (pos0 > 0)
		{
			digitalWrite(pins[pos0], LOW);
			digitalWrite(pins[pos0-1], HIGH);

			digitalWrite(pins[7-pos0], LOW);
			digitalWrite(pins[7-pos0+1], HIGH);
		}
		if (pos0++ == 3) dir0 = 0;
	}
	else 
	{
		if (pos0 < 4)
		{
			digitalWrite(pins[pos0], HIGH);
			digitalWrite(pins[pos0-1], LOW);

			digitalWrite(pins[7-pos0], HIGH);
			digitalWrite(pins[7-pos0+1], LOW);
		}

		if (pos0-- == 1) dir0 = 1;               
	}

	delay(getDelay());

}