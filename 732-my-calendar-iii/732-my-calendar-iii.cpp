struct node{
    node*left=NULL;
    node*right=NULL;
    int val=0;
    int lazy=0;
};
class seg{
public:
    
    seg(){
        
    }
    int query(node*root,int start,int end,int l,int r){
        if(start!=end){
        if(!root->left){
            root->left = new node();
        }
        if(!root->right){
            root->right = new node();
        }
        }
        if(root->lazy!=0){
            root->val+=root->lazy;
            if(start!=end){
            root->left->lazy+=root->lazy;
            root->right->lazy+=root->lazy;
            }
            root->lazy = 0;
        }
        if(start>r || end<l){
            return 0;
        }
        else if(start>=l && end<=r){
            return root->val;
        }
        else{
            int mid = (start+end)/2;
            int x = query(root->left,start,mid,l,r);
            int y = query(root->right,mid+1,end,l,r);{
            return max(x,y);
            }
        }
    }
    void update(node*root,int start,int end,int l,int r){
        if(start!=end){
        if(!root->left){
            root->left = new node();
        }
        if(!root->right){
            root->right = new node();
        }
        }
        if(root->lazy){
            root->val+=root->lazy;
            if(start!=end){
            root->left->lazy+=root->lazy;
            root->right->lazy+=root->lazy;
            }
            root->lazy = 0;
        }
        if(start>r || end<l){
            return;
        }
        else if(start>=l && end<=r){
            root->val++;
            if(start!=end){
            root->left->lazy++;
            root->right->lazy++;
            }
            return;
        }
        int mid = (start+end)/2;
        update(root->left,start,mid,l,r);
        update(root->right,mid+1,end,l,r);
        root->val = max(root->left->val,root->right->val); 
        
    }
};
class MyCalendarThree {
public:
    int ans=1;
    node*root = new node();
    seg *se = new seg();
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        se->update(root,0,1000000001,start,end-1);
        int x = se->query(root,0,1000000001,start,end-1);
        ans = max(ans,x);
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */