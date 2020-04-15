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
//원하는 번호를 입력하는 함수
int selectDataNo(Product *p, int count){
  //int no;
  listProduct(p,count);
  printf("번호는 (취소 :0)? ");
  scanf("%d",&no);
  return no;
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
//이름 검색 기능하는 함수
void searchName(Product*p, int count){
  //int scount=0; //데이터의 존재유무 가리는 변수
  //char search[20]; //사용자가 검색할 제품명
  scount=0;
  printf("검색할 제품명? ");
  scanf("%s",search);
  for(int i=0;i<count;i++){
    if(p[i].weight !=-1)
      if(strstr(p[i].name, search)){
        printf("%2d ",i+1);
        readProduct(&p[i]);
        scount++;
      }
  }
  if(scount==0) printf("=> 검색된 데이터 없음!");
  printf("\n");
}
//원하는 가격대의 제품을 찾아주는 함수
void searchPrice(Product*p,int count){
  //int scount=0;//데이터의 존재유무 가리는 변수
  //int search1, search2;//사용자가 원하는 최저가격대/ 원하는 최고가격대
  scount=0;
  printf("원하는 가격한도?( ~ ) :");
  scanf("%d~%d",&search1,&search2);
  for(int i=0;i<count;i++){
    if(p[i].weight !=-1)
      if(p[i].price>=search1 && p[i].price<=search2){
        printf("%2d ",i+1);
        readProduct(&p[i]);
        scount++;
      }
  }
  if(scount==0) printf("=> 검색된 데이터 없음!");
  printf("\n");  
}
//원하는 평점 이상의 제품을 찾아주는 함수
void searchStar(Product*p,int count){
  scount=0;//데이터의 존재유무 가리는 변수
  //int search;//사용자가 원하는 평점
  printf("원하는 평점? (0~5)");
  scanf("%d",&starnum);
  for(int i=0;i<count;i++){
    if(p[i].weight !=-1)
      if(p[i].star>=starnum){
        printf("%2d ",i+1);
        readProduct(&p[i]);
        scount++;
      }
  }
  if(scount==0) printf("=> 검색된 데이터 없음!");
  printf("\n");  
}
//검색 기능을 실행하는 함수
void searchFunction(Product*p,int count){
  printf("=== 검색기능 ===\n1. 제품명 검색\n2. 제품가격대 검색\n3. 제품평점 검색\n0. 취소\n");
  no= selectDataNo(p, count);
  if(no==1) searchName(p,count);
  else if(no==2) searchPrice(p, count);
  else if(no==3) searchStar(p, count);
  else if(no==0) printf("취소되었습니다!");
}
