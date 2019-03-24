 #include <stdio.h>
 void foo(void);
  int main(void)
   {
       printf("Ths current function is %s\n", __FUNCTION__);
       foo();
       return 0;
    }
 
 void foo (void)
   {
       printf("Ths current function is %s\n", __FUNCTION__);
    }
