/*
* Filename: Design_BrowserHistory.cpp
*
* Authors: Rachel, Afridha Shaheen & Thrisha 
* 
* Description: Designed a browser history that can create a Homepage, visit a new page, move backwards and forwards within the browser 
				using doubly linked list.
*/
 
#include <iostream>									//header files 
#include <string>
using namespace std;


struct Webpage {									//structure for a webpage using doubly linked list
    string data;									//the data part of the doubly linked list that stores the URL			
    Webpage* prevWebpage;							//the pointer to the previous webpage's address 
    Webpage* nextWebpage;							//the pointer to the next webpage's address 
};

Webpage* head = NULL;
Webpage* NewWebpage = NULL;

string visit_newWebpage(string url) {
    if (head == NULL) {
        Webpage* Homepage = new Webpage;		        //creating a new node to store the homepage
        Homepage->data = url;
        Homepage->prevWebpage = NULL;			        //the homepage has no previous node
        Homepage->nextWebpage = NULL; 			        //the homepage's next node is NULL for now 
        head = Homepage;
        NewWebpage = Homepage;
    } else {
        Webpage* temp = new Webpage;			        //creating a new webpage node that holds the URL
        temp->data = url;
        temp->prevWebpage = NewWebpage; 			    //the previous node of the new webpage points to current page
        temp->nextWebpage = NULL;
        NewWebpage->nextWebpage = temp;			        //the current page's next points to the new webpage
        NewWebpage = temp;					            //move current pointer to new webpage
    }
    return NewWebpage->data;
}
int move_backward(int steps) {									//function to move backwards from the current webpage

/* while the number of steps given is greater than zero and the new webpage's previous node is not NULL, 

		the new webpage's next node points to it's previous webpage
*/
    while (steps > 0 && NewWebpage->prevWebpage != NULL) {		
        NewWebpage = NewWebpage->prevWebpage;
        steps--;
    }
    cout << "Current page: " << NewWebpage->data << endl;		//to print the current page after going back
    return 0;
}



