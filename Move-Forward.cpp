/*
 * Function to move forward in the browser history.
 *
 * @param - steps - Number of steps to move forward.
 */
int move_forward(int steps) {
    while (steps > 0 && NewWebpage->nextWebpage != nullptr) {						// As long as steps > 0 and next page exists
        NewWebpage = NewWebpage->nextWebpage;									// Move forward to next page
        steps--;																// Decrease step count
    }
    cout << "Current page: " << NewWebpage->data << endl;	// Show current page after moving forward
    return 0;															
}