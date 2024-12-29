#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
float find_mean(int arr[],int n)
{
	float mean,sum=0;
    for(int i=0;i<n;i++)
    {
    	sum+=arr[i];
	}
    mean=sum/n;
    return mean;
}
float find_b(int arrX[],int arrY[],int n,float x,float y)
{
	float sum=0,add=0,deviation;
	for(int i=0;i<n;i++)
	{
		add+=(arrX[i]-x)*(arrY[i]-y);
		sum+=(arrX[i]-x)*(arrX[i]-x);
	}
	deviation=add/sum;
	return deviation;
}
int main()
{
	int n,arrX[100],arrY[100],z=0;
	float x,y,a,b,X,Y;
	cout<<"Enter the final value to calculate the predicted values: ";
	cin>>X;
	cout <<"Enter the size of array X and Y: ";
	cin>>n;
	cout<<"Enter the elements of X: ";
	for(int i=0;i<n;i++)
	{cin>>arrX[i];}
	cout<<"Enter the elements of Y: ";
	for(int i=0;i<n;i++)
	{cin>>arrY[i];}
   x=find_mean(arrX,n);
   y=find_mean(arrY,n);
   cout<<"Mean of X: "<<x<<endl;
   cout<<"Mean of Y: "<<y<<endl;
   b=find_b(arrX,arrY,n,x,y);
   a=y-(b*x);
   cout<<"The value of B is: "<<b<<endl;
   cout<<"The value of A is: "<<a<<endl;
   Y=a+(b*X);
   cout<<"The predicted value is :"<<Y<<endl;
}
