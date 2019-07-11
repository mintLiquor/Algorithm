#include <iostream>
using namespace std;

#define Max 50
typedef struct road* Road;
typedef struct road
{
	int a, b;
	int w;
}road;

typedef struct graph* Graph;
typedef struct graph
{
	int e, n;
	Road data;
}graph;

Graph initGraph(int m, int n)
{
	Graph g = (Graph)malloc(sizeof(graph));
	g->n = m;
	g->e = n;
	g->data = (Road)malloc(sizeof(road) * (g->e + 1));
	return g;
}

void create(Graph g)
{
	int i;
	for (i = 1; i <= g->e; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		if (x < y)
		{
			g->data[i].a = x;
			g->data[i].b = y;
		}
		else
		{
			g->data[i].a = y;
			g->data[i].b = x;
		}
		g->data[i].w = w;
	}
}

int getRoot(int v[], int x)
{
	while (v[x] != x)
	{
		x = v[x];
	}
	return x;
}

void sort(Road data, int n)
{
	int i, j;
	for (i = 1; i <= n - 1; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			if (data[j].w > data[j + 1].w)
			{
				road t = data[j];
				data[j] = data[j + 1];
				data[j + 1] = t;
			}
		}
	}
}

int Kruskal(Graph g)
{
	int sum = 0;
	//²¢²é¼¯
	int v[Max];
	int i;
	//init
	for (i = 1; i <= g->n; i++)
	{
		v[i] = i;
	}
	sort(g->data, g->e);
	//main
	for (i = 1; i <= g->e; i++)
	{
		int a, b;
		a = getRoot(v, g->data[i].a);
		b = getRoot(v, g->data[i].b);
		if (a != b)
		{
			v[a] = b;
			sum += g->data[i].w;
		}
	}
	return sum;
}

int main()
{
	int m, n, id = 1;
	while (cin>>m && cin>>n)
	{
		int r;
		Graph g = initGraph(m, n);
		create(g);
		r = Kruskal(g);
		cout << "case" << id++ << ":" << r << endl;
		free(g);
	}
	return 0;
}