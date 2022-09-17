class Solution {
private:
    int solve(int n, int k){
        if(n == 0){
            return 0;
        }
        
        return (solve(n-1,k)+k)%n;
    }
public:
    int findTheWinner(int n, int k) {
        int ans = solve(n , k);
        return ans+1;
    }
};