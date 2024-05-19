#include <Stepper.h>
// pocet kroku na otacku dle vaseho krokoveho motoru
const int steps = 100;  

// inicializace krokoveho motoru myStepper
Stepper myStepper(steps, 16,17,2,3);            

int stepCount;		//pocet kroku

void setup() {
	myStepper.setSpeed(30);
	Serial.begin(9600);

}

void loop() {
	while(Serial.available() == 0) {	}
	stepCount = Serial.parseInt();
	myStepper.step(stepCount);

}

