//
// Created by buksa on 11/12/2025.
//

#ifndef LAB9_DIRECTORY_H
#define LAB9_DIRECTORY_H
#include "FileSystemItem.h"
#include <vector>

class Directory : public FileSystemItem {
private:
    std::vector<FileSystemItem*> children;

public:
    Directory(const std::string& name);
    Directory(const Directory& other);
    Directory& operator=(const Directory& other);
    virtual ~Directory();

    void add(FileSystemItem* item);
    void remove(const std::string& name);
    FileSystemItem* find(const std::string& name);

    long getSize() const override;
    void display(int depth = 0) const override;
    FileSystemItem* clone() const override;

    // Operátorok
    Directory& operator+=(FileSystemItem* item);
    Directory& operator-=(const std::string& name);
};
#endif //LAB9_DIRECTORY_H