#pragma once
#include <iostream>
#include <string>
#include "DeviceClass.h"
using namespace std;
class ResistanceClass :public DeviceClass
{
public:
	ResistanceClass();
	ResistanceClass(string name, float def, float min, float max);
	virtual void Print_Device();
	~ResistanceClass();
};

