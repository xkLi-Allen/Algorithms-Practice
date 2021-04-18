#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int maxN = 5e6+5;//最长的名字长度，字符数
const int NUM = 30;//小写字母的个数
vector<vector<int>> trie(maxN, vector<int>(NUM));   // 第一维的大小怎么决定？ => 【第一维的大小就是整个trie 树中的节点数！！！】)
vector<int> End(NUM);                               //End[i]表示第i个节点是一个字符串的结束标记
vector<int> vis(NUM);                               //结束标记，判断是否同一字符串反复查找








void buildTrie(string input){
    int tot = 0,p = 0;  //tot表示节点个数;p 表示开始节点【p的含义是什么？ =》 当前正在判断的节点序号？】
    int cNum;           //char型字符串中单个字符-'a'得到的值【是个数字】
    p = 0;
    for (int i = 0; i < input.length(); i++){
        cNum = input[i] - 'a';
        if (!trie[p][cNum]){
            tot++;
            trie[p][cNum] = tot;
        }
        p = trie[p][cNum];
    }
    End[p] = 1;
    return;
}

void searchTrie(string target){
    int p = 0;
    int cNum;
    for (int i = 0; i < target.length(); i++){
        cNum = target[i] - 'a';
        if (trie[p][cNum]){
            p = trie[p][cNum];
        }
        else{
            cout << "ERROR!" << endl;
            return;
        }
    }
    if(End[p]){
        if(!vis[p]){
            cout << "FIND TARGET STRING!" << endl;
            vis[p]++;
        }
        else{
            cout << "REAPEAT FIND!" << endl;
        }
    }
    else{
        cout << "ERROR!" << endl; 
    }
    return;
}


int main(){
    cout << "Input create trie string" << endl;
    string input;
    cin >> input;
    buildTrie(input);

    cout << "Input find trie string" << endl;
    string target;
    cin >> target;
    searchTrie(target);
}