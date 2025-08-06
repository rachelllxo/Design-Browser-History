/*
* Filename: Design_BrowserHistory.cpp
*
* Authors: Rachel, Afridha Shaheen & Thrisha 
* 
* Description: Designed a browser history that can create a Homepage, visit a new page, 
*              move backwards and forwards within the browser using doubly linked list.
*/

#include <iostream>
#include <string>
using namespace std;

struct Webpage {
    string data;
    Webpage* prevWebpage;
    Webpage* nextWebpage;
};

Webpage* head = NULL;
Webpage* NewWebpage = NULL;

int visit_newWebpage(string url) {
    if (head == NULL) {
        Webpage* Homepage = new Webpage;
        Homepage->data = url;
        Homepage->prevWebpage = NULL;
        Homepage->nextWebpage = NULL;
        head = Homepage;
        NewWebpage = Homepage;
    } else {
        Webpage* temp = new Webpage;
        temp->data = url;
        temp->prevWebpage = NewWebpage;
        temp->nextWebpage = NULL;
        NewWebpage->nextWebpage = temp;
        NewWebpage = temp;
    }
    cout << "Visited: " << NewWebpage->data << endl;
    return 0;
}

int move_backward(int steps) {
    while (steps > 0 && NewWebpage->prevWebpage != NULL) {
        NewWebpage = NewWebpage->prevWebpage;
        steps--;
    }
    cout << "Current page: " << NewWebpage->data << endl;
    return 0;
}

int move_forward(int steps) {
    while (steps > 0 && NewWebpage->nextWebpage != NULL) {
        NewWebpage = NewWebpage->nextWebpage;
        steps--;
    }
    cout << "Current page after going forward: " << NewWebpage->data << endl;
    return 0;
}

int show() {
    Webpage* temp = head;
    cout << "Browser History: ";
    while (temp != NULL) {
        if (temp == NewWebpage) {
            cout << "[" << temp->data << "] "; // highlight current page
        } else {
            cout << temp->data << " ";
        }
        temp = temp->nextWebpage;
    }
    cout << endl;
    return 0;
}

int main() {
    string homepage;
    cout << "Enter homepage URL: ";
    cin >> homepage;
    visit_newWebpage(homepage);

    string command;
    while (true) {
        cout << "\nCommands: visit <url> | back <steps> | forward <steps> | show | exit" << endl;
        cout << "Enter command: ";
        cin >> command;

        if (command == "visit") {
            string url;
            cin >> url;
            visit_newWebpage(url);
        }
        else if (command == "back") {
            int steps;
            cin >> steps;
            move_backward(steps);
        }
        else if (command == "forward") {
            int steps;
            cin >> steps;
            move_forward(steps);
        }
        else if (command == "show") {
            show();
        }
        else if (command == "exit") {
            cout << "Exiting browser history..." << endl;
            return 0;
        }
        else {
            cout << "Invalid command. Please try again." << endl;
        }
    }

    return 0;
}
