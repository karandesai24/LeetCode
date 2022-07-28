class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
         const int m = heights.size(), n = heights[0].size();
        const vector<int> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
     
        priority_queue< pair<int,int>,
                        vector<pair<int,int>>,
                        greater<pair<int,int>>> pq;
       
        vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
      
        pq.push({0, 0});
       
        while( !pq.empty() ){
            pair<int,int> cur = pq.top();
            int effort = cur.first;
            const int x = pq.top().second / 100, y = pq.top().second % 100;
            pq.pop();
            if( x == m-1 && y == n-1 ) return effort;
            if( effort >= efforts[x][y] ) continue;
            else efforts[x][y] = effort;
         
            for(int i=0; i<4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if( nx < 0 || nx >= m || ny < 0 || ny >= n ) continue;
                int n_effort = max( effort, 
                                    abs( heights[x][y] - heights[nx][ny] ));
                pq.emplace( n_effort, nx * 100 + ny);
               
            }
        } return -1;
    }
};