//
// Created by URANIUM on 13/11/2026.
//

#ifndef DREAMDB_H
#include <string>

namespace dreamdb {
    enum class FileType { Image, Video };

    class File {
    private:
        FileType fileType;

    public:
        std::string name;

        void rename(std::string_view newName) ;

        FileType inspectType() const;

        File();
    };
}

#define DREAMDB_H

#endif //DREAMDB_H
