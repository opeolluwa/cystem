//
// Created by URANIUM on 13/11/2026.
//

#include "dreamdb.h"

namespace dreamdb {

   FileType File::inspectType() const {
        return this->fileType;
    }

   void File::rename(std::string_view newName) {
       this->name = newName;
   }
}
