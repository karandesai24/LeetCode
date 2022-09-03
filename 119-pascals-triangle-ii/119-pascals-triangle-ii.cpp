class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<int> prev,next;
		prev.push_back(1);
		if(rowIndex==0) return prev;
		for(int i=1;i<=rowIndex;i++)  {
			next.resize(i+1);
			next[0]=1,next[i]=1;
			for(int j=1;j<i;j++) {
				next[j]=prev[j]+prev[j-1];
			}
			prev=next;
		}
		return prev;
    }
};