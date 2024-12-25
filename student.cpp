#include "main.h"
/* ******************************************************** */
Node* hashTable[MOD]={nullptr};
/* ******************************************************** */

/******************************************************
 * 学生类函数
 */

int student::check_day(int day){
    if(day<=0||day>31){
        print_itemdot(); cout<<"error!: 学生出生日期输入有误,日期范围1~31,请再次尝试:"; cin>>day;
        return check_day(day);
    }
    return day;
}


int student::check_month(int month){
    if(month<=0||month>12){
        print_itemdot(); cout<<"error!: 学生出生月份输入有误,日期范围1~12,请再次尝试:"; cin>>month;
        return check_month(month);
    }
    return month;
}

int student::check_year(int year){
    if(year<=1900){
        print_itemdot(); cout<<"error!: 学生出生年份输入有误,你活得有点长了,请再次尝试:"; cin>>year;
        return check_year(year);
    }
    if(year>CurrentYear){
        print_itemdot(); cout<<"error!: 学生出生年份输入有误,我们不欢迎时间穿越者,请再次尝试:"; cin>>year;
        return check_year(year);
    }
    return year;
}

int student::check_leapyear(int year){ return (year%4==0 && year%100!=0) || (year%400==0); }

int month_31[7]={1,3,5,7,8,10,12};
int month_30[4]={4,6,9,11};

int student::special_check(){
    if(find(begin(month_31),end(month_31),MM)!=end(month_31)){ return 1;}//我边界写的足够好,这里什么都不需要做,但出于工整考虑还是加上
    if(find(begin(month_30),end(month_30),MM)!=end(month_30)){
        if(DD==31){ print_itemdot(); cout<<"error!: "<<MM<<"月怎么会有"<<DD<<"天呢,请重新输入年月日"<<endl; return 0;}
        return 1;
    }
    if(MM==2){
        if(DD<=28) return 1;
        if(DD==29 && !check_leapyear(YY)){ print_itemdot();  cout<<"error!: 你这也不是闰年啊,哪来的第29天,请重新输入年月日 "<<endl; return 0; }
        if(DD>29){ print_itemdot(); cout<<"error!: "<<MM<<"月怎么会有"<<DD<<"天呢,请重新输入年月日"<<endl; return 0; }
    }
    print_itemdot(); cout<<"ERROR!:这里有溢出的边界情况,位于 student.cpp special_check()"<<endl;
    return 0;
}

int student::check_score(int tempScore){
    if(tempScore<0||tempScore>100){
        print_itemdot(); cout<<"error!: 学生成绩输入有误,成绩范围0~100,请再次尝试:"; cin>>tempScore;
        return check_score(tempScore);
    }
    return tempScore;
}

string student::check_idcard(string tempidcard){
    if(tempidcard.length()!=18){
        print_itemdot();cout<<"error!:学生身份证号输入有误，身份证号为十八位数字，请再次尝试:";cin>>tempidcard;
        return check_idcard(tempidcard);
    }
    
        string idcard_prefix =tempidcard.substr(0,3);
        unordered_set<string> legal_prefixes={
            "110", "120", "130", "140", "150", "210", "220", "230", 
                                           "310", "320", "330", "340", "350", "360", "370", "410", 
                                           "420", "430", "440", "450", "460", "500", "510", "520", 
                                           "530", "540", "610", "620", "630", "640", "650", "710","810","820","910"
        };
        if(legal_prefixes.find(idcard_prefix)==legal_prefixes.end()){
            print_itemdot();
        cout<<"error!:学生身份证号的前三位不符合合法地区代码，请再次尝试："<< endl;
        cin>>tempidcard;
        return check_idcard(tempidcard);


        }
        
    

    return tempidcard;

}
string student::check_phonenumber(string tempphone_number){
    if(tempphone_number.length()!=11){
        print_itemdot();cout<<"error!:学生电话号码输入有误，电话号码为十一位数字，请再次尝试:";cin>>tempphone_number;
        return check_phonenumber(tempphone_number);
    }
    return tempphone_number;

}

