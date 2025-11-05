class Solution {
public:
int fun(int N,vector<int>&dp){
    //Base case
    if(N==0) return 0;
    if(dp[N]!=-1) return dp[N];
    int ans = INT_MAX;;
    // Recursive case
    
    for(int i=1;(i*i)<=N;i++){
        ans = min(1+(fun(N-(i*i),dp)),ans);
    }
    dp[N] = ans;
    return dp[N];
}

// Code with Radheshyam (.^.)
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return fun(n,dp);
    }
};