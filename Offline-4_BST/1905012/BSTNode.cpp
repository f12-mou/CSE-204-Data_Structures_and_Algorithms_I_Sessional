#include<iostream>
using namespace std;

template<typename Key,typename E>
class BSTNode
{
private:

    E data;
    BSTNode* lc;
    BSTNode* rc;
public:
    Key key;
    BSTNode()
    {
        lc=rc=NULL;
    }
    BSTNode(Key k, E d,BSTNode* left, BSTNode* right)
    {
        key=k;
        data=d;
        lc=left;
        rc=right;
    }
    ~BSTNode()
    {

    }
    E getData(){return data;}
    void setData(E item){data=item;}
    Key getKey(){return key;}
    void setKey(Key item){key=item;}
    void setLeft(BSTNode* left){lc=left;}
    void setRight(BSTNode* right){rc=right;}
    BSTNode* left(){return lc;}
    BSTNode* right(){return rc;}
    bool isLeaf()
    {
        return (lc==NULL && rc==NULL);
    }
    void preTraverse()
    {
        cout<<data<<" ";
        if(left()!=NULL) left()->preTraverse();
        if(right()!=NULL) right()->preTraverse();
    }
    void inTraverse()
    {
        if(left()!=NULL) left()->inTraverse();
        cout<<data<<" ";
        if(right()!=NULL) right()->inTraverse();
    }
    void postTraverse()
    {
        if(left()!=NULL) left()->postTraverse();
        if(right()!=NULL) right()->postTraverse();
        cout<<data<<" ";
    }
};
