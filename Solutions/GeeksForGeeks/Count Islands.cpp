class Solution {
  public:
    void dfs(int row, int col, vector<vector<char>>& grid ,
                               vector<vector<int>>& visited)
    {
        visited[row][col] = 1;
           
        int dx[]={ 0, 0,-1, 1, 1,-1,1,-1};
        int dy[]={-1, 1, 0, 0,-1,-1,1, 1}; 
        
        for (int i=0; i<8 ; i++)
        {
            int drow = row + dx[i];
            int dcol = col + dy[i];
            
            if(( drow >=0 && drow < grid.size()) &&
               ( dcol >=0 && dcol < grid[0].size()))
            {
                if(!visited[drow][dcol] && grid[drow][dcol] == 'L')
                    dfs(drow, dcol, grid, visited);
            }
        }
    }
    
    
    
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        //vector<int> visited (grid.size(),vector<int>(grid[0].size(),0) );
        vector<vector<int>> visited(
            grid.size(),
            vector<int>(grid[0].size(), 0)
        );
        
        int count = 0;
        for(int i=0;i<grid.size() ; i++)
        {
            for(int j = 0; j<grid[0].size();j++)
            {
                if(!visited[i][j] && grid[i][j] == 'L')
                {
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return count;
    }
};