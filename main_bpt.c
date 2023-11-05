/*
 *  B_Plus Tree Implementation in C 
 */

#include <stdbool.h>

// adapt the code accordingly
#ifdef _WIN32 
#define bool char
#define false 0
#define true 1
#endif

// Including Base Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// INCLUDES for Node Structure
#include "node.h"

// Includes for Utility, Insert, Delete and To_String functionality
#include "utility.c"
#include "insert.c"
#include "delete.c"
#include "to_string.c"



// Constant for optional command-line input with "i" (insert) command.
#define BUFFER_SIZE 256

// MAIN

int main() {

	node * root;
	int input_key, input_key_2;
	char instruction;

	root = NULL;
	verbose_output = false;


    message_1();
	message_2();


	printf("> ");

    char buffer[BUFFER_SIZE];
    int count = 0;
    bool line_consumed = false;
	while (scanf("%c", &instruction) != EOF) {
        line_consumed = false;
		switch (instruction) {
		case 'd':
			scanf("%d", &input_key);
			root = delete(root, input_key);
			print_tree(root);
			break;
		case 'i':
            fgets(buffer, BUFFER_SIZE, stdin);
            line_consumed = true;
            count = sscanf(buffer, "%d %d", &input_key, &input_key_2);
            if (count == 1)
              input_key_2 = input_key;
			root = insert(root, input_key, input_key_2);
			print_tree(root);
			break;
		case 'f':
		case 'p':
			scanf("%d", &input_key);
			find_and_print(root, input_key, instruction == 'p');
			break;
		case 'l':
			print_leaves(root);
			break;
		case 'q':
			while (getchar() != (int)'\n');
			return EXIT_SUCCESS;
			break;
		case 't':
			print_tree(root);
			
			break;
		case 'v':
			verbose_output = !verbose_output;
			break;
		case 's':
			 char result[1024];  // Adjust the size as needed

			toString(root, result);
			printf("\n");
			break;
		case 'x':
			if (root)
				root = destroy_tree(root);
			print_tree(root);
			break;
		default:
			message_2();
			break;
		}
        if (!line_consumed)
           while (getchar() != (int)'\n');
		printf("> ");
	}
	printf("\n");

	return EXIT_SUCCESS;
}