/*1161. Maximum Level Sum of a Binary Tree
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

Example 1:
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.*/
//T.C.- O(n)
class Solution {
public:
    unordered_map<int,int>mp; //{level,sum}
    void solve(TreeNode* root,int level){
        if(root==NULL) return;
        if(mp.find(level)!=mp.end()){
            mp[level]=mp[level]+root->val;
        }
        else{
            mp[level]=root->val;
        }
        solve(root->left,level+1);
        solve(root->right,level+1);
    }
    int maxLevelSum(TreeNode* root) {
        solve(root,1);
        int maxi=INT_MIN;
        int level=1;
        for(auto &pair:mp){
            if(pair.second>maxi){
                maxi=pair.second;
                level=pair.first;
            }
            if(pair.second==maxi){
                level=min(level,pair.first);
            }
        }
        return level;
    }
};