/*
    You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits 
    (0 to 9) to another digit.

    Return the difference between the maximum and minimum values Bob can make by remapping exactly one 
    digit in num.
    Notes:

    When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
    Bob can remap a digit to itself, in which case num does not change.
    Bob can remap different digits for obtaining minimum and maximum values respectively.
    The resulting number after remapping can contain leading zeroes.
*/

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string copy = s;

        int i=0;
        while(i<s.size()){
            if(s[i]<'9'){
                char temp=s[i];
                replace(s.begin(),s.end(),temp,'9');
                break;
            }
            i++;
        }
        char temp = copy[0];
        replace(copy.begin(),copy.end(),temp, '0');
        return stoi(s)-stoi(copy);
    }
};


class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string copy = s;

        int i=0;
        while(i<s.size()){
            if(s[i]<'9'){
                int temp=s[i];
                s[i]='9';
                while(i<s.size()){
                    if(s[i]==temp) s[i]='9';
                    i++;
                }
            }
            i++;
        }
        i=0;
        while(i<copy.size()){
            if(copy[i]>'0'){
                int temp=copy[i];
                copy[i]='0';
                while(i<copy.size()){
                    if(copy[i]==temp) copy[i]='0';
                    i++;
                }
            }
            i++;
        }
        return stoi(s)-stoi(copy);
    }
};