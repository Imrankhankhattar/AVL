
#include <iostream>

using namespace std;
class Node
{
private:
    int data;
    Node *left;
    Node *right;
public:
    Node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;

    }
    void Set_data(int x)
    {
        data=x;
    }
    int Get_data()
    {
        return data;
    }
    void Set_left(Node *p)
    {
        left=p;
    }
    Node* Get_left()
    {
        return left;
    }
    void Display()
    {
        cout<<data<<endl;
    }
    void Set_right(Node *p)
    {
        right=p;
    }
    Node* Get_right()
    {
        return right;
    }
};
class BST
{
private:
    Node * root;
    Node * right;
    Node * left;
public:
    BST()
    {
        root=NULL;
        left=NULL;
        right=NULL;

    }
    void Add_node(int x)
    {
        Node*new_node=new Node(x);
        if(root==NULL)
        {
            root=new_node;
            return;
        }
        Node *temp=root;
        while(temp!=NULL)
        {
            if(new_node->Get_data()>temp->Get_data())
            {

                if(temp->Get_right()==NULL)
                {
                    temp->Set_right(new_node);

                    Balance(root,temp->Get_data(),x);
                    return;
                }
                temp=temp->Get_right();

            }

            else
            {

                if(temp->Get_left()==NULL)
                {
                    temp->Set_left(new_node);

                    Balance(root,temp->Get_data(),x);
                    return;
                }
                temp=temp->Get_left();
            }
        }

    }
    void  Balance( Node*R,int data,int x )
    {
        if(balancefacter(R)==-2)
        {
            if(x>data)
            {
                                    cout<<"Temp->Data"<<data<<endl;

                cout<<"Rotating->LEFT..."<<endl;

                root=RotateLeft(R);
            }

            else if(x<data)
            {
                                                    cout<<"Temp->Data"<<data<<endl;

                cout<<"Right left Rotation"<<endl;
                root=RightleftRotatoin(R);

            }
        }
        else if(balancefacter(R)==2)
        {
            if(x>data)
            {
                                                    cout<<"Temp->Data"<<data<<endl;

                cout<<"Left right Rotation"<<endl;
                root=LeftrightRotation(R);


            }
            else if(x<data)
            {
                                                    cout<<"Temp->Data"<<data<<endl;

                cout<<"Rotating->RIGHT..."<<endl;
                root=RotateRight(R);

            }
        }

    }
    int Search_data(int x)
    {

        cout<<"  "<<endl;
        if(root==NULL)
        {
            cout<<"Tree Is Empty ......."<<endl;
            return -1;
        }
        Node * temp=root;
        while(temp!=NULL)
        {
            if(x>temp->Get_data())
            {
                if(temp->Get_data()==x)
                {
                    cout <<"Search_Result: "<<x<<":found...."<<endl;
                    return 2;
                }
                temp=temp->Get_right();

            }
            else
            {

                if(temp->Get_data()==x)
                {
                    cout<<"Search_Result:"<<x<<" found..."<<endl;
                    return 2;
                }
                temp=temp->Get_left();
            }
        }

        cout<<"Search_Result: "<<x<<" :NOT FOUND!"<<endl<<endl;
        return -1;
    }
    void Delete_node(int x)
    {
        if(Search_data(x)==-1)
        {
            cout<<"Delete_Result:"<<"DATA NOT FOUND..!"<<endl<<endl;
            return;
        }
        if(root==NULL)
        {
            cout<<"NOTHING TO Delete......"<<endl;
            return;
        }
        Node * temp=root;
        if(root->Get_data()==x&&root->Get_left()==NULL&&root->Get_right()==NULL)
        {
            root=NULL;
            return;

        }
        if(root->Get_data()==x)
        {
            temp=root->Get_right();
            if(temp->Get_left()==NULL)
            {
                root->Set_data(temp->Get_data());
                root->Set_right(temp->Get_right());
                return;
            }
            while(temp->Get_left()!=NULL)
            {
                temp=temp->Get_left();
            }
            root->Set_data(temp->Get_data());
            temp->Set_left(NULL);
            return;
        }
        while(temp!=NULL)
        {

            if(x>temp->Get_data())
            {
                if(temp->Get_right()->Get_data()==x)

                {
                    if(temp->Get_right()->Get_right()==NULL)
                    {
                        temp->Set_right(NULL);

                        return;
                    }
                }

                if(temp->Get_right()->Get_data()==x)

                {

                    if(temp->Get_right()->Get_right()->Get_right()==NULL&&temp->Get_right()->Get_left()==NULL)
                    {
                        temp->Set_right(temp->Get_right()->Get_right());

                        return;
                    }
                }
                if(temp->Get_right()->Get_data()==x)
                {
                    Node *temp2=temp->Get_right()->Get_right();
                    if(temp2->Get_left()==NULL)
                    {
                        temp->Get_right()->Set_data(temp2->Get_data());
                        temp->Get_right()->Set_right(temp2->Get_right());
                        return;

                    }
                    while(temp2->Get_left()->Get_left()!=NULL)
                    {
                        temp2=temp2->Get_left();
                    }
                    temp->Get_right()->Set_data(temp2->Get_left()->Get_data());
                    temp2->Set_left(NULL);
                    return;

                }
                temp=temp->Get_right();
            }
            else
            {

                if(temp->Get_left()->Get_data()==x)
                {
                    if(temp->Get_left()->Get_left()==NULL)
                    {
                        temp->Set_left(NULL);

                        return;
                    }
                }
                if(temp->Get_left()->Get_data()==x)
                {
                    if(temp->Get_left()->Get_left()->Get_left()==NULL&&temp->Get_left()-> Get_right()==NULL)
                    {
                        temp->Set_left(temp->Get_left()->Get_left());

                        return;
                    }
                }
                if(temp->Get_left()->Get_data()==x)
                {
                    Node * temp2=temp->Get_left()->Get_left();
                    if(temp2->Get_right()==NULL)
                    {
                        temp->Get_left()->Set_data(temp2->Get_data());
                        temp->Get_left()->Set_left(temp2->Get_left());

                        return;

                    }
                    while(temp2->Get_right()->Get_right()!=NULL)
                    {
                        temp2=temp2->Get_right();
                    }
                    temp->Get_left()->Set_data(temp2->Get_right()->Get_data());
                    temp2->Set_right(NULL);

                    return;
                }

                temp=temp->Get_left();
            }
        }
    }
    void Display()
    {
        cout<<"Display_Result:"<<endl;
        if(root==NULL)
        {
            cout<<"Nothing To Display...!"<<endl;
            return;
        }
        cout<<"\t\t\t\tPRE_OREDER IS: "<<endl<<endl;
        cout<<"\t\t\t\t";
        Preorder(root);
        cout<<"  "<<endl<<endl;
        cout<<"\t\t\t\tPOST_OREDER IS: "<<endl<<endl;
        cout<<"\t\t\t\t";
        Postorder(root);
        cout<<"  "<<endl<<endl;
        cout<<"\t\t\t\tIN_OREDER IS: "<<endl<<endl;
        cout<<"\t\t\t\t";
        Inorder(root);
        cout<<"   "<<endl<<endl;
    }
    void Preorder(Node*R)
    {
        if(R==NULL)
        {
            return;
        }
        else
        {
            cout<<"   "<<R->Get_data();
            Preorder(R->Get_left());
            Preorder(R->Get_right());
        }
    }
    void Postorder(Node*R)
    {
        if(R==NULL)
        {
            return;
        }
        else
        {
            Postorder(R->Get_left());
            Postorder(R->Get_right());
            cout<<"   "<<R->Get_data();

        }

    }
    void Inorder(Node*R)
    {
        if(R==NULL)
        {
            return;
        }
        else
        {
            Inorder(R->Get_left());
            cout<<"   "<<R->Get_data();
            Inorder(R->Get_right());

        }

    }
    int Show_height()
    {
        cout<<"Height of BST : "<<get_height(root)<<endl;
    }

