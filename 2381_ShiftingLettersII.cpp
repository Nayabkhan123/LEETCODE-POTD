/*
    You are given a string s of lowercase English letters and a 2D integer array shifts where 
    shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the 
    index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

    Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so 
    that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter 
    in the alphabet (wrapping around so that 'a' becomes 'z').

    Return the final string after all such shifts to s are applied.
*/

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> temp(n, 0); 

        for (auto shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2] == 1 ? 1 : -1;

            temp[start] += direction;
            if(end+1<n)
            temp[end + 1] -= direction; 
        }
        int shiftAmount = 0;
        for (int i = 0; i < n; ++i) {
            shiftAmount += temp[i];
            int newChar = ((s[i] - 'a') + shiftAmount) % 26;
            if (newChar < 0) newChar += 26;
            s[i] = 'a' + newChar;
        }
        return s;
    }
};
