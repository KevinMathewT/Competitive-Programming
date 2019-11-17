#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

string solve(string s){
	ll n = s.size();
        if(n == 0){
            string ret("");
            return ret;
        }
        ll dp[n][n];
        
        for(ll i=0;i<n;i++){
            for(ll j=0;j+i<n;j++){
                if(i == 0)
                    dp[j][j+i] = 1;
                else if(i == 1){
                    if(s[j] == s[j+1])
                        dp[j][j+i] = 2;
                    else
                        dp[j][j+i] = 1;
                }
                else{
                    if(s[j] == s[j + i])
                        dp[j][j+i] = dp[j+1][j+i-1] + 2;
                    else
                        dp[j][j+i] = max(dp[j+1][j+i], dp[j][j+i-1]);
                }
            }
        }
        
        ll nn = dp[0][n-1];
        string ret(nn, '0');
            
        ll st = 0, end = nn-1;
        ll dst = 0, dend = n-1;
        while(st <= end && dst <= dend){
            if(s[dst] == s[dend]){
                ret[st] = ret[end] = s[dst];
                st++; end--;
                dst++; dend--;
            }
            else{
                if(dp[dst][dend-1] >= dp[dst+1][dend])
                    dend--;
                else
                    dst++;
            }
        }
        
        return ret;	
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	string s;
	cin >> s;
	cout << solve(s) << "\n";

	return 0;
}