// TO DO:  Student class definition  here.
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>
#include "Course.hpp"

class Student {
private:
    int id;
    std::string name;
    double gpa;

    Course* courses;      // dynamic array (manual, no STL)
    int courseCount;
    int courseCapacity;

    void ensureCapacity(int minCapacity);

public:
    Student();
    Student(int id, const std::string& name, double gpa);

    // Rule of 3 (because we own dynamic memory)
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();

    int getId() const;
    std::string getName() const;
    double getGpa() const;

    void setId(int newId);
    void setName(const std::string& newName);
    void setGpa(double newGpa);

    void addCourse(const Course& c);
    int getCourseCount() const;

    void print(std::ostream& os = std::cout) const;
    void printCourses(std::ostream& os = std::cout) const;
};

#endif
