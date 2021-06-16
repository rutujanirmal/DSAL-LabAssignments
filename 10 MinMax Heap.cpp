/*
Lab Assignemt 10
Read the marks obtained by students of second year in an 
online examination of particular subject. 
Find out maximum and minimum marks obtained in that subject. 
Use heap data structure. 
Analyze the algorithm.
*/

#include<iostream>
using namespace std;
void maxHeapify(int heap[],int i,int n)
{
    int left=2*i;
    int right=(2*i)+1;
    int largest=i;
     
    if(left<=n && heap[i]<heap[left])
        largest=left;
    if(right<=n && heap[largest]<heap[right])
        largest=right;
         
        if(largest !=i)
        {
            int temp=heap[largest];
            heap[largest]=heap[i];
            heap[i]=temp;
            maxHeapify(heap,largest,n);
        }
}
void buildHeap(int heap[],int n)
{
            for(int i=n/2;i>=1;i--)
            maxHeapify(heap,i,n);
}
int main()
{
    int n,i;
    cout<<"Enter Number of Students :: ";
    cin>>n;
    int heap[n+1];
    cout<<"Enter Marks :: \n";
    for(int i=1;i<=n;i++)
    cin>>heap[i];
     
    buildHeap(heap,n);
    int heapSize=n;
    for(i=n;i>=2;i--)
    {  
        int temp=heap[1];
        heap[1]=heap[i];
        heap[i]=temp;
        --heapSize;
        maxHeapify(heap,1,heapSize);
    }
    cout<<"\nAfter Sorting :: ";
    for(i=1;i<=n;i++)
    cout<<heap[i]<<" ";
    cout<<"\n\n---------------------------";
    cout<<"\nMAXIMUM MARKS ::"<<heap[n]<<endl;
    cout<<"MINIMUM MARKS ::"<<heap[1]<<endl;
    cout<<"---------------------------";
    return 0;
}
