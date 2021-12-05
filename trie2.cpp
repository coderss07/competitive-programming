// Author : Sarthak Sharma
// Date: 2021-10-23 16:44

// <------------------------------------- Headers Files ------------------------------------->
#include<bits/stdc++.h>

// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tab1 " "
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)
#define fbo find_by_order
#define oof order_of_key

using namespace std;

// <------------------------------------- Templates ------------------------------------->
template <class T> void _print(T arg) { cerr << arg << endl; }

template <class T> void _print(vector<T> &a) { for(auto &it: a) { cerr << it << tab1; }cerr << endl; }

// <------------------------------------- Code ------------------------------------->

const int N = 1e5 + 10;
const int mod = 1e9;

class  trie {
	public:
		unordered_map<char, trie*> child;
		bool isEnd;
		trie() {
			isEnd = false;
		}
};

trie* root;

void insert(string s) {
	trie* ptr = root;
	for(auto c: s) {
		if(!ptr->child[c - 'a']) {
			ptr->child[c - 'a'] = new trie();
		}
		ptr = ptr->child[c - 'a'];
	}

	ptr->isEnd = 1;
}

bool search(string s) {
	trie* ptr = root;
	for(auto c: s) {
		if(!ptr->child[c - 'a']) {
			return false;
		}
		ptr = ptr->child[c - 'a'];
	}
	if(!ptr->isEnd) return false;
	return true;
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    root = new trie();
    int n; cin >> n;
    rep(i, 0, n) {
    	string s; cin >> s;
    	insert(s);
    }
    
    string s; cin >> s;
    if(search(s)) cout << "Present" << endl;
    else cout << "Not Present" << endl;

    #ifndef ONLINE_JUDGE
          clock_t terminator_69 = clock();
          cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    #endif 
    return 0;
}