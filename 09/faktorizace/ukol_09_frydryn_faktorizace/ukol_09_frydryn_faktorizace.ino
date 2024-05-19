unsigned int vstup;
unsigned int n = 2;
void setup()
{
	Serial.begin(9600);
}

void loop()
{

	if(Serial.available()){

		while (true)
		{
			vstup = Serial.readString().toInt();	
			if (vstup > 2 && vstup < 10000) 
			{	
				break;
			}
			else
			{
				Serial.println("Vyberte cislo mensi nez 10000");
			}
		}	

		Serial.print(vstup);
		Serial.print("=");

		while (n != vstup)
		{
			if (vstup % n == 0) 
			{
				Serial.print(n);
				Serial.print("*");	
				vstup = vstup / n;	
			}
			else
			{
				n++;
			}
		}
		Serial.println(n);
		n = 2;
	}			
}
