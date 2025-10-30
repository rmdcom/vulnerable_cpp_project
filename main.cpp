// Introducde the Bugs CVEs
#include <libxml/parser.h>
#include <sqlite3.h>
#include <expat.h>

void test_libxml2() {
    xmlDocPtr doc = xmlReadMemory("<root><child/></root>", 22, "noname.xml", NULL, 0);
    if (doc) xmlFreeDoc(doc);
}

void test_sqlite() {
    sqlite3 *db;
    sqlite3_open(":memory:", &db);
    sqlite3_close(db);
}

void test_expat() {
    XML_Parser parser = XML_ParserCreate(NULL);
    XML_Parse(parser, "<root></root>", strlen("<root></root>"), 1);
    XML_ParserFree(parser);
}

#include <iostream>
#include <curl/curl.h>
#include <openssl/ssl.h>
#include <zlib.h>

int main() {
    std::cout << "Testing vulnerable dependencies..." << std::endl;
    curl_version_info_data* curl_info = curl_version_info(CURLVERSION_NOW);
    std::cout << "libcurl version: " << curl_info->version << std::endl;
    std::cout << "OpenSSL version: " << OpenSSL_version(OPENSSL_VERSION) << std::endl;
    std::cout << "zlib version: " << zlibVersion() << std::endl;
    
    test_libxml2();
    test_sqlite();
    test_expat();
    return 0;
}
