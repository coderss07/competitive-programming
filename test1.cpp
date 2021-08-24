#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
	int n;
	cin>>n;
	string u_n[n];
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		u_n[i]=s;
	}
	int cnt=0;
	for(int i=0; i<n; i++){
		string s;
		s=u_n[i];
		int l=s.size();
		for(int j=0; j<l-1; j++){
			if(s[j] == 'c' && s[j+1] == 'h'){
				cnt++;
				break;
			}else if(s[j] == 'h' && s[j+1] == 'e'){
				cnt++;
				break;
			}else if(s[j] == 'e' && s[j+1] == 'f'){
				cnt++;
				break;
			}
		}
	}


	cout<< cnt <<endl;
	
	return 0;
}
