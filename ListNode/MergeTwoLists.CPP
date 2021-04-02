# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int val) : val(val), next(nullptr) {}
	ListNode(int val, ListNode* next) : val(val), next(next) {}
};

vector<int> createVector() {
	cout << "input Vector" << endl;
	char c;
	int temp;
	cin >> temp;
	vector<int> input;
	input.push_back(temp);
	while ((c = getchar()) != '\n') {
		cin >> temp;
		input.push_back(temp);
	}
	return input;
}

ListNode* createList() {
	vector<int> input = createVector();
	ListNode* head = new ListNode(input[0]);
	ListNode* end = head;
	for (int i = 1; i < input.size(); i++) {
		ListNode* temp = new ListNode(input[i]);
		end->next = temp;
		end = temp;
	}
	return head;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* preHead = new ListNode(-1);

    ListNode* prev = preHead;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }

    // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
    prev->next = l1 == nullptr ? l2 : l1;

    return preHead->next;
}

void showList(ListNode* head) {
	cout << "ListNode Value" << endl;
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {
	ListNode* l1 = createList();
	showList(l1);
	ListNode* l2 = createList();
	showList(l2);
	cout << "execute merge opeator" << endl;
	ListNode* ans = mergeTwoLists(l1, l2);
	showList(ans);
}