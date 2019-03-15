#include<iostream>
#define L 1002
using namespace std;

long long dp[L][L];
int M=0,N=0;

long long GCD(long long a,long long b){
    return b==0?a:GCD(b,a%b);
}
long long C(int n,int r){
    if(n<r)return 0;
    r=min(r,n-r);
    long long ans = 1;
    for(int i=0;i<r;i++)
        ans=ans*(n-i)/(i+1);
    return ans;
}

int main(){

    for(int i=2;i<L;i++)
        for(int j=2;j<L;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+GCD(i,j)-1;
    for(int i=2;i<L;i++)
        for(int j=2;j<L;j++)
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];

    int counter=0;
    cin>>M>>N;
    while(M&&N){
        long long triangle = C((M+1)*(N+1),3)-C(M+1,3)*(N+1)-C(N+1,3)*(M+1)-2*dp[M][N];

        cout<<"Case "<<++counter<<": "<<triangle<<endl;
        cin>>M>>N;
    }
    return 0;
}
