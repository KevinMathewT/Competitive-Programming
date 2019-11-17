#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;

void te(){
	cin >> n;
	ll ans = 1;
	ll t = n, c = 0;
	while(t > 0){
		ans *= t % 10;
		t /= 10;
		c++;
	}

	// cout << c << "\n";
	t = n;

	ll b = 10;
	for(ll i=1;i<=c;i++){
		ll curr = 1;
		ll l = t % 10;
		// cout << t << "-\n";
		if(t % 10 == 0){
			t /= 10;
			continue;
		}
		// cout << t << "--\n";
		t = t / 10; ll co = 0;
		ll left = t % b;
		// cout << t << "---\n";
		ll k = t;
		while(k > 0){
			curr *= k % 10;
			k /= 10;
			co++;
		}
		// cout << curr << "----\n";
		for(ll j=c-i+1;j<c;j++)
			curr *= 9;
		// cout << curr << "-----\n";
		if(l == 1 && i == c){}
		else
			curr *= (l-1);
		b *= 10;
		// cout << curr << "------\n";
		ans = max(ans, curr);
	}

	cout << ans << "\n";
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