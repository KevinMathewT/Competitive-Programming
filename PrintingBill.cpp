#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Author - Shubham Kumar
// Birla Institute of Technology, Mesra

ll n;

void te(){
	cin >> n;
	pair<ld, pair<string, string> > a[n];
	ld tot = 0;

	for(ll i=0;i<n;i++){
		string s; ld p, d;
		cin >> s >> p >> d;

		p -= ((p * d) / 100);
		tot += p;
		p = p * 100;
		p = round(p);
		p = p / 100;
		a[i].first = -p;
		a[i].second.first = s;
		a[i].second.second = s;
		for(ll j=0;j<a[i].second.first.size();j++)
			a[i].second.first[j] = tolower(a[i].second.first[j]);
	}

	sort(a, a + n);

	for(ll i=0;i<n;i++){
		cout << a[i].second.second << " " << -a[i].first << "\n";
	}

	tot = tot * 100;
	tot = round(tot);
	tot = tot / 100;

	cout << "Total " << tot << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.
	cout << fixed << setprecision(2);

	te();

	return 0;
}