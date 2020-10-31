#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18
#define P 1000000007
ll block;
bool comp(pair<pair<ll, ll>, ll> &a, pair<pair<ll, ll>, ll> &b)
{
    if (a.first.first / block != b.first.first / block)
    {
        return (a.first.first / block) < (b.first.first / block);
    }
    return a.first.second < b.first.second;
}
 ll m[1000005];
ll answer = 0;
void remove(ll x)
{
    m[x]--;
    if (m[x] == 0)
        answer--;
}

void add(ll x)
{
    m[x]++;
    if (m[x] == 1)
        answer++;
}
int main()
{  
    ll i, j, n;
    cin >> n;
    block = sqrt(n) + 1;
    vector<ll> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    ll q;
    cin >> q;
    ll q1 = q;
    vector<pair<pair<ll, ll>, ll>> v;
    i = 0;
    while (q1--)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        v.push_back({{l, r}, i});
        i++;
    }

    sort(v.begin(), v.end(), comp);
    vector<ll> ans(q + 3);
    ll curl = 0;
    ll curr = 0;

    for (i = 0; i < q; i++)
    { //cout<<"First "<<v[i].first.first<<" "<<v[i].first.second<<"\n";
        ll l = v[i].first.first;
        ll r = v[i].first.second;
        while (curl < l)
        {
            remove(a[curl]);

            curl++;
        }
        while (curl > l)
        {
            add(a[curl - 1]);
            curl--;
        }
        while (curr <= r)
        {
            add(a[curr]);
            curr++;
        }
        while (curr > r + 1)
        {
            remove(a[curr - 1]);
            curr--;
        }
        ans[v[i].second] = answer;
    }

    for (i = 0; i < q; i++)
        cout << ans[i] << "\n";

    return (0);
}