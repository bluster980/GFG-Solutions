//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &arr) {
    
    long long int cnt=0;
    
    long long int len=0;
    for(int i=0;i<n;i++)
    {
        //count total no of continuos 0
        if(arr[i]==0)
        {
            len++;
        }
        else
        {
            cnt+=len*(len+1)/2;//formula for total continous subarray of 0
            len=0;
        }
    }
    if(arr[n-1]==0) //if last value i n vector is 0
    {
        cnt+=len*(len+1)/2;
    }
    return cnt;
    
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends