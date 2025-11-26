#include <iostream>
#include "Directory.h"
#include "File.h"

int main() {
    Directory root("root");

    Directory* documents = new Directory("documents");
    Directory* pictures = new Directory("pictures");

    documents->add(new File("report.txt", 1500));
    documents->add(new File("notes.txt", 800));

    pictures->add(new File("photo1.jpg", 2048000));
    pictures->add(new File("photo2.jpg", 1856000));

    root.add(documents);
    root.add(pictures);
    root.add(new File("readme.txt", 500));

    std::cout << "Fajlrendszer tartalma:\n";
    root.display();

    std::cout << "\nOsszmeret: " << root.getSize() << " bajt\n";

    std::string keresett = "photo1.jpg";
    FileSystemItem* found = nullptr;

    found = pictures->find(keresett);
    if (found)
        std::cout << "\nKereses: " << keresett << " - Talalat!\n";
    else
        std::cout << "\nKereses: " << keresett << " - Nincs talalat!\n";

    std::cout << "\nElem torlese: pictures konyvtar\n";
    root.remove("pictures");

    std::cout << "Torles utan:\n";
    root.display();
    std::cout << "\nUj oszmeret: " << root.getSize() << " bajt\n";

    std::cout << "\nKlonozas teszt:\n";
    Directory copyRoot = root;
    copyRoot.display();

    std::cout << "\nOperator tesztek:\n";

    copyRoot += new File("extra.txt", 300);
    std::cout << "Hozzaadas után:\n";
    copyRoot.display();

    copyRoot -= "readme.txt";
    std::cout << "\nEltavolitas utan:\n";
    copyRoot.display();

    std::cout << "\n<< operator hasznalata:\n";
    std::cout << copyRoot;

    Directory temp("alpha");
    if (temp < copyRoot)
        std::cout << "\n\"" << temp.getName() << "\" nev kisebb mint \"" << copyRoot.getName() << "\"\n";
    else
        std::cout << "\n\"" << temp.getName() << "\" nev nem kisebb mint \"" << copyRoot.getName() << "\"\n";

    return 0;
}