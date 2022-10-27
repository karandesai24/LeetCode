class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source,
                        vector<int>& target) {
    unordered_set<long> blockedSet;
    for (const auto& b : blocked)
      blockedSet.insert(hash(b[0], b[1]));

    return dfs(blockedSet, source[0], source[1], hash(target[0], target[1]),
               {}) &&
           dfs(blockedSet, target[0], target[1], hash(source[0], source[1]),
               {});
  }

 private:
  bool dfs(unordered_set<long>& blockedSet, int i, int j, long target,
           unordered_set<long>&& visited) {
    if (i < 0 || i >= 1e6 || j < 0 || j >= 1e6 ||
        blockedSet.count(hash(i, j)) || visited.count(hash(i, j)))
      return false;

    visited.insert(hash(i, j));
    if (visited.size() > (1 + 199) * 199 / 2 || hash(i, j) == target)
      return true;
    return dfs(blockedSet, i + 1, j, target, move(visited)) ||
           dfs(blockedSet, i - 1, j, target, move(visited)) ||
           dfs(blockedSet, i, j + 1, target, move(visited)) ||
           dfs(blockedSet, i, j - 1, target, move(visited));
  }

  long hash(int i, int j) {
    return (static_cast<long>(i) << 16) + j;
        
    }
};

/*
class Solution {
public:
    bool canReach(vector<int> &source,vector<int> &target,int numBlocked,set<pair<int,int>> &block)
    {
        vector<int> dx,dy;
        dx={0,0,1,-1};
        dy={1,-1,0,0};
        int maxArea=numBlocked*(numBlocked-1)/2;
        int currArea=1;
        set<pair<int,int>> visited;
        queue<pair<int,int>> q;
        q.push({source[0],source[1]});
        visited.insert({source[0],source[1]});
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int new_x,new_y;
                new_x=x+dx[i];
                new_y=y+dy[i];
                if(new_x==target[0]&&new_y==target[1])
                return true;
                if(currArea>maxArea)
                return true;
                if(new_x>=0&&new_x<1e6&&new_y>=0&&new_y<1e6&&block.find({new_x,new_y})==block.end()&&visited.find({new_x,new_y})==visited.end())
                {
                    currArea++;
                    visited.insert({new_x,new_y});
                    q.push({new_x,new_y});
                }
            }
        }
        return false; 
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        set<pair<int,int>> block;
        int count=0;
        for(int i=0;i<blocked.size();i++)
        {
            count++;
            block.insert({blocked[i][0],blocked[i][1]});
        }
        return canReach(source,target,count,block)&&canReach(target,source,count,block);
    }
};
*/
