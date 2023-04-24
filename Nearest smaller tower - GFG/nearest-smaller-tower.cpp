//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        stack<int> st;
        vector<int> left;
        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            if(!st.empty())
                left.push_back(st.top());
            else
                left.push_back(-1);
            
            st.push(i);
        }
        
        while(!st.empty())
            st.pop();
        
        vector<int> right;
        
        for(int i = arr.size() - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            if(!st.empty())
                right.push_back(st.top());
            else
                right.push_back(-1);
            
            st.push(i);
        }
        reverse(right.begin(), right.end());
        
        
        int i = 0;
        vector<int> ans;
        while(i < arr.size()){
            int ind1 = left[i];
            int ind2 = right[i];
            
            if(ind1 != -1 && ind2 != -1){
                if(i - ind1 == ind2 - i){
                    if(arr[ind1] <= arr[ind2])
                        ans.push_back(ind1);
                    else
                        ans.push_back(ind2);
                }
                else{
                    if(i - ind1 < ind2 - i)
                        ans.push_back(ind1);
                    else
                        ans.push_back(ind2);
                }
            }
            else if(ind1 != -1)
                ans.push_back(ind1);
                
            else if(ind2 != -1)
                ans.push_back(ind2);
                
            else
                ans.push_back(-1);
            
            i++;
        }
        return ans;
    }


};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends