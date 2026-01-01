/*66. Plus One
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
*/
//T.C.-> O(n)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int ne=digits[n-1]+1; //ne->new element
        int carry=ne/10;    
        int re=ne%10;   //re->remainder
        vector<int>ans;
        ans.push_back(re);
        for(int i=n-2;i>=0;i--){
            int new_ele=digits[i]+carry;
            carry=new_ele/10;
            int rem=new_ele%10;
            ans.push_back(rem);
        }
        if(carry){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
