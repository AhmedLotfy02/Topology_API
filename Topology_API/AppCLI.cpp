#include <iostream>
#include "json.hpp"
#include <string>
using json = nlohmann::json;
#include "API.h"
#include "Topology.h"
using namespace std;
#include <fstream>
#include <unordered_map>
#include "API_TestingClass.h"

int main() {
	char Query;
	API app;
	Topology topo;
	while (true) {
		cout << "Please Follow the instruction :" << endl;
		cout << "Press 1 to Read a topology from a given JSON file and store it in the memory" << endl;
		cout << "Press 2 to Write a topology from the memory to a JSON file." << endl;
		cout << "Press 3 to Query about which topologies are currently in the memory." << endl;
		cout << "Press 4 to Delete a topology from memory." << endl;
		cout << "Press 5 to Query about which devices are in a topology." << endl;
		cout << "Press 6 to Query about which devices are connected to a given netlist node in a given topology" << endl;
		cout << "Press t for Unit Tests" << endl;
		cout << "Your Query: ";

		cin >> Query;
		cout << endl;
		if (Query == '1') {
			string fileName;
			cout << "Please Enter the json file name without (.json) : ";
			cin >> fileName;
			cout << endl;
			bool x=app.ReadJson(fileName);
			if (x)
				cout << "Done Reading & Adding to Memory" << endl;
			else
				cout << "Error Happened while reading & adding to memory or you entered wrong topology's id"<<endl;
		}
		else if (Query == '2') {
			string Selected_topo_id;
			cout << "Select the Topology ID : " ;
			cin >> Selected_topo_id;
			cout << endl;
			bool x = app.writeJSON(Selected_topo_id);
			if (x)
				cout << "Topology's json is created Successfully" << endl;
			else
				cout << "Enter valid Existed Topology id" << endl;
		}
		else if (Query == '3') {
			vector<Topology>TopologyList = app.queryTopologies();
			for (int i = 0; i < TopologyList.size(); i++) {
				TopologyList[i].Print_Topology();
			}
		}
		else if (Query == '4') {
			string Selected_topo_id;
			cout << "Select the Topology ID : " ;
			cin >> Selected_topo_id;
			cout << endl;
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
				cout << "There is no devices in the given Topology or you entered a wrong Topology's ID" << endl;
			}
			else {
				cout << "The Connected Devices to the given Topology :" << endl;
				for (int i = 0; i < devices.size(); i++) {

					devices[i]->Print_Device();
				}
			}
		}
		else if (Query == '6') {
			vector<DeviceClass*>devices;
			string Selected_topo_id;
			string Selected_NodeID;
			cout << "Select the Topology ID : ";
			cin >> Selected_topo_id;
			cout << endl;
			cout << "Select NetListNode ID : ";
			cin >> Selected_NodeID;
			cout << endl;
			devices = app.queryDevicesWithNetlistNode(Selected_topo_id, Selected_NodeID);
			if (devices.size() == 0) {
				cout << "There is no devices in the given topology" << endl;
			}
			else {
				cout << "The Connected Devices to the given NetList Node in a Given Topology or you entered a wrong Topology's ID :" << endl;

				for (int i = 0; i < devices.size(); i++) {

					devices[i]->Print_Device();
				}
			}
		}
		else if (Query == 't') {
			API_TestingClass UnitTest;
			cout << "TESTING QUERY 1 :" << endl;
			UnitTest.Testing_Query1();
			cout << "TESTING QUERY 2 :" << endl;
			UnitTest.Testing_Query2();
			cout << "TESTING QUERY 3 :" << endl;
			UnitTest.Testing_Query3();
			cout << "TESTING QUERY 4 :" << endl;
			UnitTest.Testing_Query4();
			cout << "TESTING QUERY 5 :" << endl;
			UnitTest.Testing_Query5();
			cout << "TESTING QUERY 6 :" << endl;
			UnitTest.Testing_Query6();
		}
		cout << "Query is Ended" << endl;
		cout << "--------------------------------------------------------";
	}
	

	//string fileName = "topology";
	

	return 0;
}