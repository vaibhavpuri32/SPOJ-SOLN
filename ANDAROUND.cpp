#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define P 1000000007
#define inf 1e18
ll t[4 * (500000 + 5)];

void build(ll a[], ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = (t[2 * v] & t[2 * v + 1]);
    }
}

ll get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
    {
        return (-1);
    }
    if (tl == l && tr == r)
    {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return (get(2 * v, tl, tm, l, min(tm, r)) & get(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
}

int main()
{
    ll i, test;
    cin >> test;
    while (test--)
    {
        ll n, k;
        cin >> n >> k;

        ll a[3 * n + 5];
        for (i = 0; i < n; i++)
            cin >> a[i];
        for (i = n; i < 3 * n; i++)
        {
            a[i] = a[i - n];
        }

        build(a, 1, 0, 3 * n - 1);
        ll low = 0, high = 3 * n - 1;
        for (i = 0; i < n; i++)
        {
            cout << get(1, 0, 3 * n - 1, max(low, n + i - k), min(high, n + i + k)) << " ";
        }
        cout << "\n";
    }

    return (0);
}