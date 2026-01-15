/*Max rectangle

You are given a 2D binary matrix mat[ ][ ], where each cell contains either 0 or 1. Your task is to find the maximum area of a rectangle that can be formed using only 1's within the matrix.

Examples:

Input: mat[][] = [[0, 1, 1, 0],
                [1, 1, 1, 1],
                [1, 1, 1, 1],
                [1, 1, 0, 0]]
Output: 8
Explanation: The largest rectangle with only 1’s is from (1, 0) to (2, 3) which is
[1, 1, 1, 1]
[1, 1, 1, 1]
and area is 4 * 2 = 8.

Input: mat[][] = [[0, 1, 1],
                [1, 1, 1],
                [0, 1, 1]]
Output: 6
Explanation: The largest rectangle with only 1’s is from (0, 1) to (2, 2) which is
[1, 1]
[1, 1]
[1, 1]
and area is 2 * 3 = 6.
Constraints:
1 ≤ mat.size(), mat[0].size() ≤1000
0 ≤ mat[][] ≤1*/

class Solution {
  public:
    vector<int> NSR(vector<int>&arr){
        int n=arr.size();
        vector<int>res(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()) res[i]=st.top();
            st.push(i);
        }
        return res;
    }
    
    vector<int> NSL(vector<int>&arr){
        int n=arr.size();
        vector<int>res(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&& arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()) res[i]=st.top();
            st.push(i);
        }
        return res;
    }
    
    int getMaxArea(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>nsr=NSR(arr);
        vector<int>nsl=NSL(arr);
        int maxArea=INT_MIN;
        for(int i=0;i<n;i++){
            int newArea=(nsr[i]-nsl[i]-1)*arr[i];
            maxArea=max(maxArea,newArea);
        }
        return maxArea;
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<int> currArr(m,0);
        for(int i=0;i<m;i++){
            if(mat[0][i]==1) currArr[i]=1;
        }
        int maxArea=getMaxArea(currArr);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) currArr[j]=0;
                else currArr[j]+=1;
            }
            int newArea=getMaxArea(currArr);
            maxArea=max(newArea,maxArea);
        }
        return maxArea;
    }
};