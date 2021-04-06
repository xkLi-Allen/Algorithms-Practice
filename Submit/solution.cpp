# include<iostream>
# include<vector>
# include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
	TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == nullptr) {
			return ans;
		}
		else {
			queue<TreeNode*> Q;
			Q.push(root);
			while (!Q.empty()) {
				vector<int> tempans;
				for (int i = 0; i < Q.size(); i++) {
					TreeNode* temp = Q.front();
					Q.pop();
					tempans.push_back(temp->val);
					if (temp->left) {
						Q.push(temp->left);
					}
					if (temp->right) {
						Q.push(temp->right);
					}

				}
				ans.push_back(tempans);
			}
		}
        return ans;

	}
};

vector<int> creatVector() {
	cout << "input vector value" << endl;
	vector<int> input;
	char c;
	int temp;
	cin >> temp;
	input.push_back(temp);
	while ((c = getchar()) != '\n') {
		cin >> temp;
		input.push_back(temp);
	}
	return input;
}

TreeNode* creatBTree() {
	vector<int> input = creatVector();
	TreeNode* root = new TreeNode;
	if (input[0] == -1) {
		return nullptr;
	}
	else {
		root->val = input[0];
		for (int i = 1; i < input.size(); i++) {
			TreeNode* newNode = new TreeNode(input[i]);
			TreeNode* currentTree = root;
			TreeNode* backTree = currentTree;
			while (currentTree) {
				backTree = currentTree;
				if (currentTree->val > input[i]) {
					currentTree = currentTree->left;
				}
				else {
					currentTree = currentTree->right;
				}
			}
			if (backTree->val > input[i]) {
				backTree->left = newNode;
			}
			else {
				backTree->right = newNode;
			}
		}
		return root;
	}

}

TreeNode* creatOrderBTree() {
	TreeNode* root = new TreeNode();
	vector<int> input = creatVector();
	queue<TreeNode*> tempQueue;
	int n = 0;
	int val = input[n++];
	if (val == -1) {
		return nullptr;
	}
	else {
		root->val = val;
		tempQueue.push(root);
	}
	while (!tempQueue.empty()) {
		TreeNode* temp = tempQueue.front();
		tempQueue.pop();
		val = input[n++];
		if (val == -1) {
			temp->left == nullptr;
		}
		else {
			temp->left = new TreeNode(val);
			tempQueue.push(temp->left);
		}
		val = input[n++];
		if (val == -1) {
			temp->right == nullptr;
		}
		else {
			temp->right = new TreeNode(val);
			tempQueue.push(temp->right);
		}
	}
	return root;

}

void printOrderBTree(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	else {
		queue<TreeNode*> tempQueue;
		tempQueue.push(root);
		while (!tempQueue.empty()) {
			TreeNode* temp = tempQueue.front();
			tempQueue.pop();
			cout << temp->val << " ";
			if (temp->left) {
				tempQueue.push(temp->left);
			}
			if (temp->right) {
				tempQueue.push(temp->right);
			}
		}
	}
	cout << endl;
	return;
}

void preOrder(TreeNode* root) {
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(TreeNode* root) {
	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}

void postOrder(TreeNode* root) {
	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << " ";

}
int main() {
	// vector<int> input = creatVector();
	// for (vector<int> :: iterator cur = input.begin(); cur != input.end(); cur++){
	//     cout << (*cur) << " ";
	// }

	TreeNode* root1 = creatOrderBTree();
	// TreeNode* root2 = creatBTree();
	printOrderBTree(root1);
	Solution solution;
	vector<vector<int>> answer = solution.levelOrder(root1);
	
}