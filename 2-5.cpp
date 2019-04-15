#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
ofstream outfile("output.txt", ios::out);

void Swap(char &a, char &b)
{
	char c;
	c = a;
	a = b;
	b = c;
}

bool FindSame(char list[], int k, int i)
{
	if (i>k)
	{
		for (int j = k; j<i; j++)
			if (list[i] == list[j])
				return true;
	}
	return false;
}
int perm(char list[], int k, int m)
{
	static int count = 0;
	if (k == m)
	{
		for (int i = 0; i <= m; i++)
		{
			outfile << list[i];
		}
		count++;
		outfile << endl;
	}
	else //还有多个元素待排列
	{
		for (int i = k; i <= m; i++)
		{
			if (FindSame(list, k, i)) continue;
			Swap(list[k], list[i]);
			perm(list, k + 1, m);
			Swap(list[k], list[i]);
		}
	}
	return count;
}
int main()
{   //主函数，功能：输入字符数组并调用全排列函数
	int i, n, c;
	ifstream infile("input.txt", ios::in);
	infile >> n;
	char *a = new char[n];
	for (i = 0; i < n; i++)
		infile >> a[i];
	infile.close();

	a[n] = '\0';
	c = perm(a, 0, n - 1);

	outfile << c;
	outfile.close();

	return 0;
}