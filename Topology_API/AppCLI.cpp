#include <iostream>
#include "json.hpp"
#include <string>
using json = nlohmann::json;
#include "API.h"
#include "Topology.h"
using namespace std;
#include <fstream>
#include <unordered_map>


int main() {
	char Query;
	API app;
	Topology topo;
	while (true) {
		cout << "Please Follow the instruction :" << endl;
		cout << "Press 1 to Read a topology from a given JSON file and store it in the memory" << endl;

		cin >> Query;

		if (Query == '1') {
			string fileName;
			cout << "Please Enter the json file name without (.json) :" << endl;;
			cin >> fileName;
			bool x=app.ReadJson(fileName);
			if (x)
				cout << "Done Reading & Adding to Memory" << endl;
			else
				cout << "Error Happened while reading & adding to memory"<<endl;
		}
		else if (Query == '2') {
			string Selected_topo_id;
			cout << "Select the Topology ID" << endl;
			cin >> Selected_topo_id;
			bool x = app.writeJSON(Selected_topo_id);
			if (x)
				cout << "Topology's json is created Successfully" << endl;
			else
				cout << "Enter valid Existed Topology id" << endl;
		}
		else if (Query == '3') {
			vector<Topology>TopologyList = app.queryTopologies();
		}
		else if (Query == '4') {
			string Selected_topo_id;
			cout << "Select the Topology ID" << endl;
			cin >> Selected_topo_id;
			bool x = app.deleteTopology(Selected_topo_id);
			if (x)
				cout << "Topology is deleted successfully" << endl;
			else
				cout << "The id you entered is not found" << endl;
		}
		else if (Query == '5') {
			vector<DeviceClass*>devices;
			string Selected_topo_id;
			cout << "Select the Topology ID" << endl;
			cin >> Selected_topo_id;
			devices = app.queryDevices(Selected_topo_id);
			if (devices.size() == 0) {
				cout << "There is no devices in the given topology" << endl;
			}
			cout << "The Connected Devices to the given Topology :" << endl;
			for (int i = 0; i < devices.size(); i++) {
			
				devices[i]->Print_Device();
			}
		}
	}
	

	//string fileName = "topology";
	

	return 0;
}