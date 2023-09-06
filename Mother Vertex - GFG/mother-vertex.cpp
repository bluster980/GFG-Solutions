//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	void dfs(int vertex, vector<int> adj[], vector<bool> &vis){
        vis[vertex] = true;
        for(auto child:adj[vertex]){
            if(vis[child]) continue;
            dfs(child,adj,vis);
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	   int temp;
	   vector<bool> vis(V,false);
	    for(int i=0; i<V; i++){
	        if(!vis[i]){
	            dfs(i,adj,vis);
	            temp = i;
	        }
	    }
        fill(vis.begin(),vis.end(),false);
        dfs(temp,adj,vis);
        for(auto xx:vis){
            if(xx == false){
                return -1;
            }
        }
	    return temp;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends