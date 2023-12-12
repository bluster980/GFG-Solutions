class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int x=0,y; int minn = INT_MAX, in;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= nums[x]){
                x = i;
            }
            if(nums[i] < minn){
                minn = nums[i];
                in = i;
            }
        }
        y = in; 
        // cout<<y<<endl;
        for(int i=0; i<nums.size(); i++){
            if((nums[i] > nums[y]) && (nums[i] <= nums[x]) && (i!=x)){
                y = i;
            }
        }
        // cout<<x<<" "<<y<<endl;
        return (nums[x]-1) * (nums[y]-1);
    }
};