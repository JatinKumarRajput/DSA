/*1351. Count Negative Numbers in a Sorted Matrix
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

Example 1:
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:
Input: grid = [[3,2],[1,0]]
Output: 0
 
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100*/
class Solution {
public:
    //Brute O(m*n)
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]<0) count++;
            }
        }
        return count;
    }
};

//Approach-2 (Using Binary Search - upper_bound) O(m * log(n))
//m = rows
//n = columns
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int result = 0;
        
        for(auto &vec : grid) {
            
            int idx = upper_bound(begin(vec), end(vec), 0, greater<int>()) - begin(vec);// it will find the just next element less than zero
            
            result += n-idx;
            
        }
        
        return result;
    }
};

//Approach-3 (Using the sorted proprrty) - O(m+n)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int row = m-1;
        int col = 0;
        
        int result = 0;
        while( row >= 0 && col < n) {
            
            if(grid[row][col] < 0) {
                result += n-col;
                row--;
            } else {
                col++;
            }
        }
        
        return result;
    }
};