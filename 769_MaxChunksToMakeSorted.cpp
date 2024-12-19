/*
You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. 
After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.
*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int maxelem= 0;
        int chunk = 0;
        for(int i=0;i<n;i++){
            maxelem=max(maxelem,arr[i]);
            if(maxelem==i){
                chunk++;
            }
        }
        return chunk;
    }
};