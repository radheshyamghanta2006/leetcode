class Solution {
public:
// Code with Radheshyam (.^.)
    int searchInsert(vector<int>& nums, int target) {
        int pos = nums.size();
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target){
                pos = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return pos;
    }
};