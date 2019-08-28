#include "BST.h"
#include <iostream>
#include <string>
#include <queue>

using std::string;
using std::cout;
using std::endl;

TreeNode* BST::Search(int KEY)
{

    TreeNode *current = root;               // �Ncurent���Vroot�@��traversal�_�I

    while (current != NULL && KEY != current->key) {  // ��ر��p���X�j��G
    	                                              // 1.�S��� 2.�����
        if (KEY < current->key){
            current = current->leftchild;   // �V����
        }
        else {
            current = current->rightchild;  // �V�k��
        }
    }
    return current;
}

void BST::InsertBST(int key, string element)
{

    TreeNode *y = 0;        // �Ƿs�⪨��
    TreeNode *x = 0;        // ��L
    TreeNode *insert_node = new TreeNode(key, element);

    x = root;
    while (x != NULL) {                // �bwhile��, �H�p�PSearch()���覡�M��A����m
        y = x;
        if (insert_node->key < x->key){
            x = x->leftchild;
        }
        else{
            x = x->rightchild;
        }
    }                                  // ���X�j���, x�Y��NULL
                                       // y�Y��insert_node��parent
    insert_node->parent = y;           // �Ninsert_node��parent pointer���Vy

    if (y == NULL){                    // �U���@��if-else, ��insert_node���WBST
        this->root = insert_node;
    }
    else if (insert_node->key < y->key){
        y->leftchild = insert_node;
    }
    else{
        y->rightchild = insert_node;
    }
}

TreeNode* BST::Leftmost(TreeNode *current)
{

    while (current->leftchild != NULL){
        current = current->leftchild;
    }
    return current;
}
TreeNode* BST::Successor(TreeNode *current){

    if (current->rightchild != NULL){
        return Leftmost(current->rightchild);
    }

    TreeNode *new_node = current->parent;

    while (new_node != NULL && current == new_node->rightchild) {
        current = new_node;
        new_node = new_node->parent;
    }

    return new_node;
}
void BST::InorderPrint(){
    TreeNode *current = new TreeNode;
    current = Leftmost(root);
    while(current){
        cout << current->element << "(" << current->key << ")" << " ";
        current = Successor(current);
    }
}

void BST::Levelorder()
{

    std::queue<TreeNode*> q;
    q.push(this->root);					    // ��root�@��level-order traversal���_�I
    								        // ���iqueue��
    while (!q.empty()){                     // �Yqueue���O�Ū�, ����٦�node�S��visiting

    	TreeNode *current = q.front();      // ���X���i�Jqueue��node
    	q.pop();
    	cout << current->element << "(" << current->key << ")" << " ";

    	if (current->leftchild != NULL){    // �Yleftchild�����, �N����iqueue
            q.push(current->leftchild);
        }
        if (current->rightchild != NULL){   // �Yrightchild�����, �N����iqueue
            q.push(current->rightchild);
        }
    }
}
