# include<iostream>
# include<vector>
# include<queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};
TreeNode* creatBTree(vector<int> data){
    int val;
    int n = 0;
    val = data[n++];
    queue<TreeNode*> Q;
    TreeNode* root = new TreeNode();
    if (val == -1){
        return nullptr;
    }
    else{
        root -> val = val;
        Q.push(root);
    }
    while(!Q.empty()){
        TreeNode* temp = Q.front();
        Q.pop();
        val = data[n++];
        if (val == -1){
            temp -> left = nullptr;
        }
        else{
            temp -> left = new TreeNode(val);
            Q.push(temp -> left);
        }
        val = data[n++];
        if (val == -1){
            temp -> right = nullptr;
        }
        else{
            temp -> right = new TreeNode(val);
            Q.push(temp -> right);
        }
    }
    return root;
}
void creatOrderBTree(int data, TreeNode* root){
    TreeNode* newNode = new TreeNode(data);
    if (root == nullptr){
        root = newNode;
    } 
    else{
        TreeNode* currentTree = root;
        TreeNode* backTree = nullptr;
        while(currentTree != nullptr){
            backTree = currentTree;
            if (currentTree -> val > data){
                currentTree = currentTree -> left;
            }
            else{
                currentTree = currentTree -> right;
            }
        }
        if (backTree -> val > data){
            backTree -> left = newNode;
        }
        else{
            backTree -> right = newNode;
        }
    }
}

vector<int> creatVector(){
    cout << "input Vector elements" << endl;
    vector<int> input;
    char c;
    int temp;
    cin >> temp;
    input.push_back(temp);
    while((c = getchar()) != '\n'){
        cin >> temp;
        input.push_back(temp);
    }
    return input;
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
void showOrderBTree(TreeNode* root){
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        TreeNode* temp = Q.front();
        Q.pop();
        cout << temp -> val << " ";
        if (temp -> left){
            Q.push(temp -> left);
        }
        if (temp -> right){
            Q.push(temp -> right);
        }
    }
}

void showBTree(TreeNode *root){
    cout << "preOrder result: " << endl;
    preOrder(root);
    cout << endl;
    cout << "inOrder result: " << endl;
    inOrder(root);
    cout << endl;
    cout << "postOrder result: " << endl;
    postOrder(root);
    cout << endl;
    cout << "Order result: " << endl;
    showOrderBTree(root);
    cout << endl;
    cout << "------------------------------------------------------------------" << endl;
}
int maxDepth(TreeNode* root){
    if (root == nullptr){
        return 0;
    }
    return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
}
int main(){
    vector<int> input1 = creatVector();
    TreeNode* root1 = new TreeNode(input1[0]);
    for (int i = 1; i < input1.size(); i++){
        creatOrderBTree(input1[i], root1);
    }
    cout << "Tree1 maxDepth: " << maxDepth(root1) << endl;
    showBTree(root1);
    vector<int> input2 = creatVector();
    TreeNode* root2 = creatBTree(input2);
    cout << "Tree2 maxDepth: " << maxDepth(root2) << endl;
    showBTree(root2);
}