/*
    Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

    Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

    A palindrome is a string that reads the same forwards and backwards.

    A subsequence of a string is a new string generated from the original string with some characters (can be none) 
    deleted without changing the relative order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".
*/

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> arr(26, {-1, -1});
        for (int i = 0; i < s.size(); i++) {
            int index = s[i] - 'a';
            if (arr[index].first == -1) {
                arr[index].first = i;
            }
            arr[index].second = i;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            int first = arr[i].first;
            int last = arr[i].second;
            if (first != -1 && last != -1 && last > first + 1) {
                unordered_set<char> midchars;
                for (int j = first + 1; j < last; j++) {
                    midchars.insert(s[j]);
                }
                ans += midchars.size();
            }
        }
        return ans;        
    }
};