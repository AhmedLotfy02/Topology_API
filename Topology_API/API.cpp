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

Topology API::ReadJson(string FileName)
{
	//vector<Topology> TopologyList;
	ifstream file(FileName + ".json");
	json jf = json::parse(file);
	//cout << jf[0]<<endl;
	Topology topo;
	vector<ComponentClass> comps;
		topo.set_id(jf["id"]);
		for (int i = 0; i < jf["components"].size(); i++) {
			ComponentClass comp;
		 comp.set_id(	jf["components"][i]["id"]);
		 comp.set_type(jf["components"][i]["type"]);
		 
		 if (comp.get_type() == "resistor") {
			 ResistanceClass r;
			 r.set_name("resistance");
			 json res = jf["components"][i]["resistance"];
			 r.set_Default(res["default"]);
			 r.set_Min(res["min"]);
			 r.set_Max(res["max"]);
			 json net = jf["components"][i]["netlist"];
			 //cout << net;
			 comp.set_Device(r);
			 comp.set_netList(net);
			 comps.push_back(comp);
		 }
		 else if (comp.get_type() == "nmos" || comp.get_type() == "pmos") {
			 TransistorClass t;
			 t.set_name("m(l)");
			 json res = jf["components"][i]["m(l)"];
			 t.set_Default(res["default"]);
			 t.set_Min(res["min"]);
			 t.set_Max(res["max"]);
			 json net = jf["components"][i]["netlist"];
			 //cout << net;
			 comp.set_Device(t);
			 comp.set_netList(net);
			 comps.push_back(comp);
		 }
		
		}
		topo.set_ComponentArray(comps);
		return topo;
}

API::~API()
{
}
