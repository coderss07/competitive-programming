#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

const int N = 1e5 + 1;
bool vis[N];

void DFS(vvi ad, int node) {
	vis[node] = true;
	cout << node << " ";

	for(auto &it: ad[node]) {
		if(!vis[it]) {
			DFS(ad, it);
		}
	}
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

	cout<< "Adjacent List for the undirected graph is : " <<endl;
	rep(i,1,n) {
		cout<< "list " << i << "-> ";
		for(auto it: adj[i]) {
			cout<< it <<" ";
		}cout<<endl;
	}

	DFS(adj,1);

	// stack<int> st;
	// st.push(1);
	// vis[1] = true;

	// while(!st.empty()) {
	// 	int i = st.top();
	// 	st.pop();
	// 	cout<< i << " ";
	// 	for(auto &it: adj[i]) {
	// 		if(!vis[it]) {
	// 			st.push(it);
	// 			vis[it] = true;
	// 		}
	// 	}
	// }cout << endl;

	return 0;

}
