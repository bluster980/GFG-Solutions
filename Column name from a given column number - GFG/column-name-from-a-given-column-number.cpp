//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        string str;
        string ans = "";
            while(n>0){
                long rem = (n-1)%26;
                char ch = (char)(rem + 'A');
                ans = ch+ans;
                n = (n-1)/26;
            }
            return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends