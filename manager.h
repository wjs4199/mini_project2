#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int curcount;

// main에서 selectDataNo(p, curcount)호출시에 return값을 저>장하는 변수
int num;
//main 함수의  else if (menu == 4)에서 정말로 삭제할지 말지 대답을 받는 변수
int deleteok;



/*함수들 */
//readProduct함수 이용해서 리스트출력
void listProduct(Product* p, int count);

