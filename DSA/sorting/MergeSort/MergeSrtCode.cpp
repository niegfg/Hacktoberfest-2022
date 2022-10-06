#include<bits/stdc++.h>//for including all header files
using namespace std;


const int N=1e5+10;//N=10^5+10
int a[N];

//l-- lower bound
//r-- upper bound
//mid-- middle index
void merge(int l, int r, int mid){
int l_sz =mid-l+1;//left array size
int L[l_sz+1];//declaring the left array

int r_sz=r-mid;//right array size
int R[r_sz+1];//declaring the right array

//Putting elements in the left array

for(int i=0;i<l_sz;i++){
    L[i]=a[i+l];
}

//Putting elements in the right array
for(int i=0;i<r_sz;i++){
    R[i]=a[i+mid+1];
}
L[l_sz]=R[r_sz]=INT_MAX;
/*Doing this because while comparing if one of the
array ends, we do not have to write extra loop for 
copying the remaining elements, adding  a large element
will normalize the comparison.*/

//The Merging algorithm
int l_i=0;
int r_i=0;
for(int i=l;i<=r;i++){
if(L[l_i]<=R[r_i]){
    a[i]=L[l_i];
    l_i++;
}else{
a[i]=R[r_i];
r_i++;
}
}
}

void mergeSrt(int l,int r){
    if(l==r)//i.e array has only one element
    return;
int mid=(l+r)/2;
mergeSrt(l,mid);//sorting left half
mergeSrt(mid+1,r);//sorting right half
merge(l,r,mid);//merging the two arrays
}

int main(){
int n;
cin>>n;
for(int i=0;i<n;i++){
cin>>a[i];
}
mergeSrt(0,n-1);//calling the merge sort function

for(int i=0;i<n;i++)
cout<<a[i]<<" ";

}
