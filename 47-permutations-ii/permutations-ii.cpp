class Solution {
public:

vector<vector<int>> ans;
  void solve(int i, vector<int>& arr,vector<vector<int>>& ans){
    if(i == arr.size()){
        ans.push_back(arr);
        return;
    }    
    unordered_map<int,int>mp;
    for(int j = i;j < arr.size(); j++){
        if(mp.find(arr[j]) != mp.end()){
            continue;
        }
        mp[arr[j]]++;
        swap(arr[i],arr[j]);
        solve(i + 1, arr, ans);
        swap(arr[i], arr[j]);
    }
      
  }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         // Code with Radhesdhyam (.^.)
        sort(nums.begin(),nums.end());
        solve(0, nums, ans);
        return ans;
    }
};