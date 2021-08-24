#include<bits/stdc++.h>
#define ll long long int

using namespace std;

priority_queue<int, vector<int> > maxheap;
priority_queue<int, vector<int>, greater<int> > minheap;

void Insert(int x) {
	if(maxheap.size() == minheap.size()) {
		if(maxheap.size() == 0) {
			maxheap.push(x);
			return;
		}
		if(x < maxheap.top()) {
			maxheap.push(x);                                                               
			return;
		}else {
			minheap.push(x);
			return;
		}
	}else if(maxheap.size() > minheap.size()) {
		if(x >= maxheap.top())  minheap.push(x);
		else {
			int temp = maxheap.top();
			maxheap.pop();
			minheap.push(temp);
			maxheap.push(x);
		}
	}else {
		if(x <= minheap.top())  maxheap.push(x);
		else {
			int temp = minheap.top();
			minheap.pop();
			maxheap.push(temp);
			minheap.push(x);
		}
	}
}

float median() {
	if(maxheap.size() == minheap.size()) {
		return (maxheap.top() + minheap.top()) / 2;
	}else if(maxheap.size() > minheap.size()) {
		return maxheap.top();
	}else {
		return minheap.top();
	}
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	int marks = 0;
	int i;
	for (i = 0; i < n; ++i) {
		Insert(a[i]);
		cout<< median() <<" ";
	}cout<<endl;
	return 0;

}
