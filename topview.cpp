#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
    void top(Node* root, map<int, int> &m, int h = 0) {
        if(root) {
            if(m[h] == 0) {
                m[h] = root->data;
            }
            top(root->left, m, h - 1);
            top(root->right, m, h + 1);
        }
    }

    void topView(Node * root) {
        map<int, int> m;
        top(root, m);
        for(auto &it: m) {
            cout << it.second << " ";
        }   cout << endl;  
    }

}; //End of Solution

void verticalOrderprint(Node* head, map<int, vector<int>> &m, int h = 0) {
	if(head == NULL) {
		return;
	}

	m[h].push_back(head->data);
	verticalOrderprint(head->left, m, h - 1);
	verticalOrderprint(head->right, m, h + 1);
}

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	// myTree.topView(root);
    map<int, vector<int> > mp;
	verticalOrderprint(root, mp);
	for(auto &it : mp) {
		for(int i = 0; i < (it.second).size(); i++) {
			cout << (it.second)[i] << " ";
		}cout << endl;
	}cout << endl;
    return 0;
}