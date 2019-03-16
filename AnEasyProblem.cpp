#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll h, m, x;
string s, s1, s2;

void te(){
	cin >> s;
	cin >> x;
	s1 = s.substr(0, 2);
	s2 = s.substr(3, 2);

	h = stoll(s1);
	m = stoll(s2);

	// cout << h << " " << m << "\n";

	ll th = h;
	ll tm = m;
	ll i = 0;

	for(ll i=0;i<10000;i++){
		ll f = h / 10;
		ll s = h % 10;
		ll thi = m / 10;
		ll fo = m % 10;

		// cout << f << " " << s << " " << thi << " " << fo << "\n";
		// cout << (f + s + thi + fo) << "\n";

		if(((f + s + thi + fo) % x) == 0){
			cout << i << "\n";
			return;
		}

		m++;
		if(m == 60){
			m = m % 60;
			h++;
			if(h == 24){
				h = h % 24;
			}
		}

		if(h == th && m == tm){
			cout << -1 << "\n";
			return;
		}
	}
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