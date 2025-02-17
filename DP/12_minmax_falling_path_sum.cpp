// Code with Vinay
#include<bits/stdc++.h>
using namespace std;


// int recursion(int i,int j,vector<int,vector<int>> matrix,int m){
//     if(j<0 || j>m)
//         return INT_MIN;
//     if(i==0)
//         return matrix[0][j];
//     int up=matrix[i][j]+recursion(i-1,j,matrix,m);
//     int ld=matrix[i][j]+recursion(i-1,j-1,matrix,m);
//     int rd=matrix[i][j]+recursion(i-1,j+1,matrix,m);

//     return max(up,max(ld,rd));
// }

#include <bits/stdc++.h>
using namespace std;

int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix, 
vector<vector<int> > &dp){
    
    // Base Conditions
    if(j<0 || j>=m)
        return -1e9;
    if(i==0)
        return matrix[0][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int up = matrix[i][j] + getMaxUtil(i-1,j,m,matrix,dp);
    int leftDiagonal = matrix[i][j] + getMaxUtil(i-1,j-1,m,matrix,dp);
    int rightDiagonal = matrix[i][j] + getMaxUtil(i-1,j+1,m,matrix,dp);
    
    return dp[i][j]= max(up,max(leftDiagonal,rightDiagonal));
    
}

int getMaxPathSum(vector<vector<int> > &matrix){
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,-1));
    
    int maxi = INT_MIN;
    
    for(int j=0; j<m;j++){
        int ans = getMaxUtil(n-1,j,m,matrix,dp);
        maxi = max(maxi,ans);
    }
    
    return maxi;
}

int main() {

  vector<vector<int> > matrix{{1,2,10,4},
                              {100,3,2,1},
                              {1,1,20,2},
                              {1,2,2,1}};
  
  cout<<getMaxPathSum(matrix);
}
// Output:105

// Time Complexity: O(N*N)
// Reason: At max, there will be M*N calls of recursion to solve a new problem,

// Space Complexity: O(N) + O(N*M)
// Reason: We are using a recursion stack space: O(N), 
// where N is the path length and an external DP Array of size ‘N*M’.

#include <bits/stdc++.h>

using namespace std;

int getMaxPathSum(vector<vector<int> > &matrix){
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,0));
    
    // Initializing first row - base condition
    for(int j=0; j<m; j++){
        dp[0][j] = matrix[0][j];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){
            
            int up = matrix[i][j] + dp[i-1][j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += dp[i-1][j-1];
            else leftDiagonal += -1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += dp[i-1][j+1];
            else rightDiagonal += -1e9;
            
            dp[i][j] = max(up, max(leftDiagonal,rightDiagonal));
            
        }
    }
    
    int maxi = INT_MIN;
    
    for(int j=0; j<m;j++){
        maxi = max(maxi,dp[n-1][j]);
    }
    
    return maxi;
}

int main() {

  vector<vector<int> > matrix{{1,2,10,4},
                              {100,3,2,1},
                              {1,1,20,2},
                              {1,2,2,1}};
  
  cout<<getMaxPathSum(matrix);
}
// Output:105

// Time Complexity: O(N*M)
// Reason: There are two nested loops

// Space Complexity: O(N*M)
// Reason: We are using an external array of size ‘N*M’. 
// The stack space will be eliminated.

#include <bits/stdc++.h>

using namespace std;

int getMaxPathSum(vector<vector<int> > &matrix){
    
     int n = matrix.size();
    int m = matrix[0].size();
    
    vector<int> prev(m,0), cur(m,0);
    
    // Initializing first row - base condition
    for(int j=0; j<m; j++){
        prev[j] = matrix[0][j];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){
            
            int up = matrix[i][j] + prev[j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += prev[j-1];
            else leftDiagonal += -1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += prev[j+1];
            else rightDiagonal += -1e9;
            
            cur[j] = max(up, max(leftDiagonal,rightDiagonal));
            
        }
        
        prev = cur;
    }
    
    int maxi = INT_MIN;
    
    for(int j=0; j<m;j++){
        maxi = max(maxi,prev[j]);
    }
    
    return maxi;

}

int main() {

  vector<vector<int> > matrix{{1,2,10,4},
                              {100,3,2,1},
                              {1,1,20,2},
                              {1,2,2,1}};
  
  cout<<getMaxPathSum(matrix);
}
// Output:105

// Time Complexity: O(N*M)
// Reason: There are two nested loops
// Space Complexity: O(M)
// Reason: We are using an external array of size ‘M’ to store only one row.