void student::add(){
    print_itemdot(); cout<<"请输入学生姓名:"; cin>>name;
    string tempId="";
    int tempScore=0;
    string tempidcard="";
    string tempphone_number="";

    //学号处理
    print_itemdot(); cout<<"请输入学生学号(十位):"; cin>>tempId;
    while(tempId.length()!=10){ print_itemdot(); cout<<"error!: 学生学号输入有误,学号为十位整数,请再次尝试:"; cin>>tempId;}
    id=tempId;

    //成绩处理
    print_itemdot(); cout<<"请输入DS课程的期末成绩:"; cin>>tempScore;
    DSScore=check_score(tempScore);

    //出生日期
    int tmp; need_redone_in_edit:
    print_itemdot(); cout<<"请输入出生日期(DD):"; cin>>tmp; DD=check_day(tmp);
    print_itemdot(); cout<<"请输入出生月份(MM):"; cin>>tmp; MM=check_month(tmp);
    print_itemdot(); cout<<"请输入出生年份(YY):"; cin>>tmp; YY=check_year(tmp);
    if(!special_check()) goto need_redone_in_edit;
   
    //身份证
    print_itemdot(); cout<<"请输入身份证(十八位):"; cin>>tempidcard;
     while(tempidcard.length()!=18){ print_itemdot(); cout<<"error!: 学生身份证号码输入有误,改号码为十八位整数,请再次尝试:"; cin>>tempidcard;}
    idcard=check_idcard(tempidcard);

  
     //电话号码
    print_itemdot();cout<<"请输入电话号码(十一位)：";cin>>tempphone_number;
    while(tempphone_number.length()!=11){print_itemdot();cout<<"error!:学生电话号码输入有误，电话号码应为十一位整数，请再次尝试:";cin>>tempphone_number;}
    phone_number=check_phonenumber(tempphone_number);
    
    next=NULL;
}

/**********************************************************
 * 学生类接口定义
 */
bool student::readFile(istream & in)//没有bug的读入文件
{
    in>>name>>id>>DSScore>>DD>>MM>>YY>>idcard>>phone_number;
    return !in.fail();
}

void student::display(){ cout<<id<<"\t"<<name<<"  \t"<<DSScore<<"   \t"<<DD<<"/"<<MM<<"/"<<YY<<" \t"<<idcard<<" \t"<<phone_number<<endl; }

void student::swap(student *toExchange){//与传入的对象交换信息 用于简单排序法时交换
    string tempName,tempId;
    int tempDSScore,tempDD,tempMM,tempYY;
    tempName=name; name=toExchange->name; toExchange->name=tempName;
    tempId=id; id=toExchange->id; toExchange->id=tempId;
    tempDSScore=DSScore; DSScore=toExchange->DSScore; toExchange->DSScore=tempDSScore;
    tempDD=DD; DD=toExchange->DD; toExchange->DD=tempDD;
    tempMM=MM; MM=toExchange->MM; toExchange->MM=tempMM;
    tempYY=YY; YY=toExchange->YY; toExchange->YY=tempYY;
}

void clear_tmp(student * curr){
    while(curr){
        curr->changetmp(nullptr);
        curr=curr->getnext();
    }
}

void fix_tmp(student * curr){
    //cout<<"now in "<<curr->getid()<<" "<<curr->getds()<<endl;
    if(curr->getnext()!=nullptr) fix_tmp(curr->getnext());
    // else throw "i know it.";
    curr->changenext(curr->gettmp());
    //if(curr->gettmp()) cout<<"now change "<<curr->getid()<<"-"<<curr->getds()<<"'s next to "<<curr->gettmp()->getid()<<"-"<<curr->gettmp()->getds()<<endl;
    //else cout<<"this one is last"<<endl;
}

/*******************************************************
 * 学生列表类构造函数
 */
studentList::studentList(){//没有bug的读入文件
    in.open("stuDate.txt");////有bug的读入文件
    if(!in){
        cout<<"\t*欢迎新用户,请先输入用户信息再使用.";
        print_shortstar();
        cout<<endl;
        first=NULL;
        last=NULL;
        num=0;
    }else{
        first=new student;
        last=first;
        while(last->readFile(in)){
/* ************************************************************** */
            int index=hashFunction(last->id);
            Node* newNode=new Node{*last,hashTable[index]};
            hashTable[index]=newNode;//将读入信息存进哈希表
/* ************************************************************** */
            last->next=new student;
            last=last->next;
            ++num;
        }
        // 删除多余的空节点
        if(last==first) { //为空
            delete first;
            first=last=nullptr;
        }else{  //有数据，删除最后的空节点
            student* temp=first;
            while(temp->next!=last){
                temp=temp->next;
            }
            delete last;
            last=temp;
            last->next=nullptr;
        }
        in.close();
        // cout<<"\t^欢迎再次使用,读取学生信息成功.\n";
        // Sleep(1000);
    }
}
/**
 *通过Id添加学生信息
 */
