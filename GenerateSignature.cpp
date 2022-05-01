//
// Created by yukarichan on 2022/5/2.
//

#include <cstring>
#include "GenerateSignature.h"
#include "hmacsha256.h"

std::string GenerateSignature::getStringSigFromNative(){
    //  char dest; // [esp+8h] [ebp-54h]
    static std::map<char,char> wordptr{
            {0x9,0x64},
            {0x2D,0x57},
            {0x37,0x4D},
            {0x3B,0x64},
            {0x40,0x6E},
            {0x46,0x6E},
            {0x0C,0x51},
            {0x14,0x56},
            {0x19,0x4B},
            {0x1B,0x50},
            {0x27,0x43},
            {0x28,0x41},
            {0x2C,0x4F},
            {0x33,0x60},
            {0x45,0x43},
            {0x0D,0x37},
            {0x16,0x39},
            {0x1F,0x34},
            {0x21,0x39},
            {0x23,0x37},
            {0x2F,0x33},
            {0x38,0x37},
            {0x42,0x30},

    };

    std::map<char,std::vector<char>> dwordptr{
            {0x35,{0x3E,0x3C}},
            {0x3C,{0x35,0x4C,0x42,0x55}},
            {0x31,{0x56,0x45}},
            {0x1D,{0x4D,0x52}},
            {0x39,{0x64,0x70}},
            {0x0F,{0x69,0x6E,0x49,0x65}},
            {0x17,{0x52,0x5C}},
            {0x29,{0x62,0x7D}},

    };
    char dest[64] = {'\0'};
    //memset(dest,'\0',100);
    memcpy(dest, "~*}$#,$-\").=$)\",,#/-.'%(;$[,|@/&(#\"~%*!-?*\"-:*!!*,$\"%.&'*|%/*,*", 0x40u);
    for(auto i = wordptr.begin();i!=wordptr.end();i++){
        dest[i->first - 0x8] = i->second;
    }
    for(auto i=dwordptr.begin();i!=dwordptr.end();i++){
        char pos = i->first;
        for(auto k = i->second.rbegin();k!=i->second.rend();k++){
            dest[pos++  - 0x8] = *k;
        }
    }
    return dest;
};

std::string GenerateSignature::getStringConFromNative(std::string strArr[]){
    char * v13 = (char *)malloc(1024);
    memset(v13,'\0',1024);
    std::string v23 = strArr[0];
    std::string v20 = strArr[1];
    std::string v19 = strArr[2];
    std::string v18 = strArr[3];
    std::string v17 = strArr[4];
    std::string v16 = strArr[5];
    std::string v22 = strArr[6];
    std::string v21 = strArr[7];
    strcpy(v13, v20.c_str());
    strcat(v13, v19.c_str());
    strcat(v13, v18.c_str());
    strcat(v13, v17.c_str());
    strcat(v13, v16.c_str());
    std::string _v13(v13);
    free(v13);
    return _v13;
}
std::string GenerateSignature::Sign_HASH(std::string _encode){ //m1388a
    char f1827uq[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    char* cArr = new char[_encode.length() * 2];
    for(int i =0;i<_encode.length();i++){
        int i2 = _encode[i] & 255;
        int i3 = i * 2;
        cArr[i3] = f1827uq[(unsigned int)i2 >> 4];
        cArr[i3 + 1] = f1827uq[i2 & 15];
    }
    std::string _arr(cArr);
    delete cArr;
    return _arr;
}

std::string GenerateSignature::Generate(std::string _stringConFromNative,std::string _getStringSigFromNative){
    //_getStringSigFromNative为hmac的key
    this->toLower(_stringConFromNative);
    return HMAC_SHA256(_getStringSigFromNative,_stringConFromNative);
}

std::string GenerateSignature::Generate(std::string _strArr[]){
    std::string str = "";
    for (auto i = _strArr->begin();i!=_strArr->end();i++) {
        str = str + *i + ",";
    }
    std::string stringConFromNative = this->getStringConFromNative(_strArr);
    std::string stringSigFromNative = this->getStringSigFromNative();
    return this->Sign_HASH(this->Generate(stringConFromNative, stringSigFromNative));
}