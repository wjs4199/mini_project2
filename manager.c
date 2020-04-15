#include <stdio.h>
#include "product.h"
#include "manager.h"

//readProduct함수 이용해서 리스트출력
void listProduct(Product *p, int count){
    printf("==========제품정보==========\n");
    for(i=0;i<count;i++){
      if(p[i].weight ==-1) continue;
      printf("%2d",i+1);
      readProduct(&p[i]);
      printf("\n");
    }

}

