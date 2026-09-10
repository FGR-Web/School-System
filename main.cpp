#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // 用于格式化输出
#include <algorithm> // 用于查找算法

using namespace std;

// ==========================================
// 1. 数据结构定义
// ==========================================

// 学生结构体
struct Student {
    string id;      // 学号
    string name;    // 姓名
    string major;   // 专业
    double score;   // 成绩
};

// 教师结构体
struct Teacher {
    string id;      // 工号
    string name;    // 姓名
    string dept;    // 部门/学院
    double salary;  // 薪资
};

// ==========================================
// 2. 管理类定义
// ==========================================

class SchoolManager {
private:
    vector<Student> students; // 存储学生的容器
    vector<Teacher> teachers; // 存储教师的容器

public:
    // 主菜单
    void run();

    // 学生模块功能
    void studentMenu();
    void addStudent();
    void displayStudents();

    // 教师模块功能
    void teacherMenu();
    void addTeacher();
    void displayTeachers();
};

// ==========================================
// 3. 主程序入口与主控逻辑
// ==========================================

void SchoolManager::run() {
    int choice = -1;
    while (choice != 0) {
        cout << "\n========================================" << endl;
        cout << "      欢迎使用高校综合信息管理系统       " << endl;
        cout << "========================================" << endl;
        cout << "  1. 进入【学生信息管理】模块" << endl;
        cout << "  2. 进入【教师信息管理】模块" << endl;
        cout << "  0. 退出系统" << endl;
        cout << "----------------------------------------" << endl;
        cout << "请输入您的选择: ";
        
        if (!(cin >> choice)) {
            cin.clear(); // 清除错误标志
            cin.ignore(10000, '\n'); // 丢弃非法输入
            cout << "[错误] 请输入有效的数字！" << endl;
            continue;
        }

        switch (choice) {
            case 1: studentMenu(); break;
            case 2: teacherMenu(); break;
            case 0: cout << "感谢使用，系统已退出。" << endl; break;
            default: cout << "[错误] 无效的选择，请重试。" << endl;
        }
    }
}

// ==========================================
// 4. 学生模块实现
// ==========================================

void SchoolManager::studentMenu() {
    int choice;
    while (true) {
        cout << "\n--- [学生管理] ---" << endl;
        cout << "1. 录入学生信息" << endl;
        cout << "2. 显示所有学生" << endl;
        cout << "0. 返回上一级" << endl;
        cout << "请选择: ";
        cin >> choice;

        if (choice == 0) break;
        else if (choice == 1) addStudent();
        else if (choice == 2) displayStudents();
        else cout << "无效输入" << endl;
    }
}

void SchoolManager::addStudent() {
    Student s;
    cout << "\n>> 录入新学生:" << endl;
    cout << "学号: "; cin >> s.id;
    
    // 简单查重逻辑
    for(const auto& stu : students) {
        if(stu.id == s.id) {
            cout << "[警告] 该学号已存在！" << endl;
            return;
        }
    }

    cout << "姓名: "; cin >> s.name;
    cout << "专业: "; cin >> s.major;
    cout << "成绩: "; cin >> s.score;
    
    students.push_back(s);
    cout << "[成功] 学生 " << s.name << " 添加成功！" << endl;
}

void SchoolManager::displayStudents() {
    if (students.empty()) {
        cout << "\n[提示] 当前没有学生数据。" << endl;
        return;
    }
    cout << "\n------------------------------------------------------" << endl;
    cout << left << setw(10) << "学号" << setw(10) << "姓名" << setw(15) << "专业" << setw(10) << "成绩" << endl;
    cout << "------------------------------------------------------" << endl;
    for (const auto& s : students) {
        cout << left << setw(10) << s.id 
             << setw(10) << s.name 
             << setw(15) << s.major 
             << setw(10) << s.score << endl;
    }
}

// ==========================================
// 5. 教师模块实现
// ==========================================

void SchoolManager::teacherMenu() {
    int choice;
    while (true) {
        cout << "\n--- [教师管理] ---" << endl;
        cout << "1. 录入教师信息" << endl;
        cout << "2. 显示所有教师" << endl;
        cout << "0. 返回上一级" << endl;
        cout << "请选择: ";
        cin >> choice;

        if (choice == 0) break;
        else if (choice == 1) addTeacher();
        else if (choice == 2) displayTeachers();
        else cout << "无效输入" << endl;
    }
}

void SchoolManager::addTeacher() {
    Teacher t;
    cout << "\n>> 录入新教师:" << endl;
    cout << "工号: "; cin >> t.id;
    cout << "姓名: "; cin >> t.name;
    cout << "所属部门: "; cin >> t.dept;
    cout << "薪资: "; cin >> t.salary;

    teachers.push_back(t);
    cout << "[成功] 教师 " << t.name << " 添加成功！" << endl;
}

void SchoolManager::displayTeachers() {
    if (teachers.empty()) {
        cout << "\n[提示] 当前没有教师数据。" << endl;
        return;
    }
    cout << "\n------------------------------------------------------" << endl;
    cout << left << setw(10) << "工号" << setw(10) << "姓名" << setw(15) << "部门" << setw(10) << "薪资" << endl;
    cout << "------------------------------------------------------" << endl;
    for (const auto& t : teachers) {
        cout << left << setw(10) << t.id 
             << setw(10) << t.name 
             << setw(15) << t.dept 
             << setw(10) << t.salary << endl;
    }
}

// ==========================================
// 6. 程序启动
// ==========================================

int main() {
    // 设置控制台编码为 UTF-8 (防止中文乱码，视系统环境而定)
    // system("chcp 65001"); 
    
    SchoolManager manager;
    manager.run();

    return 0;
}
