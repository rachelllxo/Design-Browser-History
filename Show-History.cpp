/*
 * Function to display the full browser history from the beginning.
 */
int show() {
    Webpage* temp = head;													// Start from the head of the list
    cout << "Browser History: ";											// Print heading
    while (temp != nullptr) {													// Loop through all nodes
        if (temp == NewWebpage) {											// If the node is the current page
            cout << "[" << temp->data << "] ";								// Highlight it with brackets
        } else {
            cout << temp->data << " ";										// Print normally
        }
        temp = temp->nextWebpage;											// Move to the next page
    }
    cout << endl;															// End the output line
    return 0;															
}