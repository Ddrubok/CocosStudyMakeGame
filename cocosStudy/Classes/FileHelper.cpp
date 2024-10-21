#include "FileHelper.h"

using namespace cocos2d;
using namespace tinyxml2;

//void FileHelper::readJsonFile(const std::string& filePath) {
//    // 파일 읽기
//    std::string data = FileUtils::getInstance()->getStringFromFile(filePath);
//
//    // JSON 파서
//    Json::Value jsonData;
//    Json::CharReaderBuilder readerBuilder;
//    std::string errs;
//
//    std::istringstream stream(data);
//    if (Json::parseFromStream(readerBuilder, stream, &jsonData, &errs)) {
//        // JSON 데이터 사용
//        CCLOG("Name: %s", jsonData["name"].asString().c_str());
//        CCLOG("Age: %d", jsonData["age"].asInt());
//    }
//    else {
//        CCLOG("Failed to parse JSON: %s", errs.c_str());
//    }
//}

//void FileHelper::readXmlFile(const std::string& filePath) {
//    XMLDocument doc;
//   
//    if (doc.LoadFile(filePath.c_str()) == XML_SUCCESS) {
//        XMLElement* root = doc.RootElement();
//
//        // XML 데이터 사용
//        for (XMLElement* element = root->FirstChildElement("item"); element != nullptr; element = element->NextSiblingElement("item")) {
//            const char* name = element->Attribute("name");
//            const char* value = element->GetText();
//            CCLOG("Item: %s, Value: %s", name, value);
//        }
//    }
//    else {
//        CCLOG("Failed to load XML file: %s", doc.ErrorID());
//    }
//}

void FileHelper::readCsvFile(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line;

    if (!file.is_open()) {
        CCLOG("Failed to open CSV file: %s", filePath.c_str());
        return;
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string item;
        while (std::getline(ss, item, ',')) {
            CCLOG("Item: %s", item.c_str());
        }
    }
    file.close();
}
