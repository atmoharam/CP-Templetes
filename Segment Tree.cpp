struct node{
    ll x ;
 
};
 
node retNode = {0};
 
 
node merge (node left , node right){
    node temp ;
    temp.x = left.x + right.x ;
    return temp;
}
 
class SegmentTree{
 
private:
    int n ;
    vector<node> Tree ;
    vector<ll> a ;
 
    void build(int parent , int left , int right){
 
        if(left == right){
            Tree[parent].x = a[left];
            return;
        }
        int mid = (left + right) / 2 ;
        build(parent * 2 , left , mid);
        build(parent * 2 + 1 , mid +1 , right);
        Tree[parent] = merge(Tree[parent*2] , Tree[parent*2 + 1]);
    }
 
    void update(int parent , int left , int right , int index , int value){
 
        if(left == right){
            Tree[parent].x = value ;
            a[left] = value;
            return;
        }
 
        int mid = (left + right) / 2 ;
 
        if(index <= mid)
        {
            update(parent * 2 , left , mid , index , value);
        }
        else{
            update(parent * 2 + 1 , mid + 1 , right , index , value);
        }
        Tree[parent] = merge(Tree[parent*2] , Tree[parent*2 + 1]);
    }
 
    node query (int parent , int left , int right , int qLeft , int qRight){
 
        if(qRight < left || qLeft > right){
            return retNode ;
        }
        if(left >= qLeft && qRight >= right){
            return Tree[parent];
        }
        int mid = (left + right) / 2 ;
 
        node lefNode = query(parent * 2 , left , mid , qLeft , qRight);
        node rightNode = query(parent * 2 + 1 , mid + 1 , right , qLeft , qRight);
 
        return merge(lefNode , rightNode);
    }
    
    int findTh(int parent , int left , int right , int k){  // from left
 
        if(left == right){
            return left;
        }
        int mid = (left + right) / 2 ;
        if(Tree[parent * 2 ].x >= k){
            return findTh(parent * 2 , left , mid , k);
        }
        else{
            return findTh(parent * 2 + 1 , mid +1 , right , k - Tree[parent * 2].x);
        }
    }
    
    int findTh(int parent , int left , int right , int k){         // from right
 
        if(left == right){
            return left;
        }
        int mid = (left + right) / 2 ;
        if(Tree[parent * 2 + 1 ].x >= k){
            return findTh(parent * 2 + 1 , mid + 1 , right , k);
        }
        else{
            return findTh(parent * 2  , left , mid , k - Tree[parent * 2 + 1].x);
        }
    }
 
public:
 
    SegmentTree (vector<ll> a , int x){
        this->a = a ;
        this->n = x ;
        Tree.assign(4 * n , retNode);
        build(1 , 0 , n - 1 );
    }
 
    void update(int index , int value){
        update(1 , 0 , n - 1 , index , value);
    }
 
    node query(int qLeft , int qRight){
        return query(1 , 0 , n- 1 , qLeft  , qRight);
    }
    
    int findTh(int k){
        return findTh(1 , 0 , n - 1 , k);
    }
    
};
