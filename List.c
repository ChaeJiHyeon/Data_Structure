#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define List_LEN 100

typedef int LData; //자료 저장할 대상의 자료형

typedef struct __ArrayList{
    LData arr[List_LEN];
    int numOfData;  //데이터 수
    int curPosition;    //현재 참조하는 데이터 위치
} ArrayList;

typedef ArrayList List;

void ListInit(List* plist){
    (plist->numOfData)=0;   //데이터 수 초기화, 포인터 연산(->)
    (plist->curPosition)=-1;    //-1은 아무런 위치도 참조하지 않음을 의미
}

void ListInsert(List* plist, LData data){
        if(plist->numOfData > List_LEN){
            puts("can't saved\n");
            return;
        }   //배열 꽉참

        plist->arr[plist->numOfData] = data;
        (plist->numOfData)++;
}

int LFirst(List* plist, LData* pdata){
    if(plist->numOfData==0) return FALSE;

    (plist->curPosition) = 0;
    *pdata = plist->arr[0];
    return TRUE;
}

int LNext(List* plist, LData* pdata){
    if(plist->curPosition >= (plist->numOfData)-1) return FALSE;

    (plist->curPosition)++;
    *pdata = plist -> arr[plist->curPosition];
    return TRUE;
}

LData LRemove(List* plist){
    int rpos = plist-> curPosition;
    int num = plist->numOfData;
    int i;
    LData rdata = (plist->arr[i+1]);

    for(i=rpos;i<num-1;i++){
        (plist->arr[i]) = (plist->arr[i+1]);
    }

    (plist->numOfData)--;
    (plist->curPosition)--; //LNext실행시 curPosition을 증가 시킨 후 그 위치값을 반환하는데 curPosition감소시키지 않으면 삭제 시킨 위치의 데이터는 참조 되지 않음
    return rdata;
}

int LCount(List* plist){
    return plist->numOfData;
}

int main(void){
    int data;
    List list;  //리스트 생성
    ListInit(&list);    //초기화 필수

    ListInsert(&list, 11);
    ListInsert(&list, 11);
    ListInsert(&list, 13);
    ListInsert(&list, 20);
    ListInsert(&list, 15);

    printf("now data count:%d \n", LCount(&list));

    if(LFirst(&list, &data)){   //첫번째 데이터 조회
        printf("%d", data);

        while(LNext(&list, &data))  printf("%d\n", data);   //두번째 이후 데이터 조회
    }

    if(LFirst(&list, &data)){
        if(data == 20){
            LRemove(&list);
        }

        while(LNext(&list, &data)){
            if(data == 20)
                LRemove(&list);
        }
    }
}
