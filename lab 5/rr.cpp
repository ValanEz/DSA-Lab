#include "clist.h"
#include<iostream>

using namespace std;

class RoundRobin : public Clist {
public:
    void execute_process(int time_slot);
};

void RoundRobin::execute_process(int time_slot) {
    if (len_ll() == 0) {
        cout << "\nNo processes to execute.";
        return;
    }

    while (len_ll() > 0) {
        int process_time = del_beg();
        cout << "\nExecuting process with time " << process_time;

        int remaining_time = process_time - time_slot;

        if (remaining_time > 0) {
            cout << "\nProcess needs more time, moving it to the back.";
            insert_end(remaining_time);
        } else {
            cout << "\nProcess completed!";
        }

        display();
    }
}

int main() {
    RoundRobin rr;
    int ch, time_slot, process_time;

    cout << "Enter time slot for execution: ";
    cin >> time_slot;

    while (true) {
        cout << "\n\nMenu\n";
        cout << "1. Insert Process\n";
        cout << "2. Execute Processes\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter process execution time: ";
                cin >> process_time;
                rr.insert_end(process_time);
                break;

            case 2:
                rr.execute_process(time_slot);
                break;

            case 3:
                rr.display();
                break;

            case 4:
                cout << "\nExiting program....";
                return 0;

            default:
                cout << "\nInvalid choice! Please enter 1-4.";
        }
    }
}


