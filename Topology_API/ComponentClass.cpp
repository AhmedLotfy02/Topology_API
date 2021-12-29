#include "ComponentClass.h"

ComponentClass::ComponentClass(string typ, string id, DeviceClass d, unordered_map<string, string> netlist)
{
	this->set_Device(d);
	this->set_id(id);
	this->set_type(typ);
	this->set_netList(netlist);
}

ComponentClass::ComponentClass()
{

}

void ComponentClass::set_type(string type)
{
	this->type = type;
}

void ComponentClass::set_id(string id)
{
	this->id = id;
}

void ComponentClass::set_Device(DeviceClass d)
{
	this->Device = d;
}

void ComponentClass::set_netList(unordered_map<string, string> netlist)
{
	this->netlist = netlist;
}

string ComponentClass::get_type()
{
	return this->type;
}

string ComponentClass::get_id()
{
	return this->id;
}

DeviceClass ComponentClass::get_Comp_Device()
{
	return this->Device;
}

unordered_map<string, string> ComponentClass::get_netList()
{
	return this->netlist;
}

ComponentClass::~ComponentClass()
{
}
