#include<bits/stdc++.h>

using namespace std;

class node{
	public:
		int data;
		node* lchild;
		node* rchild;
		node(int d){
			data=d;
			lchild=NULL;
			rchild=NULL;
		}
};

void findfunc(node* head, node* &par, node* &loc,int val){
	if(!head){
		par=NULL;
		loc=NULL;
		return;
	}
	if(head->data == val){
		par=NULL;
		loc=head;
		return;
	}
	node* ptr;
	node* parptr = head;
	if(val < head->data)
		ptr = head->lchild;
	else
		ptr = head->rchild;
	while(ptr){
		if(val == ptr->data){
			par = parptr;
			loc = ptr;
			return;
		}
		parptr = ptr;
		if(val < ptr->data){
			ptr = ptr->lchild;
		}else{
			ptr = ptr->rchild;
		}

	}
	par = parptr;
	loc =NULL;

}

void delcase1(node* &head, node* &par, node* &loc){
	if(!par){
		head=NULL;
	}else if(par->lchild == loc){
		par->lchild=NULL;
	}else{
		par->rchild=NULL;
	}
}

void delcase2(node* &head,node* &par, node* &loc){
	node* child;
	if(loc->lchild)
		child=loc->lchild;
	else
		child=loc->rchild;
	if(!par){
		head=child;
	}else if(loc == par->lchild){
		par->lchild=child;
	}else{
		par->rchild=child;
	}
	
}

void delcase3(node* &head,node* &par, node* &loc){
	node* succ;
	node* parsucc=loc;
	succ=loc->rchild;
	while(succ->lchild){
		parsucc=succ;
		succ=succ->lchild;

	}
	if(!succ->lchild && !succ->rchild){
		delcase1(head,parsucc,succ);
	}else{
		delcase2(head,parsucc,succ);
	}
	if(par == NULL){
		head=succ;
	}else if(loc == par->lchild){
		par->lchild=succ;
	}else{
		par->rchild=succ;
	}
	succ->lchild=loc->lchild;
	succ->rchild=loc->rchild;
	
}

void deletNode(node* &head, int value){
	if(head == NULL){
		return;
	}
	node* par=NULL;
	node* loc=NULL;
	findfunc(head, par, loc, value);
	if(!loc){
		cout<< "Item Not Present..." <<endl;
		return;
	}
	
	if(!loc->lchild && !loc->rchild){
		delcase1(head,par,loc);
		
	}else if(loc->lchild && !loc->rchild ){
		delcase2(head,par,loc);
		
	}else if(!loc->lchild && loc->rchild){
		delcase2(head,par,loc);
		
	}else{
		delcase3(head,par,loc);
		
	}
	delete loc;
}

void insert(node* &head,int data){
	node* par=NULL;
	node* loc=NULL;
	findfunc(head, par, loc, data);
	if(loc){
		cout<< "Item Already Present..." <<endl;
		return;
	}
	node* n = new node(data);
	if(par  == NULL){
		head = n;
		return;	
	}
	if(data < par->data){
		par->lchild=n;
	}else{
		par->rchild=n;
	}
}

void inorder(node* head){
	if(head){
		inorder(head->lchild);
		cout<< head->data << "->";
		inorder(head->rchild);
	}
}

void preorder(node* head){
	if(head){
		cout<< head->data << "->";
		preorder(head->lchild);
		preorder(head->rchild);
	}
}

void postorder(node* head){
	if(head){
		postorder(head->lchild);
		postorder(head->rchild);
		cout<< head->data << "->";
	}

}

int levelSum(node* head, int k){
	queue<node*> q;
	q.push(head);
	q.push(NULL);
	int cnt=0;
	int sum=0;
	while(!q.empty()){
		node* n = q.front();
		q.pop();
		if(n!=NULL){
			if(cnt == k) sum+=n->data;
			if(n->lchild){
				q.push(n->lchild);
			}
			if(n->rchild){
				q.push(n->rchild);
			}
		}else if(!q.empty()){
			q.push(NULL);
			cnt++;
		}
	}
	return sum;
}

