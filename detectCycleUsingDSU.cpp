#include<bits/stdc++.h>
#define vi vector<int>
#define vpi vector<pair<int,int>>
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

bool isCyclic(vpi &ad) {

    for(auto &it: ad) {
        int x = find_set(it.first);
        int y = find_set(it.second);
        if(x == y)
            return true;
        union_set(it.first,it.second);
    }
    return false;
}

int main() {
	int n,m;
	cin>>n>>m;
	n++;
    rep(i,1,n) {
        make_set(i);
    }
	vpi adj(m);
	rep(i,0,m) {
		int x, y;
		cin >> x >> y;
        adj[i] = make_pair(x, y);
	}

    if(isCyclic(adj)) {
        cout << "Cycle is present" << endl;
    }else {
        cout << "Cycle is not present" << endl;
    }
	return 0;

}
