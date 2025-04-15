/*
    Given an array of integers arr, and three integers a, b and c. You need to find the 
    number of good triplets.

    A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:

    0 <= i < j < k < arr.length
    |arr[i] - arr[j]| <= a
    |arr[j] - arr[k]| <= b
    |arr[i] - arr[k]| <= c
    Where |x| denotes the absolute value of x.

    Return the number of good triplets.
*/

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt=0,n=arr.size();
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                if (abs(arr[i] - arr[j]) > a) continue;
                for (int k = j + 1; k < n; ++k) {
                    if (abs(arr[j] - arr[k]) > b) continue;
                    if (abs(arr[i] - arr[k]) > c) continue;
                    cnt++;
                }
            }
        }    
        return cnt;
    }
};

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt=0,n=arr.size();
        for(int j=0;j<n-1;j++){
            vector<int>v1,v2;
            for(int i=0;i<j;i++){
                if(abs(arr[i]-arr[j])<=a){
                    v1.push_back(i);
                }
            }
            for(int k=j+1;k<n;k++){
                if(abs(arr[j]-arr[k])<=b){
                    v2.push_back(k);
                }
            }
            for(auto i : v1){
                for(auto k : v2){
                    if(abs(arr[i]-arr[k])<=c){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};

// BRUTE FORCE 
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt=0,n=arr.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                if(abs(arr[i]-arr[j])<=a){
                    for(int k=j+1;k<n;k++){
                        if(abs(arr[j]-arr[k])<=b && abs(arr[i]-arr[k])<=c){
                            cnt++;
                        }
                    }
                }    
            }
        }
        return cnt;
    }
};