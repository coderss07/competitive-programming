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

class trieNode {
	public:
		vector<trieNode*> child;
		trieNode() {
			child = vector<trieNode*>(2, NULL);
		}
};

trieNode* root;

void insert(int a) {
	trieNode* ptr = root;
	rrep(i, 32, 0) {
		int bit = (a >> i) & 1;
		if(!ptr->child[bit]) {
			ptr->child[bit] = new trieNode();
		}
		ptr = ptr->child[bit];
	}

}

int query(int a) {
	trieNode* ptr = root;
	int ans = 0;
	rrep(i, 32, 0) {
		int bit = ((a >> i) & 1) xor 1;
		if(ptr->child[bit]) {
			ans <<= 1;
			ans |= 1;
			ptr = ptr->child[bit];
		}else {
			ans <<= 1;
			ptr = ptr->child[bit xor 1];
		}
	}
	return ans;
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    root = new trieNode();
    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) {
    	cin >> a[i];
    }
    insert(0);
    vi rmax(n + 1, 0);
    int R = a[n - 1];
    rmax[n - 1] = query(R);
    insert(R);
    rrep(i, n - 1, 0) {
    	R = R xor a[i];
    	rmax[i] = max(rmax[i + 1], query(R));
    	insert(R);
    }

    free(root);

    root = new trieNode();
    insert(0);
    vi lmax(n + 1, 0);
    R = a[0];
    lmax[0] = query(R);
    insert(R);
    rep(i, 1, n) {
    	R = R xor a[i];
    	lmax[i] = max(lmax[i - 1], query(R));
    	insert(R);
    }
    int ans = 0;
    rep(i, 0, n - 1) {
        ans = max(ans, lmax[i] + rmax[i + 1]);
    }


	cout << ans << endl;

    #ifndef ONLINE_JUDGE
          clock_t terminator_69 = clock();
          cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    #endif 
    return 0;
}