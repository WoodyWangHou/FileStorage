/**
 * Author: Hou Wang
 * 
 * Application: sfarchiver
 * Association: file storage engine, command parser
 * 
 */
#pragma once
#include <vector>

namespace filestorage{
    extern const char *VERSION;
    extern const char *APPNAME;
    extern const char *BUILDTIME;
    class FileStorageEngineBase {
        private:
            static FileStorageEngineBase* mInstance;
        protected:
            FileStorageEngineBase();
        public:
            static FileStorageEngineBase* getInstance();
            void add(); 
            void del();
            void list();
            void getProps();
            void extract();
            void getVersion();
    };
}