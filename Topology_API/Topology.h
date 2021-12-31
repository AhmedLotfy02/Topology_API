#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "ComponentClass.h"
using namespace std;

class Topology
{
private:
	string id;
	vector<ComponentClass> Components;
public:
	Topology();
	Topology(string id);
	Topology(string id, vector<ComponentClass>comp);
	void set_id(string id);
	void set_ComponentArray(vector<ComponentClass>comp);
	void Add_Component(ComponentClass c);
	string get_id();
	vector<ComponentClass> get_Components();
	void Print_Topology();
	~Topology();
};

