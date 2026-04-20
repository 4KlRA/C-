#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class Student {
private:
    string name;
    int age;
    string grade;
    int studentID;
    int totalMarks;
    int totalSubjects;
    vector<pair<string, int>> subjects;
public:
    Student() : name(""), age(0), grade(""), studentID(0), totalMarks(0), totalSubjects(0) {}
    Student& setName() {
        cout << "Enter name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name); 
        return *this;
    }
    Student& setAge() {
            cout << "Enter age: ";
            cin >> age;
            return *this;
        }
    Student& setGrade() {
        cout << "Enter grade: ";
        cin >> grade;
        return *this;
    }
    Student& setStudentID() {
        cout << "Enter student ID: ";
        cin >> studentID;
        return *this;
    }
    Student& addSubject() {
        string subjectName;
        int marks;
        cout << "Enter subject name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, subjectName);
        cout << "Enter marks out of 100: ";
        cin >> marks;
        subjects.push_back({subjectName, marks});
        totalMarks += marks;
        totalSubjects++;
        return *this;
    }
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Total Subjects: " << totalSubjects << endl;
        cout << "Subjects and Marks: " << endl;
        for (const auto& subject : subjects) {
            cout << subject.first << ": " << subject.second << endl;
        }
        cout << "Total Marks: " << totalMarks << endl;
        cout << "Average Marks: " << (totalSubjects > 0 ? static_cast<double>(totalMarks) / totalSubjects : 0) << endl;
    }
};

int main() {
    Student student1;
    student1.setName().setAge().setGrade().setStudentID();
    int numSubjects;
    cout << "Enter number of subjects: ";
    cin >> numSubjects;
    for (int i = 0; i < numSubjects; ++i) {
        student1.addSubject();
    }
    student1.displayInfo();
    return 0;
}