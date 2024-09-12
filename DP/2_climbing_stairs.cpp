#include <bits/stdc++.h>

using namespace std;

int recursion(int n){
    if(n==0 || n==1)
        return 1;
    return recursion(n-1)+recursion(n-2);
}

int main() {

  int n=3;
  vector<int> dp(n+1,-1);
  
  dp[0]= 1;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}

// Time Complexity: O(N)
// Time Complexity: O(N)

#include <bits/stdc++.h>

using namespace std;


int main() {

  int n=3;
  
  int prev2 = 1;
  int prev = 1;
  
  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
  cout<<prev;
  return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)