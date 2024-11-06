class Solution {
public:
    // Code with Radheshyam (.^.)
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int prevMax = INT_MIN;
        int currMax = nums[0];
        int currMin = nums[0];
        int setbitCount = __builtin_popcount(nums[0]);
        int i = 1;

        while (i < n) {
            // Extract current segment
            while (i < n && __builtin_popcount(nums[i]) == setbitCount) {
                currMax = max(currMax, nums[i]);
                currMin = min(currMin, nums[i]);
                i++;
            }
            if (prevMax > currMin) {
                return false;
            } else if (i < n) {
                prevMax = currMax;
                currMax = nums[i];
                currMin = nums[i];
                setbitCount = __builtin_popcount(nums[i]);
            }
        }
        return true;
    }
};