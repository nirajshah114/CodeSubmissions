class Solution {
  public:

    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        

        queue<pair<pair<int,int>,int>> q;
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(
            m,
            vector<int>(n, 0)
        );

        vector<vector<int>> level(
            m,
            vector<int>(n, 0)
        );
        
        
        
        for(int i=0; i<m ; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                    level[i][j] = 0;
                }
            }
        }
        
        
        while( !q.empty())
        {
            int sr = q.front().first.first;
            int sc = q.front().first.second;
            
            int lvl = q.front().second;
            
            q.pop();
            
            int dx[]={ 1,-1, 0, 0};
            int dy[]={ 0, 0, 1,-1};
            
            for(int i=0; i<4; i++)
            {
                int tr = sr+ dx[i];
                int tc = sc+ dy[i];
            
            
                if(tr>=0 && tr<m && tc>=0 && tc<n &&
                   grid[tr][tc] == 0 && !visited[tr][tc])
                {
                    int new_lvl = lvl + 1;
                    level[tr][tc] = new_lvl;
                    q.push({{tr,tc},new_lvl});
                    visited[tr][tc] = 1;
                }
            }
            
        }
    
       return level; 
    }
};