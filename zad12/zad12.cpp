#include <iostream>
#include <stack>
using namespace std;

template <class Typ>
class Node {
public:
    Node* leftchild;
    Node* rightchild;


    Typ data;
    Node(Typ data, Node* leftchild, Node* rightchild){
        this->data=data;
        leftchild = nullptr;
        rightchild = nullptr;
    }
};


template <class Typ>
class Tree{
private:
    Node<Typ>* minValueNode(Node<Typ>* node) {
        Node<Typ>* current = node;
        while (current && current->leftchild != nullptr) {
            current = current->leftchild;
        }
        return current;
    }
public:
    Node<Typ>* root;
    Tree(){
        root = nullptr;
    }

    void dodaj(Typ dane){
        if(root == NULL){
            root = new Node<Typ>(dane, nullptr, nullptr);
        }  else {

            Node<Typ>* curr = root;
            int b = 1;
            while(b){
                if(dane >= curr -> data){

                    if(curr->leftchild == nullptr){
                        curr -> leftchild = new Node<Typ>(dane, nullptr, nullptr);
                        b=0;
                    }else {
                        curr = curr -> leftchild;
                    }

                } else if (dane < curr ->data){
                    if(curr->rightchild == nullptr){
                        curr -> rightchild = new Node<Typ>(dane, nullptr, nullptr);
                        b=0;
                        return;
                    }else {
                        curr = curr -> rightchild;
                    }
                }
            }

        }

    }

    Node<Typ>* usun(Node<Typ>* root, Typ k) {
        if (root == nullptr) {
            return root;
        }


        if (k < root->data) {
            root->leftchild = usun(root->leftchild, k);
        } else if (k > root->data) {
            root->rightchild = usun(root->rightchild, k);
        } else {
            if (root->leftchild == nullptr) {
                Node<Typ>* temp = root->rightchild;
                delete root;
                return temp;
            } else if (root->rightchild == nullptr) {
                Node<Typ>* temp = root->leftchild;
                delete root;
                return temp;
            }

            Node<Typ>* temp = minValueNode(root->rightchild);

            root->data = temp->data;


            root->rightchild = usun(root->rightchild, temp->data);
        }
        return root;
    }

    int najdluzsza() {
        return najdluzszaSciezka(root) - 1;
    }

    int najdluzszaSciezka(Node<Typ>* val) {
        if (val == nullptr){
            return 0;
        }

        int lewaSciezka = najdluzszaSciezka(val -> leftchild);
        int prawaSciezka = najdluzszaSciezka(val -> rightchild);

        if (lewaSciezka > prawaSciezka) {
            return 1 + lewaSciezka;
        } else {
            return 1 + prawaSciezka;
        }
    }

    int najkrotsza() {
        return najkrotszaSciezka(root);
    }

    int najkrotszaSciezka(Node<Typ> *val) {
        if (val == nullptr){
            return 0;
        }

        int lewaSciezka = najkrotszaSciezka(val -> leftchild);
        int prawaSciezka = najkrotszaSciezka(val -> rightchild);

        if (lewaSciezka > prawaSciezka) {
            return 1 + prawaSciezka;
        } else {
            return 1 + lewaSciezka;
        }
    }

    void preorder(Node<Typ>* node){
        if (node == NULL)
            return;

        cout << node->data << " ";
        preorder(node->leftchild);
        preorder(node->rightchild);
    }

    void inorder(Node<Typ>* node){
        if (node == NULL)
            return;
        inorder(node->leftchild);
        cout << node->data << " ";
        inorder(node->rightchild);
    }

    void postorder(Node<Typ>* node){
        if (node == NULL)
            return;

        postorder(node->leftchild);
        postorder(node->rightchild);
        cout << node->data << " ";
    }

};

int main(){
    int K,L,M;
    Tree<double> drzewko;
    cin>>K;
    for(int i=0; i < K; i++){
        double d;
        cin>>d;
        drzewko.dodaj(d);
    }

    cin>>L;
    for(int i=0; i < L; i++){
        double d;
        cin>>d;
        drzewko.root = drzewko.usun(drzewko.root, d);
    }

    cin >> M;
    switch(M){
        case 0:{
            drzewko.preorder(drzewko.root);
            break;
        }
        case 1:{
            drzewko.inorder(drzewko.root);
            break;
        }
        case 2:{
            drzewko.postorder(drzewko.root);
            break;
        }
    }

    cout << drzewko.najdluzsza()<<" ";
    cout << drzewko.najkrotsza();

    return 0;
}