#include <bits/stdc++.h>

using namespace std;

template <class T,class U>
void maximize(T &x,U y){
    if(x < y)x = y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x = y;
}
template <class T>
T Abs(T x){
    return (x < (T)0 ? -x : x);
}

#define ll long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

namespace task{

    const int N = (1 << 10);
    int mask[N];
    int n,step = 0;

    int toIndex(char a){
        return a - 'a';
    }

    char toChar(int c){
        return (char)(c + 'a');
    }

    void out(int cur){
        cout<<setw(10);
        int c = 0;
        cout<<"{";
        for(int i = 0;i < n;++i){
            if(BIT(cur,i)){
                cout<<toChar(i);
                if(++c < __builtin_popcount(cur)){
                    cout<<",";
                }
            }
        }
        if(!c) {
            cout << "-";
        }
        cout<<"}";
    }

    void out(int R,int P,int X){
        cout<<++step<<setw(step < 10 ? 2 : 1)<<":";
        out(R),out(P),out(X);
        if(!P and !X){
            cout<<setw(10)<<"MBYM";
        }
        cout<<"\n\n";
    }

    void calc(int R,int P,int X){
        out(R,P,X);
        if(!P and !X){
            return ;
        }
        for(int i = 0;i < n;++i){
            if(BIT(P,i)){
                calc(R | MASK(i),P & ~mask[i] & ~MASK(i),X & ~mask[i] & ~MASK(i));
                P &= ~MASK(i);
                X |= MASK(i);
                out(R,P,X);
            }
        }
    }

    void solve(){
        cin>>n;
        char a,b;
        while(cin >> a){
            if(a == '!')break;
            cin>>b;
            mask[toIndex(a)] |= MASK(toIndex(b));
        }
        calc(0,MASK(n) - 1,0);
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    //freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
