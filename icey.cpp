#include "main.h"
#define  _WINSOCK_DEPRECATED_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;

void plz_watch_me(){
	SetWindowPos(GetConsoleWindow(),HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE|SWP_DRAWFRAME);//始终置顶
	//                             HWND_TOP:顶端   HWND_TOPMOST: 保持顶端   HWND_BOTTOM:底端
    //下面是关按钮
    HWND hwnd=GetConsoleWindow();
    HMENU hmenu=GetSystemMenu(hwnd,false);
    RemoveMenu(hmenu,SC_CLOSE,MF_BYCOMMAND); //移除关闭按钮
    LONG style=GetWindowLong(hwnd,GWL_STYLE); //对当前窗口的style
    style &= ~(WS_MINIMIZEBOX);               //最小化的地方按位取反来屏蔽
    SetWindowLong(hwnd,GWL_STYLE,style);      //应用修改，即这三行移除最小化按钮
    // SetWindowPos(hwnd,HWND_TOP,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE); //窗口全屏，跟后期的改动重复了
    // ShowWindow(hwnd,SW_SHOWNORMAL);
    DestroyMenu(hmenu);
    ReleaseDC(hwnd,NULL);
}
void full_screen(){
    HWND hwnd=GetForegroundWindow(); // 获取当前窗口句柄
    int cx=GetSystemMetrics(SM_CXSCREEN); // 屏幕宽度（像素）
    int cy=GetSystemMetrics(SM_CYSCREEN); // 屏幕高度（像素）

    // 获取当前窗口样式
    LONG l_WinStyle=GetWindowLong(hwnd,GWL_STYLE);

    // 修改窗口样式为最大化，无边框但保留标题栏
    SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle|WS_POPUP|WS_MAXIMIZE));

    // 强制更新窗口位置和大小
    SetWindowPos(hwnd,HWND_TOP,0,0,cx,cy,SWP_FRAMECHANGED|SWP_SHOWWINDOW);
}


string get_execute_path(){
    char buffer[MAX_PATH];
    DWORD len=GetModuleFileName(NULL,buffer,MAX_PATH);
    if(len==0){
        cerr<<"GetModuleFileName 失败，错误码: "<<GetLastError()<<endl;
        return "";
    }
    return string(buffer);
}

void restart_program(){
    string path=get_execute_path();
    if(!path.empty()){
        cout<<"正在重启程序: "<<path<<endl;
        // 使用 ShellExecute 启动新的进程
        ShellExecute(NULL,"open",path.c_str(),NULL,NULL,SW_SHOW);
    } else{
        cerr<<"无法获取程序路径，重启失败！"<<endl;
    }
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
    // cout<<"\033c";
}

void open_github_page(){
    const char* url="https://github.com/fjnu-DS-204/StudentManageSystemUwU";
    // 使用ShellExecute函数打开默认浏览器并访问指定URL
    ShellExecute(NULL,"open",url,NULL,NULL,SW_SHOWNORMAL);
}

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
    print_itemdot(); cout<<"我很确定这只是一个简单实现学生管理系统的程序"<<endl; Sleep(2000);
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
    unsigned long size=255;
    GetUserName(UserName,&size);
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
    print_itemdot(); cout<<"很难想象到在信息碎片化的时代能看到有人不厌其烦的调戏一个简单的C++大作业，对吧"<<currentUser<<"?"<<endl; Sleep(1500);
    print_itemdot(); cout<<"来都来了，来看看这个项目在github上的开源吧"<<endl; Sleep(1500);
    open_github_page(); Sleep(1000);
    print_itemdot(); cout<<"哦，我忘了我当时写了强制页面位于最顶层了，你可能看不到"<<endl; Sleep(1500);
    print_itemdot(); cout<<"或者说，呃，访问不了github也是有可能的"<<endl; Sleep(1500);
    print_itemdot(); cout<<"但问题不大，你马上就能看到了"<<endl; Sleep(1500);
    print_itemdot(); cout<<"永别了，"<<currentUser<<endl; Sleep(1500);
    change_title_collapse(); clear_screen(); change_cmd_color(3);
	print_itemdot(); print_by_word(" 检测到管理系统损坏"); Sleep(700);
	print_itemdot(); print_by_word(" $ ~ 重启./qwq.exe"); Sleep(2000);
    restart_program();
    exit(0);
}