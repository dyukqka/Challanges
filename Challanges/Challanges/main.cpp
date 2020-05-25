#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int calculate(const int &mass) {

	return (mass / 3) - 2;

}
int main() {
	ifstream inFile("fuel.txt");
	vector<int> fuelVec;
	string line;
	while (getline(inFile,line))
	{
		fuelVec.push_back(stoi(line));

	}
	int counter = 0;
	for (const auto& i : fuelVec)
	{
		int f{};
		
		f = calculate(i); // remove whule for part1
		while (f > 0) // part2
		{
			counter += f;
			f = calculate(f);
		}
		
	}
	cout << counter;

}