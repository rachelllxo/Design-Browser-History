/*
 * Filename: Design_BrowserHistory.cpp
 *
 * Authors: Rachel, Afridha Shaheen & Thrisha 
 * 
 * Description: Implements a simple browser history system using a doubly linked list.
 *              The user can visit a new webpage, move backward and forward, and 
 *              view the entire history.
 */

#include <iostream>                     // Header file for standard I/O operations
#include <string>                       // Header file for using string data type
using namespace std;                    // Standard namespace
#include "Node-Structure.cpp"			//include node structure 
#include "Visit-Newpage.cpp"           // Include visit function implementation
#include "Move-Backwards.cpp"          // Include backward movement function
#include "Move-Forward.cpp"            // Include forward movement function
#include "Show-History.cpp"    		// Include show function

/*
 * Main function to interact with the user and perform browser history operations.
 */
int main() {
    string homepage;                                                       // Variable to store homepage URL
    cout << "Enter homepage URL: ";                                        // Prompt user to enter homepage
    cin >> homepage;                                                       // Read homepage URL
    visit_newWebpage(homepage);                                            // Call function to add homepage

    string command;                                                        // To store the command entered by user
    while (true) {                                                         // Infinite loop to keep the browser running
        cout << "\nCommands: visit <url> | back <steps> | forward <steps> | show | exit" << endl;
        cout << "Enter command: ";                                         // Prompt user for a command
        cin >> command;                                                    // Read the command

        if (command == "visit") {                                          // If user wants to visit a new page
            string url;                                                    // Variable to store new URL
            cin >> url;                                                    // Read URL from user
            visit_newWebpage(url);                                         // Call visit function
        }
        else if (command == "back") {                                      // If user wants to go back
            int steps;                                                     // Variable to store steps
            cin >> steps;                                                  // Read number of steps
            move_backward(steps);                                          // Call backward function
        }
        else if (command == "forward") {                                   // If user wants to go forward
            int steps;                                                     // Variable to store steps
            cin >> steps;                                                  // Read number of steps
            move_forward(steps);                                           // Call forward function
        }
        else if (command == "show") {                                      // If user wants to see history
            show();                                                        // Call show function
        }
        else if (command == "exit") {                                      // If user wants to exit
            cout << "Exiting browser history..." << endl;                  // Exit the program
            return 0;
        }
        else {                                                             // If command is not valid
            cout << "Invalid command. Please try again." << endl;         // Show error message
        }
    }

    return 0;
}
