/*
    You are given two positive integers low and high.

    An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits 
    of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits 
    are never symmetric.

    Return the number of symmetric integers in the range [low, high].
*/

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i+=1){
            string s_low = to_string(i);
            int n=s_low.size();
            if(n%2) continue;
            int firsthalf=0,secondhalf=0;
            for(int j=0;j<n/2;j++){
                firsthalf += s_low[j];
            }
            for(int j=n/2;j<n;j++){
                secondhalf += s_low[j];
            }
            if(firsthalf == secondhalf) cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int digitSum(int n){
        int sum=0;
        while(n){
            int rem = n%10;
            sum = sum + rem; 
            n=n/10;
        }
        return sum;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i+=1){
            string s_low = to_string(i);
            int n=s_low.size();
            if(n%2) continue;
            int sumA = digitSum(stoi(s_low.substr(0,n/2)));
            int sumB = digitSum(stoi(s_low.substr(n/2,n)));
            if(sumA == sumB) cnt++;
        }
        return cnt;
    }
};