class Solution {
  public:
    void fill(vector<vector<char>>& grid) {
        // Code here
        int m = grid.size(); int n = grid[0].size();
        
        vector<vector<int>> visited(m,vector<int>(n, 0));
        vector<vector<int>> NotReplaceable(m,vector<int>(n, 0));
        
        queue<pair<int,int>> q;
        
        //add the O's at the border
        for(int i=0; i<m; i++)
        {
            if(grid[i][0] == 'O')
            {
                q.push({i,0});
                visited[i][0] = 1;
                NotReplaceable[i][0] = 1;
            }
            

            if(grid[i][n-1] == 'O')
            {
                q.push({i,n-1});
                visited[i][n-1] = 1;
                NotReplaceable[i][n-1] = 1;
            }
        }
        
        for(int i=1; i<(n-1);i++)
        {
            if(grid[0][i] == 'O')
            {
                q.push({0,i});
                visited[0][i] = 1;
                NotReplaceable[0][i] = 1;
            }
            
            if(grid[m-1][i] == 'O')
            {
                q.push({m-1,i});
                visited[m-1][i] = 1;
                NotReplaceable[m-1][i] = 1;
            }
        }
        
        
        //begin logic now to find not replaceable
        while(!q.empty())
        {
            int sr = q.front().first;
            int sc = q.front().second;
            q.pop();
            
            int dx[]={ 1,-1, 0, 0};
            int dy[]={ 0, 0, 1,-1};
            
            for(int i=0; i<4; i++)
            {
                int tr = sr + dx[i];
                int tc = sc + dy[i];
                
                if(tr>=0 && tr<m && tc>=0 && tc<n &&
                   !visited[tr][tc] && grid[tr][tc] == 'O')
                {
                    q.push({tr,tc});
                    NotReplaceable[tr][tc] = 1;
                    visited[tr][tc] = 1;
                }
            }
        }
        
        for(int i =0; i<m; i++)
        {
            for(int j=0;j<n; j++)
            {
                if(NotReplaceable[i][j] == 0 && grid[i][j] == 'O')
                    grid[i][j] = 'X';
            }
        }
        


    }
};