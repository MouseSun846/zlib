#include <stdio.h>
#include <stdlib.h>
#include "zip.h"
#include <vector>
#include <string>

int main() {
    zipFile zf = zipOpen("log.zip", APPEND_STATUS_CREATE);
    if (zf == NULL) {
        printf("zipOpen error!\n");
        exit(EXIT_FAILURE);
    }
    std::vector<std::string> vect = {"/workspace/zlib/mas_2023_05_27.txt", "/workspace/zlib/mas_2023_05_29.txt", "/workspace/zlib/mas_2023_05_28.txt"};
    for(size_t i = 0;i < vect.size(); i++) {
        auto pos = vect[i].rfind('/');
        std::string name = vect[i].substr(pos + 1);                
        zip_fileinfo file_info = {};
        zipOpenNewFileInZip3_64(zf, name.c_str(), &file_info, NULL, 0, NULL, 0, NULL, Z_DEFLATED, Z_DEFAULT_COMPRESSION, 0, 15, 1, Z_DEFAULT_STRATEGY, NULL, 0, 1);
        char buffer[1024];
        int len;

        FILE* fp = fopen(vect[i].c_str(), "rb");
        if (fp == NULL) {
            printf("Cannot open file test.txt\n");
            continue;
        }

        while ((len = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
            zipWriteInFileInZip(zf, buffer, len);
        }

        fclose(fp);
    }


    zipCloseFileInZip(zf);
    zipClose(zf, NULL);

    return 0;
}
