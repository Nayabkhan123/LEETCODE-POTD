/*
    There is a circle of red and blue tiles. You are given an array of integers colors 
    and an integer k. The color of tile i is represented by colors[i]:

    colors[i] == 0 means that tile i is red.
    colors[i] == 1 means that tile i is blue.
    An alternating group is every k contiguous tiles in the circle with alternating 
    colors (each tile in the group except the first and last one has a different 
    color from its left and right tiles).

    Return the number of alternating groups.

    Note that since colors represents a circle, the first and the last tiles are 
    considered to be next to each other.
*/

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int left=0,n=colors.size(),cnt=0;
            for(int right=1;right<(n+k-1);right++){
                if(colors[right%n]==colors[(right-1)%n]){
                    left=right;
                }
                if(right-left+1==k){
                    left++;
                    cnt++;
                }
            }
            return cnt;
        }
    };