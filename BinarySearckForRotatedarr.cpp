#include <bits/stdc++.h>

using namespace std;

int Search_Rotated(int *a, int l, int h, int k)
{
	if (l > h)
	{
		return -1;
	}

	int mid = (l + h) / 2;
	if (a[mid] == k)
		return mid;
	if (a[l] <= a[mid])
	{
		if (k >= a[l] && k <= a[mid])
		{
			return Search_Rotated(a, l, mid - 1, k);
		}
		return Search_Rotated(a, mid + 1, h, k);
	}
	if (a[mid] <= a[h])
	{
		if (k >= a[mid] && k <= a[h])
		{
			return Search_Rotated(a, mid + 1, h, k);
		}
		return Search_Rotated(a, l, mid - 1, k);
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int *a = new int[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		cout << Search_Rotated(a, 0, n, k) << endl;
	}
	return 0;
}
