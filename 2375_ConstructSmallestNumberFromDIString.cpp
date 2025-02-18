/*
    You are given a 0-indexed string pattern of length n consisting of the characters 'I' 
    meaning increasing and 'D' meaning decreasing.

    A 0-indexed string num of length n + 1 is created using the following conditions:

    num consists of the digits '1' to '9', where each digit is used at most once.
    If pattern[i] == 'I', then num[i] < num[i + 1].
    If pattern[i] == 'D', then num[i] > num[i + 1].
    Return the lexicographically smallest possible string num that meets the conditions.
*/

class Solution {
    public:
        string smallestNumber(string pattern) {
            int n=pattern.size();
            string ans="";
            stack<char>s;
            for(int i=1;i<=n+1;i++){
                s.push(i+'0');
    
                if(i==n+1 || pattern[i-1] == 'I'){
                    while(!s.empty()){
                        ans.push_back(s.top());
                        s.pop();
                    }
                }
            }
            return ans;
        }
    };