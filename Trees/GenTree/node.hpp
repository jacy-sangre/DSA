struct Node{

    int data;
    Node* parent;
    Node** children;
    int num_of_children;
    int cap;

    Node(int val){
        data = val;
        parent = nullptr;
        children = nullptr;
        num_of_children = 0;
        cap = 5;
    }

};