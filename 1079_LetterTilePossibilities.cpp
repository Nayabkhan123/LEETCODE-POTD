/*
    You have n  tiles, where each tile has one letter tiles[i] printed on it.

    Return the number of possible non-empty sequences of letters you can make using the 
    letters printed on those tiles.
*/

class Solution {
    public:
        int n;
        int backtrack(vector<int>& freq){
            int count = 0;
            for(int i=0;i<26;i++){
                if(freq[i]==0) continue;
                count++;
                freq[i]--;
                count += backtrack(freq);
                freq[i]++;
            }
            return count;
        }
        int numTilePossibilities(string tiles) {
            n=tiles.size();
            vector<int>freq(26);
            for(auto it :tiles){
                freq[it-'A']++;
            }
            int count = backtrack(freq);
            return count;
        }
    };


class Solution {
    public:
        int n;
        void backtrack(string tiles, vector<bool>& used,set<string>&s,string curr){
            if(s.find(curr)!=s.end()) return;
            s.insert(curr);
            for(int i=0;i<n;i++){
                if(used[i]) continue;
                used[i] = true;
                backtrack(tiles,used,s,curr+tiles[i]);
                used[i]=false;
            }
        }
        int numTilePossibilities(string tiles) {
            n=tiles.size();
            vector<bool>used(n);
            set<string>s;
            backtrack(tiles,used,s,"");
            return s.size()-1;
        }
    };