#include <iostream>
#include <string>
#include "API.h"
#include "Topology.h"
using namespace std;
#include <fstream>



int main() {
	vector<Topology>TopologyList;
	char Query;
	API app;
	while (true) {
		cout << "Please Follow the instruction :" << endl;
		cout << "Press 1 to Read a topology from a given JSON file and store it in the memory" << endl;

		cin >> Query;

		if (Query == '1') {
			string fileName;
			cout << "Please Enter the json file name without (.json) :" << endl;;
			cin >> fileName;
			Topology topo = app.ReadJson(fileName);
			TopologyList.push_back(topo);
			cout << "Done Reading & Adding to Memory" << endl;
		}

	}
	

	//string fileName = "topology";
	

	return 0;
}