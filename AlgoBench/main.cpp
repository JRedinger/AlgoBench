#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <chrono>

#include "algo.h"

using namespace std;

// n sets the number that we're working with in the following situation:
// Let an array sized n+1 contain random numbers in the range of [1..n]
// This program will identify the location of at least one duplicate number
// in the array using two different algorithms; by iteration through the
// array (basic) and by using a dictionary map (map).
// At the end the results will be printed along with a benchmark telling us
// the amount of time each algorithm took to produce the required results 
// in microseconds.
// Set n between 2 and 100000.
const int n = 10;

// Setting fVerbose to true will print the full array and duplicate findings
// for both algorithms. Setting fVerbose to false will print nothing but the 
// benchmark results in microseconds.
bool fVerbose = true;

void genArray(int *array, int n)
{   
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, n);

	for (int i = 0; i != n + 1; i++) {
		array[i] = dis(gen);
	}

}
void printArray(int* array, int n) {
	for (int i = 0; i != n + 1; i++) {
		cout << "[" << i << ", " << array[i] << "]" << endl;
	}
}
int main()
{
	if (n < 2 || n > 100000) {
		cerr << "Please set n to a number between 2 and 100000.";
		return 0;
	}

	int array[n + 1];
	genArray(array, n);

	if (fVerbose)
		printArray(array, n);

	algo basic;
	algomap map;

	vector<algo*> vAlgo;

	vAlgo.push_back(&basic);
	vAlgo.push_back(&map);

	for (auto al : vAlgo) {
		int64_t start = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count();
		al->findDuplicates(array, n);
		int64_t end = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count();
		al->ms = end - start;
	}

	if (fVerbose) {
		cout << endl;
		cout << "findDuplicates() Basic Results:" << endl << vAlgo[0]->getFound() << endl;
		cout << "findDuplicates() Map Results:" << endl << vAlgo[1]->getFound() << endl;
		cout << endl << endl;
	}
	cout << "findDuplicates() Basic time: " << vAlgo[0]->ms << " microseconds." << endl;
	cout << "  findDuplicates() Map time: " << vAlgo[1]->ms << " microseconds." << endl;

	return 0;
}

