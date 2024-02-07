class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        set<pair<int,char>> st;
        for(auto xx:mp){
            st.insert({xx.second,xx.first});
        }
        string ans;
        for(auto yy:st){
            for(int i=0; i<yy.first; i++){
                ans.push_back(yy.second);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};