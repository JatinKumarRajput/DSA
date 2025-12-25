/*
2054. Two Best Non-Overlapping Events
You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

Input: events = [[1,3,2],[4,5,2],[2,4,3]]
Output: 4
Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
*/
// t.c. O(n* logn)
class Solution {
public:
     //upper_bound of endTime
    int binarySearch(vector<vector<int>>& events, int endTime) {
        int n=events.size();
        int l = 0;
        int r = n-1;
        int result = n;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(events[mid][0] > endTime) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }

    int solve(vector<vector<int>>& events, int i, int counter,vector<vector<int>>&dp){
        if(counter==2 || i>=events.size()) return 0;

        if(dp[i][counter]!=-1) return dp[i][counter];
        int next_ind=binarySearch(events,events[i][1]);

        int take = events[i][2] + solve(events, next_ind, counter+1,dp);

        int not_take = solve(events, i+1, counter,dp);

        return dp[i][counter]=max(take,not_take);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(begin(events), end(events));
        int counter=0;

        vector<vector<int>> dp(n,vector<int>(3,-1));
        return solve(events,0,counter,dp);
    }
};