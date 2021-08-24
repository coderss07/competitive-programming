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
	int n;
	cin>> n;
	priority_queue<int, vector<int>, greater<int> > pq;
	rep(i,0,n) {
		int data;
		cin>> data;
		pq.push(data);
	}
	int cost = 0;
	while(pq.size() != 1) {
		int data = 0;
		data += pq.top(); pq.pop();
		data += pq.top(); pq.pop();
		pq.push(data);
		cost += data;
	}
	cout<< cost << endl;
	return 0;

}