void studentList::add(){
    student * t=new student;
    t->add();
    student * p=first;
    while(p){
        if(p->id==t->id){
            print_itemdot(); cout<<"error!: 学号输入错误或该学生已经存在,如需添加,请先删除原纪录再重新录入!"<<endl;
            return;
        }
        p=p->next;
    }
    num++;
    if(first==NULL){
        first=last=t;
        cout<<"\t*学生信息创建成功:) "<<endl; Sleep(1000);
        print_stu_table_Title();
        last->display();
        print_stu_table_Foot();
    }
    else{
        last->next=t;
        last=last->next;
        cout<<"\t*学生信息创建成功:) "<<endl; Sleep(1000);
        print_stu_table_Title();
        last->display();
        print_stu_table_Foot();
    }
/* ******************************************************** */
    int index=hashFunction(t->id);
    Node* newNode=new Node{*t,hashTable[index]};
    hashTable[index]=newNode;
/* ******************************************************** */
}

/**
 *通过Id修改学生信息
 */
void studentList::edit(){
    string tempId;
    char isCheck;

    print_itemdot(); cout<<"请输入要修改的学生学号:";
    cin>>tempId;
    while(tempId.length()!=10){//学号验证
        print_itemdot(); cout<<"error!: 学生学号输入有误,学号为十位整数,请再次尝试:";
        cin>>tempId;
    }
    // while(t){
    //     if(t->id==tempId) break;
    //     t=t->next;
    // }
/* ************************************************************** */
    int index=hashFunction(tempId);
    Node* p=hashTable[index];
    student* hash_ID=nullptr;
    while(p){
        if(p->stu.id==tempId){
            hash_ID=&p->stu;
            break;
        }
        p=p->next;
    }
/* ************************************************************** */
    if(!hash_ID){//t到最后为空
        print_itemdot(); cout<<"error!: 未找到您所要修改的学生,请确认学号后重试"<<endl;
        return;
    }else{
        cout<<"\t*已为您查询到该学生 ";
        print_shortstar();
        cout<<endl;
        print_stu_table_Title();
        hash_ID->display();
        print_stu_table_Foot();
    }
    cout<<endl;
    print_itemdot(); cout<<"确认修改此学生吗(y/n) (默认为y) :";
    // cin>>isCheck;
    getchar(); scanf("%c",&isCheck); //getchar先读掉前面的回车,用scanf来读入回车的情况
    switch(isCheck){
        case 'Y':
        case 'y':
        case '\n': {
            print_itemdot(); cout<<"修改学生姓名:"; cin>>hash_ID->name;
            int tempScore=0;

            print_itemdot(); cout<<"修改DS课程的期末成绩:"; cin>>tempScore;
            while(tempScore<0 || tempScore>100){
                print_itemdot(); cout<<"error!: 学生成绩输入有误,成绩范围0~100,请再次尝试:"; cin>>tempScore;
            }
            hash_ID->DSScore=tempScore;

            print_itemdot(); cout<<"修改出生日期:"<<endl; int tmp; string syz;
            need_redone_in_List_edit:
            print_itemdot(); cout<<"请输入出生日期(DD):"; cin>>tmp; hash_ID->DD=hash_ID->check_day(tmp);
            print_itemdot(); cout<<"请输入出生月份(MM):"; cin>>tmp; hash_ID->MM=hash_ID->check_month(tmp);
            print_itemdot(); cout<<"请输入出生年份(YY):"; cin>>tmp; hash_ID->YY=hash_ID->check_year(tmp);
            print_itemdot(); cout<<"修改身份证号:"; cin>>syz; hash_ID->idcard=hash_ID->check_idcard(syz);
            print_itemdot(); cout<<"修改手机号:"; cin>>syz; hash_ID->phone_number=hash_ID->check_phonenumber(syz);
            if(!hash_ID->special_check()) goto need_redone_in_List_edit;
/* ************************************************************** */
            student *ID=first;
            while(ID){
                if(ID->id==tempId){
                    ID->name=hash_ID->name;
                    ID->DSScore=hash_ID->DSScore;
                    ID->DD=hash_ID->DD;
                    ID->MM=hash_ID->MM;
                    ID->YY=hash_ID->YY;
                    break;
                }
                ID=ID->next;
            }
/* ************************************************************** */
            cout<<"\t>./学生信息已成功修改."<<endl;
            print_stu_table_Title();
            hash_ID->display();
            print_stu_table_Foot();
            Sleep(500);
            break;
        }
        case 'N':
        case 'n':
        default :
            cout<<"\t>./学生信息修改已取消."<<endl;
            Sleep(500);
            break;
    }
}

