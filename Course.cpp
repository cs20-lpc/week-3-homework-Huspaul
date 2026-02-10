// TODO:  Course class methods implementation here.
#include "Course.hpp"

Course::Course() : name(""), location("") {}

Course::Course(const std::string& name, const std::string& location)
    : name(name), location(location) {}

void Course::setName(const std::string& n) { name = n; }
void Course::setLocation(const std::string& loc) { location = loc; }

std::string Course::getName() const { return name; }
std::string Course::getLocation() const { return location; }

void Course::print(std::ostream& os) const {
    os << name << " " << location;
}
