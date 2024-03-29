//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int n = __builtin_popcount( b ) , m = __builtin_popcount( a ) , i = 0;
        while( n != m )
        {
            if( n > m )
            {
                if( ( a & ( 1 << i ) ) == 0 )
                {
                    a |= ( 1 << i );
                    n--;
                }
            }
            else
            {
                if( ( a & ( 1 << i ) ) > 0 )   
                {
                    a &= ~( 1 << i );
                    m--;
                }
            }
            i++;
        }
        return a;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends