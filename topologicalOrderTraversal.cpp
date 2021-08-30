#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

// Works on DAG (Directed Acyclic Graph)
void topologicalOrder(vvi ad, vi indeg, int n) {

    queue<int> q;

    rep(i, 1, n) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(auto &it: ad[node]) {
            indeg[it]--;
            if(indeg[it] == 0) {
                q.push(it);
            }
        }
    }cout << endl;
}

int main() {
	int n, m;
	cin >> n >> m;
	n++;
	vvi adj(n);
    vi indeg(n, 0);
	rep(i, 0, m) {
		int x, y;
		cin >> x >> y;

		adj[x].push_back(y);
        indeg[y]++;
	}

    topologicalOrder(adj, indeg, n);


	return 0;

}
