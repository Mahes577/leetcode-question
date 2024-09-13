#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;
#define pb push_back;
#define run ios::sync_with_stdio (false); cin.tie (0); cout.tie (0);
#define faster ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define yy cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define nl endl;
#include <unordered_set>
#define MOD 1e9+7
typedef long long int ll;
bool isprime(int n){
    if(n<2) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(int i=3;i*i<=n;i=i+2){
        if(n%i==0) return false;
    }
    return true;
}
int gcd(int a, int b) {
    if(b==0)
    return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return (a/gcd(a,b))*b;
}
long long mod(long long a,long long b){
    return((a%b)+b);
}
int f(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        return dp[i][j]=f(s1,s2,i-1,j-1,dp);
    }
    if(s1[i]!=s2[j]){
        return dp[i][j]=min(1+f(s1,s2,i-1,j-1,dp),min(1+f(s1,s2,i,j-1,dp),1+f(s1,s2,i-1,j,dp)));
    }
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n1=s1.length();
    int n2=s2.length();
    vector<vector<int>>dp(n1,vector<int>(n2,-1));
    cout<<f(s1,s2,n1-1,n2-1,dp)<<endl;
    return 0;
}
