#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{    public:
     T data;
     vector<TreeNode<T>*> children;

     TreeNode(T data)
     {
          this->data = data;
     }
     ~TreeNode(){
          for(int i=0;i<children.size();i++){
               delete children[i];
          }
     }
};

TreeNode<int>* takeInput(){
     int rootData;
     cout << "Enter rootData" << endl;
     cin >> rootData;
     TreeNode<int> *root = new TreeNode<int>(rootData);

     cout << "Enter no. of children of " << rootData << endl;
     int childrenSize;
     cin >> childrenSize;
     for(int i=0;i<childrenSize;i++){
        TreeNode<int> *child =  takeInput();
        root->children.push_back(child);
     }

     return root;
}

TreeNode<int>* takeInputLevelWise(){
     int rootData;
     cout << "Enter root data" << endl;
     cin >> rootData;
     TreeNode<int> *root = new TreeNode<int>(rootData);
     queue<TreeNode<int>*> pendingNodes;
     pendingNodes.push(root);

     while(pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter no. of children of " << front->data << endl;
        int childrenSize;
        cin >> childrenSize;

        int childData;
        for (int i = 0; i < childrenSize; i++){
          cout << "enter child data of " << front->data << endl;
          cin >> childData;
          TreeNode<int> *child = new TreeNode<int>(childData);
          pendingNodes.push(child);
          front->children.push_back(child);
        }
        
     }

     return root;
}

void printTree(TreeNode<int>* root){    // preOrder 
     if(root == NULL) return ;

     cout << root->data << ": ";
     for(int i=0;i<root->children.size();i++){ 
          cout << root->children[i]->data << ", ";
     }
     cout << endl;

     for(int i=0;i<root->children.size();i++){
          printTree(root->children[i]);
     }

}

void printTreeLevelWise(TreeNode<int>* root){  
     if(root == NULL) return;

     queue<TreeNode<int>*> pendingNodes;
     pendingNodes.push(root);

     while (pendingNodes.size() != 0){
          TreeNode<int> *front = pendingNodes.front();
          pendingNodes.pop();

          cout << front->data << ": ";
          for(int i=0;i<front->children.size();i++){
               cout << front->children[i]->data << ", ";
          }
          cout << endl;

          for(int i=0;i<front->children.size();i++){
               pendingNodes.push(front->children[i]);  
          }
     }   
} 


int main(){
     TreeNode<int>* root = takeInputLevelWise();
     printTreeLevelWise(root);

     delete root;
     return 0;
}