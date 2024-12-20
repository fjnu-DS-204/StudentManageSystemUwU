#ifndef STUMANAGE_MAIN_H
#define STUMANAGE_MAIN_H
#define  _WINSOCK_DEPRECATED_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstring>
#include <string>
#include <windows.h>
#include <stdlib.h>
#define TruePassword "1"
#define TryPasswordTimes 3
#define CurrentYear 2024
#define rei register int
#define PIS pair<int,string>
using namespace std;
const int MOD=5;

/* 菜单布局 */
void print_dividerstar();
void print_shortstar();
void print_longstar();
void print_itemdot();
void print_commandsign();
void print_slowdot();

void print_welcome_logo();
void print_greeting_menu();
void print_MAIN_menu();
void print_kapoo();

/* 功能函数 */
extern int tryPasswordCount;
void check_loginPW(string password);
char* get_time();
void change_title();
void choose_fuc(char chooseItemId);

/* icey交互类 */
void plz_watch_me(); //禁用最小化和关闭按钮，控制台保持前置
void full_screen();
void change_title_icey();
void change_title_collapse();
void change_cmd_color(int type);
void clear_screen();
void print_by_word(string s);
void error_1();
void error_2();
void error_3();
void error_4();
void error_5();
void error_6();
void error_7();

/* 个人学生类 */
class student{
    friend class studentList;
private:
    string name;
    string id;
    string idcard;
    string phone_number;
    int DD,MM,YY;
    int DSScore;
    student * next; //指向下一个学生
    student * tmp;//堆排用到的临时下一个
public:
    int check_score(int tempscore);
    int check_day(int day);
    int check_month(int month);
    int check_year(int year);
    int check_leapyear(int year);
    int special_check();
    void add();
    bool readFile(istream & in); //有bug的读入文件
    void display(); //打印学生信息
    void swap(student *toExchange); //与传入的对象交换信息

    string getid(){return id;}//调用ID和成绩
    int getds(){return DSScore;}
    void changenext(student* a){ next=a;}    //改next
    void changetmp(student* a){ tmp=a;}
    student* getnext(){ return next;}
    student* gettmp(){ return tmp;}
    //student* getnext(student* a){return a->next;}
};

/* 学生链表类 */
class studentList{
private:
    student * first;
    student * last;
    int num;
    ifstream in;
    ofstream out;

public:
    studentList();          //学生链表类构造函数
    // ~studentList();         //析构函数
    void add();             //增
    void edit();            //改
    void remove_last();      //删除表中最后一个节点
    void remove();          //删除表中学生成绩记录
    void search_by_id();
    void search_by_name();    //姓名查询学生成绩记录
    void sort_by_id();        //按学号排序学生成绩记录
    void sort_by_ds();        //按DS排序学生成绩记录
    void show();            //显示学生信息
    void show_by_level();     //成绩分级显示
    
    // void changefirstlast(student* a,student* b){first=a;last=b;}//获取和改变first
    void changefirstlast(student* a,student* b);//获取和改变first
    student* getfirst();
    void save();            //有bug的文件保存

};
extern studentList stuL;
void create_stu();
void edit_stu();
void delete_stu();
void search_stu();
void sort_stu();
void switch_search_fuc(char chooseWayId);
void switch_sort_fuc(char chooseWayId);
void show_all_stu();
void print_stu_table_Title();
void print_stu_table_Foot();
void print_stu_table_Title_sp(int op);

/* 哈希表 */
struct Node{
    student stu;  // 学生对象
    Node* next;       // 指向下一个节点的指针
};
int hashFunction(const string& id);


void fix_tmp(student* curr); //tmp赋值给next
void clear_tmp(student* curr); //清空tmp

void heapSortid(student* &a,int n,string arr[]);
void heapSortDS(student* &a,int n,PIS arr[]);

#endif //STUMANAGE_MAIN_H
