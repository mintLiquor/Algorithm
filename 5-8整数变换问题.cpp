#include<iostream>
#include<fstream>
using namespace std;

class IntChange {
public:
	int n;//待变换的整数
	int m;//需要变换成的整数
	int nowcount;//当前已变换的次数 
	int mincount;//记录最小的变换次数
	int* sign;//记录路径，0表示左子树f,1表示右子树g 
	int* minsign;//记录最小变换次数的路径 
	int* recordx;//记录出现过的值 

	int Backtrack(int x);

	int test(int x) {
		int i = 1;
		while (recordx[i] != -1) {
			if (x == recordx[i])	return 0;
			i++;
		}
		return 1;
	}

	int f(int i) {
		return 3 * i;
	}

	int g(int i) {
		return i / 2;
	}
};

int IntChange::Backtrack(int x)
{
	if (test(x) == 0) {
		return 0;
	}//检测n是否能够转化为m 
	if (x == m) {
		if (nowcount < mincount) {
			mincount = nowcount;
			for (int i = 1; i <= n; i++) minsign[i] = sign[i];
		}
		return 1;//返回 
	}
	nowcount++;
	recordx[nowcount] = x;
	if (nowcount < mincount) {//当前的变换次数小于mincount 
		if (x < m) {
			sign[nowcount] = 0;
			Backtrack(f(x));//当x小于m时先进入左子树	    	
		}
		else {
			sign[nowcount] = 1;
			Backtrack(g(x));//当X大于m时进入右子树 			
		}
	}
}

void Compute(int n, int m, ofstream & outfile)
{
	IntChange ic;//实例化一个对象
	ic.n = n;
	ic.m = m;
	ic.nowcount = 0;
	ic.mincount = INT_MAX;
	ic.sign = new int[256];
	ic.minsign = new int[256];
	ic.recordx = new int[256];
	for (int i = 0; i <= n; i++) {
		ic.sign[i] = -1; ic.minsign[i] = -1; ic.recordx[i] = -1;//初始化为-1 
	}

	if (ic.Backtrack(ic.n) == 1) {
		outfile << ic.mincount << endl;
		int i = 1;
		while (ic.minsign[i] != -1) {
			if (ic.minsign[i] == 0) outfile << "f";
			else outfile << "g";
			i++;
		}
		outfile << endl;
	}
	else {
		outfile << ic.n << "无法转化为" << ic.m << endl;
	}
	delete[]ic.sign;
	delete[]ic.minsign;
}


int main() {
	ifstream cinfile;
	cinfile.open("input.txt", ios::in);
	int n, m;
	cinfile >> n >> m;
	cinfile.close();

	ofstream outfile;
	outfile.open("output.txt", ios::out);
	Compute(n, m, outfile);
	outfile.close();
	return 0;
}
