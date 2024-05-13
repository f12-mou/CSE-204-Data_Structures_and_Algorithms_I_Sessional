#include<iostream>
#include<fstream>
#include<cstdlib>
#include<sstream>
#include<string>
#include "DictionaryADT.cpp"
#include "BSTNode.cpp"
using namespace std;

// Binary Search Tree Implementation for Dictionary ADT
template<typename Key, typename E>
class BST:public Dictionary<Key,E>
{
private:
    BSTNode<Key,E>* root;
    int nodeCount;


    void clearhelp(BSTNode<Key,E>* root)
    {
        if(root==NULL)
            return;
        clearhelp(root->left());
        clearhelp(root->right());
        delete root;
    }
    BSTNode<Key,E>* inserthelp(BSTNode<Key,E>* root,Key k, E it)
    {
        if(root==NULL)
            return new BSTNode<Key,E>(k,it,NULL,NULL);
        if(k<root->getKey())
            root->setLeft(inserthelp(root->left(),k,it));
        else if(k>=root->getKey())
            root->setRight(inserthelp(root->right(),k,it));
        return root;
    }
    BSTNode<Key,E>* deletemin(BSTNode<Key,E>* rt)
    {
        if(rt->left()==NULL)
            return rt->right();
        else
        {
            rt->setLeft(deletemin(rt->left()));
            return rt;
        }
    }
    BSTNode<Key,E>* getmin(BSTNode<Key,E>* rt)
    {
        if(rt->left()==NULL)
            return rt;
        else return getmin(rt->left());
    }
    BSTNode<Key,E>* removehelp(BSTNode<Key,E>* rt,Key k)
    {
        if(rt==NULL)
            return NULL;
        else if(k<rt->getKey())
        {
            rt->setLeft(removehelp(rt->left(),k));
        }
        else if(k>rt->getKey())
        {
            rt->setRight(removehelp(rt->right(),k));
        }

        else
        {
          BSTNode<Key,E>* temp=rt;
          if(rt->left()==NULL)
          {
              rt=rt->right();
              delete temp;
          }
          else if(rt->right()==NULL)
          {
              rt=rt->left();
              delete temp;
          }
          else
          {
              BSTNode<Key,E>* temp=getmin(rt->right());
              rt->setData(temp->getData());
              rt->setKey(temp->getKey());
              rt->setRight(deletemin(rt->right()));
              delete temp;
          }
        }
        return rt;
    }
    int findhelp(BSTNode<Key,E>* root,Key k)
    {
        if(root==NULL){return 0;}
        if(k<root->getKey())
            return findhelp(root->left(),k);
        else if(k>root->getKey())
            return findhelp(root->right(),k);
        else{
             return 1;
        }
    }
    void printhelp(BSTNode<Key,E>* root)
    {
        if(root==NULL)
            {
                return;
            }
        cout<<"(";
        cout<<root->getData();
        if(root->left()!=NULL) printhelp(root->left());
        else{
            if(root->right()!=NULL)
            cout<<"()";
        }
        if(root->right()!=NULL) printhelp(root->right());
        else{
             if(root->left()!=NULL)
            cout<<"()";
        }
        cout<<")";
    }
public:
    BST()
    {
        root=NULL;
        nodeCount=0;
    }
    ~BST()
    {
        clearhelp(root);

    }
    void clear()
    {
        clearhelp(root);
        root=NULL;
        nodeCount=0;
    }
    void insert(Key k,E item)
    {
        root=inserthelp(root,k,item);
        nodeCount++;
    }
    int remove(Key k)
    {
        int ans=findhelp(root,k);
        if(ans==1)
        {
            root=removehelp(root,k);
            nodeCount--;
        }
        else
        {
            cout<<"Invalid Operation"<<endl;
        }
        return ans;
    }
    E* removeAny()
    {
        E*temp2;
        if(root!=NULL)
        {
            E temp=root->getData();
            temp2=&temp;
            root=removehelp(root,root->key);
            nodeCount--;
            return temp2;
        }
        else
            return NULL;
    }
    void find(Key k)
    {
        int ans=findhelp(root,k);
        if(ans==0)
            cout<<"False"<<endl;
        else
            cout<<"True"<<endl;
    }
    int size()
    {
        return nodeCount;
    }
    void preTraverse()
    {
        if(root!=NULL)
            {
                root->preTraverse();
            }
        cout<<endl;
    }
     void inTraverse()
    {
        if(root!=NULL)
            {
                root->inTraverse();
            }
        cout<<endl;
    }
     void postTraverse()
    {
        if(root!=NULL)
            root->postTraverse();
        cout<<endl;
    }
    void print()
    {
        if(root==NULL)
        {
            cout<<"The tree is empty"<<endl;
        }
        else
            {
                cout<<root->getData()<<"";
                if(root->left()!=NULL) printhelp(root->left());
                else
                {
                    if(root->right()!=NULL)
                    cout<<"()";
                }
                if(root->right()!=NULL) printhelp(root->right());
                else
                    if(root->left()!=NULL)
                    cout<<"()";
            }
        cout<<endl;
    }
};

int main()
{
    BST<int,int>b;
    ifstream inFile;
    inFile.open("BST.txt");
    if(!inFile)
    {
        cout<<"Can't open the file"<<endl;
        exit(1);
    }
    string line;
    int flag=1,x=5;
    while(inFile>>line)
        {
                string str2(line);
                inFile>>line;
                if(str2.compare("T")!=0){
                stringstream convert;
                convert<<line;
                convert>>x;
                }

            if(str2.compare("I")==0){
                b.insert(x,x);
                b.print();
            }
            else if(str2.compare("T")==0){
                if(line.compare("Pre")==0)
                    b.preTraverse();
                else if(line.compare("Post")==0)
                    b.postTraverse();
                else if(line.compare("In")==0)
                    b.inTraverse();
            }
            else if(str2.compare("F")==0){
                b.find(x);
            }
            else  if(str2.compare("D")==0){
                int a=b.remove(x);
                if(a==1) b.print();
            }
    }
    inFile.close();
    return 0;
}






