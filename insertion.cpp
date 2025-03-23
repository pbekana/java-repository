#include<iostream>
using namespace std;
void setdata(int num[]){
for(int i = 0;i<5;i++){
  cout<<" enter data"<<endl;
cin>>num[i];
}

}
void printdata(int num[]){
    cout<<"\n the number is ;";
   for(int i = 0;i<5;i++){
   cout<<num[i]<<"\t";
}
}

void insertion_sort(int num[]){
int temp;
int j;
for(int i = 0;i<5-1;i++){
    temp = num[i];
    j = i-1;
    while( j>-1 && num[j] > temp){
       num[j+1] = num[j];
        j--;
    }
    num[j+1] = temp;
}
printdata(num);
}
int Linear_Search(int list[],int n, int key){
int i=0;
int loc= -1;
do{
if(key==list[i])
 loc=i;
else
 i++;
}while(loc==-1&&i<n);
if(loc>=0)
 cout<<"item is found and searching is successful";
return loc;
printdata(list);
}
int Binary_Search(int list[],int k){
int left=0,n;
int right=n-1;
int found=0;
do{
int mid=(left+right)/2;
if(int key == list[mid])
 found=1;
else{
 if(key<list[mid])
 right=mid-1;
 else
left=mid+1;
}
}while(found==0&&left<right);
if(found==0)
 index=-1;
else
 index=mid;
return index;
}
int main(){
int num[5];
setdata(num);
printdata(num);
//insertion_sort(num);
//Linear_Search(num,5,-1);
Binary_Search(num);
return 0;
}
