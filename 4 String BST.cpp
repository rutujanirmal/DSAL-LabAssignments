// String BST
/*
Menu driven program
1) BST creation ( keyword and its meaning)
2) Inorder
3)Search
4)update meaning
5)delete 
    5.1) node to be deleted is leaf
    5.2) node to be deleted having one one child ( left / right)
    5.3) node to be deleted having 2 children
6) display in ascending/ Descending order
*/

#include <iostream>
using namespace std;

//structre Node
struct Node
{
    string key;
    string meaning;
    Node* left;
    Node* right;
};

//function to create node
Node* create(string key,string meaning){
    Node* temp=new Node();
    temp->key=key;
    temp->meaning=meaning;
    temp->left=temp->right=NULL;
    return temp;
}

//function to insert node
void insert(Node* &root,string key,string meaning){
    if(root==NULL){
        root=create(key,meaning);
    }
    else if(root->key > key){
        insert(root->left,key,meaning);
    }
    else{
        insert(root->right,key, meaning);
    }
}

//inorder
void displayIn(Node* root){
    if(root!=NULL){
        displayIn(root->left);      //LEFT
        cout<<root->key<<" ";      //PARENT
        displayIn(root->right);     //RIGHT
    }

}

//searching element
void search(Node* root,string keyword){
    if(root!=NULL){
        if(root->key>keyword){
            search(root->left,keyword);
        }
        else if(root->key<keyword){
            search(root->right,keyword);
        }
        else if(root->key==keyword){
            cout<<"\nKeyword found"<<endl
                <<root->key<<" :: "<<root->meaning;
        }
    }
    else{
        cout<<"Keyword NOT found";
    }

}

//updating the meaning
void update(Node*root , string k1, string m1){
    if(root!=NULL){
        if(root->key>k1){
            search(root->left,k1);
        }
        else if(root->key<k1){
            search(root->right,k1);
        }
        else if(root->key==k1){
            cout<<"\nKeyword found"<<endl;
            root->meaning=m1;
            cout<<"Meaning updated"<<endl
                <<root->key<<" :: "<<root->meaning;
        }
    }
    else{
        cout<<"Keyword NOT found";
    }
}

//inorder sucessor
Node* inorder_s(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

//deletion
Node* deletion(Node* root,string key){
    Node* parent=NULL;
    Node* cur=root;
    if(root==NULL){
        return root;
    }
    if (key<root->key){
        root->left=deletion(root->left, key);
    }
    else if (key>root->key){
        root->right=deletion(root->right,key);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        
        Node * temp = inorder_s(root->right);

        root->key=temp->key;
        root->right=deletion(temp->right,temp->key);
    }
    return root;
}

//display ascending
void display_ascending(Node* root){
    if(root!=NULL){
        display_ascending(root->left);      //LEFT
        cout<<root->key<<" :: "<<root->meaning<<endl;      //PARENT
        display_ascending(root->right);     //RIGHT
    }
}

//display decending
void display_decending(Node* root){
    if(root!=NULL){
        display_decending(root->right);      //LEFT
        cout<<root->key<<" :: "<<root->meaning<<endl;      //PARENT
        display_decending(root->left);     //RIGHT
    }
}

//main_function
int main(){
    bool loop=1;
    Node* root=NULL;
    int ch,n;
    string k,m;
    while(loop==1){
        //Menu
        cout<<"\n----MENU----"<<endl
            <<"1) BST creation"<<endl
            <<"2) Inorder"<<endl
            <<"3) Search"<<endl
            <<"4) Update meaning"<<endl
            <<"5) Delete "<<endl
            <<"6) Display in Ascending order"<<endl
            <<"7) Display in Descending order"<<endl
            <<"8) Quit"<<endl
            <<"Enter :: ";
        cin>>ch;
        switch (ch)
        {
            case 1:
            {
                cout<<"\nEnter the number of elements :: ";
                cin>>n;
                
                for(int i=0;i<n;i++){
                    cout<<"\nKeyword :: ";
                    cin>>k;
                    cout<<"Meaning :: ";
                    cin>>m;
                    insert(root,k,m);
                }
                break;
            }
            case 2:
            {
                cout<<"\nINORDER :: ";
                displayIn(root);
                break;
            }
            case 3:{
                string key;
                cout<<"\nEnter the Keyword you want to search :: ";
                cin>>key;
                search(root,key);
                break;
            }
            case 4:{
                string k1,m1;
                cout<<"Enter the Keyword : ";
                cin>>k1;
                cout<<"Enter New Meaning : ";
                cin>>m1;
                update(root,k1,m1);
                break;
            }
            case 5:{
                cout<<"Enter the keyword to delete :: ";
                string str;
                cin>>str;
                root=deletion(root,str);
                break;
            }
            case 6:{
                cout<<"\nAscending Order\n\n";
                display_ascending(root);
                break;
            }
            case 7:{
                cout<<"\nDecending Order\n\n";
                display_decending(root);
                break;
            }
            case 8:{
                loop=0;
                break;
            }
            default:
                
                break;
        }
    }
}



