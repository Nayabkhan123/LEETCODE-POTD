/*
    The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

    countAndSay(1) = "1"
    countAndSay(n) is the run-length encoding of countAndSay(n - 1).
    Run-length encoding (RLE) is a string compression method that works by replacing consecutive 
    identical characters (repeated 2 or more times) with the concatenation of the character and 
    the number marking the count of the characters (length of the run). For example, to compress 
    the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" 
    and replace "1" with "11". Thus the compressed string becomes "23321511".

    Given a positive integer n, return the nth element of the count-and-say sequence.
*/

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string temp = countAndSay(n-1);
        int cnt=1;
        string s="";
        for(int i=0;i<temp.size();i++){
            if((i+1)<temp.size() && temp[i]==temp[i+1]){
                cnt++;
            }
            else{
                s+=to_string(cnt);
                s+=temp[i];
                cnt=1;
            }
        }
        return s;
    }
};