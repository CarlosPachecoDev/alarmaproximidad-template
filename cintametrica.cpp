#include "arduino.h"
#include "cintametrica.h"

// ****** CLASE ULTRASONIDO  **********
//Constructor parametrizado

Ultrasonido::Ultrasonido(byte _pinTrigger, byte _pinEcho){
    pinTrigger = _pinTrigger;
    pinEcho= _pinEcho;
    pinMode(_pinTrigger, OUTPUT);
    pinMode(_pinEcho, OUTPUT);
};
Ultrasonido::Ultrasonido(){};

//hace la medición de distancia, devuelve los cmtros de distancia hasta 350 cm maximo
int Ultrasonido::medirCM(){
    digitalWrite(pinTrigger, LOW);
	delayMicroseconds (4);
	digitalWrite(pinTrigger, HIGH);
	delayMicroseconds (10);
	digitalWrite(pinTrigger, LOW);

	distancia = pulseIn(pinEcho, HIGH)/56.5812;
	distancia = constrain(distancia,0,350);

    return (int) distancia;
};



// **** CLASE DISPLAY7  ******
// esta clase no emplea un constructor para configurarse
// utiliza un metodo
void Display7::configurar(byte _pins[]){
    for(byte j=0; j<7; j++) {
        pins[j] = _pins[j];
		pinMode(pins[j], OUTPUT);
	}
};

void Display7::mostrar(byte _num){
    if(_num > 9) {
        _num = 9;
    }
    
    byte value, pin;
    for(byte j=0; j<7; j++) {
		value = numbers[_num][j];
        pin = pins[j];
        digitalWrite(pin, value);

	}

};
