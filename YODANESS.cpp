#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18
#define P 1000000007
ll t[400005];

void update(ll v, ll tl, ll tr, ll pos)
{
    if (tl > tr)
        return;
    if (tl == tr)
    {
        t[v] = 1;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos);
        else
            update(2 * v + 1, tm + 1, tr, pos);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

ll get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
    {
        return t[v];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        return (get(2 * v, tl, tm, l, min(tm, r)) + get(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
    }
}

int main()
{
    ll t1, i, j;
    cin >> t1;
    while (t1--)
    {
        ll n;
        cin >> n;
        vector<string> v1, v2;
        for (i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            v1.push_back(s);
        }

        map<string, ll> m;
        for (i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            m[s] = i;
        }

        ll a[n + 5];
        for (i = 0; i < n; i++)
        {
            a[i] = m[v1[i]];
        }

        ll ans = 0;
        for (i = 0; i < n; i++)
        {
            ans = ans + get(1, 0, n - 1, a[i], n - 1);
            update(1, 0, n - 1, a[i]);
        }
        for(i=1; i<=100000; i++)
         t[i] = 0; 
         
        cout<<ans<<"\n";
    }

    return (0);
}