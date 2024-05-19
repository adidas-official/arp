//MDCMOTOR zapojeny na portu D

int rychlost;

void setup() {
	pinMode(3, OUTPUT);
	Serial.begin(9600);
}

void loop() {

	while (Serial.available()) {}
	rychlost = Serial.parseInt();
	
	Serial.println(rychlost);

	analogWrite(3,255);
}

