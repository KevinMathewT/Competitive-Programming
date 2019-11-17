#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    os << "]";
	return os;
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

#define MAXLEN 50010

char st[MAXLEN];

ll SA[MAXLEN], RA[MAXLEN], tempSA[MAXLEN], tempRA[MAXLEN], counting[MAXLEN];
ll n;

void countingSort(ll k){
    ll maxRange = max((ll)260, n);
    memset(counting, 0, sizeof counting);
    for (ll i = 0; i < n; i++)
        counting[i + k < n ? RA[i + k] : 0]++;

    ll sum = 0;
    for (ll i = 0; i < maxRange; i++){
        ll temp = counting[i];
        counting[i] = sum;
        sum += temp;
    }

    for (ll i = 0 ; i < n; i++)
        tempSA[counting[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    for (ll i = 0; i < n; i++)
        SA[i] = tempSA[i];
}

void constructSA(){
    for (ll i = 0; i < n; i++){
        SA[i] = i;
        RA[i] = st[i];
    }

    for (ll k = 1; k < n; k <<= 1){
        countingSort(k);
        countingSort(0);
        ll rank;
        tempRA[SA[0]] = rank = 0;
        for (ll i = 1; i < n; i++)
            tempRA[SA[i]] = (RA[SA[i - 1]] == RA[SA[i]] && RA[SA[i - 1] + k] == RA[SA[i] + k]) ? rank : ++rank;
        for (ll i = 0; i < n; i++)
            RA[i] = tempRA[i];
        if (RA[SA[n - 1]] == n - 1)
            break;
    }
}

ll LCP[MAXLEN], PLCP[MAXLEN], Phi[MAXLEN];

void computeLCP(){
    Phi[SA[0]] = -1;
    for (ll i = 1; i < n; i++)
        Phi[SA[i]] = SA[i - 1];
    ll L = 0;
    for (ll i = 0; i < n; i++){
        if (Phi[i] == -1){
            PLCP[i] = 0;
            continue;
        }
        while (st[i + L] == st[Phi[i] + L])
            L++;
        PLCP[i] = L;
        L = max(L - 1, (ll)0);
    }
    for (ll i = 0; i < n; i++)
        LCP[i] = PLCP[SA[i]];
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

    ll T = 1;
    while (T--){
    	cin >> st;
        n = strlen(st);
        st[n++] = '$';
        constructSA();

        computeLCP(); 
        ll substring = 0;
        for (ll i = 0; i < n; i++){
            substring += n - SA[i] - 1;
            substring -= LCP[i];
        	printf("%d\n", substring);
        }
    }
    return 0;
}