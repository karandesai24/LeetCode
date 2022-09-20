class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        	long long ways=0;
			for(int i=0;(total-i*cost1)>=0;i++){
				int j=(total-i*cost1)/cost2;
				ways+=j+1;       
			}
			return ways;
    }
};