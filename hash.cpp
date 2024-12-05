#include "main.h"
int hashFunction(const string& id){
    int hash=0;
    hash=(stoll(id))%MOD; // 字符串哈希计算
    return hash;
}
