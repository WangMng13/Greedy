#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	double v;//价值
	double w;//重量
	double vdw;
} wu[100];
bool cmp1(node a, node b)//重量
{
	if (a.w == b.w)
		return a.v > b.v;
	return a.w < b.w;
}
bool cmp2(node a, node b)//价值
{
	if (a.v == b.v)
		return a.w < b.w;
	return a.v > b.v;
}
bool cmp3(node a, node b)// 单位价值
{
	if ((a.v / a.w) == (b.v / b.w))
		return a.w < b.w;
	return (a.v / a.w) > (b.v / b.w);
}
double fun1(int n, int c)
{
	sort(wu, wu + n, cmp1);
	double value = 0;
	for (int i = 0; i < n; i++)
	{
		if (c >= wu[i].w)
		{
			c -= wu[i].w;
			value += wu[i].v;
		}
		else
		{
			value += wu[i].vdw * c;
			break;
		}
	}
	return value;
}
double fun2(int n, int c)
{
	sort(wu, wu + n, cmp2);
	double value = 0;
	for (int i = 0; i < n; i++)
	{
		if (c >= wu[i].w)
		{
			c -= wu[i].w;
			value += wu[i].v;
		}
		else
		{
			value += wu[i].vdw * c;
			break;
		}
	}
	return value;
}
double fun3(int n, int c)
{
	sort(wu, wu + n, cmp3);
	double value = 0;
	for (int i = 0; i < n; i++)
	{
		if (c >= wu[i].w)
		{
			c -= wu[i].w;
			value += wu[i].v;
		}
		else
		{
			value += wu[i].vdw * c;
			break;
		}
	}
	return value;
}
int main()
{
	int n, c;//n个物品，c的容量
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> wu[i].w;
	for (int j = 0; j < n; j++)
		cin >> wu[j].v;
	for (int i = 0; i < n; i++)
		wu[i].vdw = wu[i].v / wu[i].w;
	cout << "优先放重量最小的答案：";
	cout << fun1(n, c) << endl;
	cout << "优先放价值最大的答案：";
	cout << fun2(n, c) << endl;
	cout << "先放性价比最大的答案：";
	cout << fun3(n, c) << endl;
	return 0;
}
