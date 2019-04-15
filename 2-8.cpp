#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<fstream>
using namespace std;

long long S(long long n, long long m)
{
	if (m == 0 && n != 0)
		return 0;
	if (m == 0 && n == 0)
		return 1;
	if (m == n + 1)
		return 0;
	else
		return m*S(n - 1, m) + S(n - 1, m - 1);
}

int main()
{
	long long n, m;
	ifstream infile("input.txt", ios::in);
	infile >> n >> m;
	infile.close();
	ofstream outfile("output.txt", ios::out);
	outfile << S(n, m);
	outfile.close();
	return 0;
}