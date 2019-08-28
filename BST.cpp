#include "BST.h"
#include <iostream>
#include <string>
#include <queue>

using std::string;
using std::cout;
using std::endl;

TreeNode* BST::Search(int KEY)
{

    TreeNode *current = root;               // 將curent指向root作為traversal起點

    while (current != NULL && KEY != current->key) {  // 兩種情況跳出迴圈：
    	                                              // 1.沒找到 2.有找到
        if (KEY < current->key){
            current = current->leftchild;   // 向左走
        }
        else {
            current = current->rightchild;  // 向右走
        }
    }
    return current;
}

void BST::InsertBST(int key, string element)
{

    TreeNode *y = 0;        // 準新手爸媽
    TreeNode *x = 0;        // 哨兵
    TreeNode *insert_node = new TreeNode(key, element);

    x = root;
    while (x != NULL) {                // 在while中, 以如同Search()的方式尋找適當的位置
        y = x;
        if (insert_node->key < x->key){
            x = x->leftchild;
        }
        else{
            x = x->rightchild;
        }
    }                                  // 跳出迴圈後, x即為NULL
                                       // y即為insert_node的parent
    insert_node->parent = y;           // 將insert_node的parent pointer指向y

    if (y == NULL){                    // 下面一組if-else, 把insert_node接上BST
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
    q.push(this->root);					    // 把root作為level-order traversal之起點
    								        // 推進queue中
    while (!q.empty()){                     // 若queue不是空的, 表示還有node沒有visiting

    	TreeNode *current = q.front();      // 取出先進入queue的node
    	q.pop();
    	cout << current->element << "(" << current->key << ")" << " ";

    	if (current->leftchild != NULL){    // 若leftchild有資料, 將其推進queue
            q.push(current->leftchild);
        }
        if (current->rightchild != NULL){   // 若rightchild有資料, 將其推進queue
            q.push(current->rightchild);
        }
    }
}

void BST::DeleteBST(int KEY){               // 要刪除具有KEY的node

    TreeNode *delete_node = Search(KEY);    // 先確認BST中是否有具有KEY的node
    if (delete_node == NULL) {
        std::cout << "data not found.\n";
        return;
    }

    TreeNode *y = 0;      // 真正要被刪除並釋放記憶體的node
    TreeNode *x = 0;      // 要被刪除的node的"child"

    if (delete_node->leftchild == NULL || delete_node->rightchild == NULL){
        y = delete_node;
    }
    else{
        y = Successor(delete_node);        // 將y設成delete_node的Successor
    }                                      // 經過這組if-else, y調整成至多只有一個child
                                           // 全部調整成case1或case2來處理
    if (y->leftchild != NULL){
        x = y->leftchild;                  // 將x設成y的child, 可能是有效記憶體,
    }                                      // 也有可能是NULL
    else{
        x = y->rightchild;
    }

    if (x != NULL){                        // 在y被刪除之前, 這個步驟把x接回BST
        x->parent = y->parent;             // 此即為圖二(c)中, 把基紐接回龜仙人的步驟
    }
                                           // 接著再把要被釋放記憶體的node之"parent"指向新的child
    if (y->parent == NULL){                // 若刪除的是原先的root, 就把x當成新的root
        this->root = x;
    }
    else if (y == y->parent->leftchild){    // 若y原本是其parent之left child
        y->parent->leftchild = x;           // 便把x皆在y的parent的left child, 取代y
    }
    else{                                   // 若y原本是其parent之right child
        y->parent->rightchild = x;          // 便把x皆在y的parent的right child, 取代y
    }
                                            // 針對case3
    if (y != delete_node) {                 // 若y是delete_node的替身, 最後要再將y的資料
        delete_node->key = y->key;          // 放回delete_node的記憶體位置, 並將y的記憶體位置釋放
        delete_node->element = y->element;  // 圖二(d), y即是達爾, delete_node即是西魯
    }

    delete y;                               // 將y的記憶體位置釋放
    y = 0;
}
