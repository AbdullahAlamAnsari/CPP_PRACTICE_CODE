#include <iostream>
using namespace std;

class Resource {
protected:
    int resourceID;

public:
    Resource(int id) {
        resourceID = id;
    }

    void showResource() {
        cout << "Resource ID: " << resourceID << endl;
    }
};

class Memory : virtual public Resource {
protected:
    int ramSize;

public:
    Memory(int ram) : Resource(0) {
        ramSize = ram;
    }

    void showMemory() {
        cout << "RAM Size: " << ramSize << " GB" << endl;
    }
};

class Storage : virtual public Resource {
protected:
    int diskSize;

public:
    Storage(int disk) : Resource(0) {
        diskSize = disk;
    }

    void showStorage() {
        cout << "Disk Size: " << diskSize << " GB" << endl;
    }
};

class Server : public Memory, public Storage {
    string serverName;

public:
    Server(string name, int id, int ram, int disk)
        : Resource(id), Memory(ram), Storage(disk) {
        serverName = name;
    }

    void showServer() {
        cout << "Server Name: " << serverName << endl;
        showResource();
        showMemory();
        showStorage();
    }
};

int main() {
    Server s("LinuxServer", 101, 32, 1024);
    s.showServer();

    return 0;
}
