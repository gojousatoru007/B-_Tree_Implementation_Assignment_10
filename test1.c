// Function to create a sample B+ tree for testing
node* createSampleTree() {
    // Implement this function to create a sample B+ tree for testing
    // ...
    node* root = NULL;
    root = insert(root, 1, 1);
    root = insert(root, 2, 2);
    root = insert(root, 3, 3);
    root = insert(root, 4, 4);
    root = insert(root, 5, 5);
    root = insert(root, 6, 6);
    root = insert(root, 7, 7);
    root = insert(root, 8, 8);
    root = insert(root, 9, 9);
    root = insert(root, 10, 10);
    
    return root;/* return the root of the created tree */;
}
void test1() {
    // Run the tests
    node *sampleTree = createSampleTree();
    
    // Test 1: Test the toString function
    const char *expected_output = "[1, 2] 3 , [3, 4] 5 , [5, 6] 7 , [7, 8] 9 , [9, 10] ";
    test_toString(sampleTree, expected_output);

    // Clean up the tree
    destroy_tree(sampleTree);

    return 0;
}
