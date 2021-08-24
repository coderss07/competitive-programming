#include<bits/stdc++.h>

using namespace std;

/*
input:
1 1 1 1 1 1
0 0 0 0 0 1
1 1 1 1 1 1
1 0 0 0 0 0
1 1 1 1 0 0
1 1 1 1 1 1
*/

bool isRight(int** a, int x,int y,int n,bool** vis){
	return ((x >= 0 && x<n) && (y >= 0 && y<n) && a[x][y] == 1 && !vis[x][y]);
}

int shortestPath(int** a,int x,int y,int n,bool** vis){
	if(x == n-1 && y == n-1){
		vis[x][y] = true;
		return 0;
	}
	if(isRight(a,x,y,n,vis)) {
		vis[x][y] = true;
		int r = shortestPath(a,x+1,y,n,vis) + 1;
		int d = shortestPath(a,x,y+1,n,vis) + 1;
		int l = shortestPath(a,x-1,y,n,vis) + 1;
		int u = shortestPath(a,x,y-1,n,vis) + 1;
		//backtracking
		vis[x][y] = false;
		return min( min(r,l) , min(u,d) );
	}
	return 1e8;
}

int main() {
	int n;
	cin>>n;
	int** a = new int*[n];
	for(int i=0; i<n; i++){
		a[i] = new int[n];
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin>>a[i][j];
		}
	}
	bool** vis = new bool*[n];
	for(int i=0; i<n; i++){
		vis[i] = new bool[n];
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			vis[i][j] = false;
		}
	}

	cout<<shortestPath(a,0,0,n,vis)<<endl;
	// cout<<INT_MAX<<endl;
	// for (int i = 0; i < n; ++i){
	// 	for (int j = 0; j < n; ++j){
	// 		cout<<vis[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return 0;
}
