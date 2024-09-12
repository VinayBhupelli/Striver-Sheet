// Code with Vinay
#include<bits/stdc++.h>
using namespace std;

int recursion(int n,int height[]){
    if(n==0)
        return 0;
    int onejump= recursion(n-1,height) + abs(height[n]-height[n-1]);
    int twojumps=INT_MAX;
    if(n>1)
        twojumps = recursion(n-2,height) + abs(height[n]-height[n-2]);

    return min(onejump,twojumps);
}

int solve(int ind, vector<int>& height, vector<int>& dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) 
        return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
    if(ind>1)
        jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
    
    return dp[ind]=min(jumpOne, jumpTwo);
}


int main() {

  vector<int> height{30,10,60 , 10 , 60 , 50};
  int n=height.size();
  vector<int> dp(n,-1);
  cout<<solve(n-1,height,dp);
}

// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>

using namespace std;


int main() {

  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  vector<int> dp(n,-1);
  dp[0]=0;
  for(int ind=1;ind<n;ind++){
      int jumpTwo = INT_MAX;
        int jumpOne= dp[ind-1] + abs(height[ind]-height[ind-1]);
        if(ind>1)
            jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2]);
    
        dp[ind]=min(jumpOne, jumpTwo);
  }
  cout<<dp[n-1];
}
// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>

using namespace std;


int main() {

  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  int prev=0;
  int prev2=0;
  for(int i=1;i<n;i++){
      
      int jumpTwo = INT_MAX;
      int jumpOne= prev + abs(height[i]-height[i-1]);
      if(i>1)
        jumpTwo = prev2 + abs(height[i]-height[i-2]);
    
      int cur_i=min(jumpOne, jumpTwo);
      prev2=prev;
      prev=cur_i;
        
  }
  cout<<prev;
}
// Output: 40
// Time Complexity: O(N)
// Reason: We are running a simple iterative loop
// Space Complexity: O(1)
// Reason: We are not using any extra space.