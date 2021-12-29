#pragma once
#include <iostream>
#include <string>
using namespace std;
class DeviceClass
{
private:
	float defaultNo;
	float max;
	float min;
	string name;
public:
	DeviceClass(string name, float def, float max, float min);
	DeviceClass();
	void set_Default(float def);
	void set_Max(float max);
	void set_Min(float min);
	void set_name(string name);
	string get_name();
	float get_Default();
	float get_max();
	float get_min();
	virtual void Print_Device();
	~DeviceClass();
};

