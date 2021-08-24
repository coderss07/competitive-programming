#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

const int N = 1e5 + 1;
bool vis[N];

int main() {
	int n,m;
	cin>>n>>m;
	n++;
	vvi adj(n);
	rep(i,0,m) {
		int x, y;
		cin>> x >> y;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	queue<int> q;
	q.push(1);
	vis[1] = true;

	while(!q.empty()) {
		int i = q.front();
		q.pop();
		cout<< i << " ";

		for(auto &it: adj[i]) {
			if(!vis[it]) {
				vis[it] = true;
				q.push(it);
			}
		}
	}cout<<endl;

	cout<< "\nAdjacent List for the undirected graph is : " <<endl;
	rep(i,1,n) {
		cout<< "list " << i << "-> ";
		for(auto it: adj[i]) {
			cout<< it <<" ";
		}cout<<endl;
	}


	return 0;

}
