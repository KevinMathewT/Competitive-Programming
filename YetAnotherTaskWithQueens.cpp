#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

unordered_map<ll, vector<pair<ll, ll> > > strDiag;
unordered_map<ll, vector<pair<ll, ll> > > altDiag;
unordered_map<ll, vector<pair<ll, ll> > > sameRow;
unordered_map<ll, vector<pair<ll, ll> > > sameCol;
vector<pair<ll, ll> > v;
ll n, m, ans[9];

void te(){
	for(ll i=0;i<9;i++)
		ans[i] = 0;
	cin >> n >> m;
	for(ll i=0;i<m;i++){
		ll r, c;
		cin >> r >> c;
		v.push_back(make_pair(r, c));
	}

	sort(v.begin(), v.end());

	for(ll i=0;i<m;i++){
		ll r, c;
		r = v[i].first, c = v[i].second;

		strDiag[r+c].push_back(make_pair(r, c));
		altDiag[r-c].push_back(make_pair(r, c));
		sameRow[r].push_back(make_pair(c, r));
		sameCol[c].push_back(make_pair(r, c));
	}

	for(ll i=0;i<=2*n;i++)
		if(strDiag[i].size() != 0)
			sort(strDiag[i].begin(), strDiag[i].end());

	for(ll i=-n;i<=n;i++)
		if(strDiag[i].size() != 0)
			sort(altDiag[i].begin(), altDiag[i].end());

	for(ll i=0;i<=n;i++)
		if(sameRow[i].size() != 0)
			sort(sameRow[i].begin(), sameRow[i].end());

	for(ll i=0;i<=n;i++)
		if(sameCol[i].size() != 0)
			sort(sameCol[i].begin(), sameCol[i].end());

	for(ll i=0;i<m;i++){
		ll s = 0;
		ll r = v[i].first, c = v[i].second;
		pair<ll, ll> p = v[i];
		pair<ll, ll> rev = make_pair((ll)c, (ll)r);
		if(strDiag[r+c].size() == 1)
			s += 0;
		else if(strDiag[r+c].size() == 2)
			s += 1;
		else{
			if(strDiag[r+c][0] == p || strDiag[r+c][strDiag[r+c].size()-1] == p)
				s++;
			else
				s+=2;
		}

		if(altDiag[r-c].size() == 1)
			s += 0;
		else if(altDiag[r-c].size() == 2)
			s += 1;
		else{
			if(altDiag[r-c][0] == p || altDiag[r-c][altDiag[r-c].size()-1] == p)
				s++;
			else
				s+=2;
		}

		if(sameRow[r].size() == 1)
			s += 0;
		else if(sameRow[r].size() == 2)
			s += 1;
		else{
			if(sameRow[r][0] == rev || sameRow[r][sameRow[r].size()-1] == rev)
				s++;
			else
				s+=2;
		}

		// for(ll i=0;i<sameRow[r].size();i++)
		// 	cout << sameRow[r][i].first << " " << sameRow[r][i].second << "\n";

		if(sameCol[c].size() == 1)
			s += 0;
		else if(sameCol[c].size() == 2)
			s += 1;
		else{
			if(sameCol[c][0] == p || sameCol[c][sameCol[c].size()-1] == p)
				s++;
			else
				s+=2;
		}

		// cout << r << " " << c << " " << s << "\n";

		ans[s]++;
	}

	for(ll i=0;i<9;i++)
		cout << ans[i] << " ";
	cout << "\n";
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