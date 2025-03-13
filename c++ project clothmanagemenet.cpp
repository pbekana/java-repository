#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Student {
private:
    string name;
    string id;
    int number;
    string* clothes;
    int clothesCount;

public:
    // Constructor: Initializes clothesCount to 0 and clothes to nullptr
    Student() : clothesCount(0), clothes(nullptr) {}

    // Destructor: Frees the memory allocated for the clothes array
    ~Student() {
        delete[] clothes;
    }

    // Function to set the student's name
    void setName(const string& n) {
        name = n;
    }

    // Function to get the student's name
    string getName() const {
        return name;
    }

    // Function to set the student's ID
    void setId(const string& i) {
        id = i;
    }

    // Function to get the student's ID
    string getId() const {
        return id;
    }

    // Function to set the student's number
    void setNumber(int num) {
        number = num;
    }

    // Function to get the student's number
    int getNumber() const {
        return number;
    }

    // Function to set the number of clothes and allocate memory for the clothes array
    void setClothesCount(int count) {
        clothesCount = count;
        clothes = new string[clothesCount];
    }

    // Function to get the number of clothes
    int getClothesCount() const {
        return clothesCount;
    }

    // Function to get the clothes array
    string* getClothesArray() const {
        return clothes;
    }

    // Function to add a clothe at the specified index in the clothes array
    void addClothe(int index, const string& clothe) {
        if (index >= 0 && index < clothesCount) {
            clothes[index] = clothe;
        } else {
            cout << "Invalid index." << endl;
        }
    }

    // Function to update a clothe at the specified index in the clothes array
    void updateClothe(int index, const string& newClothe) {
        if (index >= 0 && index < clothesCount) {
            clothes[index] = newClothe;
        } else {
            cout << "Invalid index." << endl;
        }
    }

    // Function to display all the clothes in the clothes array
    void showClothes() const {
        for (int i = 0; i < clothesCount; i++) {
            cout << i + 1 << ". " << clothes[i] << endl;
        }
    }
};

void saveToFile(Student& student) {
    ofstream outFile(student.getId(), ios::binary);
    outFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
    for (int i = 0; i < student.getClothesCount(); i++) {
        size_t length = student.getClothesArray()[i].length();
        outFile.write(reinterpret_cast<char*>(&length), sizeof(length));
        outFile.write(student.getClothesArray()[i].c_str(), length);
    }
    outFile.close();
}

void loadFromFile(Student& student, const string& id) {
    ifstream inFile(id, ios::binary);
    inFile.read(reinterpret_cast<char*>(&student), sizeof(Student));
    student.setClothesCount(student.getClothesCount());
    for (int i = 0; i < student.getClothesCount(); i++) {
        size_t length;
        inFile.read(reinterpret_cast<char*>(&length), sizeof(length));
        student.getClothesArray()[i].resize(length);
        inFile.read(&student.getClothesArray()[i][0], length);
    }
    inFile.close();
}

void handleStudentOperations(Student& student) {
    int choice;
    string id;

    while (true) {
        cout << "1. Add Student" << endl;
        cout << "2. Add Clothe" << endl;
        cout << "3. Update Clothe" << endl;
        cout << "4. Show Clothes" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            {
                string name;
                int number, clothesCount;

                cout << "Enter name: ";
                cin >> name;
                student.setName(name);

                cout << "Enter ID: ";
                cin >> id;
                student.setId(id);
 cout2<< "Enter number: ";
                cin >> number;
                student.setNumber(number);

                cout << "Enter number of clothes: ";
                cin >> clothesCount;
                student.setClothesCount(clothesCount);

                for (int i = 0; i < clothesCount; i++) {
                    string clothe;
                    cout << "Enter clothe " << i + 1 << ": ";
                    cin >> clothe;
                    student.addClothe(i, clothe);
                }

                saveToFile(student);
            }
            break;
        case 2:
            cout << "Enter student ID: ";
            cin >> id;
            loadFromFile(student, id);
            cout << "Enter clothe: ";
            {
                string clothe;
                int index = student.getClothesCount();
                student.setClothesCount(student.getClothesCount() + 1);
                cin >> clothe;
                student.addClothe(index, clothe);
            }
            saveToFile(student);
            break;
        case 3:
            cout << "Enter student ID: ";
            cin >> id;
            loadFromFile(student, id);
            cout << "Enter index of clothe to update: ";
            int index;
            cin >> index;
            cout << "Enter new clothe: ";
            {
                string clothe;
                cin >> clothe;
                student.updateClothe(index - 1, clothe);
            }
            saveToFile(student);
            break;
        case 4:
            cout << "Enter student ID: ";
            cin >> id;
            loadFromFile(student, id);
            student.showClothes();
            break;
        case 5:
            return;
        default:
            cout << "Invalid choice." << endl;
        }
    }
}

int main() {
    Student student;
    handleStudentOperations(student);
    return 0;
}