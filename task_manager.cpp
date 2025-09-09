#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    int id;
    string title;
    string description;
    string dueDate;
    bool completed;
};

vector<Task> tasks;
int taskCount = 0;

// Function to add a task
void addTask() {
    Task t;
    t.id = ++taskCount;
    cout << "Enter Title: ";
    cin.ignore();
    getline(cin, t.title);
    cout << "Enter Description: ";
    getline(cin, t.description);
    cout << "Enter Due Date (YYYY-MM-DD): ";
    getline(cin, t.dueDate);
    t.completed = false;
    tasks.push_back(t);
    cout << "Task added successfully!\n";
}

// Function to view tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "\nID | Title | Description | Due Date | Completed\n";
    cout << "-----------------------------------------------\n";
    for (auto t : tasks) {
        cout << t.id << " | " << t.title << " | " << t.description 
             << " | " << t.dueDate << " | " << (t.completed ? "Yes" : "No") << endl;
    }
}

// Function to edit a task
void editTask() {
    int id;
    cout << "Enter Task ID to edit: ";
    cin >> id;
    for (auto &t : tasks) {
        if (t.id == id) {
            cin.ignore();
            cout << "Enter new Title: ";
            getline(cin, t.title);
            cout << "Enter new Description: ";
            getline(cin, t.description);
            cout << "Enter new Due Date: ";
            getline(cin, t.dueDate);
            cout << "Task updated successfully!\n";
            return;
        }
    }
    cout << "Task ID not found!\n";
}

// Function to delete a task
void deleteTask() {
    int id;
    cout << "Enter Task ID to delete: ";
    cin >> id;
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].id == id) {
            tasks.erase(tasks.begin() + i);
            cout << "Task deleted successfully!\n";
            return;
        }
    }
    cout << "Task ID not found!\n";
}

// Function to mark a task as completed
void markCompleted() {
    int id;
    cout << "Enter Task ID to mark completed: ";
    cin >> id;
    for (auto &t : tasks) {
        if (t.id == id) {
            t.completed = true;
            cout << "Task marked as completed!\n";
            return;
        }
    }
    cout << "Task ID not found!\n";
}

// Main menu
void menu() {
    int choice;
    do {
        cout << "\n--- Task Manager ---\n";
        cout << "1. Add Task\n2. View Tasks\n3. Edit Task\n4. Delete Task\n5. Mark Task Completed\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: editTask(); break;
            case 4: deleteTask(); break;
            case 5: markCompleted(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 6);
}

int main() {
    menu();
    return 0;
}
