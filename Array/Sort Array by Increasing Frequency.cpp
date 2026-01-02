/*1636. Sort Array by Increasing Frequency
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
Return the sorted array.

Example 1:
Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:
Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.*/

//complexity- O(n + k log k) time and O(n) space,
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto num:nums){
            mp[num]++;
        }
        struct cmp {
            bool operator()(const pair<int,int>& a,
                        const pair<int,int>& b) {
                if (a.first == b.first)
                    return a.second < b.second; // larger second at top
                return a.first > b.first;       // smaller first at top
            }
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            pq.push({it->second,it->first});
        }
        vector<int> ans;
        while(!pq.empty()){
            auto p=pq.top();
            int a=p.first;
            int b=p.second;
            pq.pop();
            while(a--){
                ans.push_back(b);
            }
        }
        return ans;
    }
};