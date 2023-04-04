//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    int a=1,ac=0,bc=0;

// a denote whether current character in a or not
// ac is a count and bc b count and f is total 

    if(str[0]=='b'){
        a=0;
        bc++;
    }
    else ac++;
    for(int i=1;i<str.size();i++)

//counting a substrings and b substrings 

{
        if(a&&str[i]=='b'){
            bc++;
            a=0;
        }
        else if(!a&&str[i]=='a'){
            ac++;
            a=1;
        }
    }
    if(ac==bc)return (ac+bc)-min(ac,bc)+1;
    return (ac+bc)-min(ac,bc);

}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends