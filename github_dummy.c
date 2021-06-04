#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define pi 3.141592
float con(float angle)
{
    float res=(180/pi)*angle;
    return res;

}
int main()
{
    float l1=1.0,l2=1.0,theta_1a,theta_2a,theta_1c,theta_2c,x,y;
    //theta_1a,theta_2a correspond to the set of angles in which the servo moves anti clockwise
    //the other set theta_1c,theta_2c correspond to the set of angles in which the servo moves anti clockwise
    //HERE theta_2c IS A MISNOMER IN THIS CASE ALSO 1ST SERVO IS GOING TO MOVE ANTI CLOCLWISE

   
    scanf("%f%f",&x,&y);
    float k=((x*x + y*y -(l1*l1 + l2*l2))/(2*l1*l2));//k will be parameter for acos fn
    if(x>=0 && y>=0)
    {
        theta_2a= acos(k);
        theta_2c=acos(k);

        theta_1a=atan(y/x)-atan((l2*sin(theta_2a))/(l1+l2*cos(theta_2a)));//this is gen formula.After this we will be using the fact that l1=l2
        theta_1c=atan(y/x)+(theta_2c/2);

       
    }
    else if(x<0 && y>=0)
    {
        theta_2a=acos(k);
        theta_1a=pi-fabs(atan(y/x))-(theta_2a/2);

        theta_2c=acos(k);
        theta_1c=pi+atan(y/x)+(theta_2c/2);
        

       

    }
    else if(x<=0 && y<0)
    {
        theta_2a=pi-(acos(-k));
        theta_1a=(pi)+atan(y/x)-(theta_2a/2);


        theta_2c=acos(k);
        theta_1c=pi+atan(y/x)+(theta_2c/2);
        
    }
    else if(x>0 && y<0)
    {
        theta_2a=pi-acos(-k);
        theta_1a=(2*pi)+atan(y/x)-(theta_2a/2);

        theta_2c=acos(k);
        theta_1c=(2*pi)+atan(y/x)+(theta_2c/2);

        

    }
    theta_1a=con(theta_1a);
    theta_2a=con(theta_2a);
    theta_1c=con(theta_1c);
    theta_2c=con(theta_2c);
    if(theta_1a >=0 && theta_1a<=360 && theta_2a>=0 && theta_2a<=360 )
    printf("anti the value of theta 1 is %.3f and the value of theta 2 is %.3f \n",theta_1a,theta_2a);
    else
    {
        printf("Cant be rrached");

    }
    if(theta_1c >=0 && theta_1c<=360 && theta_2c>=0 && theta_2c<=360 )
    {


    printf("clock wise the value of theta 1 c is %.3f and the value of theta 2c is %.3f \n",theta_1c,theta_2c);

        }


     else
    {
        printf("Cant be rrached");

    }
    
    
    
    
    return 0;

}