/**
 * 删除最后一个节点
 */
void studentList::remove_last(){
    //删除空节点 p为倒数第二个
    student *p=first;
    while(p->next!=NULL){ p=p->next; }
    p->next=NULL;
    last=p;
    free(p->next);
}

/**
 *通过Id删除学生信息
 */
void studentList::remove(){
    string tempId;
    cout<<"\t>./准备删除学生信息 "; print_slowdot();
    cout<<"\t>./请输入要删除的学生的学号: ";
    cin>>tempId;
    // student *t=first;
    // student *p=NULL;
    // while(t){
    //     if(t->id==tempId) break;
    //     p=t; t=t->next;
    // }
    // if(!t){//t到最后为空
    //     print_itemdot();
    //     cout<<"error!: 未找到要删除的学生,请确认学号后重试"<<endl;
    //     return;
    // }
    // if(!p){//特判第一个就相同
    //     first=first->next;
    //     print_itemdot();
    //     cout<<"Congratulations!: 您已成功删除学生"<<tempId<<endl;
    //     delete t;
    // }
    // else{
    //     p->next=t->next;//把t的下一个地址赋给p的next
    //     print_itemdot();
    //     cout<<"Congratulations!: 您已成功删除学生"<<tempId<<endl;
    //     delete t;
    // }
/* ************************************************************** */
    int index=hashFunction(tempId);
    Node* hash_p=hashTable[index];
    Node* prev=NULL;
    while(hash_p){
        if(hash_p->stu.id==tempId){
            break;
        }
        prev=hash_p;
        hash_p=hash_p->next;
    }
    if(!hash_p){
        print_itemdot();
        cout<<"error!: 未找到您所要查找的学生,请确认学号后重试"<<endl;
        return;
    }
    if(!prev){
        hashTable[index]=hash_p->next;
    }else{
        prev->next=hash_p->next;
    }
    delete hash_p;
    student* t=first;
    student* p=NULL;
    while(t){
        if(t->id==tempId) break;
        p=t; t=t->next;
    }
    if(!p){//特判第一个就相同
        first=first->next;
        print_itemdot();
        cout<<"Congratulations!: 您已成功删除学生"<<tempId<<endl;
        delete t;
    }else{
        p->next=t->next;//把t的下一个地址赋给p的next
        print_itemdot();
        cout<<"Congratulations!: 您已成功删除学生"<<tempId<<endl;
        delete t;
    }
/* ************************************************************** */
    --num;
    Sleep(1000);
}

/**
 *通过Id搜索学生
 */
void studentList::search_by_id(){
    string tempId;
    // student *t=first;

    print_itemdot(); cout<<"请输入要查找的学生学号:";
    cin>>tempId;
    while(tempId.length()!=10){//学号验证
        print_itemdot();
        cout<<"error!: 学生学号输入有误,学号为十位整数,请再次尝试：";
        cin>>tempId;
    }
    // while(t){
    //     if(t->id==tempId) break;
    //     t=t->next;
    // }
    // if(!t){//t已跑到最后为空
    //     print_itemdot();
    //     cout<<"error!: 未找到您所要查找的学生,请确认学号后重试"<<endl;
    //     return;
    // }else{
    //     cout<<"\t*已为您查询到以下学生 "<<endl;
    //     print_stu_table_Title();
    //     t->display();
    //     print_stu_table_Foot();
    // }
/* ************************************************************** */
    int index=hashFunction(tempId);
    Node* p=hashTable[index];
    if (!p){
        print_itemdot();
        cout<<"error!: 未找到您所要查找的学生,请确认学号后重试"<<endl;
        return;
    }
    while(p){
        if(p->stu.id==tempId){
            cout<<"\t*已为您查询到以下学生"<<endl;
            print_stu_table_Title();
            p->stu.display();
            print_stu_table_Foot();
            return;
        }
        p=p->next;
    }
    print_itemdot();
    cout<<"error!: 未找到您所要查找的学生,请确认学号后重试"<<endl;
}
/* ************************************************************** */

/**
 *通过Name搜索学生
 */
