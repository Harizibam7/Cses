#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll dp[1000006];
int dice(ll sum ,ll dp[]){
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
            ll ways = dice(sum+i,dp);
            ans += ways;
        }
    }
    dp[sum] = ans;
    return ans;

}

int main(){
    
    cin>>n;
    memset(dp, -1, sizeof(dp));
    cout<<dice(0,dp)<<endl;
}