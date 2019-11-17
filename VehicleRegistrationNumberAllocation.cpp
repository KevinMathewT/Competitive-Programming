#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Shubham Kumar
// Birla Institute of Technology, Mesra
// Was trying out a Digit DP solution.

string l, u, p;
ll dp[50][2][50], dp1[50][2][50], size, p_size;

bool is_num(char x){
	if(x >= '0' && x <= '9')
		return true;
	return false;
}

bool is_letter(char x){
	if(x >= '0' && x <= '9')
		return false;
	return true;
}

ll DP(ll idx, ll tight, ll curr){
	// cout << idx << " " << tight << " " << curr << "\n";
	if(idx == size-1 && curr == p_size) return 1;
	if(idx == size-1 && curr == p_size-1 && p[curr] <= l[idx]) return 1;
	if(dp[idx][tight][curr] != -1)
		return dp[idx][tight][curr];

	ll ans;
	if(tight){
		ans = 0;
		if(is_letter(l[idx+1])){
			if(curr < p_size){
				if(is_letter(p[curr+1]) && p[curr+1] < l[idx+1])
					ans += DP(idx+1, 0, curr+1);
				if(is_letter(p[curr+1]) && p[curr+1] == l[idx+1])
					ans += DP(idx+1, 1, curr+1);
			}

			if(curr == p_size){
				for(ll i=0;i<l[idx+1]-'A';i++){
					cout << i << "\n";
					ans += DP(idx+1, 0, curr);
				}
				ans += DP(idx+1, 1, curr);
			}

			for(char i='A';i<l[idx+1];i++)
				ans += DP(idx+1, 0, -1);
			ans += DP(idx+1, 1, -1);
		}
		if(is_num(l[idx+1])){
			if(curr < p_size){
				if(is_num(p[curr+1]) && p[curr+1] < l[idx+1])
					ans += DP(idx+1, 0, curr+1);
				if(is_num(p[curr+1]) && p[curr+1] == l[idx+1])
					ans += DP(idx+1, 1, curr+1);
			}

			if(curr == p_size){
				for(ll i=0;i<l[idx+1];i++)
					ans += DP(idx+1, 0, curr);
				ans += DP(idx+1, 1, curr);
			}

			for(ll i=0;i<l[idx+1];i++)
				ans += DP(idx+1, 0, -1);
			ans += DP(idx+1, 1, -1);
		}
	}

	else{
		ans = 0;
		if(is_letter(l[idx+1])){
			if(curr < p_size){
				if(is_letter(p[curr+1]) && p[curr+1] <= l[idx+1])
					ans += DP(idx+1, 0, curr+1);
			}

			if(curr == p_size){
				for(char i='A';i<=l[idx+1];i++)
					ans += DP(idx+1, 0, curr);
			}

			for(char i='A';i<=l[idx+1];i++)
				ans += DP(idx+1, 0, -1);
		}
		if(is_num(l[idx+1])){
			if(curr < p_size){
				if(is_num(p[curr+1]) && p[curr+1] <= l[idx+1])
					ans += DP(idx+1, 0, curr+1);
			}

			if(curr == p_size){
				for(ll i=0;i<=l[idx+1];i++)
					ans += DP(idx+1, 0, curr);
			}

			for(ll i=0;i<=l[idx+1];i++)
				ans += DP(idx+1, 0, -1);
		}
	}

	return dp[idx][tight][curr] = ans;
}

ll DP1(ll idx, ll tight, ll curr){
	if(idx == size-1 && curr == p_size) return 1;
	if(idx == size-1 && curr == p_size-1 && p[curr] <= u[idx]) return 1;
	if(dp1[idx][tight][curr] != -1)
		return dp1[idx][tight][curr];

	ll ans;
	if(tight){
		ans = 0;
		if(is_letter(u[idx+1])){
			if(curr < p_size){
				if(is_letter(p[curr+1]) && p[curr+1] < u[idx+1])
					ans += DP1(idx+1, 0, curr+1);
				if(is_letter(p[curr+1]) && p[curr+1] == u[idx+1])
					ans += DP1(idx+1, 1, curr+1);
			}

			if(curr == p_size){
				for(char i='A';i<u[idx+1];i++)
					ans += DP1(idx+1, 0, curr);
				ans += DP1(idx+1, 1, curr);
			}

			for(char i='A';i<u[idx+1];i++)
				ans += DP1(idx+1, 0, -1);
			ans += DP1(idx+1, 1, -1);
		}
		if(is_num(u[idx+1])){
			if(curr < p_size){
				if(is_num(p[curr+1]) && p[curr+1] < u[idx+1])
					ans += DP1(idx+1, 0, curr+1);
				if(is_num(p[curr+1]) && p[curr+1] == u[idx+1])
					ans += DP1(idx+1, 1, curr+1);
			}

			if(curr == p_size){
				for(ll i=0;i<u[idx+1];i++)
					ans += DP1(idx+1, 0, curr);
				ans += DP1(idx+1, 1, curr);
			}

			for(ll i=0;i<u[idx+1];i++)
				ans += DP1(idx+1, 0, -1);
			ans += DP1(idx+1, 1, -1);
		}
	}

	else{
		ans = 0;
		if(is_letter(u[idx+1])){
			if(curr < p_size){
				if(is_letter(p[curr+1]) && p[curr+1] <= u[idx+1])
					ans += DP1(idx+1, 0, curr+1);
			}

			if(curr == p_size){
				for(char i='A';i<=u[idx+1];i++)
					ans += DP1(idx+1, 0, curr);
			}

			for(char i='A';i<=u[idx+1];i++)
				ans += DP1(idx+1, 0, -1);
		}
		if(is_num(u[idx+1])){
			if(curr < p_size){
				if(is_num(p[curr+1]) && p[curr+1] <= u[idx+1])
					ans += DP1(idx+1, 0, curr+1);
			}

			if(curr == p_size){
				for(ll i=0;i<=u[idx+1];i++)
					ans += DP1(idx+1, 0, curr);
			}

			for(ll i=0;i<=u[idx+1];i++)
				ans += DP1(idx+1, 0, -1);
		}
	}

	return dp1[idx][tight][curr] = ans;
}

void te(){
	cin >> u >> p;
	u[9] = u[9] + 1;
	cout << u << "\n";
	size = 10, p_size = p.size();
	l = "KA01AA0001";

	for(ll i=0;i<50;i++)
		for(ll j=0;j<2;j++)
			for(ll k=0;k<50;k++)
				dp[i][j][k] = dp1[i][j][k] = -1;

	cout << DP1(0, 1, 0) - DP(0, 1, 0) << "\n";

	// for(ll i=0;i<50;i++)
	// 	for(ll j=0;j<2;j++)
	// 		for(ll k=0;k<50;k++)
	// 			cout << i << " " << j << " " << k << " " << dp[i][j][k] << "\n";
	// for(ll i=0;i<50;i++)
	// 	for(ll j=0;j<2;j++)
	// 		for(ll k=0;k<50;k++)
	// 			cout << i << " " << j << " " << k << " " << dp1[i][j][k] << "\n";

}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}