//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){

        if(s.length()<7){

            return 0;

        }

        unordered_map<char,int> mp;

        int count_l=0;

        int count_o=0;

        for(int i=0;i<s.length();i++){

            if(s[i]=='l')

            {

                count_l++;

                if(count_l==2){

                    mp['l']++;

                    count_l=0;

                    continue;

                }

            }

                

            else if(s[i]=='o')

                {

                count_o++;

                if(count_o==2){

                    mp['o']++;

                    count_o=0;

                    continue;

                }

            }

            else

                mp[s[i]]++;

        }

        return min(mp['a'],min(mp['b'],min(mp['l'],min(mp['o'],mp['n']))));

    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends