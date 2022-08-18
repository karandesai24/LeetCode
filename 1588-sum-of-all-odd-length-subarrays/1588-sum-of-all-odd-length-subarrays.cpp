class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
      int n=arr.size();
        int sum=0;
        int sum1=0;
        for(int i=0;i<n;i++)
        {
           
            int count=0;
            for(int j=i;j<n;j++)
            {
                count++;
                sum1+=arr[j];
                if(count%2!=0)
                {
                    sum+=sum1;
                }
            }
            sum1=0;
        }
        return sum;
    }
};