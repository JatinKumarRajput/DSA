/*2943. Maximize Area of Square Hole in Grid

You are given the two integers, n and m and two integer arrays, hBars and vBars. The grid has n + 2 horizontal and m + 2 vertical bars, creating 1 x 1 unit cells. The bars are indexed starting from 1.
You can remove some of the bars in hBars from horizontal bars and some of the bars in vBars from vertical bars. Note that other bars are fixed and cannot be removed.
Return an integer denoting the maximum area of a square-shaped hole in the grid, after removing some bars (possibly none).

Example 1:
Input: n = 2, m = 1, hBars = [2,3], vBars = [2]

Output: 4

Explanation:
The left image shows the initial grid formed by the bars. The horizontal bars are [1,2,3,4], and the vertical bars are [1,2,3].
One way to get the maximum square-shaped hole is by removing horizontal bar 2 and vertical bar 2.

Example 2:
Input: n = 1, m = 1, hBars = [2], vBars = [2]
Output: 4

Explanation:
To get the maximum square-shaped hole, we remove horizontal bar 2 and vertical bar 2.

Example 3:
nput: n = 2, m = 3, hBars = [2,3], vBars = [2,4]
Output: 4

Explanation:
One way to get the maximum square-shaped hole is by removing horizontal bar 3, and vertical bar 4.*/

//Approach (Sort and process)
//T.C : O(vlogv + hlogh), v = vBars.size(), h = hBars.size()
//S.C : O(1)
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        //1st Step : Sort the inputs
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));

        int maxConsecutiveHBars = 1; //Length of Longest consecutive horizontal bars
        int maxConsecutiveVBars = 1; //Length of Longest consecutive Vertical bars

        //First find Length of Longest consecutive horizontal bars
        int currConsecutiveHBars = 1;
        for(int i = 1; i < hBars.size(); i++) {
            if(hBars[i] - hBars[i-1] == 1) {
                currConsecutiveHBars++;
            } else {
                currConsecutiveHBars = 1;
            }
            maxConsecutiveHBars  = max(maxConsecutiveHBars, currConsecutiveHBars);
        }

        //Simialrl, find Length of Longest consecutive vertical bars
        int currConsecutiveVBars = 1;
        for(int i = 1; i < vBars.size(); i++) {
            if(vBars[i] - vBars[i-1] == 1) {
                currConsecutiveVBars++;
            } else {
                currConsecutiveVBars = 1;
            }
            maxConsecutiveVBars  = max(maxConsecutiveVBars, currConsecutiveVBars);
        }

        //Square width and height must be same. We can reduce the larger one to match the smaller one
        // So, take the minimum of them.
        int side = min(maxConsecutiveHBars, maxConsecutiveVBars)+1;
        
      return side*side;
    }
};
