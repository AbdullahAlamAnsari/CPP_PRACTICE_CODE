#include <iostream>
using namespace std;

/* ================= BASE CLASS ================= */

class Task {
protected:
    int id;
    bool running;

public:
    static int taskCount;

    Task() {
        id = ++taskCount;
        running = false;
    }

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void showStatus() = 0;

    int getId() {
        return id;
    }

    // VERY IMPORTANT
    virtual ~Task() {
        cout << "Task ID " << id << " destroyed\n";
    }
};

int Task::taskCount = 0;

/* ================= DERIVED CLASSES ================= */

class FileDownloadTask : public Task {
    int progress;

public:
    FileDownloadTask() {
        progress = 0;
    }

    void start() override {
        running = true;
        progress = 10;
        cout << "File download started\n";
    }

    void stop() override {
        running = false;
        cout << "File download stopped\n";
    }

    void showStatus() override {
        cout << "Download Task | ID: " << id
             << " | Progress: " << progress << "%\n";
    }
};

class AntivirusTask : public Task {
public:
    void start() override {
        running = true;
        cout << "Antivirus scan started\n";
    }

    void stop() override {
        running = false;
        cout << "Antivirus scan stopped\n";
    }

    void showStatus() override {
        cout << "Antivirus Task | ID: " << id
             << " | Running: " << (running ? "YES" : "NO") << endl;
    }
};

class MediaPlayerTask : public Task {
public:
    void start() override {
        running = true;
        cout << "Media playback started\n";
    }

    void stop() override {
        running = false;
        cout << "Media playback stopped\n";
    }

    void showStatus() override {
        cout << "Media Player Task | ID: " << id
             << " | Playing: " << (running ? "YES" : "NO") << endl;
    }
};

/* ================= MAIN PROGRAM ================= */

int main() {

    int capacity = 2;
    int count = 0;

    Task** tasks = new Task*[capacity];
    int choice;

    do {
        cout << "\n--- TASK MANAGER ---\n";
        cout << "1. Add File Download Task\n";
        cout << "2. Add Antivirus Task\n";
        cout << "3. Add Media Player Task\n";
        cout << "4. Start Task\n";
        cout << "5. Stop Task\n";
        cout << "6. Show All Tasks\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        /* ===== ADD TASKS ===== */
        if (choice >= 1 && choice <= 3) {

            if (count == capacity) {
                capacity *= 2;
                Task** temp = new Task*[capacity];

                for (int i = 0; i < count; i++)
                    temp[i] = tasks[i];

                delete[] tasks;
                tasks = temp;
            }

            if (choice == 1)
                tasks[count++] = new FileDownloadTask();
            else if (choice == 2)
                tasks[count++] = new AntivirusTask();
            else
                tasks[count++] = new MediaPlayerTask();
        }

        /* ===== START / STOP TASK ===== */
        else if (choice == 4 || choice == 5) {
            int id;
            bool found = false;

            cout << "Enter task ID: ";
            cin >> id;

            for (int i = 0; i < count; i++) {
                if (tasks[i]->getId() == id) {
                    found = true;
                    if (choice == 4)
                        tasks[i]->start();
                    else
                        tasks[i]->stop();
                    break;
                }
            }

            if (!found)
                cout << "Task not found!\n";
        }

        /* ===== SHOW ALL TASKS ===== */
        else if (choice == 6) {
            if (count == 0) {
                cout << "No tasks available\n";
            } else {
                for (int i = 0; i < count; i++)
                    tasks[i]->showStatus();   // POLYMORPHISM
            }
        }

    } while (choice != 7);

    /* ===== CLEANUP ===== */
    for (int i = 0; i < count; i++)
        delete tasks[i];

    delete[] tasks;

    return 0;
}
