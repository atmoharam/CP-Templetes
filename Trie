class Trie{
private:
    struct node{
        vector<node*>child=vector<node*>(26,NULL);
        bool isLeaf= true;
        bool isEnd= false;
    };
    node*root;
public:
    Trie(){
        root=new node();
    }
    void add(string s)
    {
        node *curr=root;
        for (char ch:s) {
            if(curr->child[ch-'a']==NULL){
                curr->child[ch-'a']=new node;
                curr->isLeaf= false;
            }
            curr=curr->child[ch-'a'];

        }
        curr->isEnd= true;
    }
  
};
