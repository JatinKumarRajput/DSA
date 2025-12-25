/*
3075. Maximize Happiness of Selected Children

You are given an array happiness of length n, and a positive integer k.

There are n children standing in a queue, where the ith child has happiness value happiness[i]. You want to select k children from these n children in k turns.

In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.

Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.
Example 1:
Input: happiness = [1,2,3], k = 2
Output: 4
Explanation: We can pick 2 children in the following way:
- Pick the child with the happiness value == 3. The happiness value of the remaining children becomes [0,1].
- Pick the child with the happiness value == 1. The happiness value of the remaining child becomes [0]. Note that the happiness value cannot become less than 0.
The sum of the happiness values of the selected children is 3 + 1 = 4.

Example 2:
Input: happiness = [1,1,1,1], k = 2
Output: 1
Explanation: We can pick 2 children in the following way:
- Pick any child with the happiness value == 1. The happiness value of the remaining children becomes [0,0,0].
- Pick the child with the happiness value == 0. The happiness value of the remaining child becomes [0,0].
The sum of the happiness values of the selected children is 1 + 0 = 1.
*/

// Brute-> O(n^2)
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        brute 
        long long sum=0;
        int n=happiness.size();
        for(int i=0;i<k;i++){
            //int maxi=*max_element(happiness.begin(),happiness.end());
            int maxi=INT_MIN;
            int max_ind=0;
            for( int j=0;j<n;j++){
                if(maxi<happiness[j]){
                    maxi=happiness[j];
                    max_ind=j;
                }
            }
            happiness[max_ind]=0;
            sum+= 1LL * maxi;
            for(int j=0;j<n;j++){
                if(happiness[j]!=0){
                    happiness[j]--;
                }
            }
        }
        return sum;
    }
}

// Optimal-> O(n+klogn)
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum=0;
        int n=happiness.size();
        priority_queue<int> pq(happiness.begin(),happiness.end());
        int counter=0;
        while(counter<k){
            int a=pq.top();
            pq.pop();
            if(a-counter>=0){
                sum+=1LL * (a-counter);
            }
            counter++;
        }
        return sum;
    }
};