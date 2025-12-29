#include <iostream>
using namespace std;

template<typename T>
class CircularLinkedList {
private:
    struct Node {
        T data;
        Node *next;
    };
    // pointer refers to First Node 
    Node *head;
public:
    // Conestructor to set the default value for the head 
    CircularLinkedList() { head = NULL; }

    // Destructor to Clean Memory and avoid Memory leak 
    ~CircularLinkedList() {
        if (head == NULL) return;

        Node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = NULL; // to set the Linked List liner and avoid infinity loop 

        while (head != NULL) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        cout << "Memory Cleaned! 🧹" << endl;
    }

    // Create function to insert last Node 
    void Insert(T value)
    {
        Node* new_Node = new Node;
        new_Node->data = value;
        // if the list is empty this mean the head = NULL 
        if (head == NULL) {
            head = new_Node;
            new_Node->next = new_Node;
            return;
        } // return to exit from the function
        Node* temp = head;
        // this loop to set the temporary pointer into the last Node 
        // this condition not be run in the first time so we added those lines below 👇
        while (temp->next != head) {
           temp = temp->next; 
        }
        // set the pointer refers to the new node to run the condition 
        temp->next = new_Node;
        new_Node->next = head;
    } // the last line to set the circular linked list consept
    // after end the loop those lines link the new node into the linkde list and set the next refers to the first Node 

    // this function was Created to dislay the values of the data of eatch Node 
    void dislay()
    {
        // this condition takes into account case if the list is empty
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        // do to run the condition one time and chick the condition while the condition can not be run to the first time 
        do {
            cout << temp->data << " "; 
            temp = temp->next;
        }while (temp != head);
    } // this loop to dislay the values of the data for eatch Node 

    // this function to add the Node at the first of the Linked List 
    void Insert_At_Beginning(T value)
    {
        Node* new_Node = new Node;
        new_Node->data = value;
        Node* temp = head;

        // if List is empty
        if (head == NULL) {
            head = new_Node;
            new_Node->next = head;
            return;
        }

        // this loop was Created to set the temporary pointer at the End of the Linked List 
        while (temp->next != head) {
            temp = temp->next;
        }

        // set the circular linked list consept 
        temp->next = new_Node;
        new_Node->next = head;
        head = new_Node;
    }

    void delete_First_Node()
    {
        // list empty
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        // only one Node in the List
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* last = head;

        // in case there are many Nodes in the List 
        // set the temp into last Node 
        while (last->next != head) {
            last = last->next;
        }
        // set the last node refers to the first Node to apply the circular Linked List consept 
        last->next = head->next;
        head->next = NULL; // to lost the first Node 
        delete head; // delete the first Node 
        head = last->next; // set the head refers to the new first Node 
    }

    // Create a function to delete last Node 
    void pop()
    {
        // in case the list is empty 
        if (head == NULL) {
            printf("List is empty\n");
            return;
        }

        // in case onle one Node 
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* last = head;
        Node* prev = head;

        // set the last pointer into last Node 
        while (last->next != head) {
            // prev = last;
            last = last->next;
            // we can set the two loops in one loop with adding in this loop 👆
        }

        // set the previas pointer into before the last Node 
        while (prev->next->next != head) {
            prev = prev->next;
        }

        last->next = NULL;
        prev->next = head;
        delete last;
    }
};
