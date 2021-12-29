#include "TransistorClass.h"

TransistorClass::TransistorClass()
{
}

TransistorClass::TransistorClass(string name, float def, float max, float min):DeviceClass(name,def,max,min)
{
}

void TransistorClass::Print_Device()
{
		
	cout << "Transistor : " << this->get_name() << endl;
	DeviceClass::Print_Device();
}

TransistorClass::~TransistorClass()
{
}
