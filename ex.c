#include <stdio.h>    

union employee
{
  double id;
  char name[32];  
};

int main()
{
  union employee e1;      
  printf("%d %d %d", sizeof(e1.id), sizeof(e1.name), sizeof(e1));
  return(0);
}
