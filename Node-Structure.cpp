/*
 * Structure representing a webpage node in the doubly linked list.
 */
struct Webpage {
    string data;                        // URL of the webpage
    Webpage* prevWebpage;              // Pointer to the previous webpage
    Webpage* nextWebpage;              // Pointer to the next webpage
};

Webpage* head = NULL;                  // Pointer to the first page (homepage)
Webpage* NewWebpage = NULL;            // Pointer to the current page
