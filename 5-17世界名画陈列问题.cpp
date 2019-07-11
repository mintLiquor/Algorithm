#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

#define MAX 50
int d[6][3] = { {0,0,0},{0,0,0},{0,0,-1}, {0,-1,0},{0,0,1},{0,1,0} };
int x[MAX + 1][MAX + 1], y[MAX + 1][MAX + 1], bestx[MAX + 1][MAX + 1];
int n, m, best, k = 0, t = 0, t1, t2, more;
bool p;

/*change（）用于在（i.j）处设置一个机器人，并改变相邻陈列室的状态*/
void change(int i, int j) {
	x[i][j] = 1;
	k++;
	for (int s = 1; s <= 5; s++) {
		int p = i + d[s][1];
		int q = j + d[s][2];
		y[p][q]++;
		if (y[p][q] == 1) {
			t++;
		}
	}
}

/*restore()用于撤销在（i，j）设置的机器人，并改变相邻陈列室的状态*/
void restore(int i, int j) {
	x[i][j] = 0;
	k--;
	for (int s = 1; s <= 5; s++) {
		int p = i + d[s][1];
		int q = j + d[s][2];
		y[p][q]--;
		if (y[p][q] == 0)
			t--;
	}
}

void search(int i, int j) {
	do {
		j++;
		if (j > m) {
			i++; j = 1;
		}
	} while (!((y[i][j] == 0) || (i > n)));

	if (i > n) {
		if (k < best) {
			best = k;
			for (int p = 1; p <= n; p++) {
				for (int q = 1; q <= m; q++)
					bestx[p][q] = x[p][q];
			}
		}
		return;
	}
	if (k + (t1 - t) / 5 >= best)
	{
		return;
	}

	if (i < n - 1 && k + (t2 - t) / 5 >= best)
	{
		return;
	}

	if (i < n)
	{
		change(i + 1, j);
		search(i, j);
		restore(i + 1, j);
	}

	if (j < m && (y[i][j + 1] == 0 || y[i][j + 2] == 0))
	{
		change(i, j + 1);
		search(i, j);
		restore(i, j + 1);
	}

	if (y[i + 1][j] == 0 && y[i][j + 1] == 0)
	{
		change(i, j);
		search(i, j);
		restore(i, j);
	}

}

void compute()
{
	int i;
	more = m / 4 + 1;
	if (m % 4 == 3)
		more++;
	else if (m % 4 == 2)
		more += 2;

	t2 = m * n + more + 4;
	t1 = m * n + 4;
	best = 65536;

	if (n == 1 && m == 1)
	{
		cout << 1 << endl;
		cout << 1 << endl;
		return;
	}

	for (i = 0; i <= m + 1; i++)
	{
		y[0][i] = 1;
		y[n + 1][i] = 1;
	}

	for (i = 0; i <= n + 1; i++)
	{
		y[i][0] = 1;
		y[i][m + 1] = 1;
	}

	search(1, 0);
}

int main()
{
	ifstream infile("input.txt",ios::in);
	ofstream outfile("output.txt", ios::out);
	while (infile >> n)
	{
		infile >> m;

		k = 0;

		for (int i = 0; i <= MAX; i++)
		{
			for (int j = 0; j <= MAX; j++)
			{
				x[i][j] = 0;
				y[i][j] = 0;
			}
		}

		compute();
		outfile << best << endl;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				outfile << bestx[i][j] << " ";
			}
			outfile << endl;
		}
	}
	infile.close();
	outfile.close();

	return 0;
}