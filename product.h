#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//구조체 정의
typedef struct{
char name[50];//제품명
int weight;//중량
int price;//가격
int avg_price;//표준가격
int star;//평점
int review;//후기 개수
}Product;

FILE* fp;//데이터를 저장하고 다시 불러올 파일스트림 형성

//int loadData(Product p[])
int i, j, k;//반복문 위한 변수
int count;//p의 index번호
int check;//check=0이면 name에 제품명 저장, 1이면 숫자를 저장하기 시작
char temp;//파일에서 문자를 하나씩 읽어서 임시저장
char str[10];//제품명 이후 나오는 문자들을 빈칸직전까지 문자열로 저장
int store[5];//빈칸을 기준으로 atoi(str)한 값을 순차적으로 저장

//void readProduct(Product* p)
char* s;//평점 표시

//int selectDataNo(Product *p, int count)+void searchFunction(Product*p,int count)

//int selectMenu()
int menu;//사용자가 입력할 메뉴번호

//void searchName(Product*p, int count)
int scount; //데이터의 존재유무 가리는 변수
char search[20]; //사용자가 검색할 제품명

//void searchPrice(Product*p,int count)
int search1, search2;//사용자가 원하는 최저가격대/ 원하는 최고가격대

//void searchStar(Product*p,int count)
int starnum;//사용자가 원하는ㄴ 평점
//void searchFunction(Product*p,int count)
int searchno;
/*Prototype*/
//파일 데이터 저장하는 함수
void saveData(Product* p, int count);
//파일 데이터 불러오는 함수
int loadData(Product p[]);
//내용 추가하는 함수
int creatProduct(Product *p);
//리스트를 출력할때 데이터 1개의 내용
void readProduct(Product* p);
//내용을 업데이트 하는 함수
int updateProduct(Product *p);
//내용을 삭제하는 함수
int deleteProduct(Product* p);
//원하는 번호를 입력하는 함수
int selectDataNo(Product *p, int count);
//원하는 이름의 제품을 찾아주는 함수
void searchName(Product*p, int count);
//원하는 가격대의 제품을 찾아주는 함수
void searchPrice(Product*p,int count);
//원하는 평점 이상의 제품을 찾아주는 함수
void searchStar(Product*p,int count);
//검색 기능을 총괄하는 함수
void searchFunction(Product*p,int count);
