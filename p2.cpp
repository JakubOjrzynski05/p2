#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Student{
    private:
    string name;
    int age;
    
public:
    Student(string name, int age) : name(name), age(age) {}

    const string& getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
};
class MyStudentsQueue{
    private:
    vector<Student> students;

public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }
    Student removeStudent() {
        if(students.empty()){
            throw runtime_error("Queue is empty");
        }
        Student removedStudent = students.front();
        students.erase(students.begin());           
        return removedStudent;
    }
    bool isEmpty() const {
        return students.empty();
    }
    string getJSONStudents() const {
        string json = "[";
        for(size_t i = 0; i < students.size(); ++i){
            json += "{\"name\":\"" + students[i].getName() + "\",\"age\":" + to_string(students[i].getAge()) + "}";
            if(i != students.size() - 1){
                json += ",";
            }
        }
        json += "]";
        return json;
    }
};

int main(){
    MyStudentsQueue queue;
    queue.addStudent(Student("Alice", 20));
    queue.addStudent(Student("Bob", 22));
    queue.addStudent(Student("Charlie", 21));

    cout << "Students in queue: " << queue.getJSONStudents() << endl;

    Student removedStudent = queue.removeStudent();
    cout << "Removed student: " << removedStudent.getName() << ", Age: " << removedStudent.getAge() << endl;

return 0;
}