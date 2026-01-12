/*Minimum ASCII Delete Sum for Two Strings
Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

Example 2:
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
 
Constraints:
1 <= s1.length, s2.length <= 1000
s1 and s2 consist of lowercase English letters.*/
class Solution {
public:
    int solve(string&s1,string&s2,int i,int j,vector<vector<int>>&dp){
        if(i>=s1.size() && j>=s2.size()){
            return dp[i][j]=0;
        }
        if(i>=s1.size()){
            return dp[i][j]=s2[j]+solve(s1,s2,i,j+1,dp);
        }
        if(j>=s2.size()){
            return dp[i][j]=s1[i]+solve(s1,s2,i+1,j,dp);
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=0+solve(s1,s2,i+1,j+1,dp);
        int del_i=s1[i]+solve(s1,s2,i+1,j,dp);
        int del_j=s2[j]+solve(s1,s2,i,j+1,dp);
        return dp[i][j]=min(del_i,del_j);
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,0,0,dp);
    }
};