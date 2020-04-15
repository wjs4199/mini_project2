#include <stdio.h>
#include "product.h"
#include "manager.h"

//내용 추가하는 함수
int creatProduct(Product *p){
printf("제품명은? ");
getchar();
scanf("%[^\n]",p->name);
getchar();
printf("제품의 중량은? ");
scanf("%d",&p->weight);
printf("제품 가격은? ");
scanf("%d",&p->price);
printf("제품의 표준가격은? ");
scanf("%d",&p->avg_price);
printf("별점수는? ");
scanf("%d",&p->star);
printf("후기 개수는? ");
scanf("%d",&p->review);
printf("=>추가됨!\n");
return 1;
}
//리스트를 출력할때 한줄의 내용
void readProduct(Product* p){
  s="★ ";
  printf(" %s %dg \n", p->name, p->weight);
  printf("%d원\n",p->price);
  printf("(10g당 %d원)\n",p->avg_price);
  for(int i=0;i<p->star;i++)
	printf("%s",s);
  printf("(%d개)",p->review);
  printf("\n");
    
}
//내용을 업데이트 하는 함수
int updateProduct(Product* p){
printf("제품명은? ");
getchar();
scanf("%[^\n]",p->name);
getchar();
printf("제품의 중량은? ");
scanf("%d",&p->weight);
printf("제품 가격은? ");
scanf("%d",&p->price);
printf("제품의 표준가격은? ");
scanf("%d",&p->avg_price);
printf("별점수는? ");
scanf("%d",&p->star);
printf("후기 개수는? ");
scanf("%d",&p->review);
printf("=> 수정됨!\n");
return 1;
}
//내용을 삭제하는 함수
int deleteProduct(Product* p){
  p->weight= -1;
  p->price= -1;
  p->avg_price= -1;
  p->star= -1;
  p->review= -1;
  printf("=> 삭제됨!\n");
  return 0;
}
//파일 데이터 저장하는 함수
void saveData(Product* p, int count){
  fp= fopen("product.txt","wt");
  for(int i=0;i<count;i++){
    if(p[i].weight !=-1)
      fprintf(fp,"%s %d %d %d %d %d \n",p[i].name, p[i].weight,p[i].price, p[i].avg_price, p[i].star,p[i].review); 
  }
  fclose(fp);
  printf("저장됨!");
}
//파일 데이터 불러오는 함수
int loadData(Product p[]){
  i=0;j=0;k=0;
  count=0; check=0;
  fp= fopen("product.txt","rt");
  if(fp==NULL){
    printf("=> 파일없음\n");
    return 0;
  }
  while(1){
    temp=fgetc(fp);
    if(temp>='0' && temp<='9') check=1;
    if(check==1){
      if(temp==32||temp=='\n' || temp==EOF){
        p[count].name[i]='\0';
        str[j]='\0';
        store[k++]=atoi(str);
        if(temp==32){
          j=0;
        }
        if(temp=='\n'){
          p[count].weight=store[0];
          p[count].price=store[1];
          p[count].avg_price=store[2];
          p[count].star=store[3];
          p[count].review=store[4];
          check=0;j=0;i=0;k=0;
          count++;
          continue;
        }
      }
      else {
        str[j++]=temp;
      }
    }
    else {
      p[count].name[i++]=temp;
    }
    if(feof(fp)){
      p[count].weight=-1;
      break;
    }
  }
  fclose(fp);
  printf("=> 로딩 성공!\n");
  return count;
}
