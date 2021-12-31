#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "DeviceClass.h"
#include "ResistanceClass.h"
#include "TransistorClass.h"
#include "Topology.h"
using namespace std;
class API
{
private:
	vector<Topology>TopologyList;
public:
	API();
	bool ReadJson(string FileName);
	bool writeJSON(string TopologyID);
	vector<Topology> queryTopologies();
	bool deleteTopology(string TopologyID);
	vector<DeviceClass*> queryDevices(string TopologyID);
	vector<DeviceClass*> queryDevicesWithNetlistNode(string TopologyID,string NetlistNodeID);
	~API();
};

