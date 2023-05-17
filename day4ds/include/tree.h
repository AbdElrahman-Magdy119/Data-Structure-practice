#ifndef TREE_H
#define TREE_H
typedef struct Node Node;
typedef struct Tree Tree;
typedef struct Node
{
    int data;
    Node *right,*left;

}Node;
typedef struct Tree
{
    Node *root;

}Tree;
void add(Tree * t,int data)
{
    Node *n=malloc(sizeof(Node));
    n->data=data;
    n->left=n->right=NULL;
    if(t->root == NULL)
    {
        t->root = n;
    }
    else
    {
        Node *current = t->root;
        Node *parent;
        while( current != NULL)
        {
            parent=current;
            if(data > current->data)
              {
                current=current->right;
              }
            else
             {
               current = current->left;
             }
        }
        if( data > parent->data )
        {
            parent->right = n ;
        }
        else
            parent->left = n;

    }
}
void display(Node *n)
{
    if(n == NULL)
        return;
    display(n->left);
    printf("%i\t",n->data);
    display(n->right);
}

Node * Getnodebydata(Tree * t,int data)
{
    Node *current= t->root;
    while(current != NULL)
    {
         if( data == current->data)
            return current;
         else if(data > current->data)
            current =current->right;
         else
            current = current->left;
    }

    return NULL;
}

Node * getparent(Tree *t,Node *n)
{
    Node * current = t->root;

  while(current  != NULL )
  {

    if(current->left->data == n->data || current->right->data == n->data )
        return current;
    if(n->data > current->data)
        current=current->right;
     else
        current = current->left;

  }
   return NULL;
}
Node * getmaxright(Node *n)
{
    Node *maxnode;
    while(n != NULL)
    {
        maxnode=n;
        n=n->right;
    }
    return maxnode;
}

int maxright(Tree *t,int data)
{
     Node *n=Getnodebydata(t,data);
    Node *maxnode;
    while(n != NULL)
    {
        maxnode=n;
        n=n->right;
    }
    return maxnode->data;
}
void removee(Tree *t,int data)
{
     Node *n=Getnodebydata(t,data);

     if(n == NULL)
        return;

    if(n == t->root)
    {
        if(t->root->left == NULL && t->root->right == NULL)
        {
            t->root=NULL;
        }
        else if( t->root->right == NULL )
        {
            t->root = t->root->left;
        }
        else if( t->root->left == NULL )
        {
            t->root= t->root->right;
        }
        else
        {
            Node *newnode = t->root->left;
            Node *maxsize = getmaxright(newnode) ;
            maxsize->right = t->root->right;
            t->root= newnode;
        }
    }

    else
    {
         Node *parent = getparent(t,n);

         if( n->left == NULL && n->right == NULL)
         {
             if( parent->right == n)
                parent->right = NULL;
             else
                parent->left = NULL;
         }
        else if( n->left == NULL)
        {
              if( parent->right == n)
                parent->right = n->right;
             else
                parent->left = n->right;

        }
        else if( n->right == NULL)
        {
            if( parent->right == n)
                parent->right = n->left;
             else
                parent->left = n->left;
        }
        else
        {
            Node *newnode = n->left;
            Node *maxsize = getmaxright(newnode);
            maxsize->right = n->right;
            if( parent->left == n )
             parent->left = newnode;
             else
                parent->right = newnode;
        }
    }

    free(n);
}

int GetMaxDepth(Node *n )
{
    int maxright, maxleft;

    if( n == NULL)
        return 0;

    maxleft = GetMaxDepth(n->left)+1;
    maxright = GetMaxDepth(n->right)+1;

    if( maxleft > maxright)
        return maxleft;
    else
        return maxright;
}



#endif // TREE_H
