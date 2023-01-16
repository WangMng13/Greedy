#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	double v;//��ֵ
	double w;//����
	double vdw;
} wu[100];
bool cmp1(node a, node b)//����
{
	if (a.w == b.w)
		return a.v > b.v;
	return a.w < b.w;
}
bool cmp2(node a, node b)//��ֵ
{
	if (a.v == b.v)
		return a.w < b.w;
	return a.v > b.v;
}
bool cmp3(node a, node b)// ��λ��ֵ
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
	int n, c;//n����Ʒ��c������
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> wu[i].w;
	for (int j = 0; j < n; j++)
		cin >> wu[j].v;
	for (int i = 0; i < n; i++)
		wu[i].vdw = wu[i].v / wu[i].w;
	cout << "���ȷ�������С�Ĵ𰸣�";
	cout << fun1(n, c) << endl;
	cout << "���ȷż�ֵ���Ĵ𰸣�";
	cout << fun2(n, c) << endl;
	cout << "�ȷ��Լ۱����Ĵ𰸣�";
	cout << fun3(n, c) << endl;
	return 0;
}
