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

ll x, s, y, m, z, c, l;
char ctp1, ctp2, o;

ll generate(ll pos, string u, ll a, ll b, ll d){
	// cout << pos << " " << u << "\n";
	l++;
	if(l >= 50){
		cout << "alsldhguaskhdkfjhskjdfksdf\n";
		exit(0);
	}
	if((pos >= s && a < s) || (pos >= (s + m) && b < m) || (pos >= (s + m + c) && d < c))
		return 0;

	if(pos >= (s + m + c)){
		cout << u << "\n";
		return 1;
	}

	ll sum = 0;
	if(pos < s){
		for(ll i=(ll)max(((char)('A')), (char)(u[pos-1]+1));i<(ll)('A' + x);i++){
			cout << (char)i << "-" << (char)('A' + x) << "\n";
			string t = u;
			t.push_back((char)i);
			sum += generate(pos+1, t, a + 1, b, d);
		}
		// cout << "tfuygfh nkadgghjkehginjkagbeifdjgfbaujdgsfbwejgSDFUJGEBSUDKJFBC\n";
	}

	else if(pos < (s + m)){
		for(char i=max(((char)('A' + x)), (char)(u[pos-1]+1));i<('A' + x + y);i++){
			string t = u;
			t.push_back(i);
			sum += generate(pos+1, t, a, b + 1, d);
		}
	}

	else{
		for(char i=max(((char)('A' + x + y)), (char)(u[pos-1]+1));i<('A' + x + y + z);i++){
			string t = u;
			t.push_back(i);
			sum += generate(pos+1, t, a, b, d + 1);
		}
	}

	return sum;
}

void solve(){
	cin >> x >> s >> y >> m >> z >> c >> ctp1 >> ctp2 >> o;
	l = 0;
	cout << generate(0, "", 0, 0, 0) << "\n";
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