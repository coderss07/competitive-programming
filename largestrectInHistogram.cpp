#include<bits/stdc++.h>

using namespace std;

int LargestRectInHisto(vector<int> a, int n) {
	int left[n];
	int right[n];
	stack<int> s;
	for(int i = 0; i < n; i++) {
		while(!s.empty() && a[s.top()] >= a[i]) {
			s.pop();
		}
		if(s.empty()) {
			left[i] = 0;
		}else {
			left[i] = s.top() + 1;
		}
		s.push(i);
	}
	/* to empty stack*/
	while(!s.empty()) s.pop();
	for(int i = n - 1; i >= 0; i--) {
		while(!s.empty() && a[s.top()] >= a[i]) {
			s.pop();
		}
		if(s.empty()) {
			right[i] = n - 1;
		}else {
			right[i] = s.top() - 1;
		}
		s.push(i);
	}
	int lar = 0;
	for (int i = 0; i < n; ++i) {
		lar = max(lar, (right[i] - left[i] + 1) * a[i]);
	}
	return lar;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n; 
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i){
			cin >> a[i];
		}
		
		cout << LargestRectInHisto(a, n) << "\n";
	}
	
	return 0;
}
