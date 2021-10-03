#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

const int N = 1e5 + 1;
bool vis[N];

void DFS(vvi &ad, int node, vi &st, vi &ed, int &t) {
	vis[node] = true;
	cout << node << " ";
	st[node] = t++;

	for(auto &it: ad[node]) {
		if(!vis[it]) {
			DFS(ad, it, st, ed, t);
		}
	}
	ed[node] = t++;
}

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

	// cout<< "Adjacent List for the undirected graph is : " <<endl;
	// rep(i,1,n) {
	// 	cout<< "list " << i << "-> ";
	// 	for(auto it: adj[i]) {
	// 		cout<< it <<" ";
	// 	}cout<<endl;
	// }
	vi starting(n);
	vi ending(n);
	int t = 1;

	DFS(adj, 1, starting, ending, t);
	cout << endl;

	for(int i = 1; i < n; i++)
		cout << starting[i] << " " << ending[i] << endl;

	return 0;

}
