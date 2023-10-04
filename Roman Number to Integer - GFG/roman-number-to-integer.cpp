//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        int x=1;
        int n=str.length();
        int count=0;
        for(int i=n-1;i>=0;i--){
            if(str[i]=='I'){
                if(x<=1) count++;
                else count--;
                
            }
            else if(str[i]=='V'){
                if(x<=2){
                    x=2;
                    count+=5;
                }
                else count-=5;
                
            }
            if(str[i]=='X'){
                if(x<=3){
                    x=3;
                    count+=10;
                }
                else count-=10;
                
            }
            if(str[i]=='L'){
                if(x<=4){
                    x=4;
                    count+=50;
                }
                else count-=50;
            }
            if(str[i]=='C'){
                if(x<=5){
                    x=5;
                    count+=100;
                }
                else count-=100;
            }
            if(str[i]=='D'){
                if(x<=6){
                    x=6;
                    count+=500;
                }
                else count-=500;
            }
            if(str[i]=='M'){
                if(x<=7){
                    x=7;
                    count+=1000;
                }
                else count-=1000;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends