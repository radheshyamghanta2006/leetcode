class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        // Code with Radheshyam (.^.)
        int n= nums.size();
        vector<int>ans (n) ;
         //step-1 : Find the total xor
        int XOR = 0;
        for(int i = 0; i < n; i++) {
            XOR ^= nums[i];
        }
        //To find flip, first find the mask having all bits set to 1
        // (2^maximumBit)-1
        int mask=(( 1<<maximumBit )-1);
        for(int i=0;i<n;i++){
            int k=XOR ^ mask; //this will give me the flipped value of XOR , my best K
            ans[i]=k;
            XOR=(XOR ^ nums[n-1-i]); //this will delete the last element from the current array
        }
        return ans;
    }
};