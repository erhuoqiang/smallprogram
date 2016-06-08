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
    Tree(int num[], int len);
    void InsertNode_recursion(int data);
    Node * SearchNode( int data);
    Node * SearchNode(Node * current, int data);
    void DeleteNode(int data);
    void DeleteNode(Node * current);

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
    friend int IsSortTree(Tree * tree);

private:
    Node * root;
};
/**********construct*******/
Tree::Tree(int num[], int len)
{
    root = new Node(num[0]);
    for(int i = 1; i < len; i++)
    {
        InsertNode_recursion(num[i]);
    }
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
    Node * Last = NULL;
    Node * Next_Last = NULL;
    Node * temp;
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
	
        if(temp->left != NULL)
        {
            q.push(temp->left);
	    Next_Last = temp->left;
        }
        if(temp->right != NULL)
        {
            q.push(temp->right);
	    Next_Last = temp->right;
        }
	if(temp == Last)
	{
		count++;
		
		cout<<temp->data<<" ";	
		if(Last != Next_Last)  //���⵽���һ���ʱ�� �������һ����к�
		{
			cout<<endl<<count<<"	";
			Last = Next_Last;
		}
			
	}
	else	
       		 cout<<temp->data<<" ";
	
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

int main()
{
    int a[10] = {5,3,7,2,4,6,8,1};
    Tree T(a,8);
    Node *p = T.SearchNode(3);
    if(p != NULL)
    cout<<"Search Element is:"<<p->data<<endl;
    //T.DeleteNode(3);
    T.PreOrderTree();
    T.PostOrderTree();
    T.MidOrderTree();
    T.LevelOrderTree();

    cout<<endl<<(IsSortTree(&T)?"YES":"NO")<<endl;
    p->data = 5;
    cout<<endl<<(IsSortTree(&T)?"YES":"NO")<<endl;
}
