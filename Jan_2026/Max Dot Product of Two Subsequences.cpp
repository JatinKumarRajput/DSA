/*1458. Max Dot Product of Two Subsequences
Given two arrays nums1 and nums2.
Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.
A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

Example 1:
Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.*/

//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;
    int t[501][501];
    
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if(i == m || j == n)
            return -100000000;
        
        if(t[i][j] != -1e9)
            return t[i][j];
        
        int val = nums1[i] * nums2[j];
        
        int take_i_j = solve(nums1, nums2, i+1, j+1) + val;
        
        int take_i = solve(nums1, nums2, i, j+1);
        int take_j = solve(nums1, nums2, i+1, j);
        
        
        return t[i][j] = max({val, take_i_j, take_i, take_j});
        
        
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        
        for(int i = 0; i<501; i++) {
            for(int j = 0; j < 501; j++) {
                t[i][j] = -1e9;
            }
        }
        
        return solve(nums1, nums2, 0, 0);
    }
};