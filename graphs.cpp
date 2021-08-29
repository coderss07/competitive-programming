#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

/*
7 7
1 2
1 3
2 4
2 5
2 6
2 7
7 3*/

int main() {
	int n, m;
	cin >> n >> m;
	n++;
	vvi adj_mat(n, vi(n, 0));
	vvi adj_list(n);
	rep(i, 0, m) {
		int x, y;
		cin >> x >> y;

		adj_mat[x][y] = 1;
		adj_mat[y][x] = 1;

		adj_list[x].push_back(y);
		adj_list[y].push_back(x);
	}

	cout<< "Adjacent Matrix for the undirected graph is : " <<endl;
	rep(i,1,n) {
		rep(j,1,n) {
			cout<< adj_mat[i][j] <<" ";
		}cout<<endl;
	}

	cout<< "\nAdjacent List for the undirected graph is : " <<endl;
	rep(i,1,n) {
		cout<< "list " << i << "-> ";
		for(auto it: adj_list[i]) {
			cout<< it <<" ";
		}cout<<endl;
	}


	return 0;

}
