//
// Created by yukarichan on 2022/5/1.
//
#include <iostream>
#include <string>
#include <crypto++/cryptlib.h>
#include <crypto++/hmac.h>
#include <crypto++/sha.h>
#include <crypto++/base64.h>
#include <crypto++/filters.h>
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::HashFilter;
using CryptoPP::Exception;
using CryptoPP::Base64Encoder;
using CryptoPP::SHA256;
using CryptoPP::HMAC;
using namespace std;
string HMAC_SHA256(string key, string plain);

string HMAC_SHA256(string key, string plain) {
    string mac, encoded;
    try {
        HMAC<SHA256> hmac((CryptoPP::byte *) key.c_str(), key.length());
        StringSource(plain, true, new HashFilter(hmac, new StringSink(mac))
        );
    }
    catch (const CryptoPP::Exception &e) {
        return NULL;
    }
    encoded.clear();
    StringSource(mac, true,
                         new StringSink(encoded)
    ); // StringSource
    return encoded;
}
