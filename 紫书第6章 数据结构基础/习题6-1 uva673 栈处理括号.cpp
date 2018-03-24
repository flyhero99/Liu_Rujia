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

int n;
stack<char> s;

int main() {
    while(scanf("%d%*c", &n) != EOF) {
        for(int i = 1;i <= n;i++) {
            while(!s.empty()) s.pop();
            char c;
            while((c = getchar()) != '\n') {
                if(c == '(' || c == '[') s.push(c);
                else if(c == ')' || c == ']') {
                    if(s.empty()) s.push(c);
                    else if(c == ')')
                        if(s.top() == '(') s.pop();
                    else if(c == ']')
                        if(s.top() == '[') s.pop();
                }
            }
            if(s.empty()) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}