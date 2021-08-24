#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i = a; i < b; ++i)


//     UNDIRECTED GRAPH

using namespace std;

const int N = 1e4 + 10;
vi parent(N);
vi sz(N);

void make_set(int x) {
    parent[x] = x;
    sz[x] = 1;
}

int find_set(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find_set(parent[x]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if(a == b) {
        return;
    }
    if(sz[a] < sz[b]) {
        swap(a,b);
    }
    parent[b] = a;
    sz[a] += sz[b];
}

int main() {
	int n,m;
	cin >> n >> m;
	n++;
    rep(i,1,n) {
        make_set(i);
	}
	vvi adj(m);
	rep(i,0,m) {
		int x, y, w;
		cin >> x >> y >> w;
        adj[i] = {x, y, w};
	}

    int cost = 0;
    sort(adj.begin(),adj.end(), [&](vi x,vi y){
        return x[2] < y[2];
    });

    for(auto &it: adj) {
        int x = find_set(it[0]);
        int y = find_set(it[1]);
        if(x == y)
            continue;
        cout<< it[0] << " " << it[1] << endl;
        cost += it[2];
        union_set(it[0], it[1]);
    }
    cout<< cost << endl;
    
	return 0;

}
