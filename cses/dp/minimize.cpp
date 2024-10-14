
#include<bits/stdc++.h>
#define ll long long
using namespace std;



// Top to Bottom Approach
ll top_to_bottom(ll x, vector<ll> arr, vector<ll>& dp){
    if(x == 0){
        return 0;
    }
    if(x < 0){
        return LLONG_MAX;
    }
    if(dp[x] != -1){
        return dp[x];
    }
    ll value = LLONG_MAX;
    for(ll i = 0; i < arr.size(); i++){
        
        ll val = top_to_bottom(x - arr[i], arr, dp);
        if(val != LLONG_MAX){
            value = min(value, val+1);
        }
    }
    dp[x] = value;
    return dp[x];
}

ll bottom_to_top(ll x, vector<ll> arr, vector<ll>& dp){
    dp[0]= 0;
    for(ll i =1;i<=x;i++){
        for(ll coin: arr){
            if((i -coin) >=0){
                if(dp[i-coin] != LLONG_MAX){
                    dp[i]=min(dp[i],dp[i-coin] +1);
                }
            }
        }
    }
    return dp[x];
}


int main(){
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    // vector<ll> dp(x + 1, LLONG_MAX);  //For Top to Bottom
    vector<ll> dp(x + 1, LLONG_MAX); //For Bottom to top
    // ll result = top_to_bottom(x, arr, dp);
    ll result = bottom_to_top(x, arr, dp);
    if(result == LLONG_MAX){
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}
