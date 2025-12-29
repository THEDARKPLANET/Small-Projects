#include <iostream>
using namespace std;

template<typename T>
class CircularLinkedList {
private:
    struct Node {
        T data;
        Node *next;

        Node(T val) {
            data = val;
            next = NULL;
        }
    };
    // pointer refers to First Node 
    Node *head;
public:
    // Conestructor to set the default value for the head 
    CircularLinkedList() { head = NULL; }
    // Destructor to Clean Memory and avoid Memory leak 
    ~CircularLinkedList() {
        if (!head) return;

        // set the List Linear 
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = NULL;

        // Compleatly deleteed 
        while (head != NULL) {
            Node* del = head;
            head = head->next;
            delete del;
        }

        cout << "Memory Cleaned! 🧹" << endl;
    }

    void Insert(T value)
    {
        Node* new_Node = new Node(value);
        // if the list is empty this mean the head = NULL 
        if (head == NULL) {
            head = new_Node;
            new_Node->next = new_Node;
        } // return to exit from the function
        else {
            Node* temp = head;
            // this loop to set the temporary pointer into the last Node 
            // this condition not be run in the first time so we added those lines below 👇
            while (temp->next != head) {
               temp = temp->next; 
            }
            // set the pointer refers to the new node to run the condition 
            temp->next = new_Node;
            new_Node->next = head;
        }
    }// the last line to set the circular linked list consept
    // after end the loop those lines link the new node into the linkde list and set the next refers to the first Node 

    void Insert_At_Beginning(T value)
    {
        Node* new_Node = new Node(value);
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
            prev = last;
            last = last->next;
            // we can set the two loops in one loop with adding in this loop 👆
        }

        last->next = NULL;
        prev->next = head;
        delete last;
    }

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

};
