class FenwickTree{
private:
    int n ;
    vector<ll> a , Tree ;

    void build(){
        for (int i = 1; i <= n; ++i) {
            add(i , a[i]);
        }
    }

public:

    FenwickTree(ll n , vector<ll> temp){
        this->a = temp ;
        this->n = n ;
        Tree.assign(n + 2 , 0);
        build();
    }

    void add(int index , ll value){
        for(; index <= n ; index += (index &(-index))){
            Tree[index] += value ;
        }
    }

    ll sumPrefix(int index){
        ll result = 0;
        for(; index > 0 ; index -= (index &(-index))){
            result += Tree[index];
        }
        return result;
    }

    ll SumRange(int left , int right){
        return sumPrefix(right) - sumPrefix(left);
    }
};
