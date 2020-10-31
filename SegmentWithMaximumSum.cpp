#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18
struct node
{
    ll pref;
    ll suf;
    ll seg;
    ll sum;
};
node t[4000005];

node merge(node a, node b)
{
    node temp;
    temp.sum = a.sum + b.sum;
    temp.pref = max(a.sum + b.pref, a.pref);
    temp.suf = max(b.sum + a.suf, b.suf);
    temp.seg = max(max(a.seg, b.seg), a.suf + b.pref);
    return temp;
}

void build(ll a[], ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v].pref = t[v].suf = t[v].seg = t[v].sum = a[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
}

void update(ll v, ll tl, ll tr, ll pos, ll val)
{
    if (tl == tr)
    {
        t[v].pref = t[v].suf = t[v].seg = t[v].sum = val;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            update(2 * v, tl, tm, pos, val);
        }
        else
        {
            update(2 * v + 1, tm + 1, tr, pos, val);
        }

        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
}

int main()
{
    ll i, n, m;
    cin >> n >> m;
    ll a[n + 5];
    for (i = 0; i < n; i++)
        cin >> a[i];
    build(a, 1, 0, n - 1);
    cout << max(t[1].seg,(ll)0) << "\n";
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        update(1, 0, n - 1, x, y);
        cout << max(t[1].seg,(ll)0) << "\n";
    }
    return (0);
}