/**
 * Author: Hou Wang
 *
 * Description: This file defines the File metadata class for each file in archive.
 */

#pragma once

#include <iostream>
#include <string>

namespace filestorage {

    class MetaData {
        private:
            unsigned int fileNameLen;       // file name length
            std::string fileName;           // file name
            
            unsigned int fileExtLen;        // extension name length
            std::string fileExtension;      // extension name of a file
                                            
            unsigned int dateLen;           // the length of string representing date added
            std::string dateAdded;          // the date file is added

            unsigned int fileSize;          // Size of a file
            
        public:
            MetaData() {
                this->fileNameLen = 0;
                this->fileName = "";
                this->fileExtLen = 0;
                this->fileExtension = "";
                this->dateLen = 0;
                this->dateAdded = "";
                this->fileSize = 0;
            }
            
            friend std::istream& operator>>(std::istream& in, MetaData& obj);
            friend std::ostream& operator<<(std::ostream& out, const MetaData& obj);

            void read(std::istream& in);
            void write(std::ostream& out) const;
            void setFileMetaData(const std::string path);

            void reset();
            
            bool isTxtFile() {
                return this->fileExtension == "txt";
            }

            std::string getAddDate() {
                return this->dateAdded;
            }

            std::string getFileName() {
                return this->fileName;
            }

            unsigned int getFileSize() {
                return this->fileSize;
            }

            unsigned int getMetadataSize() {
                return sizeof(fileNameLen) + sizeof(fileExtLen) + sizeof(dateLen) + sizeof(fileSize) +
                sizeof(char) * (fileNameLen + fileExtLen + dateLen);
            }

            std::string toString() {
                std::string res;
                res = fileName + " " + std::to_string(fileSize) + "Kb " + dateAdded;
                return res;
            }
    };
}