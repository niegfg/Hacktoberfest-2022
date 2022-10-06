#include<iostream>
using namespace std;

class Solution{
    public:
    int Lomuto(int ar[],int l,int h)
{
    int j;
    int pivot=ar[h];
    int i=l-1;                           //         i             p
    for(j=l;j<=h-1;j++)                   //      10,9,35,1,3,2,18,23
    {                                           //     j          high
        if(ar[j]<=pivot)
        {
            i++;
            swap(&ar[i],&ar[j]);
        }                  
    }    
    swap(&ar[i+1],&ar[h]);    
    return i+1;                       
}

void Quicksort(int ar[],int l,int r)
{
    int s;
    if(l<r)
    {
        s=Lomuto(ar,l,r);
        Quicksort(ar,l,s-1);
        Quicksort(ar,s+1,r);
    }
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
};

int main()
{
    int arr[]={10,9,4,1,3,2,18,23,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    Solution s;
    cout<<"BEFORE SORTING\n";
    for(int i=0;i<8;i++)
    {
        cout<<arr[i]<<'\t';
    }
    cout<<endl;
    s.Quicksort(arr,0,n-1);
    cout<<"SORTED ARRAY IS \n";
    for(int i=0;i<8;i++)
    {
        cout<<arr[i]<<'\t';
    }
    return 0;
}