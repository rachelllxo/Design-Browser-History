
/*
 * Function to visit a new webpage and add it to the history.
 *
 * @param - url - The URL of the new webpage to visit.
 */
int visit_newWebpage(string url) {
    if (head == NULL) {														// If the head pointer is NULL 
        Webpage* Homepage = new Webpage;									// Create a new node for the homepage
        Homepage->data = url;												// Store the URL in the data field
        Homepage->prevWebpage = NULL;										// Previous pointer is NULL 
        Homepage->nextWebpage = NULL;										// Next pointer is NULL 
        head = Homepage;													// Head now points to homepage
        NewWebpage = Homepage;												// NewWebpage (current page) also points to homepage
    } else {
        Webpage* temp = new Webpage;										// Create a new webpage node for the new URL
        temp->data = url;													// Store the URL in the node's data field
        temp->prevWebpage = NewWebpage;										// Set the previous pointer to current page
        temp->nextWebpage = NULL;											// Set next pointer to NULL (end of list)
        NewWebpage->nextWebpage = temp;										// Current page's next pointer updated to new node
        NewWebpage = temp;													// Move current page pointer to the new page
    }
    cout << "Visited: " << NewWebpage->data << endl;						// Print the visited page
    return 0;															
}
