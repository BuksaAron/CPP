//
// Created by buksa on 11/26/2025.
//

#ifndef LAB10_STUDNETSERVICEIMPL_H
#define LAB10_STUDNETSERVICEIMPL_H

#include "StudentService.h"
#include "GraduationDao.h"

class StudentServiceImpl : public StudentService {
private:
    GraduationDao *dao;

public:
    StudentServiceImpl(GraduationDao *dao);
    virtual bool isEnrolled(int id) const override;
    virtual double getResultBySubject(int id, const std::string& subject) const override;
    virtual std::vector<std::string> getSubjects(int id) const override;
    virtual double getAverage(int id) const override;
    virtual bool isPassed(int id) const override;
};

#endif //LAB10_STUDNETSERVICEIMPL_H