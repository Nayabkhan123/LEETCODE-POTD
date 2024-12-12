//optimal approch using Priority Queue
long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long sum=0;
        for(auto it : gifts){
            sum+=it;
            pq.push(it);
        }
        while(k--){
            int largest = pq.top();
            pq.pop();
            int sqrtvalue = sqrt(largest);
            pq.push(sqrtvalue);
            sum-=largest-sqrtvalue;
        }
        return sum;
}

// brute force approch
class Solution {
public:
    long long maxiNum(vector<int>&gifts){
        int index=-1,maxi=-1;
        for(int i=0;i<gifts.size();i++){
            if(maxi<gifts[i]){
                maxi=gifts[i];
                index=i;
            }
        }
        return index;
    }
    long long pickGifts(vector<int>& gifts, int k) {
        while(k--){
            int index=maxiNum(gifts);
            gifts[index]=sqrt(gifts[index]);
        }
        long long sum = 0;
        for(int it : gifts){
            sum+=it;
        }
        return sum;
    }
};

