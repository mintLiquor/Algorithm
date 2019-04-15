#include<iostream>
#include<fstream>
using namespace std;

//求出与中间数字相等的左右界限
void split(int a[], int n, int &l, int &r)
{
	int mid = n / 2;
	for (l = 0; l < n; l++)
	{
		//求出a[mid]左边第一个与a[mid]相等的元素下标 l
		if (a[l] == a[mid]) break;
	}
	for (r = n; r > 0; r--)
	{
		//求出a[mid]右边第一个与a[mid]相等的元素下标 r
		if (a[r] == a[mid]) break;
	}
}

void GetMaxCnt(int &mid, int &maxCnt, int a[], int n)
{
	int l, r; //左右边界
	split(a, n, l, r); //第一次分割
	int num = n / 2;
	int cnt = r - l; //中间元素的数量

					 //update
	if (cnt > maxCnt)
	{
		maxCnt = cnt;
		mid = a[num];
	}

	//左边个数大于maxCnt时搜寻
	if (l + 1 > maxCnt)
		GetMaxCnt(mid, maxCnt, a, l + 1);
	//搜寻右边
	if (n - r > maxCnt)
		GetMaxCnt(mid, maxCnt, &a[r], n - r);
}

int main()
{
	//打开input.txt
	ifstream infile("input.txt", ios::in);
	int amount;
	infile >> amount; //字符串数量
	int *p;
	p = new int[amount];
	for (int i = 0; i < amount; i++)
	{
		infile >> p[i];
		cout << p[i] << " ";
	}
	cout << endl;
	infile.close();
	int num = 0;
	int maxCnt = 0;
	GetMaxCnt(num, maxCnt, p, amount);

	//打开output.txt
	ofstream outfile("output.txt");
	cout << num << endl << maxCnt << endl;
	outfile << num << endl << maxCnt << endl;
	outfile.close();
	return 0;
}