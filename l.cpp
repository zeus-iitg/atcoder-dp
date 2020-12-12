#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long val[n];
    for(int i=0;i<n;i++){
        cin>>val[i];
    }

    long long dp[n][n];

    long long sum=0;

    //base case
    for(int i=0;i<n;i++){
        dp[i][i]=val[i];
        sum=sum+val[i];
    }

    for(int sub_size=2;sub_size<=n;sub_size++){
        for(int start=0;start<=n-sub_size;start++){
            int endd=start+sub_size-1;
            dp[start][endd]=max(val[start]-dp[start+1][endd], val[endd]-dp[start][endd-1]);
        }
    }

    //dp[0][n-1]
    //long long out=(dp[0][n-1]+sum)/2;
    //cout<<out;

    cout<<dp[0][n-1];
    return 0;
}
