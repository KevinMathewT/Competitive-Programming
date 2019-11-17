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

ll s[3], arr[3][50010], inc[3][50010];
set<ll> st;

void solve(){
	cin >> s[0] >> s[1] >> s[2];
	for(ll i=0;i<s[0];i++)
		cin >> arr[0][i];
	for(ll i=0;i<s[1];i++)
		cin >> arr[1][i];
	for(ll i=0;i<s[2];i++)
		cin >> arr[2][i];

	sort(arr[0], arr[0] + s[0]);
	sort(arr[1], arr[1] + s[1]);
	sort(arr[2], arr[2] + s[2]);

	for(ll i=0;i<3;i++){
		set<ll> in;
		for(ll j=0;j<s[i];j++)
			in.insert(arr[i][j]);
		for(ll j=0;j<s[(i+1) % 3];j++){
			ll sz = in.size();
			in.insert(arr[(i+1) % 3][j]);
			if(in.size() == sz)
				st.insert(arr[(i+1) % 3][j]);
		}
	}

	cout << st.size() << "\n";
	for(auto ele : st)
		cout << ele << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}