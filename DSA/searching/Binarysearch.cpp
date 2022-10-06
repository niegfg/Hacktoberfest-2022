#include<iostream>
using namespace std;

//BINARY SEARCH CODE WITH 
int main()
{
    int n,ar[50],loc=-1,i,j,first,last,mid,item;
    cout<<"How many elements: ";   //enter no. of  elements here
    cin>>n;
    cout<<"Enter the elements: ";//enter elements here
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    //displays the entered elements by user
    cout<<"The elements are: \n";
    for(i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<"\n";

    //please enter element to be searched here
    cout<<"Enter the item to be searched: \n";
    cin>>item;

    //initialising first and last pointers
    first=0;
    last=n-1;

    //into the loop
    while(first<=last)
    {
        mid=(first+last)/2;
        if(item==ar[mid])
        {
            loc=mid;
            break;
        }
        if(item>ar[mid])
        {
            first=mid+1;
        }
        else
        {
            last=mid-1;
        }
    }

    //DISPLAYS ELEMENT IS FOUND OR NOT
        if(loc!=-1)
        {
            cout<<"The element is found at position "<<loc+1<<"\n";
        }
        else{
            cout<<"Error: 400 not found\n";
        }
    
}