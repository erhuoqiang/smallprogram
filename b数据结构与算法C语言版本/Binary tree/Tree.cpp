#include<iostream>
#include<stack>
#include<queue>
using namespace std;
#define Element int
class Node
{
public:
    Element data;
    Node * parent;
    Node * left;
    Node * right;
    bool flag;  //二叉树后序遍历的标志位
public:
    Node(void):data(-1), parent(NULL), left(NULL), right(NULL),flag(false){};
    Node(int num): data(num), parent(NULL), left(NULL), right(NULL),flag(false){};
};

class Tree
{
public:
    Tree(void);
    Tree(int num[], int len); //构造一个排序二叉树
    Tree(int preorder[], int midorder[],int len); //根据前序遍历和中序遍历重建二叉树    不一定是排序二叉树，如果不是排序二叉树则不能使用下面的一些寻找节点等函数
    ~Tree();
    void InsertNode_recursion(int data);
    Node * SearchNode( int data);
    Node * SearchNode(Node * current, int data);
    void DeleteNode(int data);
    void DeleteNode(Node * current);   //删除某个子树或者整棵树  数可以不是排序二叉树
    void PreOrderTree(void);
    void PreOrderTree_Rescursion(Node * current);
    void PreOrderTree_UonRecursion(Node * current);

    void PostOrderTree(void);
    void PostOrderTree_Rescursion(Node * current);
    void PostOrderTree_UonRecursion(Node * current);

    void MidOrderTree(void);
    void MidOrderTree_Rescursion(Node * current);
    void MidOrderTree_UonRecursion(Node * current);

    void LevelOrderTree(void);
    void LevelOrderTree(Node * current);

    void Print_Tree(void);

    friend int IsSortTree(Tree * tree);
    //根据二叉树的前序遍历和后续遍历重建二叉树
    Node * Rebulid_BinaryTree(int preorder[], int midorder[],int len);
    Node * Rebulid_BinaryTree(int *startPreorder, int *endPreorder, int *startInorder, int * endInorder);
private:
    Node * root;
};

/**********construct*******/
Tree::Tree(void)
{
    root = NULL;
}
Tree::Tree(int preorder[], int midorder[],int len)
{
    root = NULL;
    if(preorder == NULL || midorder == NULL || len <= 0)
        return;
    Rebulid_BinaryTree(preorder, midorder, len);
}

Tree::Tree(int num[], int len)
{
    root = new Node(num[0]);
    for(int i = 1; i < len; i++)
    {
        InsertNode_recursion(num[i]);
    }
}
/********Disconstruct******/
Tree::~Tree()
{
    DeleteNode(root);
}
/************插入********************/
void Tree::InsertNode_recursion(int data)
{
    Node * newnode = new Node(data);
    Node * temp , *p;

    temp = p = root;
    while(p != NULL)
    {
        temp = p;
        if(p->data < data)
            p = p->right;
        else if(p->data > data)
            p = p->left;
        else if(p->data == data)
        {
            delete newnode;
            return;
        }
    }
    newnode->parent = temp;
    if(newnode->data > temp->data)
        temp->right = newnode;
    else
        temp->left = newnode;
}


/******************搜索*****************/
Node * Tree::SearchNode( int data)
{
    SearchNode(root, data);
}
Node * Tree::SearchNode(Node * current, int data)
{
    if(current == NULL)
    {
        return NULL;
    }
    if(current->data > data)
    {
        return SearchNode(current->left, data);
    }
    if(current->data < data)
    {
        return SearchNode(current->right, data);
    }
    return current;
}

/**************删除节点子树*************/
void Tree::DeleteNode(int data)
{
    Node * current = SearchNode(data);
    if(current == root)
    {
        this->root = NULL;
    }
    else if(current != NULL)
    {
        if(current->parent->data > current->data)
            current->parent->left =  NULL;
        if(current->parent->data < current->data)
            current->parent->right =  NULL;
    }
    if(current != NULL)
        DeleteNode(current);
}

void Tree::DeleteNode(Node * current)
{
    if(current == NULL)
        return;
    if(current->left != NULL)
        DeleteNode(current->left);
    if(current->right != NULL)
        DeleteNode(current->right);

    delete current;
    current = NULL;
}

