
#ifndef TESTCONTROL_H
#define TESTCONTROL_H

#include <iostream>
#include <string>
#include <iomanip>

#include "View.h"
#include "SpaceW.h"
#include <vector>
#include <random>
#include <unordered_set>

#define ROCKET_NUM 3
#define PART_NUM 10
#define TEST_MENU 6

using namespace std;

class TestControl {
		
	public:
		TestControl(): today(2023, 7, 1){}
		void launch();
	
	private:
		View view;

		void initSpaceW(SpaceW& sw);
		// These also test the print functions
		void addRocket();
		void addPart();
		void installPart();
		void inspectionReport();
		void inspectRocket();
		void launchRocket();

		void initCapture();
		void endCapture();	
		void pressEnterToContinue();
		void find(vector<int>& keys, const string* search, int& error);
		void findInOrder(vector<int>& keys, const string* search, int& error);
		// generate a set (no duplicates) of "count" random integers
		// from 0 to "range"
		void ran(vector<int>& list, int count, int range);
		// generate a random integer in the given range
		int ran(int range_from, int range_to);

		Date today;

		const static string rocket_name[ROCKET_NUM];
		const static string parts[PART_NUM];
		const static int max_launches[PART_NUM];
		const static int max_days[PART_NUM];
		const static string menu[TEST_MENU];

		streambuf* oldCoutStreamBuf;
    	ostringstream strCout;
		string output;
	
};
#endif