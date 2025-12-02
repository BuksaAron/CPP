//
// Created by buksa on 11/26/2025.
//

#ifndef LAB10_GRADUATIONDAO_H
#define LAB10_GRADUATIONDAO_H

#include <map>
#include <string>
#include "Student.h"

using namespace std;

class GraduationDao {
    int year{2023};
    map<int, Student> students;
public:
    explicit GraduationDao(int year) : year(year) {}
    void enrollStudents(const string &filename);
    void readGradesSubject(const string &subject, const string &filename);
    void computeAverage();
    int numEnrolled() const;
    int numPassed() const;
    Student findById(int id) const; //throws out_of_range exception for nonexistent id
    double getAverageBySubject(const string &subject) const;
    const std::map<int, Student>& getStudents() const;
};

#endif //LAB10_GRADUATIONDAO_H