void levelOrder(node* head){
	queue<node*> q;
	q.push(head);
	q.push(NULL);
	while(!q.empty()){
		node* n = q.front();
		q.pop();
		if(n!=NULL){
			cout<< n->data << " ";
			if(n->lchild){
				q.push(n->lchild);
			}
			if(n->rchild){
				q.push(n->rchild);
			}
		}else if(!q.empty()){
			q.push(NULL);
		}
	}
}

vector<int> rightView(node* head){
	vector<int> v;
	queue<node*> q;
	q.push(head);
	q.push(NULL);
	while(!q.empty()){
		node* n = q.front();
		q.pop();
		if(n!=NULL){
			if(q.front() == NULL){
				v.push_back(n->data);
			}
			if(n->lchild){
				q.push(n->lchild);
			}
			if(n->rchild){
				q.push(n->rchild);
			}
		}else if(!q.empty()){
			q.push(NULL);
		}
	}
	return v;
}

vector<int> leftView(node* head){
	vector<int> v;
	queue<node*> q;
	q.push(head);
	q.push(NULL);
	v.push_back(head->data);
	while(!q.empty()){
		node* n = q.front();
		q.pop();
		if(n!=NULL){
			if(n->lchild){
				q.push(n->lchild);
			}
			if(n->rchild){
				q.push(n->rchild);
			}
		}else if(!q.empty()){
			v.push_back(q.front()->data);
			q.push(NULL);
		}
	}
	return v;
}

node* LCA(node* head,int n1,int n2){
	if(head == NULL){
		return NULL;
	}
	if(head->data == n1 || head->data == n2){
		return head;
	}
	node* l=LCA(head->lchild, n1, n2);
	node* r=LCA(head->rchild, n1, n2);
	if(l && r){
		return head;
	}
	if(l){
		return l;
	}
	if(r){
		return r;
	}
	return NULL;
}

int Dist(node* head,int k,int des=0){
	if(head == NULL){
		return -1;
	}

	if(head->data == k){
		return des;
	}
	int l=Dist(head->lchild,k,des+1);
	if(l != -1){
		return l;
	}
	return Dist(head->rchild,k,des+1);
}

int shortestDistance(node* head, int n1, int n2){
	node* lca = LCA(head,n1,n2);
	if(lca == NULL){
		return -1;
	}
	return (Dist(lca,n1) + Dist(lca,n2));
}

int height(node* head){
	if(head -> lchild == NULL && head -> rchild == NULL){
		return 0;
	}
	return (max(height(head->lchild),height(head->rchild))+1);
}

bool isBalanced(node* head,int &h){
	if(head == NULL){
		h=0;
		return true;
	}
	int lh=0,rh=0;
	if(isBalanced(head->lchild,lh) && isBalanced(head->rchild,rh)){
		if(abs(lh-rh) <= 1){
			h = max(lh, rh) + 1;
			return true;
		}
	}
	return false;
}

int diameter(node* head, int &h){
	if(head == NULL){
		h=0;
		return 0;
	}
	int lh = 0, rh = 0;
	int ldia=diameter(head->lchild, lh);
	int rdia=diameter(head->rchild, rh);

	int curr = lh+rh+1;
	h=max(lh,rh)+1;
	return max(curr, max(ldia, rdia) );
}

void sumReplacement(node* &head){
	if(head == NULL){
		return;
	}
	sumReplacement(head->rchild);
	sumReplacement(head->lchild);
	if(head->lchild)
		head->data += (head->lchild->data);
	if(head->rchild)
		head->data += (head->rchild->data);
}

// int leftHeight(node* head){
// 	if(head == NULL){
// 		return 0;
// 	}
// 	return leftHeight(head->lchild)+1;
// }

// int rightHeight(node* head){
// 	if(head == NULL){
// 		return 0;
// 	}
// 	return rightHeight(head->rchild)+1;
// }

// int diameter(node* head){
// 	if(head == NULL){
// 		return 0;
// 	}

// 	return max((leftHeight(head->lchild)+rightHeight(head->rchild)+1) , max(diameter(head->lchild),diameter(head->rchild)));
// }

int sumOfNodes(node* head){
	if(head == NULL){
		return 0;
	}
	return (sumOfNodes(head->lchild)+sumOfNodes(head->rchild)+head->data);
}

int nodeCount(node* head){
	if(head == NULL){
		return 0;
	}
	return (nodeCount(head->lchild)+nodeCount(head->rchild)+1);
}