    void Show_level()
    {

        printLevelOrder(root);

    }
    void printLevelOrder(Node* root)
    {
        int h =get_height(root)+1;
        int i;
        for (i = 1; i <= h; i++)
        {
            printGivenLevel(root, i);
            cout<<endl;
        }

    }
    /* Print nodes at a given level */
    void printGivenLevel(Node* root, int level)
    {
        if (root == NULL)
            return;
        if (level == 1)
            cout << root->Get_data()<< "      ";
        else if (level > 1)
        {
            printGivenLevel(root->Get_left(), level-1);
            printGivenLevel(root->Get_right(), level-1);

        }
    }
    int get_height(Node *root)
    {
        if (root == NULL)
            return -1;

        // find the height of each subtree
        int lh = get_height(root->Get_left());
        int rh = get_height(root->Get_right());

        return 1 + max(lh,rh);
    }

    int balancefacter(Node *node)
    {
        int lh, rh;
        if(node==NULL)
            return 0;
        if(node->Get_left()==NULL)
            lh=0;
        else
            lh=get_height(node->Get_left())+1;
        if(node->Get_right()==NULL)
            rh=0;
        else
            rh=get_height(node->Get_right())+1;
        return lh-rh;

    }
    Node* RotateRight(Node *root)
    {
        Node *node_2=root->Get_left();
        root->Set_left(node_2->Get_right());
        node_2->Set_right(root);
        return node_2;
    }

    Node * LeftrightRotation(Node*root)
    {
        Node* temp=root->Get_left();
        root->Set_left(RotateLeft(temp));
        return RotateRight(root);
    }
    Node* RotateLeft(Node *root)
    {

        Node *node_2=root->Get_right();
        root->Set_right(node_2->Get_left());
        node_2->Set_left(root);
        return node_2;
    }

    Node * RightleftRotatoin(Node*root)
    {
        Node* temp=root->Get_right();
        root->Set_right(RotateRight(temp));
        return RotateLeft(root);
    }

};
int main()
{
    BST obj;
       obj.Add_node(60);
    obj.Add_node(50);

    obj.Add_node(70);
    obj.Add_node(85);
    obj.Add_node(92);
    obj.Add_node(120);
    obj.Add_node(130);
    obj.Add_node(140);
    obj.Add_node(410);
    obj.Add_node(640);
    obj.Display();
    obj.Show_level();
    obj.Show_height();
    return 0;
}
/*Node *node_2=root->Get_left();
        Node *node_3=node_2->Get_right();
        node_2->Set_right(node_3->Get_left());
        node_3->Set_left(node_2);
        root->Set_left(node_3);
        Node *node_2=root->Get_right();
        Node *node_3=node_2->Get_left();
        node_2->Set_left(node_3->Get_right());
        if(node_3!=NULL){
        node_3->Set_right(node_2);
        }
        root->Set_right(node_3);
        */
