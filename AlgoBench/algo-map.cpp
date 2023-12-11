#include "algo.h"

using namespace std;
void algomap::findDuplicates(int* array, int n) {
	for (int i = 0; i != n + 1; i++) {
		dup[array[i]].push_back(i);
	}
	for (auto it = dup.begin(); it != dup.end(); it++) {
		if (it->second.size() > 1) {
			found += " Found " + to_string(it->first) + " at locations ";
			for (auto vIt = it->second.begin(); vIt != it->second.end(); vIt++) {
				found += to_string(*vIt) + " ";
			}
			found += "\n";
		}
	}
}

string algomap::getFound() {
	return found;
}