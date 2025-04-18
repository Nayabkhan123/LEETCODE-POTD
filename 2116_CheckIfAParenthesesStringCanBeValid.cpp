/*
    A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the 
    following conditions is true:

    It is ().
    It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
    It can be written as (A), where A is a valid parentheses string.
    You are given a parentheses string s and a string locked, both of length n. locked is a binary string 
    consisting only of '0's and '1's. For each index i of locked,

    If locked[i] is '1', you cannot change s[i].
    But if locked[i] is '0', you can change s[i] to either '(' or ')'.
    Return true if you can make s a valid parentheses string. Otherwise, return false.
*/

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n&1) return false;
        int opening = 0, closing = 0;
        int wild_card = 0;
        for(int i=0;i<n;++i){
            if(locked[i]=='0'){
                wild_card++;
            } 
            else if(s[i]=='('){
                opening++;
            }
            else closing++;

            if(wild_card < (closing - opening))
                return false;
        }

        opening = closing = wild_card = 0;
        for(int i=n-1;i>0;--i){
            if(locked[i]=='0') wild_card++;
            else if(s[i]=='(') opening++;
            else closing++;

            if(wild_card < (opening - closing))
                return false;
        }
        return true;
    }
};