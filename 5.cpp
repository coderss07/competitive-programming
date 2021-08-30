#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) { 
		int n;
		cin >> n;
        vi a(n);
		rep(i, 0, n) {
			cin >> a[i];
		}
		
        int sum = 0;
        int ans = 0;
        multiset<int> s;

        rep(i, 0, n) {
            if(a[i] > 0) {
                s.insert(a[i]);
            }else {
                sum = 0;
                
                while(s.size() > 2) {
                    auto temp = s.begin();
                    sum += *temp;
                    s.erase(temp);
                }

                ans = max(ans, sum);

                while(!s.empty()) {
                    s.erase(s.begin());
                }
            
            }
        }
        if(!s.empty()) {
            sum = 0;
            while(s.size() > 2) {
                auto temp = s.begin();
                s.erase(temp);
                sum += *temp;
            }
            ans = max(ans, sum);
        }

        cout << ans << endl;
	}
	return 0;
}
