//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    string ans;
    stack<char> st;
    for(auto it : num)
    {
        while(!st.empty() && k > 0 && st.top() > it)
        {
            st.pop();
            k-=1;
        }
        st.push(it);
    }
    while(k > 0 && !st.empty())
    {
        st.pop();
        k-=1;
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin() ,ans.end());
    while(ans.front() == '0' && ans.size() != 0)
    {
        ans.erase(ans.begin());
    }
    if(ans.size() == 0)
        return "0";
    return ans;
}