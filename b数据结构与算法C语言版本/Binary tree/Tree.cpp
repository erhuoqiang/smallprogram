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
    bool flag;  //��������������ı�־λ
public:
    Node(void):data(-1), parent(NULL), left(NULL), right(NULL),flag(false){};
    Node(int num): data(num), parent(NULL), left(NULL), right(NULL),flag(false){};
};

class Tree
{
public:
    Tree(void);
    Tree(int num[], int len); //����һ�����������
    Tree(int preorder[], int midorder[],int len); //����ǰ���������������ؽ�������    ��һ�����������������������������������ʹ�������һЩѰ�ҽڵ�Ⱥ���
    ~Tree();
    void InsertNode_recursion(int data);
    Node * SearchNode( int data);
    Node * SearchNode(Node * current, int data);
    void DeleteNode(int data);
    void DeleteNode(Node * current);   //ɾ��ĳ����������������  �����Բ������������
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
    //���ݶ�������ǰ������ͺ��������ؽ�������
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
/************����********************/
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


/******************����*****************/
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

/**************ɾ���ڵ�����*************/
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

/*******************ǰ�����************/
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
/*******************ǰ��ݹ�**********/
void Tree::PreOrderTree_Rescursion(Node * current)
{
    if(current != NULL)
    {
        cout<<current->data<<" ";
       PreOrderTree_Rescursion(current->left);
       PreOrderTree_Rescursion(current->right);
    }
}
/******************ǰ��ǵݹ�********/
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
            current = s.top();  //����ջ��Ԫ��
            s.pop();  //�Ƴ�ջ����Ԫ
            current = current->right;
        }
    }
}

/*******************�������************/
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

/*******************����ݹ�**********/
void Tree::MidOrderTree_Rescursion(Node * current)
{
    if(current != NULL)
    {
       MidOrderTree_Rescursion(current->left);
       cout<<current->data<<" ";
       MidOrderTree_Rescursion(current->right);
    }
}

/******************����ǵݹ�********/
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
            current = s.top();  //����ջ��Ԫ��
            cout<<current->data<<" ";
            s.pop();  //�Ƴ�ջ����Ԫ
            current = current->right;
        }
    }
}
/*******************�������************/
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
/*******************����ݹ�**********/
void Tree::PostOrderTree_Rescursion(Node * current)
{
    if(current != NULL)
    {
       PostOrderTree_Rescursion(current->left);
       PostOrderTree_Rescursion(current->right);
       cout<<current->data<<" ";
    }
}
/******************����ǵݹ�********/
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
            current = s.top();//����ջ��Ԫ��
            if(!current->flag)
            {
                current->flag = true;
                current = current->right;
            }
            else
            {
                cout<<current->data<<" ";
                s.pop();  //�Ƴ�ջ����Ԫ
                current = NULL;   //���Ԫ�غ���NULL����ֹcurrent �ڴ����Լ���ֵ����whileѭ�����������ޱ���
            }
        }
    }
}

/****************�������****************/
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
/*******��ӡ�������������ͽṹ���ڲ������*************/
void Tree::Print_Tree(void)
{
    queue<Node *>q;
    Node * current = root;
    Node * Last = NULL;
    Node * Next_Last = NULL;
    Node * temp;
    int num= 0; //����ͳ�Ƶ�ǰ��������ݵĸ������������ʱ���������������ʱ������*��
    unsigned int count  = 1; //��¼��ǰ����
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
            q.push(NULL); //����������NULL���Ƴ��������*
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
            if(num % 2 == 1 && count != 1)  //��һ�в����� ��Ϊ��һ��num�϶�������
            {
                q.pop();
                cout<<"* ";
            }
            count++;
            if(Last != Next_Last)  //���⵽���һ���ʱ�� �������һ����к�
            {
                cout<<endl<<count<<"	";
                Last = Next_Last;
                num = 0;
            }
            else  //������Ч�ڵ������ Last = Next_Last ջ���滹ʣ�ºܶ�NULL ��������ȫ���Ƴ�
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
/**********�����������ж����Ƿ�Ϊ����������********/
//���������������������ӡ��ʵ�ǰ�Ԫ�ش�С���������������һ���� ���ǿ����ж�һ�����Ƿ�Ϊ������
int IsSortTree(Tree * tree)
{
    stack<Node *> s;
    if(tree->root == NULL || tree == NULL)
        return false;
    Element temp = 0;
    int count = 0;   // ������ ���� ����һ��temp ������ �Ƚ�

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
                if(current->data > temp)  //����������û���ظ���ֵ ��������ֻҪ����temp�Ϳ��� ���ֵ���Ҳ˵������������
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
/*******************�ؽ�������**********************/
Node * Tree::Rebulid_BinaryTree(int *startPreorder, int *endPreorder, int *startInorder, int * endInorder)
{
    int rootValue = startPreorder[0];
    Node * temproot = new Node;
    temproot->data = rootValue;
    //temproot->left = NULL;
    //temproot->right = NULL;
  // temproot->parent = NULL;
    int * rootInorder = startInorder;
   //������������������ҵ����������ķֽ�㣬Ҳ���Ǹ�
    while(rootInorder < endInorder &&  *rootInorder != rootValue)
        rootInorder++;
//�ж�ǰ����������������Ԫ���Ƿ���ͬһ��������
    if(rootInorder == endInorder && *rootInorder != rootValue)
    {
        cout<<"Invalid input"<<endl;
        return NULL;
    }
    int left_len = rootInorder - startInorder;

    //�ؽ���������ԭ������ø��ڵ���������������ҵ���������������������������������ǰ������
    //��Ӧ�ĵ�һ��Ԫ�ؾ��Ǹ��ڵ����ڵ���ҽڵ㣬Ȼ��������������
    //���ĵ�ǰ������������Ԫ����������������ǰ���������ĵĵ�һ��Ԫ��Ϊ����������
    //���з����������������������ԭ���ϵݹ���ȥ�����չ���������
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
