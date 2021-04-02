# include<iostream>
# include<vector>
using namespace std;


struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int val) : val(val), next(nullptr){}
    ListNode(int val, ListNode* next) : val(val), next(next){}
};

int getListLength(ListNode* head){
    if (head == nullptr){
        return 0;
    }
    int n = 0;
    while(head){
        n++;
        head = head -> next;
    }
    return n;
}

vector<int> createVector(){
    cout << "input Vector" << endl;
    char c;
    int temp;
    cin >> temp;
    vector<int> input;
    input.push_back(temp);
    while((c = getchar()) != '\n'){
        cin >> temp;
        input.push_back(temp);
    }
    return input;
}

ListNode* createList(){
    vector<int> input = createVector();
    ListNode* head = new ListNode(input[0]);
    ListNode* end = head;
    for (int i = 1; i < input.size(); i++){
        ListNode* temp = new ListNode(input[i]);
        end -> next = temp;
        end = temp;
    }
    return head;
}

void showList(ListNode* head){
    cout << "ListNode Value" << endl;
    while(head){
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}

ListNode* addNode(ListNode* head){
    cout << "execute add ListNode..." << endl;
    int position;
    int value;
    cout << "input add position" << endl;
    cin >> position;
    if (position > getListLength(head)){
        cout << "ERROR!" << endl;
        return head;
    }
    cout << "input add value" << endl; 
    cin >> value;
    ListNode* end = head;
    for (int i = 1; i < position; i++){
        end = end -> next;
    }
    ListNode* temp = new ListNode(value, end -> next);
    end -> next = temp;
    end = temp;
    return head;
}

ListNode* deleteNode(ListNode* head){
    cout << "execute delete ListNode..." << endl;
    int position;
    cout << "input delete position" << endl;
    cin >> position;
    if (position > getListLength(head)){
        cout << "ERROR!" << endl;
        return head;
    }
    ListNode* end = head;
    if (position == 1){
        head = head -> next;
        return head;
    }
    ListNode* pre = new ListNode();
    for (int i = 1; i < position; i++){
        pre = end;
        end = end -> next;
    }
    pre -> next = end -> next;
    delete(end);
    return head;
}

ListNode* deleteFromEndNode(ListNode* head){
    cout << "execute delete ListNode" << endl;
    int position;
    cout << "input delete position" << endl;
    cin >> position;
    int length = getListLength(head);
    if (position > length){
        cout << "ERROR!" << endl;
        return head;
    }
    if (length == 0){
        return nullptr;
    }
    ListNode* end = head;
    ListNode* pre = end;
    if (position == length){
        head = head -> next;
        return head;
    }
    for (int i = 0; i < length - position; i++){
        pre = end;
        end = end -> next;
    }
    pre -> next = end -> next;
    delete(end);
    return head;
}
int main(){
    ListNode* head = createList();
    showList(head);
    head = addNode(head);
    showList(head);
    head = deleteNode(head);
    showList(head);
    head = deleteFromEndNode(head);
    showList(head);
}