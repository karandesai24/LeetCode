class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
         int n=points.size();
        if(n<=2) return n;
        int ans=2;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int temp=2;
                for(int k=0; k<n && k!=i && k!=j ; k++){
                  int t1= (points[j][1]-points[i][1])*(points[k][0]-points[i][0]);
                  int t2= (points[k][1]-points[i][1])*(points[j][0]-points[i][0]);
                  if(t1==t2) temp++;  
                }
               ans=max(ans, temp); 
            }
        }
       return ans; 
    }
};