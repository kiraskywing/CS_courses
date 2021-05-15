#include <iostream>
#include <string>

using namespace std;

class Student{
public:
    string name;
    int exam_scores[4];  
    
    Student(string s1): name(s1) {}
    
    void get_minimum_final_score()
    {
        exam_scores[3] = 60 * 4 - (exam_scores[0] + exam_scores[1] + exam_scores[2]);
        if (exam_scores[3] < 0)
            exam_scores[3] = 0;
    }
    
    void print_name_and_score()
    {
        cout << name << " " << exam_scores[3];
    }
};

int main() {
    
    string student_name;
    cin >> student_name;
    Student student(student_name);
    for(int i = 0; i < 3; i++){
        cin >> student.exam_scores[i];
    }
    student.get_minimum_final_score();
    student.print_name_and_score();
    return 0;
}