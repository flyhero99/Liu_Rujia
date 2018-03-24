#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))

const int maxn = 1005;

bool llock;
deque<int> qr;//执行队列
queue<int> qb;//等待队列
vector<string> prg[maxn];
string s;
int t[maxn], p[maxn], var[26], lim;

void run(int i) {
    int rt = lim, v;
    string cur;
    while(rt > 0) {
        cur = prg[i][p[i]];
        if(cur[2] == '=')  // 赋值
        {
            rt -= t[0];
            v = cur[4] - '0';
            if(cur.size() == 6) v = v * 10 + cur[5] - '0';
            var[cur[0] - 'a'] = v;
        }
        else if(cur[2] == 'i')   //print
        {
            rt -= t[1];
            printf("%d: %d\n", i, var[cur[6] - 'a']);
        }
        else if(cur[2] == 'c')   //llock
        {
            rt -= t[2];
            if(llock)
            {
                qb.push(i);
                return;
            }
            else llock = true;
        }
        else if(cur[2] == 'l')  //unllock
        {
            llock = false;
            rt -= t[3];
            if(!qb.empty())
            {
                v = qb.front();
                qb.pop();
                qr.push_front(v);
            }
        }
        else return;  //end
        ++p[i];
    }
    qr.push_back(i);
}

int main()
{
    int cas, n;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n);
        for(int i = 0; i < 5; ++i)
            scanf("%d", &t[i]);
        scanf("%d", &lim);

        for(int i = 1; i <= n; ++i)
        {
            prg[i].clear();
            while(getline(cin, s))
            {
                if(s == "") continue;
                prg[i].push_back(s);
                if(prg[i].back() == "end") break;
            }
            qr.push_back(i);
        }

        memset(p, 0, sizeof(p));
        memset(var, 0, sizeof(var));
        while(!qr.empty())
        {
            int cur = qr.front();
            qr.pop_front();
            run(cur);
        }
        if(cas) puts("");
    }
    return 0;
}
