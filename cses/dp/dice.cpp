#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX 1000000007
ll n;
ll dp[1000006];

// Top to Bottom Approach

int dice1(ll sum ,ll dp[]){
    if(sum > n){
        return 0;
    }
    if(sum==n){
        return 1;
    }
    if(dp[sum] != -1){
        return dp[sum];
    }
    ll ans =0;
    for(ll i =1;i<=6;i++){
        if(sum + i<= n){
            ll ways = dice1(sum+i,dp);
            ans += ways;
        }
    }
    dp[sum] = ans;
    return ans;

}

//Bottom to Top Approach

int dice2(ll sum){
    dp[0] = 1;
    for(ll i =1;i<=sum;i++){
        dp[i] = 0;
        for(ll j = 1;j<=6;j++){
            if( j <= i){
                dp[i] = (dp[i] + dp[i-j]) % MAX;
            }
        }

    }
    return dp[sum];
}

int main(){
    
    cin>>n;
    memset(dp, -1, sizeof(dp));
    cout<<dice2(n)<<endl;
}