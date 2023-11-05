
typedef struct record {
	int value;
    struct record* next; // storing duplicate key-records in a linked-list arrangement 
	
} record;


typedef struct node {
	void ** pointers; // array of pointers 
	int * keys; // array of keys
	struct node * parent; // parent pointer
	bool is_leaf; // is the node a leaf or an internal node?
	int num_keys; // number of keys present in the node (to check with the order of the bpt)

	struct node * next; // Used for queue (nodes, specially leaf nodes are in a linked list, single or doubly.
} node;
