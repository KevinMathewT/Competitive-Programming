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

vector<ll> sort_cyclic_shifts(string const& s) {
    ll n = s.size();
    const ll alphabet = 256;

    vector<ll> p(n), c(n), cnt(max(alphabet, n), 0);
    vector<pair<char, ll> > pcl(n);
    for(ll i=0;i<n;i++)
        pcl[i] = {s[i], i};
    sort(pcl.begin(), pcl.end());
    map<char, ll> m;
    ll classes = 0;
    for(ll i=0;i<n;i++)
        if(m.find(pcl[i].first) == m.end())
            m[pcl[i].first] = classes++;

    for(ll i=0;i<n;i++){
        p[i] = pcl[i].second;
        c[i] = m[s[i]];
    }

    for(ll i=0;i<n;i++)
    	cout << s[i] << " ";
    cout << "\n";

    for(ll i=0;i<n;i++)
    	cout << p[i] << " ";
    cout << "\n";

    for(ll i=0;i<n;i++)
    	cout << c[i] << " ";
    cout << "\n";

    vector<ll> pn(n), cn(n);
    for (ll h = 0; (1 << h) < n; ++h) {
        for (ll i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (ll i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (ll i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (ll i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (ll i = 1; i < n; i++) {
            pair<ll, ll> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<ll, ll> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<ll> suffix_array_construction(string s) {
    s += "$";
    vector<ll> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

void solve(){
	string s = "aaabab";
	vector<ll> v = suffix_array_construction(s);
	for(ll i : v)
		cout << i << " ";
	cout << "\n";
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