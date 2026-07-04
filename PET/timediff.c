#include <stdio.h>

int main()
{
    int h1,h2,m1,m2,s1,s2;
    int t1,t2;
    int diff,dh,dm,ds;

    printf("Enter the start time in (hh:mm:ss)->\n");
    scanf("%d:%d:%d",&h1,&m1,&s1);
    printf("Enter the end time in (hh:mm:ss)->\n");
    scanf("%d:%d:%d",&h2,&m2,&s2);
    
    t1 = h1*3600+m1*60+s1;
    t2 = h2*3600+m2*60+s2;
    
    if(t2 < t1)
    {
       t2 = t2+24* 3600;
    }

    diff = t2-t1;

    dh = diff/3600;
    dm = (diff%3600)/60;
    ds = diff%60;
    
    printf("Time different -> %d:%d:%d\n",dh,dm,ds);

   return 0;
}