/*
    You are given two 0-indexed integer permutations A and B of length n.

    A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are 
    present at or before the index i in both A and B.

    Return the prefix common array of A and B.
    A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

*/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size(), cnt=0;
        vector<int>freq(n+1);
        vector<int>C(n);
        for(int i=0;i<n;i++){
            freq[A[i]]++;
            if(freq[A[i]]==2) cnt++;

            freq[B[i]]++;
            if(freq[B[i]]==2) cnt++;

            C[i] = cnt;
        }
        return C;
    }
};

// using Map
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mp;
        int n=A.size(),cnt=0;
        vector<int>C(n);
        
        for(int i=0;i<n;i++){
            if(A[i]==B[i]) cnt++;
            else{
                if(mp[A[i]]) cnt++;
                if(mp[B[i]]) cnt++;
            }
            C[i]=cnt;
            mp[A[i]]++;
            mp[B[i]]++;
        }
        return C;
    }
};