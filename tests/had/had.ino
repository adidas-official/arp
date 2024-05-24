int pins[] = {2, 3, 4, 5, 6, 7, 8, 9};
unsigned static int pins_l = 8;
unsigned static int p0, p1, dir = 1;
unsigned int pos = 0;

void setup()
{
	for (int i = 0; i < 8; i++)
	{
		pinMode(pins[i], OUTPUT);
		digitalWrite(pins[i], HIGH);
	}
	digitalWrite(pins[0], LOW);
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
	if (dir)
	{
		if (pos > 0)
		{
			digitalWrite(pins[pos-1], HIGH);
		}

		digitalWrite(pins[pos+1], LOW);
		if (++pos == (pins_l - 1)) dir = 0;
	}
	else 
	{
		if (pos < pins_l - 1)
		{
			digitalWrite(pins[pos+1], HIGH);
		}

		digitalWrite(pins[pos-1], LOW);
		if (--pos == 0) dir = 1;
	}
	delay(getDelay());
}