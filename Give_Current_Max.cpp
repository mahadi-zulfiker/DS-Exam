#include <bits/stdc++.h>
using namespace std;
struct Student {
    string name;
    int roll;
    int marks;

    bool operator<(const Student &other) const {
        if (marks != other.marks)
            return marks > other.marks;
        return roll < other.roll;
    }
};

int main() {
    int N;
    cin >> N;

    set<Student> students;

    for (int i = 0; i < N; ++i) {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        students.insert({name, roll, marks});
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int command;
        cin >> command;

        if (command == 0) {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            students.insert({name, roll, marks});
            if (!students.empty()) {
                const auto &topStudent = *students.begin();
                cout << topStudent.name << " " << topStudent.roll << " " << topStudent.marks << endl;
            }
        } else if (command == 1) {
            if (!students.empty()) {
                const auto &topStudent = *students.begin();
                cout << topStudent.name << " " << topStudent.roll << " " << topStudent.marks << endl;
            } else {
                cout << "Empty" << endl;
            }
        } else if (command == 2) {
            if (!students.empty()) {
                students.erase(students.begin());
            }
            if (!students.empty()) {
                const auto &topStudent = *students.begin();
                cout << topStudent.name << " " << topStudent.roll << " " << topStudent.marks << endl;
            } else {
                cout << "Empty" << endl;
            }
        }
    }

    return 0;
}
