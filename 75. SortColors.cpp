// 1st approch
 void sortColors(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]>nums[j]){
                    swap(nums[i],nums[j]);
                }
            }
        }
    }
// 2nd approch
void sortColors(vector<int>& nums) {
        int ones=0;
        int zeros=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0) zeros++;
            else if (nums[i]==1) ones++;
        }
        for(int i=0;i<zeros;i++){
            nums[i]=0;
        }
        for(int i=zeros;i<ones+zeros;i++){
            nums[i]=1;
        }
        for(int i=zeros+ones;i<n;i++){
            nums[i]=2;
        }
    }

// 3rd approch (best)
void sortColors(vector<int>& nums) {
        int start=0;
        int end = nums.size()-1;
        int index=0;
        while(index<=end){
            if(nums[index]==0){
                swap(nums[start],nums[index]);
                start++;
                index++;
            }
            else if(nums[index]==2){
                swap(nums[index],nums[end]);
                end--;
            }
            else{
                index++;
            }
        }
    }