#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 400010;

int q, ptr;
ll n, where[N];
map <ll, ll> leftSib;
map <ll, ll> rightSib;

inline ll get (ll l, ll r) {
  if (l == 1) return 1;
  if (r == n) return n;
  return l + r >> 1;
}

inline ll dist (ll l, ll r) {
  if (l == 1) return r - 1;
  if (r == n) return n - l;
  ll pos = l + r >> 1;
  return min(pos - l, r - pos);
}

struct seg {
  ll l, r;

  seg () {}
  seg (ll l, ll r) : l(l), r(r) {}

  bool operator < (const seg &s) const {
    return dist(l, r) == dist(s.l, s.r) ? (get(l, r) == get(s.l, s.r) ? (l == s.l ? r < s.r : l < s.l) : get(l, r) < get(s.l, s.r)) : dist(l, r) > dist(s.l, s.r);
  }
};

set <seg> s;

ll assign (int x) {
  // for (auto it : s) cout << it.l << " ---- " << it.r << '\n';
  // cout << "####################\n";
  seg cur = *s.begin();
  s.erase(s.begin());
  leftSib.erase(cur.r);
  rightSib.erase(cur.l);
  ll pos = get(cur.l, cur.r);
  where[x] = pos;
  if (cur.l < pos) {
    s.emplace(cur.l, pos - 1);
    leftSib[pos - 1] = cur.l;
    rightSib[cur.l] = pos - 1;
  }
  if (pos < cur.r) {
    s.emplace(pos + 1, cur.r);
    leftSib[cur.r] = pos + 1;
    rightSib[pos + 1] = cur.r;
  }
  // for (auto it : s) cout << it.l << " ---- " << it.r << '\n';
  // for (auto it : leftSib) cout << " ~~~ " << it.first << " --> " << it.second << '\n';
  // for (auto it : rightSib) cout << " ~~~ " << it.first << " --> " << it.second << '\n';
  // cout << "-------------------\n";
  return pos;
}

void remove (int x) {
  // cout << "REMOVE\n";
  // for (auto it : s) cout << it.l << " ---- " << it.r << '\n';
  // cout << "####################\n";
  ll at = where[x];
  // cout << at << endl;
  seg merge(at, at);
  if (leftSib.find(at - 1) != leftSib.end()) {
    seg out(leftSib[at - 1], at - 1);
    s.erase(out);
    leftSib.erase(out.r);
    rightSib.erase(out.l);
    merge.l = out.l;
  }
  if (rightSib.find(at + 1) != rightSib.end()) {
    // cout << "yo\n";
    seg out(at + 1, rightSib[at + 1]);
  //   cout << " --> " << out.l << " " << out.r << endl;
  // cout << "before\n";
  // for (auto it : s) cout << it.l << " ---- " << it.r << '\n';
    s.erase(out);
  // cout << "after\n";
  // for (auto it : s) cout << it.l << " ---- " << it.r << '\n';
  // cout << "$$$$$$$$$$$$$\n";
    leftSib.erase(out.r);
    rightSib.erase(out.l);
    merge.r = out.r;
  }
  leftSib[merge.r] = merge.l;
  rightSib[merge.l] = merge.r;
  s.emplace(merge);
  // for (auto it : s) cout << it.l << " ---- " << it.r << '\n';
  // for (auto it : leftSib) cout << " ~~~ " << it.first << " --> " << it.second << '\n';
  // for (auto it : rightSib) cout << " ~~~ " << it.first << " --> " << it.second << '\n';
  // cout << "-------------------\n";
}

// int cnt, rem, arr[N];

// ll brute (int cmd, int pos = -1) {
//   if (cmd == 1) {
//     ++cnt, ++rem;
//     if (rem == 1) {
//       arr[1] = cnt;
//       // cout << "1 ";
//       return 1;
//     } else {
//       int at = 1, dist = -1;
//       for (int i = 1; i <= n; ++i) {
//         if (arr[i]) continue;
//         int lt = i - 1, rt = i + 1, cur = n + n;
//         while (lt > 0 and !arr[lt]) --lt;
//         while (rt <= n and !arr[rt]) ++rt;
//         if (lt > 0) cur = min(cur, i - lt);
//         if (rt <= n) cur = min(cur, rt - i);
//         if (cur > dist) dist = cur, at = i;
//       }
//       arr[at] = cnt;
//       // cout << at << ' ';
//       return at;
//     }
//   } else {
//     --rem;
//     for (int i = 1; i <= n; ++i) {
//       if (arr[i] == pos) {
//         arr[i] = 0;
//         break;
//       }
//     }
//   }
//   return -1;
// }

int main() {
  freopen("input.txt", "r", stdin);   //Comment
  freopen("output.txt", "w", stdout);   //this out.
  cin >> n >> q;
  s.emplace(1, n);
  leftSib[n] = 1;
  rightSib[1] = n;
  while (q--) {
    int cmd, pos;
    scanf("%d", &cmd);
    if (cmd == 1) {
      ++ptr;
      ll ans = assign(ptr);
      // assert(ans == brute(cmd));
      printf("%lld\n", ans);
    } else {
      scanf("%d", &pos);
      remove(pos);
      // brute(cmd, pos);
    }
  }
  return 0;
}

