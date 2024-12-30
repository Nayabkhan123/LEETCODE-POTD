/*
    Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and 
    then at each step perform either of the following:

    Append the character '0' zero times.
    Append the character '1' one times.
    This can be performed any number of times.

    A good string is a string constructed by the above process having a length between low and high (inclusive).

    Return the number of different good strings that can be constructed satisfying these properties. 
    Since the answer can be large, return it modulo 109 + 7.
*/

class Solution {
public:
    long long countStrings(int len, int low, int high, int zero, int one, vector<int>& memo) {
        if (len > high) return 0;
        if (memo[len] != -1) return memo[len];
        long long cnt = (len >= low) ? 1 : 0;
        cnt = (cnt + countStrings(len + zero, low, high, zero, one, memo)) % 1000000007;
        cnt = (cnt + countStrings(len + one, low, high, zero, one, memo)) % 1000000007;
        return memo[len] = cnt;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> memo(high + 1, -1);
        return countStrings(0, low, high, zero, one, memo);
    }

};