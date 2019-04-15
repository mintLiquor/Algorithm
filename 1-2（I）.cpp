#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int f(int n)//n!
{
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}

int main()
{
	int num[27][7];
	int sum[7];

	memset(num, 0, sizeof(num));
	memset(sum, 0, sizeof(sum));

	for (int i = 1; i < 27; i++)
		for (int j = 1; j < 7; j++)
		{
			num[i][j] = f(26 - i) / (f(j - 1)*f(27 - i - j));
		}
	
	for (int p = 1; p < 7; p++)
		for (int q = 1; q < 27; q++)
			sum[p] += num[q][p];

	cout << "input.txt" << endl;
	int n;
	string s;
	vector<int>location;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		int loc = 0;
		for (int i = 1; i < s.length(); i++)
		{
			loc += sum[i];
		}//长度不超过j的字符串总数
		char ch = 'a';
		for (int i = 1; i < s[0] - 'a' + 1; i++)
		{
			loc += num[i][s.length()];
		}

		for (int j = 1; j < s.length(); j++)
			for (int i = s[0] - 'a' + 1 + j; i < s[j] - 'a' + 1; i++)
				loc += num[i][s.length() - j];
		location.push_back(loc + 1);
	}

	cout << "output.txt" << endl;
	for (int i = 0; i < location.size(); i++)
		cout << location[i] << endl;

	return 0;
}