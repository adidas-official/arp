
unsigned int vstup;
unsigned int x,y;	
int min = 200;
int max = 0;
void setup()
{
	Serial.begin(9600);
	Serial.println("Zadejte cislo (max 10):");
}

void loop()
{

	if(Serial.available()){	
		while (true)
		{
			vstup = Serial.readString().toInt(); 
			if (vstup < 11 && vstup > 2)
			{
				break;
			} 
		}

		for(x=0; x<vstup; x++){
			for(y=0; y<vstup; y++){
				int cislo = random(0, 200);
				if ( cislo < 10 ) 
				{
					Serial.print("00");
				}
				else if ( cislo < 100 ) 
				{ 
					Serial.print("0");
				}
				if ( cislo < min ) min = cislo;
				if ( cislo > max ) max = cislo;
				Serial.print(cislo); 
				Serial.print(" ");
			}
			Serial.println("");
		}
		Serial.println ("konec");
		Serial.print ("Min: ");
		Serial.println (min);
		Serial.print ("Max: ");
		Serial.println (max);
	}
}
