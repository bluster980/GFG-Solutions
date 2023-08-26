//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    int n = s.size();
    if(n < k) {
        return -1;
    }

    unordered_map<char, int> char_freq;
    int start = 0, end = 0, max_len = -1;

    while(end < n) {
        char_freq[s[end]]++;
        while(char_freq.size() > k) {
            char_freq[s[start]]--;
            if(char_freq[s[start]] == 0) {
                char_freq.erase(s[start]);
            }
            start++;
        }
        if(char_freq.size() == k) {
            max_len = max(max_len, end - start + 1);
        }

        end++;
    }

    if(max_len == -1) {
        return -1;
    }

    return max_len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends