#ifndef cintametrica_h
#define cintametrica_h
#include "arduino.h"  

class Ultrasonido{
private:
    long distancia;
public:
    byte pinEcho;
    byte pinTrigger;

//constructor parametrizado, recibe como parametros Trigger y Echo como byte
Ultrasonido (byte, byte);
Ultrasonido();





//Mide la distancia, el sensor es preciso hasta 3.5 metros
// por tanto el valor maximo es 350 cmtros 
int medirCM();


};

class Display7{
private:
    byte numbers[10][7]={ 
	    {1,1,1,1,1,1,0},
	    {0,1,1,0,0,0,0},
	    {1,1,0,1,1,0,1},
	    {1,1,1,1,0,0,1},
	    {0,1,1,0,0,1,1},
	    {1,0,1,1,0,1,1},
	    {1,0,1,1,1,1,1},
	    {1,1,1,0,0,0,0},
	    {1,1,1,1,1,1,1},
	    {1,1,1,0,0,1,1}
    };
public:
    byte pins[7];

void configurar(byte[]);
void mostrar(byte);
};



#endif