void studentList::search_by_name(){
    string tempName;
    student *t=first;
    student *p[] ={NULL};
    int foundCount=0;//从0开始的计数器

    print_itemdot(); cout<<"请输入要查找的学生姓名:";
    cin>>tempName;
    while(t){
        if(t->name==tempName) p[foundCount++]=t;
        t=t->next;
    }

    if(!p[0]){//p[0]为空,即t已跑到最后为空
        print_itemdot();
        cout<<"error!: 未找到您所要查找的学生,请确认姓名后重试"<<endl;
        return;
    }else{
        cout<<"\t*已为您查询到以下学生: "<<endl;
        print_stu_table_Title();
        for(int i=0;i<foundCount;++i) p[i]->display();
        print_stu_table_Foot();
    }
}

/**
 *通过Id排序学生
 */

void studentList::sort_by_id(){
    student *t=first;
    student *p=NULL;

    /*if(t==NULL){//无数据
        print_itemdot();
        cout<<"error!: 当前无学生数据,请先添加后排序"<<endl;
        return;
    }*/

    int n = 0;

    // 计算链表长度
    while (t!= nullptr) {
        n++;
        t = t->next;
    }

    
    string arr[n];
    int i=0;
    t=first;
    while (t) {
        arr[i++] = t->getid();
        t = t->next;
    }
    t=first;
    heapSortid(t,n,arr);

    cout<<"\t*已按学生学号排序成功 "<<endl;
    stuL.show();
}

/**
 *通过DS排序学生
 */
void studentList::sort_by_ds(){
    student *t=first;
    student *p=NULL;
    clear_tmp(t);
    int n=0;

    /*if(t==NULL){//无数据后的退出
        print_itemdot();
        cout<<"error!: 当前无学生数据,请先添加后排序"<<endl;
        return;
    }*/

    while (t!= nullptr) {
        n++;
        t = t->next;
    }
    // cout<<"n="<<n<<endl;
    PIS arr[n];//初始化arr
    int i=0;
    t=first;
    while (t) {
        arr[i].second = t->getid(),arr[i++].first = t->getds();
        t = t->next;
    }
    // cout<<"success in overrun,i="<<i<<endl;
    // i=0;
    // t=first;
    // while (t) {
    //     arr[i++].first = t->getds();
    //     t = t->next;
    // }

    t=first;
    
    // cout<<"here"<<endl;
    //以上没问题
    heapSortDS(t,n,arr);

    t=first;
    /*while(t){
        cout<<t->getid()<<" "<<t->getds()<<endl;
        t=t->getnext();
    }*/

    cout<<"\t*已按DS成绩排序成功 ";
    print_shortstar(); cout<<endl;
    stuL.show_by_level();

}

/**
 *显示所有学生信息
 */
void studentList::show(){
    print_stu_table_Title();
    student *t=first;
    if(t) while(t){ t->display(); t=t->next; }
    else{ print_itemdot(); cout<<"error!: 当前无学生信息"<<endl; }
    print_stu_table_Foot();
}

void studentList::show_by_level(){
    student *t=first;
    if(!t){ print_stu_table_Title(); print_itemdot(); cout<<"error!: 当前无学生信息"<<endl; print_stu_table_Foot(); return ;}
    if(t->DSScore<=100 && t->DSScore>90){
        print_stu_table_Title_sp(0);
        while(t->DSScore>90){ t->display(); if(t->next!=NULL){ t=t->next;}else{ break;}  }
        print_stu_table_Foot();
    }if(t->DSScore<=90 && t->DSScore>80){
        print_stu_table_Title_sp(1);
        while(t->DSScore>80){ t->display();  if(t->next!=NULL){ t=t->next;}else{ break;}  }
        print_stu_table_Foot();
    }if(t->DSScore<=80 && t->DSScore>70){
        print_stu_table_Title_sp(2);
        while(t->DSScore>70){ t->display();  if(t->next!=NULL){ t=t->next;}else{ break;} }
        print_stu_table_Foot();
    }if(t->DSScore<=70 && t->DSScore>60){
        print_stu_table_Title_sp(3);
        while(t->DSScore>60){ t->display();  if(t->next!=NULL){ t=t->next;}else{ break;} }
        print_stu_table_Foot();
    }if(t->DSScore<=60){
        print_stu_table_Title_sp(4);
        while(t){ t->display();  if(t->next!=NULL){ t=t->next;}else{ break;} }
        print_stu_table_Foot();
    }
}

