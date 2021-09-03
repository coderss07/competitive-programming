#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		map<int, int> m;
		rep(i, 0, n)
		{
			cin >> a[i];
		}
		rep(i, 0, n)
		{
			if (m.size() == k && m[a[i]] == 0)
				break;
			m[a[i]]++;
		}
		multimap<int, int> mmp;
		for (auto &it : m)
		{
			if (it.second != 0)
				mmp.insert({it.second, it.first});
		}
		multimap<int, int>::iterator it;
		it = mmp.end();
		do
		{
			it--;
			cout << it->second << " " << it->first << endl;
		} while (it != mmp.begin());
	}
	return 0;
}
