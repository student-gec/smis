#include <iostream>
#include <cmath>
using namespace std;
void find_hmean(float arr[],float n)
{
float mean,sum=0;
 for(int i=0;i<n;i++)
 {
 float z= 1/arr[i];
 sum +=z;
}
 mean=n/sum;
cout<<"The Harmonic mean of the array is :"<<mean<<endl;
}
void find_gmean(float arr[],float n)
{
float gmean ,mean,sum=0;
 for(int i=0;i<n;i++)
 {
 float z= log(arr[i]);
 sum +=z;
}
 mean=sum/n;
 gmean=exp(mean);
cout<<"The Geopetric mean of the array is :"<<gmean<<endl;
}
int main()
{
float n,arr[100],a=2;
int b;
float GM,HM;
while(a<3)
{
 cout<<"Enter the choise: "<<endl;
 cout<<"1) Harmonic Mean"<<endl;
 cout<<"2) Geometric mean"<<endl;
 cout<<"3) exit"<<endl;
 cin>>b;

 switch(b)
 {
 case 1:
 cout <<"Enter the size of array: ";
cin>>n;
cout<<"Enter the elements: ";
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
 find_hmean(arr,n);
 break;
 case 2:
 cout <<"Enter the size of array: ";
cin>>n;
cout<<"Enter the elements: ";
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
 find_gmean(arr,n);
 break;
case 3:
a++;
break;
 default:
 cout<<"incorrect input.";
 break;
 }
}
}
