#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
vector<int> vecOfInts{};
vector<int> copyOf{};
int calculate(size_t& param1, size_t& param2) {
	
		vecOfInts = copyOf;
		vecOfInts[1] = param1;
		vecOfInts[2] = param2;	
		int temp;
		for (size_t i = 0; i < vecOfInts.size(); i += 4)
		{
			if (vecOfInts[i] == 1)
			{
				temp = vecOfInts[i + 3];
				vecOfInts[temp] = vecOfInts[vecOfInts[i + 1]] + vecOfInts[vecOfInts[i + 2]];

			}
			else if (vecOfInts[i] == 2)
			{
				temp = vecOfInts[i + 3];
				vecOfInts[temp] = vecOfInts[vecOfInts[i + 1]] * vecOfInts[vecOfInts[i + 2]];
			}
			else if (vecOfInts[i] == 99)
			{
				break;
			}
		}
	
		return vecOfInts[0];
}



int main() {

	ifstream inFile("input.txt");
	string line;	
	while (getline(inFile,line,','))
	{
		vecOfInts.push_back(stoi(line));
		copyOf.push_back(stoi(line));
	}	
	int endresult{};

	for (size_t i = 0; i < 100; i++)
	{
		for (size_t j = 0; j < 100; j++)
		{
			endresult =calculate(i, j);
			if (endresult == 19690720)
			{
				cout << 100 * i + j;
				break;
			}
		}
	}


}