#include <iostream>
#include <string>

using namespace std;

class Task 
{
public:
    string task;
    bool status;
    Task* next;
    Task* prev;
};


class todolist
{
private:
    Task* head;
public:
    todolist() 
    {
        head = nullptr;
    }

    void addtask(string task) 
    {
        Task* newTask = new Task();
        newTask->task = task;
        newTask->status = false;
        if (head == nullptr) 
        {
            head = newTask;
            head->next = head;
            head->prev = head;
        }
        else
        {
            Task* temp = head;
            while (temp->next != head) 
            {
                temp = temp->next;
            }
            temp->next = newTask;
            newTask->prev = temp;
            newTask->next = head;
            head->prev = newTask;
        }
    }

    void addcompletedtask(string task) 
    {
        Task* newTask = new Task();
        newTask->task = task;
        newTask->status = true;
        if (head == nullptr) 
        {
            head = newTask;
            head->next = head;
            head->prev = head;
        } 
        else
        {
            Task* temp = head;
            while (temp->next != head) 
            {
                temp = temp->next;
            }
            temp->next = newTask;
            newTask->prev = temp;
            newTask->next = head;
            head->prev = newTask;
        }
    }

    bool markcompletion(int taskNumber) 
    {
        if (head == nullptr) 
        {
            cout << "To-do list is empty." << endl;
            return false;
        }
        Task* temp = head;
        int i = 1;
        do 
        {
            if (i == taskNumber) 
            {
                if (temp->status) 
                {
                    cout << "Task is already completed." << endl;
                    return true;
                } 
                else
                {
                    temp->status = true;
                    cout << "Task marked as completed." << endl;
                    return true;
                }
            }
            temp = temp->next;
            i++;
        } while (temp != head);
        cout << "Invalid task number." << endl;
        return false;
    }

    bool markincompletion(int taskNumber) 
    {
        if (head == nullptr) 
        {
            cout << "To-do list is empty." << endl;
            return false;
        }
        Task* temp = head;
        int i = 1;
        do 
        {
            if (i == taskNumber) 
            {
                if (!temp->status) 
                {
                    cout << "Task is already incompleted." << endl;
                    return true;
                } 
                else
                {
                    temp->status = false;
                    cout << "Task marked as incompleted." << endl;
                    return true;
                }
            }
            temp = temp->next;
            i++;
        } while (temp != head);
        cout << "Invalid task number." << endl;
        return false;
    }

    void display() 
    {
        if (head == nullptr) 
        {
            cout << "To-do list is empty." << endl;
        } 
        else
        {
            Task* temp = head;
            int i = 1;
            cout << "Sr. No." << "\t Tasks" << "\t\t\t\t Status" << endl;
            do 
            {
                cout << i << ".   " << temp->task << "\t\t" << (temp->status ? "Completed" : "Incompleted") << endl;
                temp = temp->next;
                i++;
            } while (temp != head);
        }
    }

    void displaycompletedtask() 
    {
        if (head == nullptr) 
        {
            cout << "To-do list is empty." << endl;
        } 
        else
        {
            Task* temp = head;
            int i = 1;
            cout << "Sr. No." << "\t Tasks" << "\t\t\t\t Status" << endl;
            do 
            {
                if (temp->status)
                {
                    cout << i << ".   " << temp->task << "\t\t" << "Completed" << endl;
                }
                temp = temp->next;
                i++;
            } while (temp != head);
        }
    }

    void displayincompletedtask() 
    {
        if (head == nullptr) 
        {
            cout << "To-do list is empty." << endl;
        } 
        else
        {
            Task* temp = head;
            int i = 1;
            cout << "Sr. No." << "\t Tasks" << "\t\t\t\t Status" << endl;
            do 
            {
                if (!temp->status) 
                {
                    cout << i << ".   " << temp->task << "\t\t" << "Incompleted" << endl;
                }
                temp = temp->next;
                i++;
            } while (temp != head);
        }
    }

    void removetask(int taskNumber) 
    {
        if (head == nullptr) 
        {
            cout << "To-do list is empty." << endl;
        } 
        else if (head->next == head)
        {
            if (taskNumber == 1) 
            {
                delete head;
                head = nullptr;
                cout << "Task removed." << endl;
            } 
            else
            {
                cout << "Invalid task number." << endl;
            }
        } 
        else
        {
            Task* temp = head;
            int i = 1;
            do 
            {
                if (i == taskNumber - 1) 
                {
                    Task* TaskToRemove = temp->next;
                    temp->next = TaskToRemove->next;
                    TaskToRemove->next->prev = temp;
                    delete TaskToRemove;
                    cout << "Task removed." << endl;
                    return;
                }
                temp = temp->next;
                i++;
            } while (temp != head);
            cout << "Invalid task number." << endl;
        }
    }
};


int main()
{
    todolist obj;
    int choice;
    while (true) 
    {
        cout << "                   Menu" << endl;
        cout << "Enter 1. to add task to the list." << endl;
        cout << "Enter 2. to add already completed task to the list." << endl;
        cout << "Enter 3. to mark task as completed in the list." << endl;
        cout << "Enter 4. to mark task as incompleted in the list." << endl;
        cout << "Enter 5. to remove task from the list." << endl;
        cout << "Enter 6. to display all tasks of the list." << endl;
        cout << "Enter 7. to display completed tasks of the list." << endl;
        cout << "Enter 8. to display incompleted tasks of the list." << endl;
        cout << "Enter 9. to exit the program." << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) 
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice) 
        {
            case 1: 
            {
                string task;
                cout << "Enter task: ";
                cin.ignore();
                getline(cin, task);
                obj.addtask(task);
                break;
            }
            case 2: 
            {
                string task;
                cout << "Enter task: ";
                cin.ignore();
                getline(cin, task);
                obj.addcompletedtask(task);
                break;
            }
            case 3: 
            {
                int taskNumber;
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                if (cin.fail()) 
                {
                    cout << "Invalid input. Please enter a number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                obj.markcompletion(taskNumber);
                int erase;
                cout << "Enter 1 if you want to delete the task as well from the list: ";
                cin >> erase;
                if (erase == 1)
                {
                    if (cin.fail()) 
                    {
                        cout << "Invalid input. Please enter a number." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    obj.removetask(taskNumber);
                }
                break;
            }
            case 4: 
            {
                int taskNumber;
                cout << "Enter task number to mark as incompleted: ";
                cin >> taskNumber;
                if (cin.fail()) 
                {
                    cout << "Invalid input. Please enter a number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                obj.markincompletion(taskNumber);
                break;
            }
            case 5: 
            {
                int taskNumber;
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                if (cin.fail()) 
                {
                    cout << "Invalid input. Please enter a number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                obj.removetask(taskNumber);
                break;
            }
            case 6: 
            {
                obj.display();
                break;
            }
            case 7: 
            {
                obj.displaycompletedtask();
                break;
            }
            case 8: 
            {
                obj.displayincompletedtask();
                break;
            }
            case 9: 
            {
                cout << "Program exitted successfully!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
    return 0;
}
