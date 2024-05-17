//#include <iostream>
//#include <string>
//#include <list>
//
//using namespace std;
//
//class ToDoApp {
//private:
//    struct Task {
//        string description;
//    };
//
//    list<Task> tasks;
//
//public:
//    // Function to add a task
//    void addTask(const string& description) {
//        tasks.push_back({ description });
//        cout << "Task added: " << description << endl;
//    }
//
//    // Function to delete the last task
//    void deleteLastTask() {
//        if (!tasks.empty()) {
//            tasks.pop_back();
//            cout << "Last task deleted." << endl;
//        }
//        else {
//            cout << "No tasks to delete." << endl;
//        }
//    }
//
//    // Function to print all tasks
//    void printTasks() {
//        if (!tasks.empty()) {
//            cout << "Tasks:" << endl;
//            int index = 1;
//            for (const auto& task : tasks) {
//                cout << index << ". " << task.description << endl;
//                index++;
//            }
//        }
//        else {
//            cout << "No tasks." << endl;
//        }
//    }
//};
//
//int main() {
//    ToDoApp todo;
//
//    char choice;
//    do {
//        cout << "\n1. Add Task\n";
//        cout << "2. Delete Last Task\n";
//        cout << "3. Print Tasks\n";
//        cout << "4. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//        cin.ignore(); // Ignore newline character
//
//        switch (choice) {
//        case '1': {
//            cout << "Enter task description: ";
//            string description;
//            getline(cin, description);
//            todo.addTask(description);
//            break;
//        }
//        case '2':
//            todo.deleteLastTask();
//            break;
//        case '3':
//            todo.printTasks();
//            break;
//        case '4':
//            cout << "Exiting...\n";
//            break;
//        default:
//            cout << "Invalid choice.\n";
//        }
//    } while (choice != '4');
//
//    return 0;
//}