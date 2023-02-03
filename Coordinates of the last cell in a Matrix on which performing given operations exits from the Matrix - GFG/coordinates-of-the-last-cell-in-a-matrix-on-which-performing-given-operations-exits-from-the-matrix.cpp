//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> a){
        //code here
        int i=0, j=0,x=0,y=0;
        int n=a.size(),m=a[0].size();
        bool fr=true, fu=false, fd=false,fl=false;
    while((i<n&&j<m)&&(i>=0&&j>=0)){
        x=i,y=j;
        if(a[i][j]==0){
            if(fr) j++;
            else if(fl) j--;
            else if(fu) i--;
            else i++;
        }
        else{
            if(fr){
                a[i][j]=0;
                fr=false;
                fd=true;
                i++;
            }
            else if(fu){
                a[i][j]=0;
                fu=false;
                fr=true;
                j++;
            }
             else if(fd){
                a[i][j]=0;
                fd=false;
                fl=true;
                j--;
            }
            else{
                    a[i][j]=0;
                    fl=false;
                    fu=true;
                    i--;
            } 
        }
    }
    return {x,y};}


};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends