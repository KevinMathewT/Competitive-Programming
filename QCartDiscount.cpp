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

int main() {
    int m;
    cin >> m;    
    cout << setprecision(2) << fixed;
    vector<ld> slab_amount(m);
    vector<ld> slab_discount_percentage(m);
    for (int i = 0; i < m; ++i) {
        cin >> slab_amount[i] >> slab_discount_percentage[i];
    }
    
    int n;
    cin >> n;
    vector<string> name(n);
    vector<ld> mrp(n);
    vector<ld> basic_discount_percentage(n);
    vector<ld> max_discount_percentage(n);
    for (int i = 0; i < n; ++i) {
        cin >> name[i] >> mrp[i] >> basic_discount_percentage[i] >> max_discount_percentage[i];
    }
    
    vector<ld> first_price(n);
    
    for(ll i=0;i<n;i++)
        first_price[i] = mrp[i] - ((basic_discount_percentage[i] * mrp[i]) / 100);
    
    ld tot = 0;
    for(ll i=0;i<n;i++){
        // cout << first_price[i] << " ";
        tot += first_price[i];
    }
    // cout << "\n";
    
    // cout << tot << "\n";
    
    ld curr = LLONG_MIN, disc, ans = LLONG_MAX;
    
//     for(ll i=0;i<m;i++){
//         if(slab_amount[i] <= tot){
//             curr = slab_amount[i];
//             disc = slab_discount_percentage[i];

//             for(ll j=0;j<n;j++){
//                 ll nw = first_price[j] - ((disc * first_price[j]) / 100);
//                 ll limit = mrp[j] - ((max_discount_percentage[j] * mrp[j]) / 100);

//                 if(nw >= limit)
//                     first_price[j] = nw;
//                 else
//                     first_price[j] = limit;
//             }

//             tot = 0;
//             for(ll j=0;j<n;j++){
//                 // cout << first_price[i] << " ";
//                 tot += first_price[j];
//             }
            
//             ans = min(ans, tot);
//         }
//     }
    
    tot = 0;
    
    for(ll i=0;i<n;i++){
        ld nw = first_price[i];
        ld limit = mrp[i] - ((max_discount_percentage[i] * mrp[i]) / 100);
        
        
        cout << nw << " " << limit << "\n";
        for(ll j=0;j<m;j++){
            if(slab_amount[j] >= nw)
                nw = min(nw, first_price[i] - ((slab_discount_percentage[j] * first_price[i]) / 100));
        }
        cout << nw << " " << limit << "\n";
        if(nw >= limit)
            tot += nw;
        else
            tot += limit;
    }
    
//     for(ll i=0;i<n;i++){
//         ll nw = first_price[i] - ((disc * first_price[i]) / 100);
//         ll limit = mrp[i] - ((max_discount_percentage[i] * mrp[i]) / 100);
        
//         if(nw >= limit)
//             first_price[i] = nw;
//         else
//             first_price[i] = limit;
//     }
    
//     tot = 0;
//     for(ll i=0;i<n;i++){
//         // cout << first_price[i] << " ";
//         tot += first_price[i];
//     }
//     // cout << "\n";
    
    cout << tot << "\n";
        
    return 0;
}