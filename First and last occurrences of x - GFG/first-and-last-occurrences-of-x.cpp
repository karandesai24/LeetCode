// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    int i = -1, j = -1;

    // searching for first occurence
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        // main logic to check first occurence
        if ((mid == 0 || arr[mid - 1] < x) && arr[mid] == x) {
            i = mid;
            break;
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else high = mid - 1;
    }

    // searching for last occurence 
    low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        // main logic for last occurence  
        if ((mid == n - 1 || arr[mid + 1] > x) && arr[mid] == x) {
            j = mid;
            break;
        }
        else if (x < arr[mid]) {
            high = mid - 1;
        }
        else low = mid + 1;
    }


    return { i,j };
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends