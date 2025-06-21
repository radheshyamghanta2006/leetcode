class Solution {
public:
// Code with Radheshyam (.^.)
void fun(vector<vector<char>>& grid,int i,int j){
    // Base case
if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!='1') return;
// mark as done
grid[i][j]='2'; 
// recursive case
fun(grid,i+1,j);
fun(grid,i-1,j);
fun(grid,i,j+1);
fun(grid,i,j-1);
}

int numIslands(vector<vector<char>>& grid) {
int n=grid.size();
int m=grid[0].size();
if(grid.size()==0 || grid[0].size()==0){
    return 0;
}
int count = 0;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j] == '1'){
            fun(grid,i,j);
            count++;
        }
    }
}
return count;
}
};