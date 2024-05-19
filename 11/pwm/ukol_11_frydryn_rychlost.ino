//MDCMOTOR zapojeny na portu D

int rychlost = 0;
int rychlost_top = 0;
bool ted = 1; // 1 = vpred
bool potom = 1; // 1 = vpred
bool zmena = 0;
bool smer = 1; // 1 proti smeru h.r. 0 po smeru

void setup() {
	pinMode(3, OUTPUT);
	pinMode(10, OUTPUT);
	Serial.begin(9600);
}

void loop() {

	while (Serial.available() == 0) {	} // cekej na input
	rychlost_top = Serial.parseInt();

	while (true) // spravny input?
	{
		Serial.println(rychlost_top);
		if (rychlost_top >= -100 && rychlost_top <= 100) break;
	}

	if (rychlost_top < 0) // po smeru hodinovych rucicek
	{

		rychlost_top = -rychlost_top;
		potom = 0;

	}
	else // proti smeru nebo stop
	{

		potom = 1;
	}

	zmena = ted ^ potom;

	if (zmena) // zastavit, zmenit smer a roztocit
	{
		while (rychlost > 0)
		{
			rychlost--;	
			analogWrite(3, rychlost * 255 / 100);
			delay(20);
		}

		if (ted && !potom) // proti ----> po
		{
			smer = 0;
			ted = 0;
		}
		else { // po ---------> proti
			smer = 1;
			ted = 1;
		}

		digitalWrite(10, smer);	// rychlost je 0, zmena smeru

		while(rychlost < rychlost_top) // zrychlovani
		{		
			rychlost++;
			analogWrite(3, rychlost * 255 / 100);
			delay(20);
		}
	}
	else
	{

		digitalWrite(10, potom); // smer je rizen hodnotou potom	

		while(rychlost != rychlost_top)
		{		

			if (rychlost < rychlost_top) // zrychlovani
			{

				rychlost++;
			}
			else // zpomalovani
			{
				rychlost--;	
			}

			analogWrite(3, rychlost * 255 / 100);
			delay(20);
		}

	}

}

