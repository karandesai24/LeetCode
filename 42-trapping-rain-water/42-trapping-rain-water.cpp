class Solution {
public:
long max (long a, long b){
    if(a>b)
        return a;
    else
        return b;
    
}
    int trap(vector<int>& height) {
        int n=height.size();
        long left_max = 0, right_max = 0;
   
            int i = 0, j = n-1;
   
            long sum = 0;
   
            while(i < j){
                
                left_max = max(left_max, height[i]);
                right_max = max(right_max, height[j]);
                
                if(left_max < right_max){
                    
                    sum += (left_max - height[i]);
                    i++;
                    
                }
                else{
                    
                    sum += (right_max - height[j]);
                    j--;
                    
                    
                }
                
            }
   
            return sum;
    }
};