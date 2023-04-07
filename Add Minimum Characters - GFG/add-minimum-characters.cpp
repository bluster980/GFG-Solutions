//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int lps(string str){
    int n = str.length();
    vector<int> dp(n,0);
    int i = 0;
    int j = 1;
    while(j < n){
        if(str[i] == str[j]){
            dp[j++] = i+1;
            i++;
        }else{
            if(i == 0){
                dp[j++] = 0;
            }else{
                i = dp[i-1];
            }
        }
    }
    return dp[n-1];
}
    int addMinChar(string str){    
        //code here
        string stt = str;
        reverse(stt.begin(),stt.end());
        string ans = str + "$" + stt;
        int res = lps(ans);
        return str.length()-res;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends