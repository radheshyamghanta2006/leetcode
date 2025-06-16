class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         int i = 0;
      int j = 0;
      int k = 0;
      int n = nums1.size();
      int m = nums2.size();
      int size = (m + n );

      int idx1 = (size / 2) - 1;
      int idx2 = size / 2;

      int element1 = -1;
      int element2 = -1;

      while(i < nums1.size() && j < nums2.size()){
        if(nums1[i] <= nums2[j]){
          if(idx1 == k){
            element1 = nums1[i];
          }
          if(idx2 == k){
            element2 = nums1[i];
          }
          i++;
        }
        else{
          if(idx1 == k){
            element1 = nums2[j];
          }
          if(idx2 == k){
            element2 = nums2[j];
          }
          j++;
        }
        k++;
      }

      while(i < nums1.size()){
        if(idx1 == k){
          element1 = nums1[i];
          
        }
        if(idx2 == k){
          element2 = nums1[i];
        }
        i++;
        k++;
      }

      while(j < nums2.size()){
        if(idx1 == k){
          element1 = nums2[j];
          
        }
        if(idx2 == k){
          element2 = nums2[j];
        }
        j++;
        k++;
      }


      if(size % 2 == 1){
        return element2;
      }

      return (element1 + element2) / 2.0;
    }
};