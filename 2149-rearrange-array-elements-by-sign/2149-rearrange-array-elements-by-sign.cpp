class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> nege,posi,ans;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                posi.push_back(nums[i]);
            }
            else{
                nege.push_back(nums[i]);
            }
        }
        for(int i = 0; i < posi.size(); i++){
            ans.push_back(posi[i]);
            ans.push_back(nege[i]);
        }
        return ans;
    }
};