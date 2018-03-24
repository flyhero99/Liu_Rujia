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

int n, target[maxn];

int main() {
    while(true) {
        scanf("%d", &n);
        if(n == 0) break;
        while(true) {
            scanf("%d", &target[1]);
            if(target[1] == 0) {puts(""); break;}
            stack<int> s;
            int A=1, B=1;
            for(int i = 2;i <= n;i++) scanf("%d", &target[i]);
            int ok = 1;
            while(B <= n) {
                if(A == target[B]) {A++; B++;}
                else if(!s.empty() && s.top() == target[B]) {s.pop(); B++;}
                else if(A <= n) {s.push(A); A++;}
                else {ok = 0; break;}
            }
            printf("%s\n", ok ? "Yes" : "No");
        }
    }
    return 0;
}