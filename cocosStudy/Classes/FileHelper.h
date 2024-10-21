#ifndef __FILE_HELPER_H__
#define __FILE_HELPER_H__

#include "cocos2d.h"
#include <spine/Json.h> // jsoncpp 헤더
#include "tinyxml2.h" // tinyxml2 헤더
#include <fstream>
#include <sstream>

class FileHelper {
public:
    // JSON 파일 읽기
    static void readJsonFile(const std::string& filePath);

    // XML 파일 읽기
    static void readXmlFile(const std::string& filePath);

    // CSV 파일 읽기
    static void readCsvFile(const std::string& filePath);
};

#endif // __FILE_HELPER_H__
