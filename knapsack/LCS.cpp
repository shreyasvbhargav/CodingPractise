#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int LCS(string s1, string s2, int m, int n){
    if(m==0 || n==0)
        return 0;

    if(s1[m-1] == s2[n-1])
        return (1+LCS(s1, s2, m-1, n-1));
    else
        return max(LCS(s1, s2, m-1, n), LCS(s1, s2, m, n-1));

}
int m, n;
int dp[6][7];
int LCS_dp(string s1, string s2, int m, int n){
    int i,j;
    for(i=0; i<=n; i++)
        dp[0][i] = 0;
    for(i=0; i<=m; i++)
        dp[i][0] = 0;

    for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[i-1][j-1];
}

string print_LCS(string s1, string s2){
    int i=s1.length(), j=s2.length();
    string lcs;
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            lcs.push_back(s1[i-1]);
            i--; j--;
        }   
        else{
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    cout<<lcs<<endl;
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main(){
    string s1 = "acbcf";
    string s2 = "abcdaf"; // 
    m = s1.length();
    n = s2.length();

    //cout<<LCS(s1, s2, s1.length(), s2.length())<<endl;
    cout<<LCS_dp(s1, s2, m, n)<<endl;
    cout<<print_LCS(s1, s2);
}