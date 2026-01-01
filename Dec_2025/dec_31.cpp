/*1970. Last Day Where You Can Still Cross
There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.
Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).
You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).
Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.
Example 1:
Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
Output: 2
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.
Example 2:
Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
Output: 1
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.
 
Constraints:
2 <= row, col <= 2 * 104
4 <= row * col <= 2 * 104
cells.length == row * col
1 <= ri <= row
1 <= ci <= col
All the values of cells are unique.*/

// T.C.-> O(R×C×log(day.size()))​
class Solution {
public:
    int ROW;
    int COL;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool bfs(vector<vector<int>> &grid, int i, int j) {
        
        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = 1;
        
        while(!que.empty()) {
            
            auto temp = que.front();
            que.pop();
            
            int x = temp.first;
            int y = temp.second;
            
            if(x == ROW-1)
                return true;
            
            for(vector<int> & dir : directions) {
                
                int new_x = x + dir[0];
                int new_y = y + dir[1];
                
                if(new_x >= 0 && new_x < ROW && new_y >= 0 && new_y < COL && grid[new_x][new_y] == 0) {
                    que.push({new_x, new_y});
                    grid[new_x][new_y] = true;
                }
                
            }
            
        }
        
        return false;
    }
    
    bool canCross(vector<vector<int>>& cells, int day) {
        vector<vector<int>> grid(ROW, vector<int>(COL));
        
        for (int i = 0; i <= day; ++i) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            
            grid[r][c] = 1;
        }
        
        for (int j = 0; j < COL; j++) {
            if (grid[0][j] == 0 && bfs(grid, 0, j)) {
                return true;
            }
        }
        return false;
        
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROW = row;
        COL = col;
        
        int n = cells.size();
        
        int l = 0;
        int r = cells.size()-1;
        int lastDay = 0;
        
        while( l <= r) {
            
            int mid = l + (r-l)/2;
            
            if(canCross(cells, mid)) {
                lastDay = mid+1;
                l       = mid+1;
            } else {
                r = mid-1;
            }
            
        }
        
        return lastDay;
        
    }
};