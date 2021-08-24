#include <bits/stdc++.h>

using namespace std;

void display(int a[][10], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	int a[10][10], b[10][10];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> b[i][j];
		}
	}
	display(a, n);
	display(b, n);
	int mul[10][10];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; ++j)
		{
			mul[i][j] = 0;
			for (int k = 0; k < n; ++k)
			{
				mul[i][j] += (a[i][k] * b[k][j]);
			}
		}
	}
	display(mul, n);

	return 0;
}