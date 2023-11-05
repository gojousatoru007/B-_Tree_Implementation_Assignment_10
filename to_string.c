
void toString(node* root) {
    if (root == NULL) {
        return;
    }

    if (root->is_leaf) {
        printf("[");
        for (int i = 0; i < root->num_keys; i++) {
            printf("%d", ((record*)root->pointers[i])->value);
            if (i < root->num_keys - 1) {
                printf(", ");
            }
        }
        printf("] ");
    } else {
        for (int i = 0; i <= root->num_keys; i++) {
            toString((node*)root->pointers[i]);

            if (i < root->num_keys) {
                printf("%d", root->keys[i]);
                if (i < root->num_keys - 1 || root->pointers[i + 1] != NULL) {
                    printf(" , ");
                }
            }
        }
    }

    if (root->next != NULL) {
        printf(", ");
        toString(root->next);
    }

}