#include <iostream>
#include <string>
using namespace std;

// class to set the operator overloading consept 
class Student {
    private:
        string name;
        int id;
    public:
        Student() {} // this default constructor is very important to array to set an empty array from this class 
        Student(string n, int i) : name(n) , id(i) {} // this constructor to set the values to all its members 
        
        friend ostream& operator<<(ostream& os, const Student& s); // this friend function to allow print object with libriary named "ostream" 
        friend istream& operator>>(istream& is, Student s); // this friend function to allow input object with libriary named "ostream" 
};


ostream& operator<<(ostream& os, const Student& s) {
    os << "[Name: " << s.name << " | ID: " << s.id << "]"; // this line is responsible for printing an object in an organized way 
    return os; // we returned os to allow make many operators in the same line as : cout << s1 << endl; this endl can be run only if we added return 
    // and this property named Chaining 
} // becuase the function will return an output stream we set the return-type with ostream and the ostream will be Reference becuase we can't copy screen 

istream& operator>>(istream& is, Student s) {
    cout << "\n=========== New Student Data ============\n";
    cout << "Name: ";
    is >> s.name;
    cout << "ID: ";
    is >> s.id;
    return is;
} // clean code 

template<typename T>
class CircularQueue {
    private:
        T *arr; // we set the array from T type to make the process flixible , so we can add integer or float or string in the same array ! 
        int front;
        int rear;
        int capacity; // this is the size of the array 
    public:
        // constructor to set the defualt value to all its opjects 
        CircularQueue(int Size) {
            capacity = Size;
            arr = new T[capacity]; // Dynamic size to set it in main 
            front = -1;
            rear = -1;
        } // set the default values 
    
        // function to add values in the Queue 
        void enQueue(T value)
        {
            // in case the Queue is Empty
            if (front == -1 && rear == -1) front = rear = 0;
            // in case the Queue if Full 
            if ((rear + 1) % capacity == front) { cout << "Queue is Full\n"; return; }
            else rear = (rear + 1) % capacity;
            arr[rear] = value;
            
        }
        // function to delete the first value in the Queue using FIFO consept 
        void deQueue()
        {
            // in case Queue is Empty
            if (front == -1 && rear == -1) { cout << "Queue is Empty\n"; return; }

            // in case onle one element in Queue
            if (front == rear) front = rear = -1;
            else front = (front + 1) % capacity; // many values 
        }
        // function to display the values in the Queue 
        void display()
        {
            // in case Queue is Empty
            if (front == -1 && rear == -1) { cout << "Queue is Empty" << endl; return; }

            // create variable to lead to the values 
            int i = front;
            cout << "Queue : ";

            // print the values 
            while (i != rear) {
                cout << arr[i] << " ";
                i = (i + 1) % capacity;
            } // don't set the condition i != front becuase that mean the function will print the first value agian 

            cout << arr[rear] << endl;
        }

        // menber function to return first value from Queue 
        void peek() {
            if (front == -1) { cout << "Queue is Empty\n"; return; }
            else cout << arr[front] << endl;
        }

        // simple function to check is Queue Empty 
        bool empty() { return (front == -1); }

        // simple function to check is Queue Full 
        bool full() { return ((rear + 1) % capacity == front); }

        // destructor to delete the array after the end adn avoid Memory Lack 
        ~CircularQueue() { delete[] arr; }
};

int main()
{
//********* Queue 1 (int) ***********
    CircularQueue<int> q1(5);

    q1.enQueue(40);
    q1.enQueue(50);
    q1.enQueue(60);
    q1.enQueue(70);
    q1.enQueue(80);

    q1.display();

    q1.deQueue();
    q1.display();

//********* Queue 2 (string) ***********
    CircularQueue<string> q2(3); // we added <string> as header in the libriary to use it here 

    q2.enQueue("Ahmed");
    q2.enQueue("Saif");
    q2.enQueue("Omar");

    q2.display();

    q2.deQueue();
    q2.display();

//********* Queue 3 (class Student) *************
    CircularQueue<Student> Queue(3);

    Queue.enQueue(Student("Saif", 311)); // this way to add object called "Anonymous Objects"
    Queue.enQueue(Student("Omar", 102));
    Queue.enQueue(Student("Hazem", 116));

    cout << "Student in Queue\n";
    Queue.display();

    Queue.deQueue();
    Queue.display();

//********* Queue 4 (Student) ***********
    CircularQueue<Student> school(3);

    school.enQueue(Student("Mentor", 1));

    Student newStudent;
    cin >> newStudent;
    school.enQueue(newStudent);

    cout << "\n School Queue \n";
    school.display();

    return 0;
}

