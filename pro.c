#include<stdio.h>
#include<math.h>
#define e 0.001
#define maxtermno 10

static int itr=0;
static int k;

struct term{
    float a;
    float p;
};
static struct term f[maxtermno];

double func(double x){
    double y=0;
    for(int i=0;i<=k;i++){
        y+=f[i].a*pow(x,f[i].p);
    }
    return y;
}

double func_display(){
    for(int i=0;i<k;i++){
        printf("+(%.3f(x)^%.2f)",f[i].a,f[i].p);
    }
    printf("=0\n");
}
int bisection(double a, double b){
    if(func(a)*func(b)>=0){
        printf("You have not assumed proper a and b\nenter interval\t");
        scanf("%f %f",&a,&b);
        double max=(a>b)?a:b;
        double min=a+b-max;
        bisection(min,max);
    }
    double c=a;
    while((b-a)>=e){
        itr++;
        c=(a+b)/2.0;
        printf("After %2d iteration c=%f\n",itr,(a+b)/2);
        if(func(c)==0){
            break;
        }
        else if(func(a)*func(c)<0){
            b=c;
        }
        else{
            a=c;
        }
    }
    printf("The value of the root after %d iterations is %lf",itr,c);
    return 1;
}

void input(){
    printf("Enter number of terms\t");
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        printf("ENter coeff and power of %dth term\t",i+1);
        scanf("%f %f",&f[i].a,&f[i].p);
    }
    func_display();
}

int main(){
    double a,b;
    input();
    printf("Enter interval\t");
    scanf("%lf %lf",&a,&b);
    double max=(a>b)?a:b;
    double min=a+b-max;
    bisection(min,max);
}
