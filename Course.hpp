// TODO:  Course class definitins go here.
#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include <iostream>

class Course {
private:
    std::string name;
    std::string location;

public:
    Course();
    Course(const std::string& name, const std::string& location);

    void setName(const std::string& n);
    void setLocation(const std::string& loc);

    std::string getName() const;
    std::string getLocation() const;

    void print(std::ostream& os = std::cout) const;
};

#endif
