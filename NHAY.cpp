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

ll l;
string n, h;

void solve(){
	cin >> n >> h;

	if(h.size() < n.size()){
		cout << "\n";
		return;
	}
	if(h.size() == n.size()){
		if(h == n)
			cout << "0\n";
		else
			cout << "\n";
		return;
	}
	else{
		vector<ll> pos(0);
		ll hash = 0, p = 27, m = 1e9 + 7, p_pow = 1;
		for(ll i=n.size()-1;i>=0;i--){
			hash = (hash + ((n[i] * p_pow) % m)) % m;
			p_pow = (p * p_pow) % m;
		}

		cout << hash << "--\n";

		ll hash2 = 0;
		p = 27, m = 1e9 + 7, p_pow = 1;
		for(ll i=h.size()-1;i>=h.size()-n.size();i--){
			hash2 = (hash2 + ((h[i] * p_pow) % m)) % m;
			cout << hash2 << " " << i << "\n";
			if(i != h.size()-n.size())
				p_pow = (p * p_pow) % m;
		}

		ll run = h.size()-n.size() - 1, end = h.size()-1;
		while(run > 0){
			cout << hash2 << " " << run << " " << end << "\n";
			if(hash2 == hash)
				pos.push_back(run);

			hash2 = (((hash2 - ((h[end] * p_pow) % m) + m) % m) * p) % m;
			hash2 = (hash2 + ((h[run]) % m)) % m;
			run--;
			end--;
		}

		reverse(pos.begin(), pos.end());

		for(ll i=0;i<pos.size();i++)
			cout << pos[i] << " ";
		cout << "\n";
	}
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	while(cin >> l)
		solve();

	return 0;
}