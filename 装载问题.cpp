/*1600012828
  Ѧ��
  װ������
  20161120
  */
#include<iostream>
using namespace std;
int a[2][50], n, zuida, max1;

void zhuang(int k)                              // ÿ����Ѱ��������װ�µ��Ǹ�
{
	max1 = 0;
	zuida = 0;
	for (int i = 1; i <= n; i++)
		if (a[0][i] > max1&&a[0][i] <= k)
		{
			zuida = i;
			max1 = a[0][i];
		}
	if (zuida == 0)
		return;
	k -= a[0][zuida];
	a[0][zuida] = 0;
	zhuang(k);
}

int main()
{
	int k1, k2, t, num = 1, sum = 0, x;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[0][i];
		a[1][i] = a[0][i];
	}
	cin >> k1 >> k2;
	zhuang(k1);
	for (int i = 1; i <= n; i++)
		sum += a[0][i];
	if (sum <= k2)                                       // ʣ�µ��ܺͱ�k2ҪС
	{
		cout << "ok,can load it" << endl;
		cout << "a way is:" << endl;
		for (x = 1;; x++)
			if (a[0][x] == 0)
				break;
		cout << "the first trip load:" << a[1][x];
		for (int i = x + 1; i <= n; i++)
			if (a[0][i] == 0)
				cout << " " << a[1][i];
		cout << endl;
		for (x = 1;; x++)
			if (a[0][x] != 0)
				break;
		cout << "the second trip load:" << a[1][x];
		for (int i = x + 1; i <= n; i++)
			if (a[0][i] != 0)
				cout << " " << a[1][i];
		cout << endl;
	}
	else                                                     // ʣ�µ�̫�࣬װ����
		cout << "can't find a way to Loading" << endl;
	return 0;
}