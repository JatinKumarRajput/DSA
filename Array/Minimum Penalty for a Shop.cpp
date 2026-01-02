//also in dec_26.cpp
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        // Penalty if closed at hour 0: all 'Y' are missed
        int penalty = 0;
        for(char c : customers) {
            if(c == 'Y') penalty++;
        }

        int minPenalty = penalty;
        int bestHour = 0;
        // Try closing at hour j (1 to n)
        for(int j = 1; j <= n; j++) {
            if(customers[j-1] == 'Y') {
                penalty--;   // now we served this customer
            } else {
                penalty++;   // shop was open but no customer
            }
            if(penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = j;
            }
        }
        return bestHour;
    }
};