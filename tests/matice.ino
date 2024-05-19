/*
Napi�te a odladte program , kter� bude na z�klade stisknut� tlac�tka generovat ctvercovou matici
4 x 4 c�sel v intervalu -30 do +30 vcetne, ale jen sud� c�sla.

Va�im �kolem je vygenerovanou matici odeslat na s�riovou linku tak,
aby hodnoty byly zarovn�ny pod sebou.
N�sledne pak vypoc�tat soucet z�porn�ch hodnot matice
*/

unsigned int x,y;	
static unsigned int btn = 10;
static unsigned int size = 4;

int pushed = 1;

void setup()
{
	Serial.begin(9600);
	pinMode(btn, INPUT);		
}

void loop()
{

	if (pushed && digitalRead(btn))
	{	
		pushed = 0;
		int total = 0;
		delay(100); // aby se netisklo vic matic

		for(x=0; x<size; x++){
			for(y=0; y<size; y++){
				int cislo = random(-15, 15);
				cislo = cislo*2;

				if (cislo < 10 && cislo >= 0)
				{
					Serial.print("  ");
				}
				else if ((cislo < 31 && cislo >= 10) || cislo > -10)
				{
					Serial.print(" ");
				}

				if ( cislo < 0 ) 
				{
					total += cislo;
				}			
				Serial.print(cislo); 
				Serial.print(" ");
			}
			Serial.println("");
		}
		Serial.print("Soucet zapornych cisel=");
		Serial.println(total);	
	}
	else
	{
		pushed = 1;
	}
}
