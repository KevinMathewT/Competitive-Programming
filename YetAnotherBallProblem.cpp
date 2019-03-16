#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, k;
ll ans[200010][2];

void te(){
	cin >> n >> k;

	ll f = 1, s = 2;

	for(ll i=1;i<=n;i+=2){
		if(f > k || s > k){
			cout << "NO\n";
			return;
		}
		ans[i][0] = f;
		ans[i][1] = s;

		s++;
		if(s > k){
			f++;
			s = f + 1;
		}
	}

	for(ll i=2;i<=n;i+=2){
		ans[i][0] = ans[i-1][1];
		ans[i][1] = ans[i-1][0];
	}

	cout << "YES\n";
	for(ll i=1;i<=n;i++)
		cout << ans[i][0] << " " << ans[i][1] << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}