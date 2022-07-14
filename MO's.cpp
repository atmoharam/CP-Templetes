
// 0 base 
ll Block_Size;
bool com(const pair<pair<ll,ll>,ll> &x , const pair<pair<ll,ll>,ll> &y){
    ll xBlock = x.first.first / Block_Size;
    ll yBlock = x.first.second / Block_Size ;
    if(xBlock != yBlock){
        return xBlock < yBlock ;
    }
    return x.first.second < y.first.second ;
}

class Mos_algorithm{
private:
    vector<ll> a;
    vector<ll> freq;
    vector<ll> ansV;
    vector<pair<pair<ll,ll>,ll>> Q ;
    ll n ;
    ll ans = 0 ;
    ll ML  = 0 , MR = 0 ;

    void add(ll index){
        ans += 1LL * a[index];
    }

    void remove(ll index){
        ans -= 1LL * a[index] ;
    }
    void update(ll left , ll right){
        while(ML > left) add(--ML);
        while(MR < right) add(MR++);
        while(ML < left) remove(ML++);
        while(MR > right) remove(--MR);
    }
public:
    Mos_algorithm(vector<ll> a , vector<pair<pair<ll,ll>,ll>> Q , ll n){
        this->n = n ;
        this->a = a ;
        this->Q = Q ;
        Block_Size = static_cast<int>(sqrt(n));
        sort(Q.begin() , Q.end() , com);
        ansV.assign(Q.size(),0);
        for (int i = 0; i < Q.size(); ++i) {
            update(Q[i].first.first , Q[i].first.second +1 );
            ansV[Q[i].second] = ans ;
        }
    }
    void print(){
        for(ll as : ansV){
            cout << as << '\n';
        }
    }
};