/*******************前序遍历************/
void Tree::PreOrderTree(void)
{
    if(this->root == NULL)
    {
        return;
    }
    cout<<"\nPreOrder_Recursion data:\n";
    PreOrderTree_Rescursion(root);
    cout<<"\nPreOrder_UonRecursion data:\n";
    PreOrderTree_UonRecursion(root);
}
/*******************前序递归**********/
void Tree::PreOrderTree_Rescursion(Node * current)
{
    if(current != NULL)
    {
        cout<<current->data<<" ";
       PreOrderTree_Rescursion(current->left);
       PreOrderTree_Rescursion(current->right);
    }
}
/******************前序非递归********/
void Tree::PreOrderTree_UonRecursion(Node * current)
{
    stack<Node *> s;
    while(current != NULL || !s.empty())
    {
        while(current != NULL)
        {
             cout<<current->data<<" ";
             s.push(current);
             current = current->left;
        }
        if(!s.empty())
        {
            current = s.top();  //返回栈顶元素
            s.pop();  //推出栈顶单元
            current = current->right;
        }
    }
}

/*******************中序遍历************/
void Tree::MidOrderTree(void)
{
    if(this->root == NULL)
    {
        return;
    }
    cout<<"\nMidOrder_Recursion data:\n";
    MidOrderTree_Rescursion(root);
    cout<<"\nMidOrder_UonRecursion data:\n";
    MidOrderTree_UonRecursion(root);
}

/*******************中序递归**********/
void Tree::MidOrderTree_Rescursion(Node * current)
{
    if(current != NULL)
    {
       MidOrderTree_Rescursion(current->left);
       cout<<current->data<<" ";
       MidOrderTree_Rescursion(current->right);
    }
}

/******************中序非递归********/
void Tree::MidOrderTree_UonRecursion(Node * current)
{
    stack<Node *> s;
    while(current != NULL || !s.empty())
    {
        while(current != NULL)
        {
             s.push(current);
             current = current->left;
        }
       if(!s.empty())
        {
            current = s.top();  //返回栈顶元素
            cout<<current->data<<" ";
            s.pop();  //推出栈顶单元
            current = current->right;
        }
    }
}
/*******************后序遍历************/
void Tree::PostOrderTree(void)
{
    if(this->root == NULL)
    {
        return;
    }
    cout<<"\nPostOrder_Recursion data:\n";
    PostOrderTree_Rescursion(root);
    cout<<"\nPostOrder_UonRecursion data:\n";
    PostOrderTree_UonRecursion(root);
}
/*******************后序递归**********/
void Tree::PostOrderTree_Rescursion(Node * current)
{
    if(current != NULL)
    {
       PostOrderTree_Rescursion(current->left);
       PostOrderTree_Rescursion(current->right);
       cout<<current->data<<" ";
    }
}
/******************后序非递归********/
void Tree::PostOrderTree_UonRecursion(Node * current)
{
    stack<Node *> s;
    while(current != NULL || !s.empty())
    {
        while(current != NULL)
        {
             s.push(current);
             current = current->left;
        }
        if(!s.empty())
        {
            current = s.top();//返回栈顶元素
            if(!current->flag)
            {
                current->flag = true;
                current = current->right;
            }
            else
            {
                cout<<current->data<<" ";
                s.pop();  //推出栈顶单元
                current = NULL;   //输出元素后，置NULL，防止current 在此以自己的值进入while循环，导致无限遍历
            }
        }
    }
}

/****************层序遍历****************/
void Tree::LevelOrderTree(void)
{
    if(root == NULL)
    {
        return;
    }
    LevelOrderTree(root);
}

void Tree::LevelOrderTree(Node * current)
{
    queue<Node *>q;
    Node * temp;

    if(current == NULL)
        return;

    q.push(current);

    cout<<"\nLevelOrderTree :\n";

    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left != NULL)
        {
            q.push(temp->left);
        }

        if(temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}
