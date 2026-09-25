class Solution {
  public:
  
  
    int bfs(vector<vector<int>>& mat, vector<vector<int>>& visited,
            queue<pair<pair<int,int>,int>> &que)
    {
        int mxlvl = que.front().second;
        int m = mat.size(); int n=mat[0].size();
        
        while(! que.empty())
        {
            
            int sr = que.front().first.first;
            int sc = que.front().first.second;
            int lvl = que.front().second;

            que.pop();
            
            if (mxlvl < lvl)
                mxlvl =lvl;
            
            int dx[]={0,0,1,-1};
            int dy[]={1,-1,0,0};
            
            
            for(int i=0; i<4 ; i++)
            {
                int tr = sr + dx[i];
                int tc = sc + dy[i];
                
                if (tr>=0 && tr<m && tc>=0 && tc<n && mat[tr][tc] == 1 && visited[tr][tc] != 2)
                {
                    que.push({{tr,tc},lvl+1});
                    visited[tr][tc] = 2;
                    
                }
            }
        }
        
        //check if there are any fresh oranges left
        for(int i = 0 ; i <m ; i++ )
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j] == 1)
                    return -1;
            }
        }
        
        return mxlvl;
        
        
        
    }                
                    
                    
                    
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        
        queue<pair<pair<int,int>,int>> que;
        vector<vector<int>> visited = mat;
        int lvl = 0;
        int mxlvl =0;
        
        
        int m = mat.size(); int n=mat[0].size();
        for(int i=0; i<m ; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] == 2)
                {   
                    que.push({{i,j},0});
                }
            }
        }
        
        return bfs(mat,visited,que);
    }
};