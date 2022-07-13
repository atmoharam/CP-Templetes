class SqrtDecomposition{
private:
    // 0 based
    ll n , len;
    vector<ll> a , b ;
    void build(){
        for (int i = 0; i < n; ++i) {
            b[i/len] += a[i];
        }
    }

public:
    SqrtDecomposition(vector<ll> a , ll n){
        len = (int) sqrt(n + .0) + 1 ;
        b.assign(len , 0);
        this->a = a ;
        this->n = n ;
        build();
    }
    ll query(ll left , ll right){
        ll ans = 0 ;
        ll leftBlock = left / len ;
        ll rightBlock = right / len ;
        if(leftBlock == rightBlock){
            for (int i = left; i <= right ; ++i) {
                ans += a[i];
            }
        }
        else{
            for (ll i = left , end = (leftBlock + 1) *len - 1; i <= end ; ++i) {
                ans += a[i];
            }
            for (ll i = leftBlock + 1; i <= rightBlock - 1 ; ++i) {
                ans += b[i];
            }
            for (ll i = rightBlock*len; i <= right ; ++i) {
                ans += a[i];
            }
        }
        return ans;
    }
    void updateValue(ll index , ll value){ //sum , xor
        ll delta = value - a[index];
        a[index] = value ;
        ll k = (index / len) ;
        b[k] += delta ;
    }
    void updateBlock(ll index , ll value){ // min , max
        a[index] = value;
        ll k = (index / len) ;
        b[k] = 0;
        for (int i = k * len ; i <= (k +1) * len ; ++i) {
            b[k] += a[i];
        }
    }
};
