#include<iostream>
#include<fstream>
using namespace std;

int Stone_merge_min(int p[],int n)
{
	//定义二维数组m[i][j]来记录i到j的合并过成中最少石子数目
	int **m; //m[n][n]
	m = new int*[n];
	for (int i = 0; i <= n; i++)
		m[i] = new int[n];
	int min = 0;
	int i, j, k;
	//当一个单独合并时，m[i][i]设为0，表示没有石子
	for (i = 1; i <= n; i++) 
		m[i][i] = 0;
	//相邻的两堆石子合并
	for (i = 1; i < n; i++)
		m[i][i + 1] = p[i] + p[i + 1];
	//n>=3
	for (int r = 3; r <= n; r++)
		for (i = 1; i <= n - r + 1; i++)
		{
			j = i + r - 1; //m[i][j]
			int sum = 0;
			for (int b = i; b <= j; b++)//sum=p[i:j]
				sum += p[b];

			m[i][j] = m[i + 1][j] + sum; //m[i][i]+m[i+1][j]

			for (k = i+1; k <= r - 1; k++)
			{
				int t= m[i][k] + m[k + 1][j] + sum;
				if (t < m[i][j])m[i][j] = t;
			}//end for
		}//end for
	min = m[1][n];
	return min;
}

int Stone_merge_max(int p[], int n)
{
	//定义二维数组m[i][j]来记录i到j的合并过成中最少石子数目
	int **m; //m[n][n]
	m = new int*[n];
	for (int i = 0; i <= n; i++)
		m[i] = new int[n];
	int max = 0;
	int i, j, k;
	//当一个单独合并时，m[i][i]设为0，表示没有石子
	for (i = 1; i <= n; i++)
		m[i][i] = 0;
	//相邻的两堆石子合并
	for (i = 1; i < n; i++)
		m[i][i + 1] = p[i] + p[i + 1];
	//n>=3
	for (int r = 3; r <= n; r++)
		for (i = 1; i <= n - r + 1; i++)
		{
			j = i + r - 1; //m[i][j]
			int sum = 0;
			for (int b = i; b <= j; b++)//sum=p[i:j]
				sum += p[b];

			m[i][j] = m[i + 1][j] + sum; //m[i][i]+m[i+1][j]

			for (k = i + 1; k <= r - 1; k++)
			{
				int t = m[i][k] + m[k + 1][j] + sum;
				if (t > m[i][j])m[i][j] = t;
			}//end for
		}//end for
	max = m[1][n];
	return max;
}

int main()
{
	int num,min,max;
	//打开input.txt
	ifstream infile("input.txt", ios::in);
	infile >> num ;
	cout << "石子堆数：" << num << endl;
	int *p = new int [num];
	for (int i = 1; i <= num; i++)
	{
		infile >> p[i];
		cout << p[i] << " ";
	}
	cout << endl;
	infile.close();

	min = Stone_merge_min(p, num);
	max = Stone_merge_max(p, num);

	//向左轮换p[] 模拟圆排列，总共有n种情况
	 for (int j = 1; j <= num - 1; j++)
	    {
		    int min_cache = 0;
		    int max_cache = 0;
            int cache = p[1];
            for (int k = 2; k <= num; k++) //向左轮换p[] 模拟圆排列
            {
                p[k - 1] = p[k];
            }
            p[num] = cache;
            min_cache = Stone_merge_min(p, num);
            max_cache = Stone_merge_max(p, num);
            if (min_cache<min)
                min = min_cache;
            if (max_cache>max)
                max = max_cache;
       }

	cout << "最小值为：" << min << endl;
	cout << "最大值为：" << max << endl;

	//打开output.txt
	ofstream outfile("output.txt");
	outfile << min << endl<<max<<endl;
	outfile.close();
	return 0;
}