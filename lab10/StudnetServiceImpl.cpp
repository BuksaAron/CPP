//
// Created by buksa on 11/26/2025.
//

#include "StudnetServiceImpl.h"
#include <stdexcept>

StudentServiceImpl::StudentServiceImpl(GraduationDao *dao) : dao(dao) {}

bool StudentServiceImpl::isEnrolled(int id) const {
    dao->findById(id);
    return true;

}

double StudentServiceImpl::getResultBySubject(int id, const std::string& subject) const {
    Student student = dao->findById(id);
    return student.getGrade(subject);
}

vector<string> StudentServiceImpl::getSubjects(int id) const {
    vector<string> subjects;
    Student student = dao->findById(id);
    const auto& grades = student.getGrades();
    for (const auto& pair : grades) {
        subjects.push_back(pair.first);
    }
    return subjects;
}

double StudentServiceImpl::getAverage(int id) const {
    Student student = dao->findById(id);
    return student.getAverage();
}

bool StudentServiceImpl::isPassed(int id) const {
    Student student = dao->findById(id);
    return student.getGrades().size() >= 6 && student.getAverage() >= 5.0;
}