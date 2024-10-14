#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define MOD 1000000007

ll top_to_bottom(ll x, vector<ll> arr,vector<ll>& dp){
    if(x == 0){
        return 1;
    }
    if(dp[x] != -1){
        return dp[x];
    }
    ll count = 0;
    for(ll i =0;i<arr.size();i++){
        if((x-arr[i]) >=0){
            count = (count + top_to_bottom(x - arr[i], arr, dp))%MOD;
        }
    }
    dp[x]=count;
    return count;
}

ll bottom_to_top(ll x, vector<ll> arr,vector<ll>& dp){
    dp[0]= 1;
    for(ll i= 1;i<= x;i++){
        dp[i]= 0;
        for(ll j =0;j<arr.size();j++){
            if((i-arr[j]) >=0){
                dp[i] =(dp[i] + dp[i-arr[j]])% MOD;
            }
        }
    }
    return dp[x];
}

int main(){
    ll n, x;
    cin>>n>>x;
    set<ll> s;
    for(ll i =0;i<n;i++){
        ll value;
        cin>>value;
        s.insert(value);
    }
    vector<ll> arr;
    vector<ll> dp(x +1, -1);
    arr.assign(s.begin(), s.end());
    // cout<<top_to_bottom(x,arr,dp);
    cout<<bottom_to_top(x, arr,dp);
    return  0;
}