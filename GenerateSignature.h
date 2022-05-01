//
// Created by yukarichan on 2022/5/2.
//

#ifndef UNTITLED_GENERATESIGNATURE_H
#define UNTITLED_GENERATESIGNATURE_H
#include <string>
#include <map>
#include <vector>
#define S_VERSION "2.2.1.3.3.4"
#define S_BUILD_VERSION "45"

class GenerateSignature {
private:
    void toLower(std::string& _str){transform(_str.begin(), _str.end(), _str.begin(), ::tolower);  }
    std::string getStringSigFromNative();
    std::string getStringConFromNative(std::string strArr[]);
    std::string Sign_HASH(std::string _encode);
    std::string Generate(std::string _stringConFromNative,std::string _getStringSigFromNative);
    std::string Generate(std::string _strArr[]);
    std::string uuid;
    std::string time;
    std::string url;
public:
    GenerateSignature():uuid(""),
                        time(""),
                        url("")
    {}
    std::string signature(){
        std::string c[]= {"https://picaapi.picacomic.com/", this->url, this->time, this->uuid, "POST", "C69BAF41DA5ABD1FFEDC6D2FEA56B", S_VERSION,S_BUILD_VERSION};
        return this->Generate(c);
    }
    GenerateSignature* set(std::string key,std::string value){
        if(key == "uuid")this->uuid = value;
        if(key == "time")this->time = value;
        if(key == "url")this->url = value;
        return this;
    };
};


#endif //UNTITLED_GENERATESIGNATURE_H
