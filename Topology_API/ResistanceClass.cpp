#include "ResistanceClass.h"

ResistanceClass::ResistanceClass()
{
}

ResistanceClass::ResistanceClass(string name, float def, float max, float min):DeviceClass(name,def,max,min)
{
}

void ResistanceClass::Print_Device()
{
	cout << "Resistance : " << this->get_name() << endl;
	DeviceClass::Print_Device();
}

ResistanceClass::~ResistanceClass()
{
}
