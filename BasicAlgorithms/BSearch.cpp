# include<iostream>
# include<vector>
using namespace std;

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
// 查找已递增排序数组A中 大于等于（或者大于） 给定target的 第一个 元素的下标
// 当eq_enable为true时  对应 [大于等于] 的情况
// 当eq_enable为false时 对应 [大于] 的情况
int Bsearch_GE_or_G(vector<int> input, int target, bool eq_enable){

    int left = 0;
    int right = input.size() - 1;
    int ans = input.size();
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (target < input[mid] || (eq_enable && target == input[mid])){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return ans;
}

// 查找已递增排序数组A中 小于等于（或者小于） 给定target的 最后一个 元素的下标
// 当eq_enable为true时  对应 [小于等于] 的情况
// 当eq_enable为false时 对应 [小于] 的情况

int Bsearch_LE_or_L(vector<int> input, int target, bool eq_enable){
    int left = 0;
    int right = input.size() - 1;
    int ans = input.size();
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (target > input[mid] || (eq_enable && target == input[mid])){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return ans;
    
}

int main(){
    vector<int> input = createVector();
    cout << "input target" << endl;
    int target;
    cin >> target;

    int answer1 = Bsearch_GE_or_G(input, target, true);
    int answer2 = Bsearch_LE_or_L(input, target, true);
    cout << "answer1: " << answer1 << endl;
    cout << "answer2: " << answer2 << endl;
}
