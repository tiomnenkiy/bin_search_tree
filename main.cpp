#include <iostream>
#include <queue>

using namespace std;

class Tree {
    class Node {
    public:
        int data;
        Node* left;
        Node* right;
        explicit Node(int info) {
            data = info;
            left = nullptr;
            right = nullptr;
        }
    };

public:
    Node* top;
    Tree() {
        top = nullptr;
    }

    ~Tree() {

    }

    int Compare (int info, Node* x) {
        if (info < x->data)
            return -1;
        else if (info > x->data)
            return 1;
        else
            return 0;
    }

    Node* Search (Node* x, int info) {
        if (x == nullptr || info == x->data)
            return x;
        if (info < x->data)
            return Search(x->left, info);
        else
            return Search(x->right, info);
    }

    Node* Min (Node* x) {
        if (x->left == nullptr)
            return x;
        return Min(x->left);
    }

    Node* Max (Node* x) {
        if (x->right == nullptr)
            return x;
        return Max(x->right);
    }

    void Add (int info) {
        if (top == nullptr) {
            top = new Node(info);
        } else {
            Node* p = top;
            bool ready = 0;

            while (!ready) {
                if (Compare(info, p) < 0) {
                    if (p->left == nullptr) {
                        p->left = new Node(info);
                        ready = 1;
                    } else {
                        p = p->left;
                    }
                } else {
                    if (p->right == nullptr) {
                        p->right = new Node(info);
                        ready = 1;
                    } else {
                        p = p->right;
                    }
                }
            }

        }
    }

    void Display ()
    {
        if (top == nullptr)
        {
            return;
        }
        Node* p = top;
        queue<Node*> q;
        q.push(p);
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            cout << p->data << " ";
            if (p->left != nullptr)
            {
                q.push(p->left);
            }
            if (p->right != nullptr)
            {
                q.push(p->right);
            }

        }
        cout << endl;

    }

    void PreorderPrint() {
        if (top == nullptr)
        {
            return;
        }
        cout << top->data << " ";
        preorderPrint(top->left);   //рекурсивный вызов левого поддерева
        preorderPrint(top->right);
        cout << endl;
    }
    void preorderPrint(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        cout << root->data << " ";
        preorderPrint(root->left);   //рекурсивный вызов левого поддерева
        preorderPrint(root->right);  //рекурсивный вызов правого поддерева
    }

    void InorderPrint()
    {
        if (top == NULL)   // Базовый случай
        {
            return;
        }
        inorderPrint(top->left);   //рекурсивный вызов левого поддерева
        cout << top->data << " ";
        inorderPrint(top->right);  //рекурсивный вызов правого поддерева
        cout << endl;
    }
    void inorderPrint(Node *root)
    {
        if (root == NULL)   // Базовый случай
        {
            return;
        }
        inorderPrint(root->left);   //рекурсивный вызов левого поддерева
        cout << root->data << " ";
        inorderPrint(root->right);  //рекурсивный вызов правого поддерева
    }

    void PostorderPrint()
    {
        if (top == NULL)   // Базовый случай
        {
            return;
        }
        postorderPrint(top->left);   //рекурсивный вызов левого поддерева
        postorderPrint(top->right);  //рекурсивный вызов правого поддерева
        cout << top->data << " " << endl;
    }
    void postorderPrint(Node *root)
    {
        if (root == NULL)   // Базовый случай
        {
            return;
        }
        postorderPrint(root->left);   //рекурсивный вызов левого поддерева
        postorderPrint(root->right);  //рекурсивный вызов правого поддерева
        cout << root->data << " ";
    }

};

int main() {
    Tree p;
    p.Add(8);
    p.Add(3);
    p.Add(1);
    p.Add(6);
    p.Add(4);
    p.Add(7);
    p.Add(10);
    p.Add(14);
    p.Add(13);
    cout << p.Min(p.top)->data << endl;
    cout << p.Max(p.top)->data << endl;
    return 0;
}
