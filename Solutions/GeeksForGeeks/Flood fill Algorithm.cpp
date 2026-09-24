class Solution {
  public:
  
    void dfs(vector<vector<int>>& image, vector<vector<int>>& visited,
             int sr, int sc, int newColor, int presentColor)
    {
        visited[sr][sc] = newColor;
        
        int dx[] = {0, 0, 1,-1};
        int dy[] = {1,-1, 0, 0};
        
        for(int i=0; i<4; i++)
        {
            int nr = sr + dx[i];
            int nc = sc + dy[i];
            
            if ((nr>=0 && nr < image.size() && nc>=0 && nc < image[0].size()) &&
                visited[nr][nc] != newColor &&  image[nr][nc] == presentColor)
                dfs(image , visited, nr, nc, newColor, presentColor);
        }
        
    }
  
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // code here
        vector <vector<int>>visited(
                image.size(),
                vector<int> (image[0].size(),0)
        );
        
        for(int i=0; i <image.size(); i++)
        {
            for(int j=0; j<image[0].size();j++)
               visited[i][j] = image[i][j];
        }
        
        
        dfs(image , visited, sr, sc, newColor, image[sr][sc]);
        
        return visited;
    }
};