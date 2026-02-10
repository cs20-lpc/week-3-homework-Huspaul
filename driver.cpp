#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"

using namespace std;

struct Node {
    Student data;
    Node* next;
    Node(const Student& s) : data(s), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList() : head(nullptr), tail(nullptr), length(0) {}

    ~LinkedList() {
        Node* cur = head;
        while (cur != nullptr) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    void insertEnd(const Student& s) {
        Node* n = new Node(s);
        if (head == nullptr) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
        length++;
    }

    bool deleteById(int id) {
        Node* cur = head;
        Node* prev = nullptr;

        while (cur != nullptr) {
            if (cur->data.getId() == id) {
                if (prev == nullptr) { // delete head
                    head = cur->next;
                    if (cur == tail) tail = head;
                } else {
                    prev->next = cur->next;
                    if (cur == tail) tail = prev;
                }
                delete cur;
                length--;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    Student* searchById(int id) {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->data.getId() == id) return &(cur->data);
            cur = cur->next;
        }
        return nullptr;
    }

    void displayAll() const {
        cout << "Students in List:\n";
        if (head == nullptr) {
            cout << "<empty>\n";
            return;
        }
        Node* cur = head;
        while (cur != nullptr) {
            cur->data.print(cout);
            cout << "\n";
            cur = cur->next;
        }
    }

    int count() const { return length; }
};

// ---- helper: safe line read after numeric input ----
static void eatLine() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    LinkedList list;
    int choice = 0;

    while (true) {
        cout << "\n1. Insert Student\n"
             << "2. Delete Student\n"
             << "3. Search Student\n"
             << "4. Display All\n"
             << "5. Count Students\n"
             << "6. Add a course\n"
             << "7. Exit\n"
             << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            eatLine();
            cout << "Invalid input.\n";
            continue;
        }

        if (choice == 7) break;

        if (choice == 1) {
            int id;
            string name;
            double gpa;

            cout << "Enter ID: ";
            cin >> id;
            eatLine();

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter GPA: ";
            cin >> gpa;

            Student s(id, name, gpa);
            list.insertEnd(s);
        }
        else if (choice == 2) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;

            if (list.deleteById(id)) {
                cout << "Deleted student with ID " << id << "\n";
            } else {
                cout << "No student found with ID " << id << "\n";
            }
        }
        else if (choice == 3) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;

            Student* s = list.searchById(id);
            if (s == nullptr) {
                cout << "No student found with ID " << id << "\n";
            } else {
                cout << "Found: ";
                s->print(cout);
                cout << "\n";
                s->printCourses(cout);
            }
        }
        else if (choice == 4) {
            list.displayAll();
        }
        else if (choice == 5) {
            cout << "Total students: " << list.count() << "\n";
        }
        else if (choice == 6) {
            int id;
            string cname, location;

            cout << "Enter ID: ";
            cin >> id;
            eatLine();

            Student* s = list.searchById(id);
            if (s == nullptr) {
                cout << "No student found with ID " << id << "\n";
                continue;
            }

            cout << "Enter Course Name: ";
            getline(cin, cname);

            cout << "Enter location: ";
            getline(cin, location);

            Course c(cname, location);
            s->addCourse(c);
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    cout << "Goodbye!\n";
    return 0;
}
