//
// Created by buksa on 11/12/2025.
//

#ifndef LAB9_FILE_H
#define LAB9_FILE_H

#include "FileSystemItem.h"
class File : public FileSystemItem {
public:
    File(const std::string& name, long size);
    virtual ~File() = default;
    File(const File& other);
    File& operator=(const File& other);
    long getSize() const override;
    void display(int depth = 0) const override;
    FileSystemItem* clone() const override;
};
#endif //LAB9_FILE_H