/*******打印二叉树的行数和结构基于层序遍历*************/
void Tree::Print_Tree(void)
{
    queue<Node *>q;
    Node * current = root;
    Node * Last = NULL;
    Node * Next_Last = NULL;
    Node * temp;
    int num= 0; //用于统计当前行输出数据的个数，当最后换行时输出个数是奇数的时候则补上*号
    unsigned int count  = 1; //记录当前层数
    if(current == NULL)
        return;

    q.push(current);
    Last = current;
    cout<<"\nLevelOrderTree :\n";
    cout<<count<<"	";
    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            num++;
            cout<<"* ";
            continue;
        }

        if(temp->left != NULL)
        {
            q.push(temp->left);
            Next_Last = temp->left;
        }
        else
        {
            q.push(NULL); //不存在推入NULL，推出是则输出*
        }

        if(temp->right != NULL)
        {
            q.push(temp->right);
            Next_Last = temp->right;
        }
        else
        {
            q.push(NULL);
        }

        if(temp == Last)
        {
            num++;
            cout<<temp->data<<" ";
            if(num % 2 == 1 && count != 1)  //第一行不考虑 因为第一行num肯定是奇数
            {
                q.pop();
                cout<<"* ";
            }
            count++;
            if(Last != Next_Last)  //避免到最后一层的时候 还输出下一层的行号
            {
                cout<<endl<<count<<"	";
                Last = Next_Last;
                num = 0;
            }
            else  //所有有效节点访问完 Last = Next_Last 栈里面还剩下很多NULL ，将他们全部推出
            {
                while(!q.empty())
                {
                    q.pop();
                }
            }

        }
        else
        {
                num++;
                cout<<temp->data<<" ";
        }

    }
}
/**********给定二叉树判断其是否为二叉排序树********/
//二叉排序树的中序遍历打印其实是把元素从小到大输出，利用这一特性 我们可以判断一棵树是否为二叉树
int IsSortTree(Tree * tree)
{
    stack<Node *> s;
    if(tree->root == NULL || tree == NULL)
        return false;
    Element temp = 0;
    int count = 0;   // 计数器 作用 ：第一次temp 不参与 比较

    Node * current = tree->root;

    while(current || !s.empty())
    {
        while(current != NULL)
        {
            s.push(current);
            current = current->left;
        }
        if(!s.empty())
        {
            current = s.top();
            s.pop();
            if(count != 0)
            {
                if(current->data > temp)  //二叉排序树没有重复的值 所以这里只要大于temp就可以 出现等于也说明不是排序树
                {
                    temp = current->data;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                temp = current->data;
                count = 1;
            }
            current = current->right;

        }
    }
    return true;
}
/*******************重建二叉树**********************/
Node * Tree::Rebulid_BinaryTree(int *startPreorder, int *endPreorder, int *startInorder, int * endInorder)
{
    int rootValue = startPreorder[0];
    Node * temproot = new Node;
    temproot->data = rootValue;
    //temproot->left = NULL;
    //temproot->right = NULL;
  // temproot->parent = NULL;
    int * rootInorder = startInorder;
   //在中序遍历的数组中找到左右子树的分界点，也就是根
    while(rootInorder < endInorder &&  *rootInorder != rootValue)
        rootInorder++;
//判断前序遍历和中序遍历的元素是否是同一个二叉树
    if(rootInorder == endInorder && *rootInorder != rootValue)
    {
        cout<<"Invalid input"<<endl;
        return NULL;
    }
    int left_len = rootInorder - startInorder;

    //重建二叉树的原理就是用根节点在中序二叉树中找到左子树和右子树（左子树和右子树的前序数组
    //对应的第一个元素就是根节点的左节点和右节点，然后又在左子树包
    //含的的前序和中序数组的元素里面以左子树的前序遍历数组的的第一个元素为根在中序数
    //组中分左子树右子树。利用这个原理不断递归下去，最终构建二叉树
    if(left_len >0)
    {
         temproot->left = Rebulid_BinaryTree( startPreorder + 1, startPreorder + left_len, startInorder,   rootInorder -1);
         temproot->left->parent = temproot;
    }
    if(left_len <  endInorder - startInorder)
    {
         temproot->right = Rebulid_BinaryTree( startPreorder + left_len + 1, endPreorder,   rootInorder + 1, endInorder );
          temproot->right->parent = temproot;
    }
    return temproot;
}
Node * Tree::Rebulid_BinaryTree(int preorder[], int midorder[],int len)
{
    if(preorder == NULL || midorder == NULL || len<=0)
        return NULL;
    if(root != NULL)
        DeleteNode(root);
    root = Rebulid_BinaryTree(preorder, preorder+len-1, midorder, midorder+len-1);
}


int main()
{
    int a[10] = {5,3,7,2,4,6,8,1};
    int b[10] = {1,2,4,7,3,5,6,8};
    int c[10] = {4,7,2,1,5,3,8,6};
    Tree T(a,8);
    Tree R(b,c,8);
    Node *p = T.SearchNode(3);
    if(p != NULL)
    cout<<"Search Element is:"<<p->data<<endl;
    //T.DeleteNode(3);
    T.PreOrderTree();
    T.PostOrderTree();
    T.MidOrderTree();
    T.LevelOrderTree();
    T.Print_Tree();
    //R.Rebulid_BinaryTree(b,c,8);
    R.Print_Tree();
    cout<<endl<<(IsSortTree(&T)?"YES":"NO")<<endl;
    p->data = 5;
    cout<<endl<<(IsSortTree(&T)?"YES":"NO")<<endl;
}
