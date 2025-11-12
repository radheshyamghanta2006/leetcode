class Solution {
public:
    bool isMatch(string s, string p) {
         // Code with Radheshyam (.^.)
        int n = p.size();
        int m = s.size();

        // 1. Initialize two 1D DP arrays for space optimization
        // 'prev' stores dp[i-1], 'curr' stores dp[i]
        // Size is m + 1 to account for empty string (index 0)
        vector<bool> prev(m + 1, false);
        vector<bool> curr(m + 1, false);

        // --- Base Cases ---
        
        // dp[0][0] = true: Empty pattern matches empty string
        prev[0] = true; 

        // Handle the first row (i=1 to n, j=0). 
        // If p is "*", "**", "***", etc., it matches an empty string s.
        // This is handled in the outer loop for i=1, as 'prev' already holds dp[i-1].

        // --- Fill DP Table Row by Row (i is pattern index, j is string index) ---
        for (int i = 1; i <= n; ++i) { // i iterates through the pattern p
            // Reset curr for the new row
            fill(curr.begin(), curr.end(), false);

            // Handle dp[i][0] (empty string s)
            // It relies on dp[i-1][0]. If p[i-1] is '*' and dp[i-1][0] was true, then dp[i][0] is true.
            if (p[i-1] == '*') {
                curr[0] = prev[0]; 
            }
            
            for (int j = 1; j <= m; ++j) { // j iterates through the string s
                char p_char = p[i-1];
                char s_char = s[j-1];

                if (p_char == s_char || p_char == '?') {
                    // Match: Depends on the diagonal cell (i-1, j-1)
                    curr[j] = prev[j-1];
                } 
                else if (p_char == '*') {
                    // '*' can match:
                    // 1. Empty sequence: depends on cell above (i-1, j) -> prev[j]
                    // 2. The character s[j-1]: depends on cell to the left (i, j-1) -> curr[j-1]
                    curr[j] = prev[j] || curr[j-1];
                } 
                else {
                    // Mismatch
                    curr[j] = false;
                }
            }

            // Move current row to previous for the next iteration
            prev = curr;
        }

        // The final result is dp[n][m], which is stored in prev[m] after the last loop.
        return prev[m];
    }

};