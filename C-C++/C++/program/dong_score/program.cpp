/*
输入一组学生的成绩（姓名+分数）， 输出：平均成绩、最高分和最低分，以及对应学生信息

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    
    string name;
    double score;
    void print();
};

void Student::print()  {
    cout << "name: " << name << '\t' << "score: " << score << endl;
}

void score_stat(const vector<Student> &stus) {
    double sum = 0;
    double max = stus[0].score;
    double min = stus[0].score;
    for (int i = 0; i < stus.size(); i++) {
        sum += stus[i].score;
        if (stus[i].score > max) max = stus[i].score;
        if (stus[i].score < min) min = stus[i].score;
        
    }
    cout << "Max: " << max << " " << "Min: " << min << " " << "Average: "
        << sum / stus.size() << endl;
}
int main()
{
    vector<Student> stus;
    //cout << stus.size() << endl;
    while(1) {
        Student stu;
        cout << "name" << " " << "score" << endl;
        cin >> stu.name >> stu.score;
        if (stu.score < 0) break;
        stus.push_back(stu);
    }
    for (int i = 0; i < stus.size(); i++) 
    {
        stus[i].print();
    }
    score_stat(stus);  //这里的stus是引用

    // Student stu;
    // stu.name = "Lee";
    // stu.score = 99.9;
    // stu.print();
    return 0;
}