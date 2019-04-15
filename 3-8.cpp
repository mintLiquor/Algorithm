#include<iostream>
#include<fstream>
using namespace std;
#define MAX(a,b) a>b?a:b 

int a[100];
int dp[1000][1000];

int main()
{
	ifstream infile("input.txt", ios::in);
	int n, m, maxvalue = 0;
	infile >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		infile >> a[i];
	}
	infile.close();
	for (int i = 1; i <= n; i++)
	{
		dp[i][1] = dp[i - 1][1] + a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 2; j <= m; j++)
		{
			int minvalue = 99999;
			for (int k = 1; k < i; k++) {
				int temp = MAX(dp[i][1] - dp[k][1], dp[k][j - 1]);
				if (temp < minvalue)
				{
					minvalue = temp;
				}
			}
			dp[i][j] = minvalue;
		}
	}
	ofstream outfile("output.txt", ios::out);
    outfile << dp[n][m] << endl;
	outfile.close();

	return 0;
}