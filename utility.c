#include "utility.h"


#define DEFAULT_ORDER 4
int order = DEFAULT_ORDER;
// Default order is 4
#define MIN_ORDER 3
#define MAX_ORDER 20
// Minimum order is necessarily 3.  We set the maximum
// order arbitrarily.  You may change the maximum order.


node * queue = NULL;

bool verbose_output = false;

// OUTPUT AND UTILITIES

/* First message to the user.
 */
void message_1(void) {
	printf("B+ Tree of Order %d.\n", order);
}


/* Second message to the user.
 */
void message_2(void) {
	printf("Enter any of the following commands after the prompt > :\n"
	"\ti <k>  -- Insert <k> (an integer) as both key and value).\n"
	"\ti <k> <v> -- Insert the value <v> (an integer) as the value of key <k> (an integer).\n"
	"\tf <k>  -- Find the value under key <k>.\n"
	"\tp <k> -- Print the path from the root to key k and its associated "
           "value.\n"
	"\td <k>  -- Delete key <k> and its associated value.\n"
	"\tx -- Destroy the whole tree.  Start again with an empty tree of the "
           "same order.\n"
	"\tt -- Print the B+ tree.\n"
	"\tl -- Print the keys of the leaves (bottom row of the tree).\n"
	"\ts -- Print the Tree in the format [leftchildvalues], root, [right_child_values]..."
	"\tq -- Quit. (Or use Ctl-D or Ctl-C.)\n");
}



/* Helper function for printing the
 * tree out.  See print_tree.
 */
void enqueue(node * new_node) {
	node * c;
	if (queue == NULL) {
		queue = new_node;
		queue->next = NULL;
	}
	else {
		c = queue;
		while(c->next != NULL) {
			c = c->next;
		}
		c->next = new_node;
		new_node->next = NULL;
	}
}


/* Helper function for printing the
 * tree out.  See print_tree.
 */
node * dequeue(void) {
	node * n = queue;
	queue = queue->next;
	n->next = NULL;
	return n;
}


/* Prints the bottom row of keys
 * of the tree (with their respective
 * pointers, if the verbose_output flag is set.
 */
void print_leaves(node * const root) {
	if (root == NULL) {
		printf("Empty tree.\n");
		return;
	}
	int i;
	node * c = root;
	while (!c->is_leaf)
		c = c->pointers[0];
	while (true) {
		for (i = 0; i < c->num_keys; i++) {
			if (verbose_output)
				printf("%p ", c->pointers[i]);
			printf("%d ", c->keys[i]);
            if(c->pointers[i]){
				record* x = c->pointers[i];
				printf("(%d", x->value);
				x = x->next;
				while(x != NULL){
					printf("->%d", x->value);
					x = x->next;
				}
				printf(")");
			}
		}
		if (verbose_output)
			printf("%p ", c->pointers[order - 1]);
		if (c->pointers[order - 1] != NULL) {
			printf(" | ");
			c = c->pointers[order - 1];
		}
		else
			break;
	}
	printf("\n");
}


/* Utility function to give the height
 * of the tree, which length in number of edges
 * of the path from the root to any leaf.
 */
int height(node * const root) {
	int h = 0;
	node * c = root;
	while (!c->is_leaf) {
		c = c->pointers[0];
		h++;
	}
	return h;
}


/* Utility function to give the length in edges
 * of the path from any node to the root.
 */
int path_to_root(node * const root, node * child) {
	int length = 0;
	node * c = child;
	while (c != root) {
		c = c->parent;
		length++;
	}
	return length;
}


/* Prints the B+ tree in the command
 * line in level (rank) order, with the 
 * keys in each node and the '|' symbol
 * to separate nodes.
 * With the verbose_output flag set.
 * the values of the pointers corresponding
 * to the keys also appear next to their respective
 * keys, in hexadecimal notation.
 */
void print_tree(node * const root) {

	node * n = NULL;
	int i = 0;
	int rank = 0;
	int new_rank = 0;

	if (root == NULL) {
		printf("Empty tree.\n");
		return;
	}
	queue = NULL;
	enqueue(root); // push root in queue
	while(queue != NULL) {
		n = dequeue();
		if (n->parent != NULL && n == n->parent->pointers[0]) {
			new_rank = path_to_root(root, n); //
			if (new_rank != rank) {
				rank = new_rank;
				printf("\n");
			}
		}
		if (verbose_output) 
			printf("(%p)", n);
		for (i = 0; i < n->num_keys; i++) {
			if (verbose_output)
				printf("%p ", n->pointers[i]);
               
			printf("%d ", n->keys[i]);

            
		}
		if (!n->is_leaf)
			for (i = 0; i <= n->num_keys; i++)
				enqueue(n->pointers[i]);
		if (verbose_output) {
			if (n->is_leaf) 
				printf("%p ", n->pointers[order - 1]);
			else
				printf("%p ", n->pointers[n->num_keys]);
		}
		printf("| ");
	}
	printf("\n");
}


/* Finds the record under a given key and prints an
 * appropriate message to stdout.
 */
void find_and_print(node * const root, int key, bool verbose) {
    node * leaf = NULL;
	record * r = find(root, key, verbose, NULL);
	if (r == NULL){
		printf("Record not found under key %d.\n", key);}
	else {
		printf("Record at %p -- key %d, value %d.\n",
				r, key, r->value);

		while(r->next != NULL){
            printf("%d", r->value);
            r = r->next;
        }
		
	}
}



/* Traces the path from the root to a leaf, searching
 * by key.  Displays information about the path
 * if the verbose flag is set.
 * Returns the leaf containing the given key.
 */
node * find_leaf(node * const root, int key, bool verbose) {
	if (root == NULL) {
		if (verbose) 
			printf("Empty tree.\n");
		return root;
	}
	int i = 0;
	node * c = root;
	while (!c->is_leaf) {
		if (verbose) {
			printf("[");
			for (i = 0; i < c->num_keys - 1; i++)
				printf("%d ", c->keys[i]);
			printf("%d] ", c->keys[i]);
		}
		i = 0;
		while (i < c->num_keys) {
			if (key >= c->keys[i]) i++;
			else break;
		}
		if (verbose)
			printf("%d ->\n", i);
		c = (node *)c->pointers[i];
	}
	if (verbose) {
		printf("Leaf [");
		for (i = 0; i < c->num_keys - 1; i++)
			printf("%d ", c->keys[i]);
		printf("%d] ->\n", c->keys[i]);
	}
	return c;
}


/* Finds and returns the record to which
 * a key refers.
 */
record * find(node * root, int key, bool verbose, node ** leaf_out) {
    if (root == NULL) {
        if (leaf_out != NULL) {
            *leaf_out = NULL;
        }
        return NULL;
    }

	int i = 0;
    node * leaf = NULL;

	leaf = find_leaf(root, key, verbose);

    /* If root != NULL, leaf must have a value, even
     * if it does not contain the desired key.
     * (The leaf holds the range of keys that would
     * include the desired key.) 
     */

	for (i = 0; i < leaf->num_keys; i++)
		if (leaf->keys[i] == key) break;
    if (leaf_out != NULL) {
        *leaf_out = leaf;
    }
	if (i == leaf->num_keys)
		return NULL;
	else
		return (record *)leaf->pointers[i];
}

/* Finds the appropriate place to
 * split a node that is too big into two.
 */
int cut(int length) {
	if (length % 2 == 0)
		return length/2;
	else
		return length/2 + 1;
}

