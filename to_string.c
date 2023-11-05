
// void toString(node* root, char str) {
    

//     if (root == NULL) {
//         return;
//     }

//     if (root->is_leaf) {
//         printf("[");
//         for (int i = 0; i < root->num_keys; i++) {
//             printf("%d", ((record*)root->pointers[i])->value);
//             if (i < root->num_keys - 1) {
//                 printf(", ");
//             }
//         }
//         printf("] ");
//     } else {
//         for (int i = 0; i <= root->num_keys; i++) {
//             toString((node*)root->pointers[i], str);

//             if (i < root->num_keys) {
//                 printf("%d", root->keys[i]);
//                 if (i < root->num_keys - 1 || root->pointers[i + 1] != NULL) {
//                     printf(" , ");
//                 }
//             }
//         }
//     }

//     if (root->next != NULL) {
//         printf(", ");
//         toString(root->next, str);
//     }
//     return str;
// }



#include <stdio.h>

void appendString(node* root, char *str) {
    if (root == NULL) {
        return;
    }

    if (root->is_leaf) {
        sprintf(str + strlen(str), "[");
        for (int i = 0; i < root->num_keys; i++) {
            sprintf(str + strlen(str), "%d", ((record*)root->pointers[i])->value);
            if (i < root->num_keys - 1) {
                sprintf(str + strlen(str), ", ");
            }
        }
        sprintf(str + strlen(str), "] ");
    } else {
        for (int i = 0; i <= root->num_keys; i++) {
            appendString((node*)root->pointers[i], str);

            if (i < root->num_keys) {
                sprintf(str + strlen(str), "%d", root->keys[i]);
                if (i < root->num_keys - 1 || root->pointers[i + 1] != NULL) {
                    sprintf(str + strlen(str), " , ");
                }
            }
        }
    }

    if (root->next != NULL) {
        sprintf(str + strlen(str), ", ");
        appendString(root->next, str);
    }
}

char* toString(node* root, char *str) {
    // Clear the string before appending to it
    str[0] = '\0';
    if(root == NULL){
        return str;
    }
    
    appendString(root, str);
    return str;
}

