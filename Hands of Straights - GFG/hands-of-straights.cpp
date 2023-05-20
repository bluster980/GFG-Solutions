//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if(N%groupSize)
        return false;
        else{
            map<int,int>mp;
            set<int>s;bool flag=true;
            for(int i=0;i<N;i++){
                mp[hand[i]]++;
                s.insert(hand[i]);
            }
            for(auto it:s){
                if(mp[it])
                {int num=mp[it];mp[it]=0;
                for(int i=it+1;i<it+groupSize;i++){
                    if(mp[i]>=num)
                    mp[i]-=num;
                    else
                    {flag=false;break;}
                }}
            }
            return flag;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends