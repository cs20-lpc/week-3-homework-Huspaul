// TODO:  Student class methods implementation here.
#include "Student.hpp"

Student::Student()
    : id(0), name(""), gpa(0.0), courses(nullptr), courseCount(0), courseCapacity(0) {}

Student::Student(int id, const std::string& name, double gpa)
    : id(id), name(name), gpa(gpa), courses(nullptr), courseCount(0), courseCapacity(0) {}

void Student::ensureCapacity(int minCapacity) {
    if (courseCapacity >= minCapacity) return;

    int newCap = (courseCapacity == 0) ? 2 : courseCapacity * 2;
    while (newCap < minCapacity) newCap *= 2;

    Course* newArr = new Course[newCap];
    for (int i = 0; i < courseCount; i++) {
        newArr[i] = courses[i];
    }

    delete[] courses;
    courses = newArr;
    courseCapacity = newCap;
}

// Copy ctor
Student::Student(const Student& other)
    : id(other.id), name(other.name), gpa(other.gpa),
      courses(nullptr), courseCount(other.courseCount), courseCapacity(other.courseCapacity) {

    if (courseCapacity > 0) {
        courses = new Course[courseCapacity];
        for (int i = 0; i < courseCount; i++) {
            courses[i] = other.courses[i];
        }
    }
}

// Assignment operator
Student& Student::operator=(const Student& other) {
    if (this == &other) return *this;

    id = other.id;
    name = other.name;
    gpa = other.gpa;

    delete[] courses;
    courses = nullptr;

    courseCount = other.courseCount;
    courseCapacity = other.courseCapacity;

    if (courseCapacity > 0) {
        courses = new Course[courseCapacity];
        for (int i = 0; i < courseCount; i++) {
            courses[i] = other.courses[i];
        }
    }
    return *this;
}

// Destructor
Student::~Student() {
    delete[] courses;
}

int Student::getId() const { return id; }
std::string Student::getName() const { return name; }
double Student::getGpa() const { return gpa; }

void Student::setId(int newId) { id = newId; }
void Student::setName(const std::string& newName) { name = newName; }
void Student::setGpa(double newGpa) { gpa = newGpa; }

void Student::addCourse(const Course& c) {
    ensureCapacity(courseCount + 1);
    courses[courseCount] = c;
    courseCount++;
}

int Student::getCourseCount() const { return courseCount; }

void Student::print(std::ostream& os) const {
    os << id << " " << name << " " << gpa;
    if (courseCount == 0) {
        os << " None";
    }
}

void Student::printCourses(std::ostream& os) const {
    if (courseCount == 0) {
        os << "Courses: None\n";
        return;
    }
    os << "Courses:\n";
    for (int i = 0; i < courseCount; i++) {
        os << "  ";
        courses[i].print(os);
        os << "\n";
    }
}
