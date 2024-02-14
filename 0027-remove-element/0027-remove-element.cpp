class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = nums.size();
        vector<int> ans;
        int count = 0;
        for(auto x:nums){
            if(x!=val) ans.push_back(x);
            else { count++; }
        }
        // reverse(ans.begin(),ans.end());
        for(auto y:ans){
            nums.push_back(y);
        }
        reverse(nums.begin(),nums.end());
        return j-count;
    }
};