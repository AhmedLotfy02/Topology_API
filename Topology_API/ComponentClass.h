#pragma once
#include <string>
#include <iostream>
#include <unordered_map>
#include "DeviceClass.h"
using namespace std;
class ComponentClass
{
private:
	string type;
	string id;
	DeviceClass *Device;
	unordered_map<string, string> netlist;
public:
	ComponentClass(string typ, string id, DeviceClass *d, unordered_map<string, string>netlist);
	ComponentClass();
	void set_type(string type);
	void set_id(string id);
	void set_Device(DeviceClass *d);
	void set_netList(unordered_map<string, string>netlist);
	string get_type();
	string get_id();
	DeviceClass* get_Comp_Device();
	unordered_map<string, string> get_netList();
	void Print_Component();
	~ComponentClass();
};

