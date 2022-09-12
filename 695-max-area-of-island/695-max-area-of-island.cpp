class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, int& c)
    {
        if (i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j] == 0) return 0;
        
        grid[i][j]=0;
        c++;
        helper(grid, i-1, j, c);
        helper(grid, i+1, j, c);
        helper(grid, i, j-1, c);
        helper(grid, i, j+1, c);
        
        return c;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int row = grid.size(), col = grid[0].size();
        int maxi = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    int c = 0;
                    maxi = max(maxi, helper(grid, i, j, c));
                }
            }
        }
        return maxi;
    }
};