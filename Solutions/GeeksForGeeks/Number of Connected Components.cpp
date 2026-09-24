class Solution {
  public:
  
    void dfs(int node, vector<vector<int>> &adjLs , vector<int> &visited)
    {
        visited[node] = 1;
        for(auto const &val : adjLs[node])
        {
            if(!visited[val])
                dfs(val,adjLs,visited);
        }
    }
  
    int countConnected(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adjLs(V);
        
        for(auto const &row: edges)
        {
            adjLs[row[0]].push_back(row[1]);
            adjLs[row[1]].push_back(row[0]);
        }
        
        int count = 0;
        
        vector<int> visited(V,0);
        
        for(int i=0; i<V ; i++)
        {
            if(visited[i] != 1)
            {
                dfs(i, adjLs, visited);
                count++;
            }
        }
        return count;
                
    }
};