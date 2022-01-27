#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define pi pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tab " "
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)

using namespace std;

string solve(string s, string t) {
    string ans = "";
    unordered_map<char, int> mp;
    int dcnt = t.size();
    int cnt = 0;
    rep(i, 0, dcnt) {
        mp[t[i]]++;
    }
    int i = -1, j = -1;
    int n = s.size();
    
    unordered_map<char, int> mp1;
    while(true) { 
        bool f1 = 0;
        bool f2 = 0;
        while(i < n - 1 && cnt < dcnt) {
            i++;
            mp1[s[i]]++;
            if(mp1[s[i]] <= mp[s[i]]) {
                cnt++;
            } 
            f1 = 1;
        }
        while(j < i and cnt == dcnt) {
            if(ans.size() == 0 || ans.size() > i - j) {
                ans = s.substr(j + 1, i - j);
            }
            j++;
            mp1[s[j]]--;
            if(mp[s[j]] > mp1[s[j]]) {
                cnt--;
            }
            f2 = 1;
        }
        cerr << ans << " ";
        if(!f1 and !f2) {
            break;
        }
    }
    return ans;
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    string s, t;
    cin >> s >> t;

    cout << solve(s, t) << endl;

    return 0;
}