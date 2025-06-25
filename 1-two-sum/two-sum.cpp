class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=nums[i];
            int moreneed= target- num;
            if(mpp.find(moreneed)!=mpp.end()){
                return {mpp[moreneed], i};
            }
           mpp[num]=i;
        }
         return {-1, -1};
    }
};