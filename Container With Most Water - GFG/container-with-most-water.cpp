//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long arr[], int len)
{
    int left=0,right=len-1;long long int MaxArea=0;
	while(left<right) {
 // MaxArea=max(MaxArea,(abs(left-right)*min(arr[left],arr[right])));
	    MaxArea=max(MaxArea,((right-left)*min(arr[left],arr[right])));
	    if(arr[left]>arr[right]) {
	        right--;
	    }
	    else
	       left++;
	}
	return MaxArea;
}


//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends