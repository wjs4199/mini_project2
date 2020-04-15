#include <stdio.h>
#include "product.h"
#include "manager.h"

//원하는 번호를 입력하는 함수
int selectDataNo(Product *p, int count){
  int no;
  listProduct(p,count);
  printf("번호는 (취소 :0)? ");
  scanf("%d",&no);
  return no;
}

int selectMenu(){
//int menu;//사용자가 입력할 메뉴번호
printf("\n*** Loacker chocolate ***\n");
printf("1. 제품조회\n");
printf("2. 제품추가\n");
printf("3. 제품수정\n");
printf("4. 제품삭제\n");
printf("5. 제품저장\n");
printf("6. 제품검색\n");
printf("0. 종료\n\n");
printf("=> 원하는 메뉴는? ");
scanf("%d", &menu);
return menu;
}

//메인함수
int main()
{
Product p[100];// 구조체변수의 배열 p[100];// 구조체변수의 배열

count=0, curcount=0;

count=loadData(p);
curcount=count;
while (1){
	menu = selectMenu();

	if (menu == 0) break;
	if (menu == 1){
#ifdef DEBUG
	printf("Debug[main.c]: 1. 제품조회->listProduct()\n");
#endif		
		if(count>0) listProduct(p, curcount);
     		else printf("데이터가 없습니다.\n");
	}
	else if (menu == 2){
#ifdef DEBUG
        printf("Debug[main.c]: 2. 제품추가->creatProduct()\n");    
#endif

        	count+=creatProduct(&p[curcount++]);
	}
	else if (menu == 3){
#ifdef DEBUG
        printf("Debug[main.c]: 3. 제품수정->updateProduct()\n");
#endif
		num=selectDataNo(p, curcount);
      		if(num==0){
        		printf("취소됨!\n");
        		continue;
      		}	
        	updateProduct(&p[num-1]);
	}
	else if (menu == 4){
#ifdef DEBUG
        printf("Debug[main.c]: 4. 제품취소->deleteProduct()\n");
#endif
      		num=selectDataNo(p, curcount);
      		if(num==0){
        		printf("=> 취소됨!\n");
        		continue;
      		}
      		printf("정말로 삭제하시겠습니까 (삭제 :1)? ");
      		scanf("%d",&deleteok);
      		if(deleteok==1){
        		if(deleteProduct(&p[num-1])) count--;
      		}
	}
	else if(menu==5){
#ifdef DEBUG
	printf("Debug[main.c]: 5. 제품저장 ->saveData()\n ");
#endif
     		if(count==0) printf("데이터가 없습니다!\n");
      		else saveData(p,curcount);
        }
   	else if(menu==6){
#ifdef DEBUG
        printf("Debug[main.c]: 6. 제품검색 ->serachFunction()\n ");
#endif
      		searchFunction(p, curcount);
    	}
   }
   printf("종료됨!\n");
   return 0;
}
