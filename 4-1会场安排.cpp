#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct time {
	int num;//会场编号
	int s, f;
	bool next;//next=1表示会场后面有安排其他活动，=0表示没有

	time() {
		num = 0;
		next = false;
	}
};

bool comp(time a, time b) {
	if (a.s < b.s)
		return true;
	else if (a.s == b.s)
		return a.f < b.f;
    /*
	{
		if (a.f < b.f)
			return true;
		else return false;
	}
	*/
	else 
		return false;
}

int greedy(vector<time> p)
{
	int len = p.size();
	sort(p.begin(), p.end(), comp);
	int sum = 1;
	p[0].num = 1;

	for (int i = 1; i < len; i++)
	{
		int j = 0;
		for (; j < i; j++)
		{
			if (p[j].next == false && p[j].f < p[i].s)
			{
				p[i].num = p[j].num;
				p[j].next = true;//安排好了后面的活动，就不再考虑下一次为此活动接后续活动。
				break;
			}
		}
		if (j == i)
		{
			sum += 1;
			p[i].num = sum;
		}
	}
	return sum;
}

int main()
{
	int k;
	vector<time> p;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		time h;
		cin >> h.s >> h.f;
		p.push_back(h);
	}
	cout << greedy(p) << endl;
	system("pause");
	return 0;
}