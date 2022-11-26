class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v[graph.size()];
		for(int i=0; i<graph.size(); i++){v[i]=-1;}
		for(int i=0; i<graph.size(); i++){
			if(v[i]==-1){
				v[i]=0;
				queue<int>q;
				q.push(i);
				while(!q.empty()){
					int ind=q.front();
					q.pop();
					for(auto it: graph[ind]){
						if(v[it]==-1){
							v[it]=!v[ind];
							q.push(it);
						}
						else if(v[it]==v[ind]){return false;}
					}
				}
			}
		}
		return true;
    }
};
/*
class Solution {
public:
	bool dfs(int x, int y, int v[], vector<vector<int>>& graph){
		v[x]=y;
		for(auto it: graph[x]){
			if(v[it]==-1){
				if(!dfs(it, !y, v, graph)){return false;};
			}
			else if(v[it]==v[x]){return false;}
		}
		return true;
	}
	bool isBipartite(vector<vector<int>>& graph) {
		int v[graph.size()];
		for(int i=0; i<graph.size(); i++){v[i]=-1;}
		for(int i=0; i<graph.size(); i++){
			if(v[i]==-1){
				if(!dfs(i, 0, v, graph)){return false;};
			}
		}
		return true;
	}
};
*/