class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originColor = image[sr][sc];
        if( originColor != newColor ) 
            dfs(image, sr, sc, originColor, newColor);
        return image;
    }
private:
    void dfs(vector<vector<int>>& image, int i, int j, int originColor, int newColor){
        if(i>=0 && i<image.size() && j>=0 && j<image[0].size() && image[i][j] == originColor){
            image[i][j] = newColor;
            dfs(image, i+1, j, originColor, newColor);
            dfs(image, i, j+1, originColor, newColor);
            dfs(image, i-1, j, originColor, newColor);
            dfs(image, i, j-1, originColor, newColor);
        } return;
    }
};