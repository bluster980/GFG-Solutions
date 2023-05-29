//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    #define append(n) push_back(n);
    vector<string> CamelCase(int n, vector<string> d, string s) {
        vector<pair<string, string>> mp;
        string str;
        for(auto val:d){
            str="";
            for(auto ch:val)if (isupper(ch)) str.push_back(ch);
            mp.append(make_pair(val, str))
        }
        sort(mp.begin(), mp.end());
        vector<string> v;
        for(auto pr:mp){
            if (s.size()<=pr.second.size()){
                bool chk=true;
                for(int i=0; i<s.size(); i++){
                    if (s[i]!=pr.second[i]) {chk=false; break;}
                }
                if (chk)v.append(pr.first);
            }
        }
        if (v.size()>0) return v;
        return {"-1"};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends