/*
    Given two positive integers num1 and num2, find the positive integer x such that:

    x has the same number of set bits as num2, and
    The value x XOR num1 is minimal.
    Note that XOR is the bitwise XOR operation.

    Return the integer x. The test cases are generated such that x is uniquely determined.

    The number of set bits of an integer is the number of 1's in its binary representation.
*/

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = __builtin_popcount(num2);

        int res=0;
        for(int i=31;i>=0 and count;i--){
            if(num1 & (1<<i)){
                count--;
                res += (1<<i);
            }
        }
        for(int i=0;i<32 and count;i++){
            if((num1 & (1<<i))==0){
                count--;
                res += (1<<i);
            }
        }
        return res;
    }
};