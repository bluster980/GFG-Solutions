//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> A, int X, int Y) {
        if(X==0 && Y==0) return 0;
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dis(n,vector<int> (m,1e9));
        dis[0][0] = 0;
        q.push({0,{0,0}});
        vector<int> ro = {-1,0,1,0};
        vector<int> co = {0,1,0,-1};
        while(!q.empty()){
            int distance = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i=0; i<4; i++){
                int newrow = row + ro[i];
                int newcol = col + co[i];
                if(newrow >= 0 && newcol >= 0 && newrow < n && newcol < m && A[newrow][newcol]==1 && distance+1 < dis[newrow][newcol] ){
                    dis[newrow][newcol] = distance+1;
                    if(newrow == X && newcol == Y){
                        return distance+1;
                    }
                    q.push({distance+1,{newrow,newcol}});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends