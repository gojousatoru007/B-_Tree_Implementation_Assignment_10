// Output and utility Prototypes

void message_1(void);

void message_2(void);

void message_3(void);

void enqueue(node * new_node);

node * dequeue(void);

int height(node * const root);

int path_to_root(node * const root, node * child);

void print_leaves(node * const root);

void print_tree(node * const root);

void find_and_print(node * const root, int key, bool verbose); 

// void find_and_print_range(node * const root, int range1, int range2, bool verbose); 

// int find_range(node * const root, int key_start, int key_end, bool verbose,
// 		int returned_keys[], void * returned_pointers[]); 

node * find_leaf(node * const root, int key, bool verbose);

record * find(node * root, int key, bool verbose, node ** leaf_out);

int cut(int length);