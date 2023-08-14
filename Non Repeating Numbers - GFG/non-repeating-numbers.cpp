//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int temp = nums[0];
        for(int i=1; i<nums.size(); i++){
            temp ^= nums[i];
        }
        int i;
        for(i=1; i<32; i++){
            if(temp & (1<<i)){
                break;
            }
        }
        
        //Think In the term of divide in the array into two part like one part have one number and another part have another number
        //think like xor of whole arry with 0^1=1 else 1^0=1 for which bit it happen just go for it.     ~Jappy
        
        int x = INT_MAX,y = INT_MAX;
        for(int j=0; j<nums.size(); j++){
            if(nums[j] & (1<<i)){
                if(x!=INT_MAX){
                    x ^= nums[j];
                }
                else{
                    x = nums[j];
                }
            }
            else{
                if(y!=INT_MAX){
                    y ^= nums[j];
                }
                else{
                    y = nums[j];
                }
            }
        }
        vector<int> ans;
        ans.push_back(min(x,y));
        ans.push_back(max(x,y));
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends