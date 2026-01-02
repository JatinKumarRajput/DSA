/*2341. Maximum Number of Pairs in Array

You are given a 0-indexed integer array nums. In one operation, you may do the following:
Choose two integers in nums that are equal.
Remove both integers from nums, forming a pair.
The operation is done on nums as many times as possible.
Return a 0-indexed integer array answer of size 2 where answer[0] is the number of pairs that are formed and answer[1] is the number of leftover integers in nums after doing the operation as many times as possible.
Example 1:
Input: nums = [1,3,2,1,3,2,2]
Output: [3,1]
Explanation:
Form a pair with nums[0] and nums[3] and remove them from nums. Now, nums = [3,2,3,2,2].
Form a pair with nums[0] and nums[2] and remove them from nums. Now, nums = [2,2,2].
Form a pair with nums[0] and nums[1] and remove them from nums. Now, nums = [2].
No more pairs can be formed. A total of 3 pairs have been formed, and there is 1 number leftover in nums.*/

//Approach- hashmap
//T.C.-O(n)

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto num:nums){
            mp[num]++;
        }
        int pair=0;
        int left_int=0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            pair+= it->second/2;
            left_int+= it->second%2;
        }
        vector<int> ans;
        ans.push_back(pair);
        ans.push_back(left_int);
        return ans;
    }
};