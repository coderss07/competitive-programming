#include <bits/stdc++.h>

using namespace std;

// string ltrim(const string &);
// string rtrim(const string &);
// vector<string> split(const string &);

/*
 * Complete the 'componentsInGraph' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY gb as parameter.
 */
const int N = 15002;
vector<int> par(N);
vector<int> sz(N);

void make_set(int n) {
    par[n] = n;
    sz[n] = 1;
}

int find_set(int a) {
    if(a == par[a]) {
        return a;
    }
    
    return par[a] = find_set(par[a]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a == b) return;
    
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    sz[b] = sz[a];
}

vector<int> componentsInGraph(vector<vector<int>> gb) {
    int n = 1;
    for(auto &it: gb) {
        n = max(n, max(it[0], it[1]));
    }
    for(int i = 0; i < n; i++) {
        make_set(i);
    }
    for(auto &it: gb) {
        union_set(it[0], it[1]);
    }
    int a = find_set(1);
    int b;
    int sm = n, lar = 1;
    for(auto &it: gb) {
        a = find_set(it[0]);
        b = find_set(it[1]);

        if(sz[a] < sz[b])
            swap(a, b);
        if(sz[b] > 1)
            sm = min(sm, sz[b]);
        lar = max(lar, sz[a]);

    }
    
    return {sm, lar};

}

int main()
{

    int n; cin >> n;

    vector<vector<int>> gb(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        gb[i] = {x, y};
    }

    vector<int> result = componentsInGraph(gb);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << " ";
        }
    }

    cout << "\n";

    // fout.close();

    return 0;
}
