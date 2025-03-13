#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int


int LCS(string s,string t,int i, int j,vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==t[j]){
        return dp[i][j]= 1+LCS(s,t,i-1,j-1,dp);
    }
    return max(LCS(s,t,i-1,j,dp),LCS(s,t,i,j-1,dp));
}

signed main(){
    string s,t; 
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
 
    cout<<LCS(s,t,n-1,m-1,dp)<<endl;
    return 0;
}




 