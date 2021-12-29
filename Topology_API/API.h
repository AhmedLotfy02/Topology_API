#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Topology.h"
using namespace std;
class API
{
private:

public:
	API();
	Topology ReadJson(string FileName);

	~API();
};

