#include "API.h"
#include "ResistanceClass.h"
#include "TransistorClass.h"
#include "Topology.h"
#include <iostream>
using namespace std;
#include "json.hpp"
#include <string>
using json = nlohmann::json;
#include <unordered_map>
API::API()
{
}

bool API::ReadJson(string FileName)
{
	ifstream file(FileName +".json");

	try
	{
		json jf = json::parse(file);
		Topology topo;
		vector<ComponentClass> comps;
		topo.set_id(jf["id"]);
		for (int i = 0; i < jf["components"].size(); i++) {
			ComponentClass comp;
			comp.set_id(jf["components"][i]["id"]);
			comp.set_type(jf["components"][i]["type"]);

			if (comp.get_type() == "resistor") {
				ResistanceClass *r=new ResistanceClass();
				r->set_name("resistance");
				json res = jf["components"][i]["resistance"];
				r->set_Default(res["default"]);
				r->set_Min(res["min"]);
				r->set_Max(res["max"]);
				json net = jf["components"][i]["netlist"];
				//cout << net;
				comp.set_Device(r);
				comp.set_netList(net);
				comps.push_back(comp);
			}
			else if (comp.get_type() == "nmos" || comp.get_type() == "pmos") {
				TransistorClass* t = new TransistorClass();;
				t->set_name("m(l)");
				json res = jf["components"][i]["m(l)"];
				t->set_Default(res["default"]);
				t->set_Min(res["min"]);
				t->set_Max(res["max"]);
				json net = jf["components"][i]["netlist"];
				//cout << net;
				comp.set_Device(t);
				comp.set_netList(net);
				comps.push_back(comp);
			}

		}
		topo.set_ComponentArray(comps);
		TopologyList.push_back(topo);
		
	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
	
	//cout << jf[0]<<endl;	
	
}

bool API::writeJSON(string TopologyID)
{
	string jsonName;
	cout << "Please enter the name of the json file you want to create : ";
	cin >> jsonName;
	if (jsonName == "") {
		return false;
	}
	cout << endl;
	json j;
	ofstream o(jsonName+".json");
	
	Topology topo;
	for (int i = 0; i < TopologyList.size(); i++) {
		if (TopologyList[i].get_id() == TopologyID) {
			topo = TopologyList[i];
			break;
		}
	}
	if (topo.get_id() == "") {
		
		return false;
	}
	
	o << "{" << endl;

	string id = " \"id\": \"" + topo.get_id() + "\",";
	o << id << endl;
	o << "\"components\" :[";
	vector<ComponentClass>comps = topo.get_Components();
	for (int i = 0; i < topo.get_Components().size(); i++) {
		o << "{";
		o << "\"type\":";
		if (comps[i].get_type() == "resistor") {
			o << "\"resistor\",";
			o << "\"id\":" << "\"" << comps[i].get_id() << "\"," << endl;
			o << "\"resistance\" : {";
			o << "\"default\" :" << comps[i].get_Comp_Device()->get_Default() << ",";
			o << "\"min\" :" << comps[i].get_Comp_Device()->get_min() << ",";
			o << "\"max\" :" << comps[i].get_Comp_Device()->get_max();
			o << "},";
			///////Netlist;
			o << "\"netlist\": {";
			unordered_map<string, string> netL = comps[i].get_netList();

			int count = 0;
			for (auto it = netL.begin(); it != netL.end(); it++)
			{
				count++;
				// Accessing the key
				o << "\"" << it->first << " \" : \""
					// Accessing the value

					<< it->second << "\"";
				if (count != 2)
					o << ",";

			}


			if (i != comps.size() - 1)
				o << "}},";
			else
				o << "}}";
		}
		else if (comps[i].get_type() == "nmos" || comps[i].get_type() == "pmos") {
			o << "\"" << comps[i].get_type() << "\",";
			o << "\"id\":" << "\"" << comps[i].get_id() << "\"," << endl;
			o << "\"m(l)\" : {";
			o << "\"default\" :" << comps[i].get_Comp_Device()->get_Default() << ",";
			o << "\"min\" :" << comps[i].get_Comp_Device()->get_min() << ",";
			o << "\"max\" :" << comps[i].get_Comp_Device()->get_max();
			o << "},";
			///////Netlist;
			o << "\"netlist\": {";
			unordered_map<string, string> netL = comps[i].get_netList();
			
			int count = 0;
			for (auto it = netL.begin(); it != netL.end(); it++)
			{
				count++;
				// Accessing the key
				o << "\"" << it->first << " \" : \""
					// Accessing the value

					<< it->second << "\"";
				if (count != 3)
					o << ",";

			}

			if (i != comps.size() - 1)
				o << "}},";
			else
				o << "}}";
		}

	}


	o << "]" << endl;
	o << "}" << endl;

	return true;
}

vector<Topology> API::queryTopologies()
{
	return TopologyList;
}

bool API::deleteTopology(string TopologyID)
{
	int size = TopologyList.size();
	for (int i = 0; i < size; i++) {
		if (TopologyList[i].get_id() == TopologyID) {
			
			TopologyList[i] = TopologyList[size - 1];
			TopologyList.pop_back();
			return true;
		}
		
	}
	return false;
}

vector<DeviceClass*> API::queryDevices(string TopologyID)
{
	string id = "not found";
	Topology topo;
	vector<DeviceClass*> devices;
	int size = TopologyList.size();
	for (int i = 0; i < size; i++) {
		if (TopologyList[i].get_id() == TopologyID) {
			topo = TopologyList[i];
			id = "found";
			break;
		}
	}
	if (id == "not found")
		return vector<DeviceClass*>();
	int componentsSize = topo.get_Components().size();
	vector<ComponentClass> comps = topo.get_Components();
	for (int i = 0; i < componentsSize; i++) {

		devices.push_back(comps[i].get_Comp_Device());
		
		
	}
	return devices;
}

vector<DeviceClass*> API::queryDevicesWithNetlistNode(string TopologyID, string NetlistNodeID)
{
	string id = "not found";
	Topology topo;
	vector<DeviceClass*> devices;
	int size = TopologyList.size();
	for (int i = 0; i < size; i++) {
		if (TopologyList[i].get_id() == TopologyID) {
			topo = TopologyList[i];
			id = "found";
			break;
		}
	}
	if (id == "not found")
		return vector<DeviceClass*>();
	int componentsSize = topo.get_Components().size();
	vector<ComponentClass> comps = topo.get_Components();
	for (int i = 0; i < componentsSize; i++) {
		unordered_map<string, string>netL = comps[i].get_netList();
		bool connected = false;
		for (auto it : netL) {
			if (it.second == NetlistNodeID) {
				connected = true;
				break;
			}
		}
		if (connected) {

			devices.push_back(comps[i].get_Comp_Device());
			
		}

	}
	

	return devices;
}

API::~API()
{
}
