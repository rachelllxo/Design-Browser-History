
/*
 * Function to move backward in the browser history.
 *
 * @param - steps - Number of steps to move back.
 */
int move_backward(int steps) {
    while (steps > 0 && NewWebpage->prevWebpage != nullptr) {					// As long as steps > 0 and previous page exists
        NewWebpage = NewWebpage->prevWebpage;								// Move back to previous page
        steps--;															// Decrease step count
    }
    cout << "Current page: " << NewWebpage->data << endl;					// Show current page after moving back
    return 0;															
}
