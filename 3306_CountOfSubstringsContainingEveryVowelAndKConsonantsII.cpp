/*
    You are given a string word and a non-negative integer k.

    Return the total number of substrings of word that contain every 
    vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.
*/

class Solution {
    public:
        bool isConsonant(char ch){
            return (ch!='a' && ch!='e' && ch!='i' && ch!='o' && ch!='u');
        }
        bool isAllVowel(vector<int>freq){
            return (freq['a'-'a']>0 && freq['e'-'a']>0 && freq['i'-'a']>0 && 
                    freq['o'-'a']>0 && freq['u'-'a']>0);
        }
        long long atleast(int k,string words){
            long long cnt=0;
            int currConsonant=0;
            vector<int>freq(26);
            int n=words.length();
            int left=0;
            for(int right=0;right<n;right++){
                char ch = words[right];
                if(isConsonant(ch)){
                    currConsonant++;
                }
                freq[ch-'a']++;
                while(currConsonant>=k && isAllVowel(freq)){
                    cnt += (n-right);
                    char c=words[left];
                    if(isConsonant(c)){
                        currConsonant--;
                    }
                    freq[c-'a']--;
                    left++;
                }
            }
            return cnt;
        }
        long long countOfSubstrings(string word, int k) {
            return atleast(k,word) - atleast(k+1,word);
        }
    };