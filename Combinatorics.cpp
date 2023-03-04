typedef long long ll;
const int N = 1e6 + 5 + 5 , M = 1e6 + 2 , mod = 1e9 + 7;
class combinatorics{
private:
    vector<ll> fact;
    ll modInverse(ll a){
        ll x,y,g;
        g=egcd(a,mod,x,y);
        if(g>1)
            return -1;
        return (x+mod)%mod;
    }
    ll egcd(ll a, ll b, ll &x, ll &y){
        if(!b){
            x=1;
            y=0;
            return a;
        }
        ll g=egcd(b,a%b,y,x);
        y-=(a/b)*x;
        return g;
    }
public:
    combinatorics(){
        fact.resize(N);
        fact[0] = 1 ;
        for (ll i = 1; i < N; ++i) {
            fact[i] = ((fact[i - 1] %mod )* (i % mod))%mod;
        }
    }

    ll Fn(ll x){
        return fact[x];
    }

    ll fPower(ll base, ll pw)
    {
        if(pw == 0){return 1;}
        if(pw == 1){return base % mod;}
        long long halfpow= fPower(base, pw / 2);
        long long res= ((halfpow%mod)*
                        (halfpow%mod))%mod;
        if(pw % 2 != 0)
            res= ((res%mod)*(base % mod)) % mod;
        return res % mod;
    }

    ll nCr(ll x,ll y){
        return (((fact[x]%mod)* (modInverse(fact[x - y])%mod) %mod) * (modInverse(fact[y])%mod))%mod;
    }

    ll nPr(ll x , ll y){
        return ((fact[x]%mod) * (modInverse(fact[x - y])%mod)) % mod;
    }

    ll nQr(ll x, ll y){
        if(x == y){
            return fact[x - 1];
        }
        else{
            return (nPr(x,y)) / modInverse(y) ;
        }
    }

    ll nHr(ll x , ll y){
        return (nCr(x + y - 1 , y));
    }

    ll removeDuplicateSolutions(int x , vector<ll> & r){
        ll denom = 1 ;
        for(int o : r){
            denom *= fact[o];
            denom %= mod;
        }
        return (x * modInverse(denom)) % mod;
    }

    ll allSame(ll x , ll r){
        return fPower(x, r) % mod;
    }

};
combinatorics obj ;
