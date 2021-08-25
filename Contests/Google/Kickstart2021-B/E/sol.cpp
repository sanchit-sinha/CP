struct LinkedList{
    long long data;
    struct LinkedList *next;
};

typedef struct LinkedList *node;
node createNode(long long val){
    node newNode;
    newNode = (node)calloc(1 , sizeof(struct LinkedList));
    newNode -> data = val;
    newNode -> next = NULL;
    return newNode;
}
// node head = createNode(10);
// node head = NULL;