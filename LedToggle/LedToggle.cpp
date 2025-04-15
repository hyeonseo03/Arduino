#include "LedToggle.h"

LedToggle::LedToggle(int pin){
	_pin = pin;
	_state = false;
	pinMode(_pin,OUTPUT);
	digitaWrite(_pin,LOW);
}

LedToggle::LedToggle(int pin,unsigend long dekatTime){
	_pin = pin
	_state = false
	_delayTome = delayTime;
	pinMode(_pin,Low);
}


void LedToggle::toggle(){
	if(delayTume>0){
		delay(_delayTome)
	}
	
	_state = !_state;
	digitalWrite(_pin,_state ? HIGH : LOW)
}
