#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define vi vector<int>

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
    cin>>n>>m;
    n++;
    rep(i,1,n) {
        make_set(i);
    }

    rep(i,0,m) {
        int a,b;
        cin >> a >> b;
        union_set(a,b);
    }

    rep(i,1,n) {
        cout<< i << " " << parent[i] << endl;
    }


    return 0;
}
