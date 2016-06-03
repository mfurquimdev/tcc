#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string,short> ids;
	map<short,string> masks;

	string stair = "RG";

	sort(stair.begin(),stair.end());
	short counter = 0;
	do
	{
		ids[stair.c_str()] = counter;
		masks[counter] = stair.c_str();

		for (size_t i = 0; i < stair.length(); i++)
			fprintf(stderr, "%c ", stair[i]);
		fprintf(stderr, "\n");

		counter++;
	} while(next_permutation(stair.begin(),stair.end()));

	for(auto p: ids)
		cout << "Key: " << p.first << "\tValue: " << p.second << endl;

	return 0;
}
