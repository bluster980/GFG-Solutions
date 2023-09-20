//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
void convertIntoBits(int arr[], int n) {
    int i = 15;
    while (n) {
        arr[i] = n % 2;
        i--;
        n = n / 2;
    }
}

vector<int> rotate(int n, int d) {

    int arr[16] = {0};

    convertIntoBits(arr, n);
    
    int left[16] = {0};
    int right[16] = {0};
    
    for(int i=0;i<16;i++){
        left[i] = right[i] = arr[i];
    }
    
    d= d%16;
    
    int x = d;

    while (x) {
        
        int leftbit = left[0];
        
        for(int i=1;i<16;i++){
            left[i-1]= left[i];
        }
        
        left[15] = leftbit;
        
        x--;
    }
    
    
    
    while(d){
        int rightbit = right[15];
        
        for(int i=15;i>=0;i--){
            right[i] = right[i-1];
        }
        
        right[0] = rightbit;
        d--;
    }
    

     int leftRotate = 0;
     int rightRotate = 0;

    for (int i = 15; i >=0; i--) {
        if(left[i] == 1)leftRotate += pow(2, 15 - i);
        if(right[i] == 1)rightRotate += pow(2, 15 - i);
    }

    return { leftRotate, rightRotate };
}
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends