//#include <cs50.h>
#include <stdio.h>

bool check(long long Number)
{
    long long sum=0;
    long long tmp1;

    for (tmp1=Number; tmp1; tmp1/=100)  //every other digit by 2 from second-to-last dig
    {
        int tmp=(tmp1/100/10) * 2;
        sum+=(tmp/10 + tmp%10);
    }

    for (tmp1=Number; tmp1; tmp1/=100)  //
    {
        int tmp=(tmp1/100%10);
        sum+=tmp;
    }

    if (sum%10!=0)
    {
        puts("INVALID");
        return 0;
    }

    long long AMEX=Number/10000000000000ll;
    long long MAST=Number/100000000000000ll;
    long long VISA1=Number/1000000000000ll,VISA2=Number/1000000000000000ll;

    if (AMEX==34 || AMEX==37)
    {
        puts("AMEX");
        return 1;
    }
    if (MAST>=51 && MAST<=55)
    {
        puts("MASTERCARD");
        return 1;
    }
    if (VISA1==4 || VISA2==4)
    {
        puts("VISA");
        return 1;
    }
    puts("INVALID");
    return 0;

}

int main()
{
    long long Number;

    while (1)
    {
    	scanf("%lld",&Number);
    	printf("%d\n",check(Number));
	}

    return 0;
}
