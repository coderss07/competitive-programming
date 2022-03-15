#include<bits/stdc++.h>
#define vv vector< vector< int > >
#define rep(i, a, b) for (int i = a; i <= b; ++i)

using namespace std;
/*
5 3 0  0 7 0  0 0 0
6 0 0  1 9 5  0 0 0
0 9 8  0 0 0  0 6 0

8 0 0  0 6 0  0 0 3
4 0 0  8 0 3  0 0 1
7 0 0  0 2 0  0 0 6

0 6 0  0 0 0  2 8 0
0 0 0  4 1 9  0 0 5
0 0 0  0 8 0  0 7 9


0 0 6  0 3 0  0 5 0
0 9 0  0 8 0  6 0 0
3 8 0  0 0 0  0 0 2

8 6 0  1 0 0  0 0 0
0 1 3  0 7 0  5 8 0
0 0 0  0 0 8  0 2 1

6 0 0  0 0 0  0 1 8
0 0 1  0 5 0  0 7 0
0 7 0  0 1 0  9 0 0
*/

bool isValid(vv s, int x, int y, int data) {
	rep(i, 0, 8) {
		if(s[x][i] == data) {
			return false;
		}
	}

	rep(i, 0, 8) {
		if(s[i][y] == data) {
			return false;
		}
	}

	int mat_i = (x / 3) * 3;
	int mat_j = (y / 3) * 3;

	rep(i, 0, 2) {
		rep(j, 0, 2) {
			if(s[mat_i + i][mat_j + j] == data) {
				return false;
			}
		}
	}

	return true;
}

bool solveSudoku(vv &s, int i = 0, int j = 0) {
	if(i == 9) {  // Base case...
		return true;
	}

	int ni = 0;
	int nj = 0;

	if(j == 8) {
		ni = i + 1;
		nj = 0;
	}else {
		ni = i;
		nj = j+1;
	}
	
	if(s[i][j] != 0) {
		if(solveSudoku(s, ni, nj)) {
			return true;
		}
	}else {
		rep(po, 1, 9) {
			if(isValid(s, i, j, po)) {
				s[i][j] = po;

				if(solveSudoku(s, ni, nj)) {
					return true;
				} 
				
				s[i][j] = 0; // backtracking

			}
		}
	}

	return false;
}

int main() {
	vv sudoku(9, vector<int>(9));
	rep(i, 0, 8) {
		rep(j, 0, 8) {
			cin >> sudoku[i][j];
		}
	}

	if(solveSudoku(sudoku)) {
		rep(i, 0, 8) {
			rep(j, 0, 8) {
				cout << sudoku[i][j] << " ";
			}cout << endl;
		}
	}else cout << "Invalid..." << endl;

	return 0;

}
// [	[".","8","7","6","5","4","3","2","1"],
// 	["2",".",".",".",".",".",".",".","."],
// 	["3",".",".",".",".",".",".",".","."],
// 	["4",".",".",".",".",".",".",".","."],
// 	["5",".",".",".",".",".",".",".","."],
// 	["6",".",".",".",".",".",".",".","."],
// 	["7",".",".",".",".",".",".",".","."],
// 	["8",".",".",".",".",".",".",".","."],
// 	["9",".",".",".",".",".",".",".","."]];
