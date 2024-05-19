#include <Stepper.h>
// pocet kroku na otacku dle vaseho krokoveho motoru
const int steps = 100;  

// inicializace krokoveho motoru myStepper
Stepper myStepper(steps, 16,17,2,3);            

int stepCount = 100;		//pocet kroku

void setup() {
	myStepper.setSpeed(50);

}

void loop() {

	myStepper.step(stepCount);
	delay(1000);
	myStepper.step(-stepCount);
	delay(1000);

}

