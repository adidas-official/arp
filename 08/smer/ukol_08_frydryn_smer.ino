//pripravek M8LED na portu BC

int pins[] = {10, 9, 8, 14, 13, 12, 11, 15}; //vystupni piny v poradi v jakem se budou prochazet
int switchPin = 7;	//prepinac
int smer = 0;
unsigned char pos = 3;	//aktualni  pozice
void setup()  {
	//nastaveni pinu jako vystupni
	for(int i=0; i<8; i++){
		pinMode(pins[i], OUTPUT);
	}
	pinMode(switchPin, INPUT); // nastaveni prepinace
} 

void loop(){
	smer = digitalRead(switchPin);
	digitalWrite(pins[pos], HIGH);//zhasnout LED
	if (smer) {
		if(++pos > 7) pos = 0;	//posuv na dalsi pozici

	} else {
		if(--pos < 1) pos = 7;	//posuv na dalsi pozici

	}
	digitalWrite(pins[pos], LOW);	//rozsvitit dalsi
	delay(200);			//cekani 200ms

}

