//
// Created by buksa on 11/12/2025.
//

#ifndef LAB9_FILESYSTEMITEM_H
#define LAB9_FILESYSTEMITEM_H
#include <string>

using namespace std;

class FileSystemItem {
protected:
    string name;
    long size;
public:
    FileSystemItem(const string& name, long size);

    virtual ~FileSystemItem() = default;
    virtual long getSize() const = 0;
    virtual void display(int depth = 0) const = 0;
    virtual FileSystemItem* clone() const = 0;
    string getName();
    friend std::ostream& operator<<(std::ostream& os, const FileSystemItem& item);
    bool operator<(const FileSystemItem& other) const;
};

#endif //LAB9_FILESYSTEMITEM_H