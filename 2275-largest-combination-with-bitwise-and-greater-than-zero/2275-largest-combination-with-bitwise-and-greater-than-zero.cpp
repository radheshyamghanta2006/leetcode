class Solution {
public:
    // Code with Radheshyam (.^.)
    int largestCombination(vector<int>& candidates) {
        int n=candidates.size();

        int max_freq=0;
        for(int i=0;i<32;++i){
            int freq=0;
            for(int j = 0; j < candidates.size(); j++) {
              if(candidates[j] & (1 << i)) {
                     freq++;
                     }
                 }

            max_freq = max(max_freq,freq);
        }
        return max_freq;
    }
};