void flattenTree(node* &head){
	if(head == NULL || (head->lchild == NULL && head->rchild == NULL)){
		return;
	}

	node* temp = head->rchild;
	if(head->lchild){
		flattenTree(head->lchild);

		head->rchild = head->lchild;
		head->lchild = NULL;
		node* ptr = head->rchild;
		while(ptr->rchild != NULL){
			ptr = ptr->rchild;
		}
		ptr->rchild = temp;
	}
	flattenTree(temp);
}

void display(node* ptr){
	if(ptr == NULL){
		cout<<"NULL"<<endl;
		return;
	}
	cout<<ptr->data<<"->";
	display(ptr->rchild);
}

void printNode(node* head, int k){
	if(head == NULL || k<0){
		return;
	}
	if(k == 0){
		cout<< head->data<<" ";
		return;
	}
	printNode(head->lchild, k-1);
	printNode(head->rchild, k-1);
}

int printAtdistk(node* head, node* &tar, int k){

	if(head == NULL){
		return -1;
	}
	if(head == tar){
		printNode(head,k);
		return 0;
	}
	int dl=printAtdistk(head->lchild, tar, k);
	if(dl != -1){
		if(dl + 1 == k){
			cout<< head->data << " ";
		}else{
			printNode(head->rchild,k-dl-2);
		}
		return dl+1;
	}
	int dr=printAtdistk(head->rchild, tar, k);
	if(dr != -1){
		if(dr + 1 == k){
			cout<< head->data << " ";
		}else{
			printNode(head->lchild,k-dr-2);
		}
		return dr+1;
	}
	return -1;
}

int maxSumPath(node* head,int& ans) {
	if(head == NULL){
		return 0;
	}
	int l_sum = maxSumPath(head->lchild, ans);
	int r_sum = maxSumPath(head->rchild, ans);
	int m = max( max(l_sum+head->data, r_sum+head->data), max(head->data, l_sum+r_sum+head->data) );
	ans = max(ans, m);
	return max(head->data, max(l_sum+head->data, r_sum+head->data));
}

int maxPathSum(node* head) {
	int ans = INT_MIN;
	maxSumPath(head, ans);
	return ans;
}

void zigzagTraversal(node* head){
	stack<node*> curr_lev;
	stack<node*> nxt_lev;
	curr_lev.push(head);
	bool right = true;
	while(!curr_lev.empty()){
		node* n=curr_lev.top();
		curr_lev.pop();
		if(n){
			cout<< n->data << " ";
			if(right){
				if(n->lchild) nxt_lev.push(n->lchild);
				if(n->rchild) nxt_lev.push(n->rchild);
			}else{
				if(n->rchild) nxt_lev.push(n->rchild);
				if(n->lchild) nxt_lev.push(n->lchild);
			}
		}
		if(curr_lev.empty()){
			right = !right;
			swap(curr_lev, nxt_lev);
		}
	}
}

bool search(node* head, int item){
	if(head == NULL){
		return false;
	}
	if(head->data == item){
		return true;
	}else if(item < head->data){
		return search(head->lchild, item);
	}else{
		return search(head->rchild, item);
	}
}

bool isIdentical(node* h1, node* h2){
	if(!h1 && !h2){
		return true;
	}
	if((h1 && h2) && (h1->data == h2->data)){
		if(isIdentical(h1->lchild,h2->lchild) && isIdentical(h1->rchild,h2->rchild)){
			return true;
		}
	}
	return false;
}

struct info{

	int min;
	int max;
	int ans;
	int size;
	bool isBST;

};

info largestBST(node* head){
	if(head == NULL){
		return {0, INT_MAX, INT_MIN, 0, true};
	}
	if(!head->lchild && !head->rchild){
		return {head->data, head->data, 1, 1, true};
	}
	info linfo = largestBST(head->lchild);
	info rinfo = largestBST(head->rchild);
	info par;
	par.size = (1 + linfo.size + rinfo.size);

	if((linfo.isBST && rinfo.isBST) && head->data > linfo.max && head->data < rinfo.min){
		par.min = min( min(linfo.min, rinfo.min), head->data );
		par.max = max( max(linfo.max, rinfo.max), head->data );
		par.ans = par.size;
		par.isBST = true;
		return par;
	}

	par.ans = max(linfo.ans, rinfo.ans);
	par.isBST = false;
	return par;
}

