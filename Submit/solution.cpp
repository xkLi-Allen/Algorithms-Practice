# include<iostream>
# include<vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        string ans;
        for (int length = 0; length < s.size(); length++){
            for (int i = 0; i + length < s.size(); i++){
                int j = i + length;
                if (length == 0){
                    dp[i][j] = 1;
                }
                else if (length == 1){
                    dp[i][j] = (s[i] == s[j]);
                }
                else{
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && length + 1 > ans.size()){
                    ans = s.substr(i, length+1);
                }
            }
        }
        return ans;

    }
};
int main(){
    cout << "inut string value" << endl;
    string input;
    cin >> input;
    Solution solution;
    string ans = solution.longestPalindrome(input);
    cout << ans << endl;
}