class Solution {
public:
    long long minEnd(int n, int x) {
        // if(n==1)    return x;
           // Code with Radheshyam (.^.)
        long long num = x;

        for(int i = 1; i < n; i++) {

            //num+1
            num = (num+1) | x;
            
        }

        return num;
    }
};