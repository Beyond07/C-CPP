#include "stdafx.h"
#include <string>

using namespace std;

wstring AnsiiToUnicode(const string& str) {
    // 参数的长度
    int strLen = str.length();
    // 预算-缓冲区中宽字节的长度
    int unicodeLen = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, nullptr, 0);
    // 给指向缓冲区的指针变量分配内存
    allocator<wchar_t> wc_t;
    wchar_t *pUnicode = wc_t.allocate(sizeof(wchar_t)*(unicodeLen + 1),0);
    // 开始向缓冲区转换字节
    MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, pUnicode, unicodeLen);
    wstring ret_str = pUnicode;
    delete pUnicode;
    return ret_str;
}

string UnicodeToAnsii(const wstring& wstr) {
    // 参数的长度
    int wstrLen = wstr.length();
    // 预算-缓冲区中多字节的长度
    int ansiiLen = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
    // 给指向缓冲区的指针变量分配内存
    allocator<char> c_t;
    char *pAssii = c_t.allocate(sizeof(char)*(ansiiLen + 1), 0);
    // 开始向缓冲区转换字节
    WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, pAssii, ansiiLen, nullptr, nullptr);
    string ret_str = pAssii;
    delete pAssii;
    return ret_str;
}
