#include<bits/stdc++.h>

using namespace std;

/*  INPUT :
6
1 1 0 1 1 1
0 1 1 1 0 1
0 0 1 0 1 1
0 1 1 1 1 0
0 1 0 0 0 1
0 1 1 1 1 1
*/

bool isRight(int** a, int x,int y,int n,bool** vis){
	return ((x >= 0 && x<n) && (y >= 0 && y<n) && a[x][y] == 1 && !vis[x][y]);
}

bool ratInMaze(int** a,int x,int y,int n,bool** vis){
	if(x == n-1 && y == n-1){
		vis[x][y] = true;
		return true;
	}
	if(isRight(a,x,y,n,vis)) {
		vis[x][y] = true;
		if(ratInMaze(a,x,y+1,n,vis)){
			return true;
		}
		if(ratInMaze(a,x+1,y,n,vis)){
			return true;
		}
		if(ratInMaze(a,x-1,y,n,vis)){
			return true;
		}
		if(ratInMaze(a,x,y-1,n,vis)){
			return true;
		}
		//backtracking
		vis[x][y] = false;
		return false;
	}
	return false;
}

int main() {
	int n;
	cin>>n;
	int** a = new int*[n];
	for (int i = 0; i < n; ++i){
		a[i] = new int[n];
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

	ratInMaze(a,0,0,n,vis);

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cout<<vis[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
