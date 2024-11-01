#include "main.h"
student* findId(studentList& stuL, string targetId) {
    student* current = stuL.getfirst();
    // cout<<targetId<<endl;
    while (current) {
        if (current->getid() == targetId) {
            return current;
        }
        current=current->getnext();
    }
    return nullptr; 
}
void heapifyid(string arr[], int n, int i) {//按ID排序
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest!= i) {
        std::swap(arr[i], arr[largest]);
        heapifyid(arr, n, largest);
        }
    }
void buildMaxHeapid(string arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyid(arr, n, i);
}

void heapSortid(student* &head,int n,string arr[]) {
    
    // for(int i=0;i<n;i++){ printf("arr[%d]:",i); cout<<arr[i]<<endl;}
    int length = n;
    if (length == 0) return;

    buildMaxHeapid(arr, length);

    for (int i = length - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapifyid(arr, i, 0);
    }

    // cout<<"endsort"<<endl;

    // for(int i=0;i<n;i++){ printf("arr[%d]:",i); cout<<arr[i]<<endl;}

         // 更新链表


    student* newFirst = nullptr;
    student* newLast = nullptr;
    studentList stul;

    for (int i=0;i<n;i++) {
        string id=arr[i];
        student* foundStudent = findId(stuL,id);
        if (foundStudent) {
            if (!newFirst) {
                newFirst = foundStudent;
                newLast = foundStudent;
            } else {
                newLast->changenext(foundStudent);
                newLast = foundStudent;
            }
        }
        //cout<<"la";测试代码
    }
    
    //cout<<"la";

    if (newLast) {
        newLast->changenext(nullptr);
    }

    stuL.changefirstlast(newFirst,newLast);

    //cout<<"la";
}

//--------------------------------------------------------------------------------------------

void heapifyDS(PIS arr[], int n, int i) {//按成绩排序
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left].first > arr[largest].first)
        largest = left;

    if (right < n && arr[right].first > arr[largest].first)
        largest = right;
    if (largest!= i) {
        std::swap(arr[i], arr[largest]);
        heapifyDS(arr, n, largest);
        }
    }
void buildMaxHeapDS(PIS arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyDS(arr, n, i);
}

void heapSortDS(student* &head,int n,PIS arr[]) {
    int length = n;
    if (length == 0) return;

    buildMaxHeapDS(arr, length);

    for (int i = length - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapifyDS(arr, i, 0);
    }

    // cout<<"endsort"<<endl;

    // for(int i=0;i<n;i++){ printf("arr[%d]:",i); cout<<arr[i]<<endl;}

         // 更新链表
    //for(int i=0;i<n;i++){ printf("arr[%d]:",i); cout<<arr[i].first<<endl;} 测试链表

    student* newFirst = nullptr;
    student* newLast = nullptr;
    studentList stul;

    for (int i=0;i<n;i++) {
        string id=arr[i].second;
        student* foundStudent = findId(stuL,id);
        if (foundStudent) {
            if (!newFirst) {
                newFirst = foundStudent;
                newLast = foundStudent;
            } else {
                newLast->changenext(foundStudent);
                newLast = foundStudent;
            }
        }
        //cout<<"la";测试代码
    }
    
    //cout<<"la";

    if (newLast) {
        newLast->changenext(nullptr);
    }

    stuL.changefirstlast(newFirst,newLast);

    //cout<<"la";
}
