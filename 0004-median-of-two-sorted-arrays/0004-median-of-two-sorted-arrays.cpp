class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int m=nums1.size() , n=nums2.size() ;
        int length;
        int p1=0;
        int p2=0;
        float median;
        while(p1<m && p2<n){
            if(nums1[p1] < nums2[p2]){
                v.push_back(nums1[p1]);
                p1++;
            }  
            else {
                v.push_back(nums2[p2]);
                p2++;
            }
        }
        if(p1==m){
            while(p2!=n){
               v.push_back(nums2[p2]);
                p2++;
            }
        }
        if(p2==n){
            while(p1!=m){
               v.push_back(nums1[p1]);
                p1++;
            }
        }
        length =v.size();
        if(length%2==0){
            int mid1;
            mid1=(length/2);
            median =(v[mid1-1]+v[mid1])/2.0;
            return median;
        }
        else{
           
            return v[length/2.0];
        }
    }
}; 