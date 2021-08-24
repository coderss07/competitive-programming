#include<bits/stdc++.h>
#define ll long long int
#define vvi vector< vector<int > >
#define vi vector< int >
#define rep(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main() {

	int t; cin >> t;
	while(t--) {
		int n;
		string origin;
		cin >> n >> origin;
		int points = 0;

		rep(i,0,n) {
			string s; cin >> s;
			if(s == "CONTEST_WON") {
				int rank; cin >> rank;
				points += 300;
				if(rank <= 20) points += (20 - rank);
				
			}else if(s == "TOP_CONTRIBUTOR") {
				points += 300;
			}else if(s == "BUG_FOUND") {
				int severity; cin >> severity;
				points += severity;
			}else if(s == "CONTEST_HOSTED"){
				points += 50;
			}
		}
		int min_red;
		if(origin == "INDIAN")
			min_red = 200;
		else 
			min_red = 400;

		
		cout << points/min_red << endl;

	}
	
	return 0;

}
