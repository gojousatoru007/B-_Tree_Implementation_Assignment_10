#include <stddef.h>
// Function to create a sample B+ tree for testing
node* createSampleTree2() {
    // Implement this function to create a sample B+ tree for testing
    // ...
    node* root = NULL;
    
    return root;/* return the root of the created tree */;
}
void test2() {
    // Run the tests
    node *sampleTree = createSampleTree2();
    
    // Test 1: Test the toString function
    const char *expected_output = "";
    test_toString(sampleTree, expected_output);

    // Clean up the tree
    destroy_tree(sampleTree);

    return 0;
}
