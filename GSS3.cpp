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
    ll child;
};

node t[4 * 100010];
bool marked[4 * 100010];
ll t1[4 * 100010];
node merge(node &a, node &b)
{
    node temp;
    temp.pref = max(a.pref, a.sum + b.pref);
    temp.suf = max(b.suf, a.suf + b.sum);
    temp.sum = a.sum + b.sum;
    temp.seg = max(max(a.seg, b.seg), a.suf + b.pref);
    temp.child = a.child + b.child;
    return temp;
}

void build(ll v, ll a[], ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v].pref = t[v].sum = t[v].seg = t[v].suf = a[tl];
        t[v].child = 1;
        return;
    }
    ll tm = (tl + tr) / 2;
    build(2 * v, a, tl, min(tr, tm));
    build(2 * v + 1, a, max(tm + 1, tl), tr);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

void build1(ll v, ll a[], ll tl, ll tr)
{
    if (tl == tr)
    {
        t1[v] = a[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build1(2 * v, a, tl, tm);
        build1(2 * v + 1, a, tm + 1, tr);
        t1[v] = max(t1[2 * v], t1[2 * v + 1]);
    }
}

void update1(ll v, ll tl, ll tr, ll pos, ll val)
{
    if (tl > tr)
        return;
    if (tl == tr)
        t1[v] = val;
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            update1(2 * v, tl, tm, pos, val);
        }
        else
        {
            update1(2 * v + 1, tm + 1, tr, pos, val);
        }
        t1[v] = max(t1[2 * v], t1[2 * v + 1]);
    }
}

ll get1(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return -inf;
    if (tl == l && tr == r)
    {
        return t1[v];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        return (max(get1(2 * v, tl, tm, l, min(tm, r)), get1(2 * v + 1, tm + 1, tr, max(tm + 1, l), r)));
    }
}
void push(ll v, ll val)
{
    if (marked[v])
    {
        marked[2 * v] = marked[2 * v + 1] = true;
        marked[v] = false;
        t[2 * v].sum = t[2 * v].child * val;
        t[2 * v + 1].sum = t[2 * v + 1].child * val;
        if (val > 0)
        {
            t[2 * v].pref = t[2 * v].suf = t[2 * v].seg = val * t[2 * v].child;
            t[2 * v + 1].suf = t[2 * v + 1].pref = t[2 * v + 1].seg = val * t[2 * v + 1].child;
        }
        else
        {

            t[2 * v].pref = t[2 * v].suf = t[2 * v].seg = 0;
            t[2 * v + 1].suf = t[2 * v + 1].pref = t[2 * v + 1].seg = 0;
        }
    }
}
void update(ll v, ll tl, ll tr, ll pos, ll val)
{
    if (tl > tr)
        return;
    if (tl == tr)
    {
        marked[v] = true;
        t[v].sum = t[v].child * val;
        if (val > 0)
        {
            t[v].suf = t[v].pref = t[v].seg = t[v].child * val;
        }
        else
        {

            t[v].suf = t[v].pref = t[v].seg = 0;
        }
    }
    else
    {
        push(v, t[v].sum / t[v].child);
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, val);
        else
            update(2 * v + 1, tm + 1, tr, pos, val);

        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
}

node get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r || tl > tr)
    {
        node temp;
        temp.pref = temp.suf = temp.seg = temp.sum = 0;
        return temp;
    }
    if (tl == l && tr == r)
    {
        return t[v];
    }
    else
    {
        push(v, t[v].sum / t[v].child);
        ll tm = (tl + tr) / 2;
        auto x1 = get(2 * v, tl, tm, l, min(tm, r));
        auto x2 = get(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
        return merge(x1, x2);
    }
}
int main()
{
    ll n, q, i;
    cin >> n;
    ll a[n + 5];
    for (i = 0; i < n; i++)
        cin >> a[i];
    cin >> q;
    build(1, a, 0, n - 1);
    build1(1, a, 0, n - 1);
    while (q--)
    {
        ll x;
        cin >> x;
        if (x == 0)
        {
            ll x, y;
            cin >> x >> y;
            x--;
            update(1, 0, n - 1, x, y);
            update1(1, 0, n - 1, x, y);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            l--;
            r--;

            ll ans = get(1, 0, n - 1, l, r).seg;
            if (ans == 0)
            {
                ans = get1(1, 0, n - 1, l, r);
            }
            
                cout << ans << "\n";
        }
    }
    return (0);
}