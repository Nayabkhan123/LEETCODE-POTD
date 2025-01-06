/*
    You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is 
    empty, and '1' if it contains one ball.
    In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j 
    if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

    Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the 
    balls to the ith box.
    Each answer[i] is calculated considering the initial state of the boxes.
*/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> lCnt(n, 0), rCnt(n, 0);

        for (int i = 1, count = 0; i < n; i++) {
            if (boxes[i - 1] == '1') {
                count++;
            }
            lCnt[i] = lCnt[i - 1] + count;
        }
        for (int i = n - 2, count = 0; i >= 0; i--) {
            if (boxes[i + 1] == '1') {
                count++;
            }
            rCnt[i] = rCnt[i + 1] + count;
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = lCnt[i] + rCnt[i];
        }
        return ans;
    }
};