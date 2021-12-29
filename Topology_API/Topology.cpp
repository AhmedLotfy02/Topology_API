#include "Topology.h"

Topology::Topology(string id)
{
	this->set_id(id);
}

Topology::Topology()
{
}

Topology::Topology(string id, vector<ComponentClass>comp)
{
	this->set_id(id);
	this->set_ComponentArray(comp);
}

void Topology::set_id(string id)
{
	this->id = id;
}



void Topology::set_ComponentArray(vector<ComponentClass> comp)
{
	this->Components = comp;
}




void Topology::Add_Component(ComponentClass c)
{
	this->Components.push_back(c);
}

string Topology::get_id()
{
	return this->id;
}

vector<ComponentClass>  Topology::get_Components()
{
	return this->Components;
}

Topology::~Topology()
{
}
