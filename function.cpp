#include "main.h"

int Failure_num=0;

void change_title(){
    system("title 学生信息管理系统UwU");
}

char* get_time(){/* 当前系统时间，返回值为时间字符串的地址 */
    time_t now=time(0);// 把 now 转换为字符串形式
    char* dt=ctime(&now);
    return dt;
}

/* 密码验证逻辑 */
void check_loginPW(string password){
    if(strcmp(password.c_str(),TruePassword)==0){
        print_dividerstar(); cout<<endl; cout<<endl;
        print_itemdot();
        cout<<"密码正确，欢迎喵"<<endl; cout<<endl;
        print_MAIN_menu();
    }else{
        ++tryPasswordCount;
        if(TryPasswordTimes-tryPasswordCount>0){
            print_dividerstar(); cout<<endl;

            print_itemdot();
            cout<<"密码错误喵，您还有"<<TryPasswordTimes-tryPasswordCount<<"次机会重试，请再次输入:"<<endl;
            print_itemdot();

            cin>>password;
            check_loginPW(password);
        }else{
            print_dividerstar(); cout<<endl; cout<<endl;
            print_itemdot();
            cout<<"杂鱼杂鱼❤，不让登录喵谢谢喵\n"<<endl;
            print_dividerstar();
            exit(0);
        }
    }
}

/* 功能切换 */
void choose_fuc(char chooseItemId){
    switch(chooseItemId){
        case '1': //创建学生信息
            create_stu(); break;
        case '2': //显示学生信息
            show_all_stu(); break;
        case '3': //排序学生信息
            sort_stu(); break;
        case '4': //查询学生信息
            search_stu(); break;
        case '5': //删除学生信息
            delete_stu(); break;
        case '6': //修改学生信息
            edit_stu(); break;
        case '0':{ //退出系统

            stuL.save();
            print_itemdot();cout<<"嘻嘻，数据保存成功了，看起来bug修好了"<<endl;
            // print_itemdot();cout<<"不嘻嘻，你的数据保存不了哦"<<endl;

            print_itemdot();cout<<"感谢使用喵，拜拜喵"<<endl;
            getchar(),getchar();
            exit(0);
        }
            break;
        default:
            //输出提示,再次输入
            Failure_num++;
                 if(Failure_num==1){ error_1(); cin>>chooseItemId; choose_fuc(chooseItemId); }
            else if(Failure_num==2){ error_2(); cin>>chooseItemId; choose_fuc(chooseItemId); }
            else if(Failure_num==3){ error_3(); cin>>chooseItemId; choose_fuc(chooseItemId); }
            else if(Failure_num==4){ error_4(); cin>>chooseItemId; choose_fuc(chooseItemId); }
            else if(Failure_num==5){ error_5(); cin>>chooseItemId; choose_fuc(chooseItemId); }
            else if(Failure_num==6){ error_6(); }
            else if(Failure_num==7){ error_7(); }
            break;
    }
}

