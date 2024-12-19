#include "main.h"

student* findId(string targetId) {
    student* current = stuL.getfirst();
    while (current) {
        if (current->getid() == targetId) {
            return current;
        }
        current=current->getnext();
    }
    return nullptr; 
}

void check(){
    cout<<"start check"<<endl;
    student *st=stuL.getfirst();
    while(st){
        cout<<st->getid()<<endl;
        st=st->getnext();
    }
    cout<<"end check"<<endl;
}

void heapifyid(string arr[], int n, int i) {//��ID����
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

        // ��������


    student* newFirst = nullptr;
    student* newLast = nullptr;
    // studentList stul;

    for (int i=0;i<n;i++) {
        string id=arr[i];
        student* foundStudent = findId(id);
        if (foundStudent) {
            if (!newFirst) {
                newFirst = foundStudent;
                newLast = foundStudent;
            } else {
                newLast->changetmp(foundStudent);
                newLast = foundStudent;
            }
        }
        //cout<<"la";���Դ���
    }
    
    //cout<<"la";

    fix_tmp(head);


    if (newLast) {
        newLast->changenext(nullptr);
    }

    stuL.changefirstlast(newFirst,newLast);
    clear_tmp(newFirst);
    //cout<<"la";
}

//--------------------------------------------------------------------------------------------


void heapifyDS(PIS arr[], int n, int i) {//���ɼ�����
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left].first < arr[largest].first)
        largest = left;

    if (right < n && arr[right].first < arr[largest].first)
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


         // ��������
    //for(int i=0;i<n;i++){ printf("arr[%d]:",i); cout<<arr[i].first<<" "<<arr[i].second<<endl;}
    student* newFirst = nullptr;
    student* newLast = nullptr;
    
    for (int i=0;i<n;i++) {
        string id=arr[i].second;
        student* foundStudent = findId(id);
        if (foundStudent) {
            if (!newFirst) {
                newFirst = foundStudent;
                newLast = foundStudent;
            } else {
                newLast->changetmp(foundStudent);
                newLast = foundStudent;
            }
        }
        else cout<<"ERROR!:�?题位于HeapStudents.cpp-heapSortDS"<<endl;
        //cout<<"la";���Դ���
    }

    fix_tmp(head);
    //cout<<"la";

    if (newLast) {
        newLast->changenext(nullptr);
    }
    
    stuL.changefirstlast(newFirst,newLast);
    clear_tmp(newFirst);
    //cout<<"la";
}
