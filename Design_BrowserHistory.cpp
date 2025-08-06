/*
 * Filename: Design_BrowserHistory.cpp
 *
 * Authors: Rachel, Afridha Shaheen & Thrisha 
 * 
 * Description: Implements a simple browser history system using a doubly linked list.
 *              The user can visit a new webpage, move backward and forward, and 
 *              view the entire history.
 */

#include <iostream>            												// Header file for standard I/O operations
#include <string>              												// Header file for using string data type
using namespace std;         												// Standard namespace to avoid prefixing std::

/*
 * Structure representing a webpage node in the doubly linked list.
 */
struct Webpage {
    string data;                 											// URL of the webpage
    Webpage* prevWebpage;      											// Pointer to the previous webpage
    Webpage* nextWebpage;       											// Pointer to the next webpage
};

Webpage* head = NULL;           											// Pointer to the first page (homepage)
Webpage* NewWebpage = NULL;     											// Pointer to the current page

/*
 * Function to visit a new webpage and add it to the history.
 *
 * @param - url - The URL of the new webpage to visit.
 */
int visit_newWebpage(string url) {
    if (head == NULL) {														// If the head pointer is NULL (i.e., no history exists)
        Webpage* Homepage = new Webpage;									// Create a new node for the homepage
        Homepage->data = url;												// Store the URL in the data field
        Homepage->prevWebpage = NULL;										// Previous pointer is NULL (no page before homepage)
        Homepage->nextWebpage = NULL;										// Next pointer is NULL (no page after yet)
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

/*
 * Function to move backward in the browser history.
 *
 * @param - steps - Number of steps to move back.
 */
int move_backward(int steps) {
    while (steps > 0 && NewWebpage->prevWebpage != NULL) {					// As long as steps > 0 and previous page exists
        NewWebpage = NewWebpage->prevWebpage;								// Move back to previous page
        steps--;															// Decrease step count
    }
    cout << "Current page: " << NewWebpage->data << endl;					// Show current page after moving back
    return 0;															
}

/*
 * Function to move forward in the browser history.
 *
 * @param - steps - Number of steps to move forward.
 */
int move_forward(int steps) {
    while (steps > 0 && NewWebpage->nextWebpage != NULL) {						// As long as steps > 0 and next page exists
        NewWebpage = NewWebpage->nextWebpage;									// Move forward to next page
        steps--;																// Decrease step count
    }
    cout << "Current page after going forward: " << NewWebpage->data << endl;	// Show current page after moving forward
    return 0;															
}

/*
 * Function to display the full browser history from the beginning.
 */
int show() {
    Webpage* temp = head;													// Start from the head of the list
    cout << "Browser History: ";											// Print heading
    while (temp != NULL) {													// Loop through all nodes
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

/*
 * Main function to interact with the user and perform browser history operations.
 */
int main() {
    string homepage;														// Variable to store homepage URL
    cout << "Enter homepage URL: ";											// Prompt user to enter homepage
    cin >> homepage;														// Read homepage URL
    visit_newWebpage(homepage);												// Call function to add homepage

    string command;																					// To store the command entered by user
    while (true) {																					// Infinite loop to keep the browser running
        cout << "\nCommands: visit <url> | back <steps> | forward <steps> | show | exit" << endl; 	// Show available commands
        cout << "Enter command: ";																	// Prompt user for a command
        cin >> command;																				// Read the command

        if (command == "visit") {											// If user wants to visit a new page
            string url;														// Variable to store new URL
            cin >> url;														// Read URL from user
            visit_newWebpage(url);											// Call visit function
        }
        else if (command == "back") {										// If user wants to go back
            int steps;														// Variable to store steps
            cin >> steps;													// Read number of steps
            move_backward(steps);											// Call backward function
        }
        else if (command == "forward") {									// If user wants to go forward
            int steps;														// Variable to store steps
            cin >> steps;													// Read number of steps
            move_forward(steps);											// Call forward function
        }
        else if (command == "show") {										// If user wants to see history
            show();															// Call show function
        }
        else if (command == "exit") {										// If user wants to exit
            cout << "Exiting browser history..." << endl;					// Exit the program
            return 0;														
        }
        else {																// If command is not valid
            cout << "Invalid command. Please try again." << endl;			// Show error message
        }
    }

    return 0;																
}
