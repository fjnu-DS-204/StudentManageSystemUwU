#include "main.h"
using namespace std;

studentList stuL;

int main(){
    full_screen();
    // SetConsoleOutputCP(65001);
    change_title(); //这玩意加上之后vscode内置控制台出问题了啊嗯
    print_greeting_menu();
    while(true) print_MAIN_menu();
    // system("pause");
    getchar();getchar();
    return 0;
}