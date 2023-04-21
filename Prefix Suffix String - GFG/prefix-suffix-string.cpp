//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
    unordered_map<string,int>mp;
    for(auto i:s2){
        mp[i]++;
    }
    int count=0;
    for(int i=0;i<s1.size();i++){
        string a,b;
        for(int j=0;j<s1[i].size()-1;j++){
            a+=s1[i][j];
            b=s1[i][s1[i].size()-1-j]+b;
            if(mp.find(a)!=mp.end()){
                if(mp[a]>0){
                    count++;
                    mp[a]--;
                }}
            if(mp.find(b)!=mp.end()){
               if(mp[b]>0){
                   count++;
                   mp[b]--;
               }
           };
        }
    }
    return count;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends