class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = (n*m-1);

        while(low<=high){
            int mid = (low + high)/2;
            int row = mid/m;
            int coll = mid % m;
            if(matrix[row][coll]==target) return true;
            else if(matrix[row][coll] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};