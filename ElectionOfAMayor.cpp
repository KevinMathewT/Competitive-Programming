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

ll n, a[200010], b[200010], c[200010], countAns;
vector<ll> p;

void solve(){
	countAns = 0;
	cin >> n;
	ll l = 0, w = 0;
	for(ll i=0;i<n;i++){
		cin >> a[i] >> b[i];
		if(a[i] > b[i]){
			c[i] = 1;
			w++;
		}
		else{
			c[i] = 0;
			l++;
		}
	}

	if(w > l){
		cout << 0 << "\n";
		return;
	}

	for(ll i=0;i<n-1;i++){
		if(w > l)
			break;
		if(c[i] == 0 && c[i+1] == 0){
			countAns++;
			p.push_back(i);
			l--;
			i++;
			continue;
		}
		if((c[i] ^ c[i+1]) == 1 && (a[i] + a[i+1]) > (b[i] + b[i+1])){
			countAns++;
			p.push_back(i);
			l--;
			i++;
			continue;
		}
	}

	if(w <= l){
		cout << -1 << "\n";
		return;
	}

	cout << countAns << "\n";
	for(ll i=0;i<p.size();i++)
		cout << p[i] + 1 << " " << p[i] + 2 << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}