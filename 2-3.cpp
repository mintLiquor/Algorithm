#include<iostream>
#include<fstream>
using namespace std;

int set(int n)
{
	int sum = 1;
	if (n == 1)
		return 1;
	else
		for (int i = 1; i <= n / 2; i++)
			sum += set(i);
	return sum;
}

int main()
{
	int a, s;
	ifstream infile("input.txt", ios::in);
	infile >> a;
	s = set(a);
	cout << s << endl;
	infile.close();

	ofstream outfile("output.txt", ios::out);
	outfile << s;
	outfile.close();

	return 0;
}