# include<iostream>
# include<vector>
# include<queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr){}
	TreeNode(int val) : val(val), left(nullptr), right(nullptr){}
	TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right){}
};
vector<int> creatVector(){
	cout << "input vector elements" << endl;
	vector<int> input;
	char c;
	int temp;
	cin >> temp;
	input.push_back(temp);
	while ((c = getchar()) != '\n'){
		cin >> temp;
		input.push_back(temp);
	}
	return input;
}

void showVector(vector<int> input){
	cout << "show Vector result" << endl;
	for (vector<int> :: iterator cur = input.begin(); cur != input.end(); cur++){
		cout << (*cur) << " ";
	}
	cout << endl;
}

TreeNode* creatOrderBTree(){
	cout << "creatOrderBtree" << endl;
	vector<int> nodeValue = creatVector();
	showVector(nodeValue);
	int n = 0;
	TreeNode* root = new TreeNode(nodeValue[n++]);
	while(n != nodeValue.size()){
		TreeNode* currentTree = root;
		TreeNode* backTree = new TreeNode();
		int tempValue = nodeValue[n++];
		while(currentTree){
			backTree = currentTree;
			if (currentTree -> val > tempValue){
				currentTree = currentTree -> left;
			}
			else{
				currentTree = currentTree -> right;
			}
		}
		if (backTree -> val > tempValue){
			backTree -> left = new TreeNode(tempValue);
		}
		else{
			backTree -> right = new TreeNode(tempValue);
		}
	}
	return root;
}

int maxDepth(TreeNode* root){
	if (root == nullptr){
        return 0;
    }
    return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
}

void levelOrder(TreeNode* root){
	cout << "levelOrder result" << endl;
	if (root == nullptr){
		return;
	}
	queue<TreeNode*> Q;
	Q.push(root);
	while(!Q.empty()){
		TreeNode* tempNode = Q.front();
		Q.pop();
		cout << tempNode -> val << " ";
		if (tempNode -> left){
			Q.push(tempNode -> left);
		}
		if (tempNode -> right){
			Q.push(tempNode -> right);
		}
	}
	cout << endl;
	return;
}

TreeNode* creatLevelBTree(){
	cout << "creatLevelBTree" << endl;
	vector<int> nodeValue = creatVector();
	int n = 0;
	int tempValue = nodeValue[n++];
	if (tempValue == -1){
		return nullptr;
	}
	TreeNode* root = new TreeNode(tempValue);
	queue<TreeNode*> Q;
	Q.push(root);
	while(!Q.empty()){
		TreeNode* tempNode = Q.front();
		Q.pop();
		tempValue = nodeValue[n++];
		if (tempValue == -1){
			tempNode -> left == nullptr;
		}
		else{
			tempNode -> left = new TreeNode(tempValue);
			Q.push(tempNode -> left);
		}
		tempValue = nodeValue[n++];
		if (tempValue == -1){
			tempNode -> right == nullptr;
		}
		else{
			tempNode -> right = new TreeNode(tempValue);
			Q.push(tempNode -> right);
		}
	}
	return root;
}
void preOrder(TreeNode* root){
	if (root == nullptr){
		return;
	}
	cout << root -> val << " ";
	preOrder(root -> left);
	preOrder(root -> right);
}

void inOrder(TreeNode* root){
	if (root == nullptr){
		return;
	}
	inOrder(root -> left);
	cout << root -> val << " ";
	inOrder(root -> right);
}

void postOrder(TreeNode* root){
	if (root == nullptr){
		return;
	}
	postOrder(root -> left);
	postOrder(root -> right);
	cout << root -> val << " ";
}
int main(){
	// vector<int> input = creatVector();
	// showVector(input);
	TreeNode* root = creatLevelBTree();
	levelOrder(root);
	TreeNode* root1 = creatOrderBTree();
	levelOrder(root1);
}