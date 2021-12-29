#pragma once
#include <iostream>
#include <string>
#include "DeviceClass.h"
using namespace std;

class TransistorClass:public DeviceClass
{
public:
	TransistorClass();
	TransistorClass(string name, float def, float max, float min);
	virtual void Print_Device();
	~TransistorClass();
};

