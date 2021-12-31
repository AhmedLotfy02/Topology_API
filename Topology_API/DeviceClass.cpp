#include "DeviceClass.h"

DeviceClass::DeviceClass(string name,float def, float max, float min)
{
	this->set_Default(def);
	this->set_Max(max);
	this->set_Min(min);
	this->set_name(name);
}

DeviceClass::DeviceClass()
{
	this->set_Default(0);
	this->set_Max(0);
	this->set_Min(0);
	this->set_name("");
}

void DeviceClass::set_Default(float def)
{
	this->defaultNo = def;
}


void DeviceClass::set_Max(float max)
{
	this->max = max;
}

void DeviceClass::set_Min(float min)
{
	this->min = min;
}

void DeviceClass::set_name(string name)
{
	this->name = name;
}

string DeviceClass::get_name()
{
	return this->name;
}

float DeviceClass::get_Default()
{
	return this->defaultNo;
}

float DeviceClass::get_max()
{
	return this->max;
}

float DeviceClass::get_min()
{
	return this->min;
}

void DeviceClass::Print_Device()
{
	cout << "Device Details : " << endl;
	cout << "Default: " << this->get_Default() << "		max: " << this->get_max() << "		min:" << this->get_min() << endl;
	cout << "-------------------------------------------------------------------------" << endl;
}

DeviceClass::~DeviceClass()
{
}
