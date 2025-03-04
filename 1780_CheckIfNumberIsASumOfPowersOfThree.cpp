/*
    Given an integer n, return true if it is possible to represent n as the sum of 
    distinct powers of three. Otherwise, return false.

    An integer y is a power of three if there exists an integer x such that y == 3x.
*/

class Solution {
    public:
        bool checkPowersOfThree(int n) {
            for (int i=16;i>=0;i--){
                if(n>=pow(3,i)){
                    n-=pow(3,i);
                }
            }
            return n==0;
        }
    };