
// Insertion Prototypes

record * make_record(int value);

node * make_node(void);

node * make_leaf(void);

int get_left_index(node * parent, node * left);

node * insert_into_leaf(node * leaf, int key, record * pointer);

node * insert_into_leaf_after_splitting(node * root, node * leaf, int key,
                                        record * pointer);
node * insert_into_node(node * root, node * parent, 
		int left_index, int key, node * right);
node * insert_into_node_after_splitting(node * root, node * parent,
                                        int left_index,
		int key, node * right);

node * insert_into_parent(node * root, node * left, int key, node * right);

node * insert_into_new_root(node * left, int key, node * right);

node * start_new_tree(int key, record * pointer);

node * insert(node * root, int key, int value);

