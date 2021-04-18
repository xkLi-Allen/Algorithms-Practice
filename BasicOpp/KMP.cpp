#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> getNext(string target){
    vector<int> nextVector(100);
    nextVector[0] = -1;
    int length = target.length();
    int location = 0;
    int tempValue = -1;
    while (location < length){
        if (tempValue == -1 || target[location] == target[tempValue]){
            location++;
            tempValue++;
            nextVector[location] = tempValue;
        }
        else{
            tempValue = nextVector[tempValue];
        }
    }
    return nextVector;

}

vector<int> KMP(string input, string target){
    vector<int> nextVector = getNext(target);
    vector<int> ans;
    int length1 = input.length();
    int length2 = target.length();
    int i = 0;
    int j = 0;
    while(i < length1){
        if (j == -1 || input[i] == target[j]){
            i++;
            j++;
        }
        else{
            j = nextVector[j];
        }
        if (j == length2){
            ans.push_back(i - length2 + 1);
            j = 0;
        }
    }


    return ans;
}


int main(){
    string input, target;
    cout << "input original string" << endl;
    cin >> input;
    cout << "input target string" << endl;
    cin >> target;
    vector<int> ans = KMP(input, target);

    for (vector<int> :: iterator cur = ans.begin(); cur != ans.end(); cur++){
        cout << (*cur) << " ";
    }

}
