#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);

    int temp=n;
    int count =0;
    while(temp>0)
    {
        count++; // oru oru veriyabel eduthu count pannikirom 
        temp=temp/10;// aprom tha delete pannidtorm 
    }

    temp=n; // re asing panrom bcz mela nama dlelte pannidormm 
    
    int sum=0;
    while(temp>0)
    {
        int rem = temp%10;
       int  power =1;// again power 1 la irunthu start aganum athuku namba use panrom apo tha 4 time antha kudukura input time multiple panna mudium 
        for(int i=0;i<count;i++)
        {
             power= power *rem; // cout time ku mutoilole panrom 
        }

         sum = sum +power; // ahta oru time sum la stroe oannrom  add pannrom 
         temp=temp/10;
    }

    printf("%d\n",sum);
}