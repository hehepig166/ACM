#include <cstdio>
#include <ctime>
#include <cstdlib>
#define Ran(a,b) (1ll*rand()*rand()*rand()%(b-a+1)+a)  //a~b µÄËæ»úÊı

int main(){
	//freopen("1.txt","w",stdout);
    srand(time(0));
    
    printf("1\n10 7\n");
    for (int i=1; i<=10; i++) printf("%d ",rand()%10+1);
    puts("");
    for (int i=1; i<=10; i++) printf("%d ",rand()%10+1);
    puts("");
    for (int i=1; i<=20; i++) printf("%d ",rand()%10+1);
    
    
    /*
    puts("10");
    for (int i=1; i<=1000; i++) {
    	printf("%d %d\n",Ran(1,(Ran(1,10)>7 ? 1000000001 : i*1000)),Ran(1,(Ran(1,10)>7 ? 1000000001 : i*1000)));
	}
    */
    /*
    int n=20,m=10;
    printf("%d %d\n",n,m);
    for (int i=1,t1,t2; i<=m; i++) {
    	t1=Ran(1,n/2);
    	t2=Ran(n/2+1,n);
    	printf("%d %d %d\n",t1,t2,Ran(1000,1000000000));
	}
	*/
    /*
    printf("1\n");
    int d=Ran(1,100),k=Ran(1,d);
    printf("%d %d\n",d,k);
    */
    /*
    int n=Ran(3,10000);
    for (int i=1; i<=n; i++)
    	printf("%d ",Ran(1,10000));
    */
    /*
    printf("2000 2000\n");
    for (int i=1; i<=4000; i++)
    	printf("%d %d\n",Ran(100000,1000000),Ran(10000,1000000));
    */
    //int n=Ran(2,1000000);
    //printf("%d %d\n",n,Ran(0,n));
    //printf("%d 19260817\n",Ran(100000000,10000000000));
    //for (int i=1; i<=5; i++) printf("%c",Ran('a','d'));
    /*
    for (int i=1; i<=5; i++)
    {
    	printf("%d%d 19260817\n",Ran(100,999),Ran(1000000,9999999));
	}
	for (int i=1; i<=45; i++)
    {
    	printf("%d 19260817\n",Ran(100000000,999999999));
	}
	*/
}

