#include <algorithm>
#include <iostream>
#include <string>

/*
�������� ��������� Student � ������ name �� marks[4];

�������� �������, �� ������ �������� �� ������� �������� �� ������� ������� ������ �� ��������� ��������;
�������� ����� of Student;
�������, �� ����� �������� � ����� �� ������� �������� ������;
�������, �� ������� ���������(pointer) �� ������������ �������� � �����;
�������, ��� �������� ������� ��������, ������� ������ ���� ����� �� ������� �������� N;
�������, ��� ������� ����� � N% ����������� ��������:
void getBestStudents(Student* inStudents, unsigned inSize, Student* outStudents, unsigned& outSize, unsigned percent);
*/

constexpr short MARKS_COUNT = 4;
constexpr short STUDENTS_COUNT = 4;

struct Student
{
    std::string name;
    unsigned short marks[MARKS_COUNT];
};

double getAverage(Student student) {
    double res = 0;
    for (int i = 0; i < MARKS_COUNT; i++) {
        res += student.marks[i];
    }
    return res / MARKS_COUNT;
}

void sortStudentsByAvarage(Student* students, unsigned short studentsCount) {
    std::sort(students, students + studentsCount, [](const Student& a, const Student& b) {
        return getAverage(a) < getAverage(b);
        });
}

Student* getTheBestStudent(Student* students, unsigned short studentsCount) {
    if (studentsCount == 0) {
        return nullptr;
    }

    int theBestIndex = 0;
    for (int i = 1; i < studentsCount; ++i) {
        if (getAverage(students[i]) > getAverage(students[theBestIndex])) {
            theBestIndex = i;
        }
    }

    return &students[theBestIndex];
}

unsigned countStudentsBetterThanN(Student* students, unsigned short studentsCount, double N) {
    unsigned counter = 0;
    for (int i = 0; i < studentsCount; i++) {
        if (getAverage(students[i]) > N) {
            counter++;
        }
    }

    return counter;
}

void getBestStudents(Student* inStudents, unsigned inSize, Student*& outStudents, unsigned& outSize, unsigned passRate) {
    outSize = countStudentsBetterThanN(inStudents, inSize, passRate);

    outStudents = new Student[outSize];
    sortStudentsByAvarage(inStudents, inSize);

    for (int i = 0; i < outSize; i++) {
        outStudents[outSize - 1 - i] = inStudents[inSize - 1 - i];
    }
}


int main()
{
    Student students[STUDENTS_COUNT] = {
        {"Alice", {1, 2, 3, 4}},
        {"Bob", {1, 1, 1, 1}},
        {"Charlie", {3, 2, 5, 8}},
        {"Den", {0, 0, 1, 0}},
    };

    Student* bestStudents = nullptr;
    unsigned int bestStudentsSize;

    getBestStudents(students, STUDENTS_COUNT, bestStudents, bestStudentsSize, 2);


    /*
Top 2 students:

Name: Alice
Average Marks: 2.5
Marks: 1 2 3 4

Name: Charlie
Average Marks: 4.5
Marks: 3 2 5 8
    */

    std::cout << "Top " << bestStudentsSize << " students:" << std::endl;
    for (unsigned i = 0; i < bestStudentsSize; i++) {
        std::cout << "Name: " << bestStudents[i].name << "\nAverage Marks: " << getAverage(bestStudents[i]) << "\nMarks: ";
        for (int j = 0; j < MARKS_COUNT; j++) {
            std::cout << bestStudents[i].marks[j] << " ";
        }
        std::cout << std::endl;
    }


    delete [] bestStudents;
    return 0;
}