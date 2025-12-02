//
// Created by buksa on 11/26/2025.
//

#ifndef LAB10_STUDENTSERVICE_H
#define LAB10_STUDENTSERVICE_H

#include <vector>
#include <string>

class StudentService {
public:
    virtual bool isEnrolled(int id) const = 0;
    virtual double getResultBySubject(int id, const std::string& subject) const = 0;
    virtual std::vector<std::string> getSubjects(int id) const = 0;
    virtual double getAverage(int id) const = 0;
    virtual bool isPassed(int id) const = 0;

    virtual ~StudentService() = default;
};

#endif //LAB10_STUDENTSERVICE_H