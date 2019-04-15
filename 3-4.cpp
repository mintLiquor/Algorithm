#include<iostream>
#include<fstream>
using namespace std;

void Num_Tri(int **m,int n)
{
	for(int row=n-1;row>=0;row--)
		for (int col = 0; col <= row; col++)
		{
			if (m[row + 1][col] > m[row + 1][col + 1])
				m[row][col] += m[row + 1][col];
			else m[row][col] += m[row + 1][col + 1];
		}
}

int main()
{
	int n;
	//打开input.txt
	ifstream infile("input.txt", ios::in);
	infile >> n;
	cout << "三角形行数：" << n << endl;

	int **m; //m[n][n]
	m = new int*[n];
	for (int i = 0; i <= n; i++)
		m[i] = new int[n];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			infile >> m[i][j];
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	infile.close();
	Num_Tri(m,n);
	//打开output.txt
	ofstream outfile("output.txt");
	outfile << m[1][1] << endl;
	cout <<"最大值为： "<< m[1][1] << endl;
	outfile.close();
	return 0;
}