//没有bug的文件保存、
void studentList::save()
{
    student *t=first;
    out.open("stuDate.txt");
    for(;t!=NULL;t=t->next)
        out<<t->name<<"\t"<<t->id<<"\t"<<t->DSScore<<"\t"<<t->DD<<"\t"<<t->MM<<"\t"<<t->YY<<"\t"<<t->idcard<<"\t"<<t->phone_number<<'\n';
    out.close();
}

// studentList::~studentList()
// {
//     save(); //没有bug的文件保存
// }
void studentList::changefirstlast(student* a,student* b){
    first=a;last=b;
}

student* studentList::getfirst(){ return first;}

void create_stu(){
    cout<<"\t>./正在创建学生信息 ";
    print_slowdot();
    stuL.add();
}

void delete_stu(){ stuL.remove(); }

void show_all_stu(){
    cout<<"\t>./显示所有学生信息 ";
    print_slowdot();
    stuL.show();
}

void edit_stu(){
    cout<<"\t>./进入修改学生信息 ";
    print_slowdot();
    stuL.edit();
}

/**
 * 查询学生信息逻辑
 */
void search_stu(){
    char chooseWayId;
    cout<<"\t.>/如何查询学生信息 ";
    print_slowdot();
    cout<<endl;
    print_itemdot(); print_longstar(); cout<<endl;
    print_itemdot(); cout<<"1.按学生的姓名查找(支持重名)"<<endl;
    print_itemdot(); cout<<"2.按学生的学号查找(学号唯一)"<<endl;
    print_itemdot(); cout<<"3.显示所有学生信息"<<endl;
    print_itemdot(); print_longstar(); cout<<endl;
    cout<<endl;
    print_itemdot(); cout<<"请选择查找方式: "; cin>>chooseWayId;
    switch_search_fuc(chooseWayId);
}

/**
 * 切换查询方式函数
 * @param chooseWayId
 */
void switch_search_fuc(char chooseWayId){
    switch(chooseWayId){
        case '1'://按姓名
            stuL.search_by_name();
            break;
        case '2'://按学号
            stuL.search_by_id();
            break;
        case '3'://全部
            show_all_stu();
            break;
        default:
            print_itemdot(); cout<<"error!: 无您所输入的选项,请确认后重试: "; cin>>chooseWayId;
            switch_search_fuc(chooseWayId);
    }
}

/**
 * 排序学生信息逻辑
 */
void sort_stu(){
    char chooseWayId;
    cout<<"\t*如何排序学生信息 ";
    cout<<endl;
    print_itemdot(); print_longstar(); cout<<endl;
    print_itemdot(); cout<<"1.按学生的DS成绩"<<endl;
    print_itemdot(); cout<<"2.按学生的学号"<<endl;
    print_itemdot(); print_longstar(); cout<<endl;
    cout<<endl;
    print_itemdot(); cout<<"请选择排序方式: "; cin>>chooseWayId;
    switch_sort_fuc(chooseWayId);
}

/**
 * 切换排序方式函数
 * @param chooseWayId
 */
void switch_sort_fuc(char chooseWayId){
    switch(chooseWayId){
        case '1':
            stuL.sort_by_ds(); break;
        case '2':
            stuL.sort_by_id(); break;
        default:
            print_itemdot(); cout<<"error!: 无您所输入的选项,请确认后重试: "; cin>>chooseWayId;
            switch_sort_fuc(chooseWayId);
    }
}

void print_stu_table_Title_sp(int op){
    string s={};
    if(op==0) s="完美";
    else if(op==1) s="优秀";
    else if(op==2) s="良好";
    else if(op==3) s="合格";
    else if(op==4) s="不合格";
 cout<<endl<<"----------------------------------"<<s<<"--------------------------------------------"<<endl;
    cout<<"  \t"<<"学号"<<"  \t"<<"姓名"<<"  \t"<<"DS"<<"  \t"<<"DD/MM/YY"<<" \t"<<"身份证号码"<<"          \t"<<"电话号码"<<endl;
}

void print_stu_table_Title(){
    cout<<endl<<"----------------------------------学生列表-----------------------------------------------"<<endl;
     cout<<"  \t"<<"学号"<<"  \t"<<"姓名"<<"  \t"<<"DS"<<"  \t"<<"DD/MM/YY"<<" \t"<<"身份证号码"<<"            \t"<<"电话号码"<<endl;
}

void print_stu_table_Foot(){
    cout<<"----------------------------------列表结束-----------------------------------------------"<<endl<<endl;
    Sleep(1500);
}
