/*Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.
Example 1:
Input: nums = [21,4,7]
Output: 32
Explanation: 
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.

Example 2:
Input: nums = [21,21]
Output: 64
Example 3:

Input: nums = [1,2,3,4,5]
Output: 0
 
Constraints:
1 <= nums.length <= 104
1 <= nums[i] <= 105*/

//T.C. - O(n*sqrt(n))

class Solution {
public:
    int get_div_sum(int n){
        vector<int> divisors;
        divisors.push_back(1);
        divisors.push_back(n);
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                divisors.push_back(i);
                if((n/i)!=i) divisors.push_back(n/i);
            }
        }
        int sum=0;
        if(divisors.size()==4){
            for(int i=0;i<4;i++){
                sum+=divisors[i];
            }
        }
        return sum;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=get_div_sum(nums[i]);
        }
        return sum;
    }
};