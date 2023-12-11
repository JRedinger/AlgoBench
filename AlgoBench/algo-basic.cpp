#include <iostream>
#include "algo.h"

using namespace std;

void algo::findDuplicates(int* array, int n) {
	vector<int> skip;
	for (int i = 0; i != n + 1; i++) {
		for (int j = i + 1; j <= n + 1; j++) {
			if (array[i] == array[j] && find(skip.begin(), skip.end(), i) == skip.end()) {
				if (dup.find(array[i]) == dup.end()) {
					dup[array[i]].push_back(i);
				}
				dup[array[i]].push_back(j);
				skip.push_back(j);
			}
		}
	}
	for (auto it = dup.begin(); it != dup.end(); it++) {
		found += " Found " + to_string(it->first) + " at locations ";
		for (auto vIt = it->second.begin(); vIt != it->second.end(); vIt++) {
			found += to_string(*vIt) + " ";
		}
		found += "\n";
	}
}

string algo::getFound() {
	return found;
}
