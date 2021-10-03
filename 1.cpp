#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> h(n, vector<int>(m));
	for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
        	cin >> h[i][j];
       	}
    }
	
    vector<vector<int>> l(n, vector<int>(m));
    vector<vector<int>> r(n, vector<int>(m));
    vector<vector<int>> u(n, vector<int>(m));
    vector<vector<int>> d(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
    	int mx = 0;
    	for(int j = 0; j < m; j++) {
            mx = max(mx, h[i][j]);
            l[i][j] = mx;
        }
    }
    for(int i = 0; i < n; i++) {
        int mx = 0;
    	for(int j = m - 1; j >= 0; j--) {
    		mx = max(mx, h[i][j]);
    		r[i][j] = mx;
    	}
    }
    for(int i = 0; i < m; i++) {
        int mx = 0;
        for(int j = 0; j < n; j++) {
            mx = max(mx, h[j][i]);
            u[j][i] = mx;
    	}
    }
    for(int i = 0; i < m; i++) {
    	int mx = 0;
    	for(int j = n - 1; j >= 0; j--) {
    		mx = max(mx, h[j][i]);
    		d[j][i] = mx;
    	}
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < m; j++) {
    		int tmp = min(min(l[i][j], r[i][j]), min(u[i][j], d[i][j]));
    		ans += (tmp - h[i][j]);
    		cerr << (tmp - h[i][j]) << " ";
    	}cerr << endl;
    }
    cout << ans << endl;
    return 0;
}