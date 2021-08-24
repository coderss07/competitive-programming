#include<bits/stdc++.h>

using namespace std;

bool isRight(int** a, int x,int y,int n){
	for(int row=0; row<x; row++){
		if(a[row][y] == 1){
			return false;
		}
	}
	int row=x;
	int col=y;
	while(row>=0 && col>=0){
		if(a[row][col] == 1){
			return false;
		}
		row--;
		col--;
	}
	row=x;
	col=y;
	while(row>=0 && col>=0){
		if(a[row][col] == 1){
			return false;
		}
		row--;
		col++;
	}
	return true;
}

int nQueen(int** a,int n,int x=0){
	if(x >= n){
		return true;
	}
	for(int col=0; col<n; col++){
		if(isRight(a,x,col,n)){
			a[x][col]=1;
			if(nQueen(a,n,x+1)){
				return true;
			}
			a[x][col]=0;
		}
	}
	return false;
}

int main() {
	int n;
	cin>>n;
	int** a = new int*[n];
	for(int i=0; i<n; i++){
		a[i] = new int[n];
		for(int j=0; j<n; j++){
			a[i][j] = 0;
		}
	}
	if(nQueen(a,n)){
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				cout<<a[i][j]<<" ";
			}cout<<endl;
		}
	}

	return 0;
}
