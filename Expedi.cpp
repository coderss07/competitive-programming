#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define rep(i,a,b) for (int i = a; i < b; ++i)

using namespace std;

/*
we are given 'n' files with their computation times in array.
we have to take 2 file add them and append to array

return the cost of computation time;
cost = sum of computation time
*/

int main() {
	int t;
	cin>> t;
	while(t--) {
		int n;
		cin>>n;
		vector<pii> a(n);
		rep(i,0,n) {
			cin>> a[i].first >> a[i].second;
		}
		int l,p;
		cin>>l>>p;

		rep(i,0,n) {
			a[i].first = l - a[i].first;
		}
		sort(a.begin(), a.end());

		int cnt = 0;
		int curr = p;
		bool flag = true;
		priority_queue<int, vector<int> > pq;

		rep(i,0,n) {
			if(curr > l) {
				break;
			}
			while(curr < a[i].first) {
				if(pq.empty()){
					flag = false;
					break;
				}
				cnt ++;
				curr += pq.top();
				pq.pop();
			}
			if(!flag)
				break;
			pq.push(a[i].second);
		}
		if(flag) {
			while(!pq.empty() && curr < l) {
				curr += pq.top();
				pq.pop();
				cnt++;
			}
			if(curr < l){
				flag = false;
			}
		}
		if(flag)
			cout<< cnt << endl;
		else
			cout<< "Not possible" << endl;
	}
	return 0;

}
