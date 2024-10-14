#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

ll top_to_bottom(ll x,ll index,vector<ll> arr,vector<vector<ll>>& dp){  
    if(x == 0){
        return 1;
    }
    if(dp[x][index] != -1){
        return dp[x][index];
    }
    ll count = 0;
    for(ll i =index;i<arr.size();i++){
        if((x-arr[i]) >=0){
            count = (count + top_to_bottom(x - arr[i],i, arr, dp))%MOD;
        }
    }
    dp[x][index]=count;
    return count;    
}

// ll bottom_to_top(){

// } 

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
    arr.assign(s.begin(), s.end());
    vector<vector<ll>> dp(x +1,vector<ll>(arr.size(), -1));
    
    cout<<top_to_bottom(x,0,arr,dp);
    // cout<<bottom_to_top(x, arr,dp);
    return 0;
}