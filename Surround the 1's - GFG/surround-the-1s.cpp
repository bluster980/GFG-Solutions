//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& nums) {
    int count = 0;
    int numRows = nums.size(); // Store the number of rows
    int numCols = nums[0].size(); // Store the number of columns

    // Loop through each element in the matrix
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (nums[i][j] == 1) {
                int temp = 0;

                // Check surrounding cells
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        int newRow = i + x;
                        int newCol = j + y;

                        // Make sure the new row and column indices are within bounds
                        if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols) {
                            if (nums[newRow][newCol] == 0) {
                                temp++;
                            }
                        }
                    }
                }

                // Exclude the center cell itself when counting surrounding zeros
                if (temp > 0 && temp % 2 == 0) { // Check for an even number of surrounding zeros
                    count++;
                }
            }
        }
    }
    return count;
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends