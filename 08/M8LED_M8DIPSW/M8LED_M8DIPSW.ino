//pripravek M8LED na portu BC
//pripravek M8DIPSW na portu D, piny 0,1 pripojeny na piny 16,17 mikrokontroleru

int pinsOut[] = {10, 9, 8, 14, 13, 12, 11, 15};	//seznam vystupnich pinu
int pinsIn[] = {16, 17, 2, 3, 4, 5, 6, 7};	//seznam vstupnich pinu
void setup(){
	//nastaveni smeru pinu (vystupni / vstupni)
	for(int i=0; i<8; i++){
		pinMode(pinsOut[i], OUTPUT);
		pinMode(pinsIn[i], INPUT);
	}
} 

void loop(){
	for(int i=0; i<8; i++){
		//cteni vstupnich pinu a promitnuti jejich stavu na vystupni piny
		digitalWrite(pinsOut[i], digitalRead(pinsIn[i]));
	}
}


