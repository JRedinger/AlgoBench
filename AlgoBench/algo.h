#ifndef ALGO_H
#define ALGO_H
#include <string>
#include <map>
#include <vector>

class algo {
	std::map<int, std::vector<int>> dup;
	std::string found;
public:
	virtual void findDuplicates(int* array, int n);
	virtual std::string getFound();
	int64_t ms;
};

class algomap : public algo {
	std::map<int, std::vector<int>> dup;
	std::string found;
public:
	void findDuplicates(int* array, int n);
	std::string getFound();
};



#endif


