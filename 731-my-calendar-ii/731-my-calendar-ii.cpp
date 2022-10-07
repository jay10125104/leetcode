struct Node{
    Node*left=NULL;
    Node*right=NULL;
    int val=0;
    int lazy=0;
};
class seg{
public:
    seg(){
        
    }
    int query(Node*node,int start,int end,int l,int r){
        
        if(!node->left){
            node->left = new Node();
        }
        if(!node->right){
            node->right = new Node();
        }
        
        if(node->lazy!=0){
            node->val+=node->lazy;
            if(start!=end){
            node->left->lazy+=node->lazy;
            node->right->lazy+=node->lazy;
            }
            node->lazy=0;
        }
        if(start>r || end<l){
            return 0;
        }
        if(start>=l && end<=r){
            return node->val;
        }
        int mid = (start+end)/2;
        int x = query(node->left,start,mid,l,r);
        int y = query(node->right,mid+1,end,l,r);
        return max(x,y);
    }
    void update(Node*node,int start,int end,int l,int r){
        
        if(!node->left){
            node->left = new Node();
        }
        if(!node->right){
            node->right = new Node();
        }
        
        if(node->lazy){
            node->val+=node->lazy;
            if(start!=end){
            node->left->lazy+=node->lazy;
            node->right->lazy+=node->lazy;
            }
            node->lazy=0;
        }
        if(start>r || end<l){
            return;
        }
        if(start>=l && end<=r){
            node->val++;
            if(start!=end){
                node->left->lazy++;
                node->right->lazy++;
            }
            return;
        }
        int mid = (start+end)/2;
        update(node->left,start,mid,l,r);
        update(node->right,mid+1,end,l,r);
        node->val = max(node->left->val,node->right->val);
    }
};
class MyCalendarTwo {
public:
    Node*root = new Node();
    seg *se = new seg();
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        if(se->query(root,0,1000000001,start,end-1)==2){
            return false;
        }
        else{
            se->update(root,0,1000000001,start,end-1);
            return true;
        }
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */