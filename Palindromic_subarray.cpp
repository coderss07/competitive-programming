#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool isPalindrome(int n)
{
	int temp = n;
	int rev = 0;
	cout << n << endl;
	while (temp != 0)
	{
		rev = rev * 10 + (temp % 10);
		temp /= 10;
	}
	if (rev == n)
		return true;
	return false;
}

int palindromic_subarray(vector<int> a, int k)
{

	int num = 0;
	for (int i = 0; i < k; i++)
	{
		num = num * 10 + a[i];
	}
	if (isPalindrome(num))
	{
		return 0;
	}
	for (int i = k; i < a.size(); ++i)
	{

		num -= a[i - k] * pow(10, k - 1);
		cout << pow(10, k - 1) << " ";
		num = num * 10 + a[i];
		if (isPalindrome(num))
		{
			return i - k + 1;
		}
	}

	return -1;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> a;
		for (int i = 0; i < n; ++i)
		{
			int item;
			cin >> item;
			a.push_back(item);
		}
		int in = palindromic_subarray(a, k);
		if (in != -1)
		{
			for (int i = in; i < k + in; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "Not found" << endl;
		}
	}

	return 0;
}
