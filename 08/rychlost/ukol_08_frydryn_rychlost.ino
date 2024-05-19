//pripravek M8LED na portu BC

int pins[] = {10, 9, 8, 14, 13, 12, 11, 15}; //vystupni piny v poradi v jakem se budou prochazet
int speed[] = {50, 100, 200, 400};	//prepinac
const int shiftUpPin = 1;
const int shiftDownPin = 2;

int gear = 0;
int up = 0;
int down = 0;

unsigned char pos = 3;	//aktualni  pozice

void setup()  {
	//nastaveni pinu jako vystupni
	for(int i=0; i<8; i++){
		pinMode(pins[i], OUTPUT);
	}
	pinMode(shiftUpPin, INPUT); // prepinac radit nahoru
	pinMode(shiftDownPin, INPUT); // prepinac radit dolu
} 

void loop(){
	up = digitalRead(shiftUpPin);
	if (up) 
	{
		if (gear < 3) gear++;

	}
	down = digitalRead(shiftDownPin);
	if (down)
	{
		if (gear > 0) gear--;
	}

	digitalWrite(pins[pos], HIGH);//zhasnout LED
	if(++pos > 7) pos = 0;	//posuv na dalsi pozici
	digitalWrite(pins[pos], LOW);	//rozsvitit dalsi
	delay(speed[gear]);
	

}

