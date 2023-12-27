class Solution {
public:
	int minCost(string s, vector<int>& time) {
		int n=s.size();
		int last=0,ans=0;

		// ans here represent the last value and add current-minimum value to it
		for(int curr=1;curr<n;++curr){
			if(s[curr]==s[last]){
				if(time[last]<time[curr]){
					ans+=time[last]; 
					last=curr;}
				else ans+=time[curr];
            }
			else last=curr; 

		} 
		return ans;
		}
};