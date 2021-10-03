#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N = 100001;
vector<int> mp(N, 0);

int main()
{
	string a, b;
	cin >> a >> b;

	bool flag = true;
	int i = 0, j = 0;
	while(i < a.size() && j < b.size()) {
		if(a[i] == b[j] || a[i] - 32 == b[j]) {gh
			i++; j++;
		}else {
			if(a[i] < 'Z') {
				flag = false;
				break;
			}
			i++;
		}
	}
	if(j < b.size()) {
		flag = false;
	}
	if(flag) {
		while(i < a.size()) {
			if(a[i] < 'Z') {
				flag = false;
				break;
			}
			i++;
		}
	}
	
	if(flag)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	
	return 0;
}
