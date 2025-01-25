#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
        string name;
        int id;
        int marks;
    Student(string n, int i, int m) : name(n), id(i), marks(m) {}
};

bool compare(const Student& a, const Student& b) {
    if (a.marks != b.marks)
        return a.marks > b.marks;
    return a.id < b.id;
}

int main(){
    int N, Q;
    cin >> N;

    vector<Student> students;
    for(int i = 0; i < N; ++i) {
        string name;
        int id, marks;
        cin >> name >> id >> marks;
        students.push_back(Student(name, id, marks));
    }

    make_heap(students.begin(), students.end(), compare);
    
    cin >> Q;
    while(Q--) {
        int command;
        cin >> command;
        if(command == 0) {
            string name;
            int id, marks;
            cin >> name >> id >> marks;
            students.push_back(Student(name, id, marks));
            push_heap(students.begin(), students.end(), compare);
            if(!students.empty()) {
                Student maxStudent = students.front();
                cout << maxStudent.name << " " << maxStudent.id << " " << maxStudent.marks << endl;
            } else {
                cout << "Empty" << endl;
            }
        } else if(command == 1) {
            if(!students.empty()) {
                Student maxStudent = students.front();
                cout << maxStudent.name << " " << maxStudent.id << " " << maxStudent.marks << endl;
            } else {
                cout << "Empty" << endl;
            }
        } else if(command == 2) {
            if(!students.empty()) {
                pop_heap(students.begin(), students.end(), compare);
                students.pop_back();
                if(!students.empty()) {
                    Student maxStudent = students.front();
                    cout << maxStudent.name << " " << maxStudent.id << " " << maxStudent.marks << endl;
                } else {
                    cout << "Empty" << endl;
                }
            } else {
                cout << "Empty" << endl;
            }
        }
    }

    return 0;
}
