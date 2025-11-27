class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        //Code with Radheshyam (.^.)
        int o = 0;
        for(int num : nums) o |= num;

        return o << (nums.size() - 1);
    }
};