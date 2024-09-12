#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector < int > & histo) {
    stack < int > st;
    int maxA = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m) {
    // Write your code here.
    int maxArea = 0;
    vector<int> height(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) height[j]++;
            else height[j] = 0;
        }
        int area = largestRectangleArea(height);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {

    vector<vector<int>> mat = {
        {1, 0, 1, 0, 0}, {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}
    };
    int n = 4, m = 5;
    int maxArea = maximalAreaOfSubMatrixOfAll1(mat, n, m);
    cout << "The maximum are is: " << maxArea << "\n";
    return 0;
}
// Output: The maximum area is: 6 (For example 1)
// Time Complexity: O(N * (M+M)), where N = total no. of rows and M = total no. of columns.
// Reason: O(N) for running a loop to check all rows. 
// Now, inside that loop, O(M) is for visiting all the columns, and 
// another O(M) is for the function we are using. The function takes linear time complexity. 
// Here, the size of the height array is M, so it will take O(M).
// Space Complexity: O(M), where M = total no. of columns.
// Reason: We are using a height array and a stack of size M.

#include<bits/stdc++.h>
using namespace std;

void findarea(vector<int> arr,int n){
    stack<long long> st;
    vector<int> leftsmall(n),rightsmall(n);
// finding the left small element
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();
        if(st.empty())
            leftsmall[i]=-1;
        else
            leftsmall[i]=st.top();
        st.push(i);
    }
    while(!st.empty())
        st.pop();
// finding the right small element
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();
        if(st.empty())
            rightsmall[i]=n;
        else
            rightsmall[i]=st.top();
        st.push(i);
    }
    long long maxarea=0;
    for(int i=0;i<n;i++){
        long long width=rightsmall[i]-leftsmall[i]-1;
        maxarea=max(maxarea,(arr[i]*(width)));
    }
    cout<<maxarea<<endl;
}
int main(){
    int n; 
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    findarea(arr,n);
    return 0;
}