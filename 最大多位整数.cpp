#include<iostream>
#include<fstream>
#include<vector>
#include <algorithm>
using namespace std;

bool cmp(string i, string j)
{
	return (i + j) > (j + i);
}

int main()
{
	ifstream infile("input.txt", ios::in);
	int n;
	infile >> n;
	
	vector<string> temp(n, "");
	for (int i = 0; i < n; i++)
	{
		infile >> temp[i];
	}
	infile.close();

	sort(temp.begin(), temp.end(), cmp);

	ofstream outfile("output.txt", ios::out);
	for (int i = 0; i < n; i++)
		outfile << temp[i];
	outfile << endl;
	outfile.close();

	return 0;
}