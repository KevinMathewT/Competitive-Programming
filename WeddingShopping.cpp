#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

const ll SIZE = 1e3;
ll dp[SIZE][SIZE];
ll k[220];
vector<ll> v[30];
ll m, c;

int DP(ll pos, ll outn, ll left){
	cout << pos << " " << outn << " " << left << "\n";
	if(left < 0)
		return INT_MAX;
	if(outn >= k[pos])
		return INT_MAX;
	if(pos >= c)
		return left;
	if(dp[pos][left] != -1)
		return dp[pos][left];
	return dp[pos][left] = min(DP(pos+1, 0, left-v[pos][outn]), DP(pos, outn+1, left));
}

void te(){
	cin >> m >> c;
	cout << m << " " << c << "\n";
	ll t;
	for(ll i=0;i<c;i++){
		cin >> k[i];
		for(ll j=0;j<k[i];j++){
			cin >> t;
			v[i].push_back(t);
		}
	}

	for(ll i=0;i<c;i++) memset(dp[i], -1, SIZE);

	cout << DP(0, 0, m) << "\n";
	cout << INT_MAX << "\n";
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
	cout << T << "\n";
	for(ll i=0;i<T;i++)
		te();

	return 0;
}