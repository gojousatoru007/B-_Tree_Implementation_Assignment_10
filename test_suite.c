
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

#include "test1.c"
#include "test2.c"

// Function to compare two strings
bool compare_strings(const char *str1, const char *str2) {
    return strcmp(str1, str2) == 0;
}

// Function to run tests for toString function
void test_toString(node *root, const char *expected_output) {
    // Create a character array to store the actual result
    char actual_output[1024];  // Adjust the size as needed

    // Generate the string representation and store it in "actual_output"
    toString(root, actual_output);

    // Compare the actual output with the expected output
    if (compare_strings(actual_output, expected_output)) {
        printf("Test Passed: Output matches the expected output.\n");
    } else {
        printf("Test Failed: Output does not match the expected output.\n");
        printf("Expected: %s\n", expected_output);
        printf("Actual:   %s\n", actual_output);
    }
}



int main() {
    // Run tests from each test file
    printf("Running tests from test1.c:\n");
    test1();


    printf("\n Running tests from test2.c:\n");
    test2();
    return 0;
}