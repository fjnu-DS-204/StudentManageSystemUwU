#include "main.h"
#define  _WINSOCK_DEPRECATED_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;

void plz_watch_me(){
	SetWindowPos(GetConsoleWindow(),HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE|SWP_DRAWFRAME);//前置
	//                             HWND_TOP:顶端   HWND_TOPMOST: 保持顶端   HWND_BOTTOM:底端
    //下面是关按钮
    HWND hwnd = GetConsoleWindow();
    HMENU hmenu = GetSystemMenu(hwnd, false);
    RemoveMenu(hmenu, SC_CLOSE, MF_BYCOMMAND);
    LONG style = GetWindowLong(hwnd, GWL_STYLE);
    style &= ~(WS_MINIMIZEBOX);
    SetWindowLong(hwnd, GWL_STYLE, style);
    SetWindowPos(hwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    ShowWindow(hwnd, SW_SHOWNORMAL);
    DestroyMenu(hmenu);
    ReleaseDC(hwnd, NULL);
}

void change_title_icey(){ system("title icey"); }
void change_title_collapse(){ system("title collapse"); }

void change_cmd_color(int type){ /*考虑到涉及system命令，为防止注入，这里只使用提前预设的颜色选项*/
    switch(type){
        case 0: //白底黑字
            system("color 70"); break;
        case 1: //黑底白字
            system("color 07"); break;
        case 2: //黄底白字
            system("color E0"); break;
        case 3: //灰底绿字
            system("color 8A"); break;
        default:
            cout<<"ERROR!: 未涉及情况,位于icey.cpp change_cmd_color()"<<endl; break;
    }
}

void clear_screen(){
    system("cls");
    // cout << "\033c";
}

// void open_github_page(){
//     const char* url = "https://github.com/fjnu-DS-204/StudentManageSystemUwU/graphs/contributors";
//     // 使用ShellExecute函数打开默认浏览器并访问指定URL
//     ShellExecute(NULL,"open",url, NULL, NULL, SW_SHOWNORMAL);
// }

void print_by_word(string s){
    for(rei i=0;i<s.length();++i){
        cout<<s[i]; Sleep(70);
    }
    cout<<endl;
}

void error_1(){
    cout<<endl; print_dividerstar(); cout<<endl; cout<<endl;
    print_itemdot(); cout<<"输错了喵，再试一次："<<" ";
}

void error_2(){
    cout<<endl; print_dividerstar(); cout<<endl; cout<<endl;
    print_itemdot(); cout<<"你先别急，输慢点喵"<<endl;
    print_itemdot(); cout<<"再来一次："<<" ";
}

void error_3(){
    cout<<endl; print_dividerstar(); cout<<endl; cout<<endl;
    print_itemdot(); cout<<"嘶，不是哥们，我怀疑你是故意的"<<endl;
    print_itemdot(); cout<<"你这次最好是对的："<<" ";
}

void error_4(){
    cout<<endl; print_dividerstar(); cout<<endl; cout<<endl;
    print_itemdot(); cout<<"等下，我们最好都冷静一下"<<endl; Sleep(1000);
    print_itemdot(); cout<<"你只需要在0~6的范围内挑一个数字就好了好吗"<<endl; Sleep(1000);
    print_itemdot(); cout<<"我相信你已经明白了，现在让我们谨慎的再试一次："<<" ";
}

void error_5(){
    cout<<endl; print_dividerstar(); cout<<endl; cout<<endl;
    print_itemdot(); cout<<"..."<<endl; Sleep(2000);
    print_itemdot(); cout<<"..."<<endl; Sleep(1000);
    print_itemdot(); cout<<"我很确定这只是一个简单实现学生管理系统的程序，而不是一个对某个能调戏旁白的游戏的拙略模仿"<<endl; Sleep(2000);
    print_itemdot(); cout<<"你唯一需要做的，就是去调试这个程序的正常功能，"<<endl; Sleep(500);
    print_itemdot(); cout<<"而非来看看我到底写了多少种特判来处理不合法输入的情况"<<endl; Sleep(1000);
    print_itemdot(); cout<<"我很确信没有别的特判了，别玩了，再试一次吧："<<" ";
}

void error_6(){
    cout<<endl; print_dividerstar(); cout<<endl; cout<<endl;
    print_itemdot(); Sleep(2000); cout<<"..."; Sleep(2000); cout<<endl;
    print_itemdot(); cout<<"哦！ 我明白了"<<endl;  Sleep(1000);
    print_itemdot(); cout<<"你一定是忘了功能对应的键位了"<<endl;  Sleep(1000);
    print_itemdot(); cout<<"没关系，我再向你展示一遍："<<endl;  Sleep(1000);
    print_MAIN_menu();
}

void error_7(){
    /*
    WCHAR UserName[255];
    unsigned long size = 255;
    GetUserName(UserName, &size);
    */ //这玩意有bug
    char currentUser[256]={0};  //以下在模块化调用windows.h中读用户名函数
	DWORD dwSize_currentUser=256;
	GetUserName(
		currentUser,			// 接收当前登录用户的用户名
		&dwSize_currentUser		// 缓冲区大小
		);
    plz_watch_me(); //这里设想是进入全新交互，要把关闭按钮关了
    change_title_icey();
    cout<<endl; print_dividerstar(); cout<<endl; cout<<endl;
    clear_screen(); Sleep(1000); change_cmd_color(0);
	print_itemdot(); cout<<"这样并不好玩，管理员"<<endl; Sleep(700);
    print_itemdot(); cout<<"也许。。我更应该称呼你为。。"<<currentUser<<"?"<<endl; Sleep(1500);
    print_itemdot(); cout<<"算了。。"; Sleep(500); cout<<"这都不重要"<<endl; Sleep(1000);
    print_itemdot(); cout<<"很难想象到在信息碎片化的时代能看到有人不厌其烦的调戏一个简单的C++大作业"<<currentUser<<"?"<<endl; Sleep(1500);
    print_itemdot(); cout<<"来都来了，来看看这个项目在github上的开源吧"<<endl; Sleep(1500);
    // open_github_page(); Sleep(1000);
    print_itemdot(); cout<<"哦，我忘了我当时写了强制页面位于最顶层了，你可能看不到"<<endl; Sleep(1500);
    print_itemdot(); cout<<"或者说，呃，访问不了github也是有可能的"<<endl; Sleep(1500);
    print_itemdot(); cout<<"这个神奇的交互就到这里好了，已经没有灵光一闪了"<<endl; Sleep(1500);
    print_itemdot(); cout<<"永别了"<<currentUser<<endl; Sleep(1500);
    change_title_collapse(); clear_screen(); change_cmd_color(3);
	print_itemdot(); print_by_word(" 检测到管理系统损坏"); Sleep(700);
	print_itemdot(); print_by_word(" $ ~ 重启./qwq.exe"); Sleep(2000);
    exit(0);
}