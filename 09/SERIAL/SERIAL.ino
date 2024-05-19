/*Program prijme vstupni cislo z terminalu seriove linky 
 a na zaklade tohoto cisla vygeneruje matici nahodnych cisel
*/

unsigned int vstup; //vstupni cislo
unsigned int x,y;	//rozmìr matice
void setup()
{
	Serial.begin(9600);
}

void loop()
{
	if(Serial.available()){	//pokud prijde neco na seriovy terminal
		vstup = Serial.readString().toInt();		//retezec co prisel preved na Int
		//generovani pole cisel
		for(x=0; x<vstup; x++){
			for(y=0; y<vstup-1; y++){
				Serial.print(random(100,300)); //odeslani terminal seriove linky
				Serial.print(" ");
			}
			Serial.println (random(100,300));
		}
		Serial.println ("konec");
	}
}
