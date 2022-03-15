// Author : Sarthak Sharma
// Date: 2022-03-11 20:00:05

// <------------------------------------- Headers Files ------------------------------------->
#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
// <------------------------------------- Code ------------------------------------->

// const int N = 1e5 + 10;
// const int mod = 1e9 + 7;
struct info {
	string id;
	pair<int, string> per;
	int c1, c2, c3;
};

pair<int, string> calc(string s) {
	int n = s.size();
	int i = 0;
	while(i < n && s[i] != '.') i++;
	int ans1 = stoi(s.substr(0, i));
	string ans2;
	if(i < n) {
		i++;
		string tmp = s.substr(i);
		int j = tmp.size();
		j--;
		while(j >= 0 && tmp[j] == '0') j--;
		ans2 = s.substr(i, j + 1);
	}else {
		ans2 = "";
	}
	return {ans1, ans2};
}

int comp(string a, string b) {
	int n = min(a.size(), b.size());
	for(int i = 0; i < n; i++) {
		if(a[i] < b[i]) return -1;
		if(a[i] > b[i]) return 1;
	}
	if(a.size() == b.size()) return 0;
	if(a.size() > b.size()) return 1;
	return -1;
}

int main() {
	fast_io;

	int c, n; cin >> c >> n;
	vector<int> col(c + 1);
	for(int i = 1; i <= c; i++) cin >> col[i];
	vector<info> a(n);
	for(int k = 0; k < n; k++) {
		string s; cin >> s;
		int i = 0, j = 0;
		int n = s.size();
		// cout << s << endl;
		while(i < n && s[i] != ',') i++;
		a[k].id = s.substr(j, i - j);
		i++, j = i;
		while(i < n && s[i] != ',') i++;
		string tmp = s.substr(j, i - j);
		a[k].per = calc(tmp);
		i++, j = i;
		while(i < n && s[i] != ',') i++;
		a[k].c1 = stoi(s.substr(j + 2, i - j - 2));
		i++, j = i;
		while(i < n && s[i] != ',') i++;
		a[k].c2 = stoi(s.substr(j + 2, i - j - 2));
		i++, j = i;
		a[k].c3 = stoi(s.substr(j + 2));
		
	}
	sort(a.begin(), a.end(), [&](info x, info y){
		// if(x.per.first == y.per.first || comp(x.per.second, y.per.second) == 0) {
		// 	return x.id < y.id;
		// }
		if(x.per == y.per) {
			return x.id < y.id;
		}
		if(x.per.first == y.per.first) {
			return (comp(x.per.second, y.per.second) == 1 ? true : false);
		}
		return x.per.first > y.per.first;
	});

	
	for(int i = 0; i < n; i++) {
		cerr<<a[i].id<<" "<<a[i].per.first<<"."<<a[i].per.second<<" "<<a[i].c3<<endl;
		if(a[i].c1 <= c && col[a[i].c1] > 0) {
			cout << a[i].id << " C-" << a[i].c1 << endl;
			col[a[i].c1]--;
		}else if(a[i].c3 <= c && col[a[i].c2] > 0) {
			cout << a[i].id << " C-" << a[i].c2 << endl;
			col[a[i].c2]--;
		}else if(a[i].c3 <= c && col[a[i].c3] > 0) {
			cout << a[i].id << " C-" << a[i].c3 << endl;
			col[a[i].c3]--;
		}
	}

	cout << endl << comp("0083", "008");
 
	return 0;
}