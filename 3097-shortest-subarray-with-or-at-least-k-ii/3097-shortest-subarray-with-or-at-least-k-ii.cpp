class Solution {
void updateFreq(vector<int>& bitFreq,int number,int val){
        for(int i=0;i<32;++i)
            if(number&(1<<i))
                bitFreq[i]+=val;
    }
    int getNumber(vector<int>& bitFreq){
        int number=0;
        long long pow = 1;
        for(int i=0;i<32;++i){
            if(bitFreq[i]>0)
                number+=pow;
            pow*=2;
        }
        return number;
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k==0)
            return 1;
    
        int n=nums.size();
        int shortest=INT_MAX;
        int left=0,right=0;
        int currOR=0;
        vector<int> bitFreq(32);
        
        while(right<n){
            updateFreq(bitFreq,nums[right],1);
            currOR |= nums[right];
            
            //Resize window
            while(left<=right and currOR>=k){
                shortest=min(shortest,right-left+1);
                updateFreq(bitFreq,nums[left],-1);
                currOR = getNumber(bitFreq);
                left++;
            }
            right++;
        }
        return shortest==INT_MAX?-1:shortest;
    }
};