void calc(node* head, node* &f, node* &m, node* &l, node* &p) {
	if(!head) {
		return;
	}

	calc(head->lchild,f,m,l,p);
	if(p && p->data > head->data) {
		if(!f) {
			f = p;
			m = head;
		}else {
			l = head;
		}
	}
	p = head;
	calc(head->rchild,f,m,l,p);
}

void recoverBST(node* head) {
	node *f = NULL;
	node *m = NULL;
	node *l = NULL;
	node *p = NULL;

	calc(head, f, m, l, p);

	if(f && l) {
		swap(f->data, l->data);
	}else if(f && m) {
		swap(f->data, m->data);
	}
}

void verticalOrderprint(node* head, map<int, vector<int>> &m, int h = 0) {
	if(head == NULL) {
		return;
	}

	m[h].push_back(head->data);
	verticalOrderprint(head->lchild,m,h-1);
	verticalOrderprint(head->rchild,m,h+1);
}

int main() {
	node* head = NULL;
	insert(head, 6);
	insert(head, 4);
	insert(head, 2);
	insert(head, 5);
	insert(head, 1);
	insert(head, 3);
	insert(head, 10);
	insert(head, 8);
	insert(head, 9);
	insert(head, 7);
	insert(head, 12);
	insert(head, 13);
	insert(head, 11);
	/*
	     6
	   /   \
	 4      10
	/ \	   /  \
   2   5  8    12
  / \	 / \  /  \
1	 3	7	9 11  13
*/

	map<int, vector<int> > mp;
	verticalOrderprint(head, mp);
	for(auto &it : mp) {
		for(int i=0; i<(it.second).size(); i++) {
			cout<<(it.second)[i]<<" ";
		}
	}cout<<endl;

	// node* head1 = NULL;
	// insert(head1, 6);
	// insert(head1, 4);
	// insert(head1, 2);
	// insert(head1, 5);
	// insert(head1, 1);
	// insert(head1, 3);
	// insert(head1, 10);
	// insert(head1, 8);
	// insert(head1, 9);
	// insert(head1, 7);
	// insert(head1, 12);
	// insert(head1, 13);
	// insert(head1, 11);

	// swap(head->rchild->data, head->lchild->lchild->data);
	// swap(head->rchild->lchild->data, head->lchild->data);
	// inorder(head);
	// cout<<endl;
	// recoverBST(head);
	// recoverBST(head);
	// inorder(head);
	// cout<<endl;

	// cout<< largestBST(head).ans <<endl;

	// cout<< (isIdentical(head, head1)?"Identical":"Not Identical")<<endl;

	// zigzagTraversal(head);
	// cout<<endl;

	// cout<< search(head, 9) << endl;
	// cout<< maxPathSum(head) << endl;

	// printAtdistk(head, head->rchild, 2);

	// node* n = LCA(head, 9,7);
	// cout<< n->data << endl;

	// flattenTree(head);
	// display(head);
	// inorder(head);

	// vector<int> v = rightView(head);
	// for(auto &i: v){
	// 	cout<< i << " ";
	// }cout<<endl;

	// vector<int> v = leftView(head);
	// for(auto &i: v){
	// 	cout<< i << " ";
	// }cout<<endl;

	// cout<< shortestDistance(head,1,6) << endl;

	// levelOrder(head);

	// preorder(head);

	// cout<< levelSum(head, 4) <<endl;

	// cout<< l_sum <<endl;

	// cout<< nodeCount(head) <<endl;

	// cout<< sumOfNodes(head) <<endl;

	cout<< height(head) <<endl;

	// cout<< diameter(head) <<endl;

	// int h=0;
	// cout<< diameter(head,h) <<endl;
	// inorder(head);
	// cout<<endl;

	// sumReplacement(head);

	// inorder(head);
	// cout<<endl;

	// h=0
	// cout<<(isBalanced(head,h) ? "Yes" : "No")<<endl;

	// postorder(head);
	// cout<<endl;

	// deletNode(head, 3);
	return 0;
}
