class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<int,set<int>> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]].insert(i);
        }
        int maxx = 0;
        for(auto t:mp){
            auto st = t.second;
            auto xx = *st.begin();
            auto xy = *(--st.end());
            maxx = max(maxx, xy-xx);
        }
        return maxx-1;
    }
};