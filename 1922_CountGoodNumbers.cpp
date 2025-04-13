/*
    A digit string is good if the digits (0-indexed) at even indices are even and the digits at 
    odd indices are prime (2, 3, 5, or 7).

    For example, "2582" is good because the digits (2 and 8) at even positions are even and the 
    digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an 
    even index but is not even.
    Given an integer n, return the total number of good digit strings of length n. Since the 
    answer may be large, return it modulo 10^9 + 7.

    A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
*/

class Solution {
    public:
        #define mod 1000000007
        long long binaryexpo(long long a,long long b){
            long long res = 1;
            while(b){
                if(b&1) res = (res*a) % mod;
                a = (a * a) % mod;
                b = b / 2;
            }
            return res;
        }
        int countGoodNumbers(long long n) {
            return (binaryexpo(5,n-(n/2)) * binaryexpo(4,n/2)) % mod;
        }
    };