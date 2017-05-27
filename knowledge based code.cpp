#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,i,j,N,tc,tcf,tt;
int *order(int t[],int ct[],int n)
{
	int st[n];
	static int or1[5];

	for(i=0;i<n;i++)
	{
		or1[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(ct[i]==t[j] && or1[i]==-1)
			{
				or1[i]=j;
			}
		}
	}
return (or1);
}

int *time(int arr[],int n,int tc)
{
	
	int a[n];
	int rr_c[n];
	int we_c[n];
	int *orr;
	static int final_c[5];
	for(i=0;i<n;i++)
	{
//		cout<<"time input variables for "<<i<<" "<<arr[i]<<endl;
		a[i]=arr[i];
	}
	sort(arr,arr+n);
	orr=order(arr,a,n);
	
	for(i=0;i<n;i++)
	{
//		cout<<"sorted time input variables for "<<i<<" "<<arr[i]<<endl;
		rr_c[i]=(100-(i*100)/n);
//	cout<<"time ranking for "<<i<<" "<<rr_c[i]<<endl;
		we_c[i]=tc*rr_c[i];
//	cout<<"time weighted ranking for "<<i<<" "<<we_c[i]<<endl;
	}
	for(i=0;i<n;i++)
	{
		final_c[i]=we_c[orr[i]];
//		cout<<"final time orignal order wieghted ranking for "<<i<<" "<<final_c[i]<<endl;
	}
	return (final_c);
	
	
}

int *cost(int arr[],int n,int tc)
{
	int a[n];
	int rr_c[n];
	int we_c[n];
	int *orr;
	static int final_c[5];
	for(i=0;i<n;i++)
	{
//			cout<<"cost input variables for "<<i<<" "<<arr[i]<<endl;
		a[i]=arr[i];
	}
	sort(arr,arr+n);
	orr=order(arr,a,n);
	
	for(i=0;i<n;i++)
	{
//	cout<<"sorted cost input variables for "<<i<<" "<<arr[i]<<endl;
		rr_c[i]=(100-(i/100)*n);
//	cout<<"cost ranking for "<<i<<" "<<rr_c[i]<<endl;
		we_c[i]=tc*rr_c[i];
//		cout<<"cost weighted ranking for "<<i<<" "<<we_c[i]<<endl;
	}
	for(i=0;i<n;i++)
	{
		final_c[i]=we_c[orr[i]];
//			cout<<"final time orignal order wieghted ranking for "<<i<<" "<<final_c[i]<<endl;
	}
	return (final_c);
	
	
}

int *comfort(int arr[],int n,int tc)
{
	int a[n];
	int rr_c[n];
	int we_c[n];
	int *orr;
	static int final_c[5];
	for(i=0;i<n;i++)
	{
//		cout<<"comfort input variables for "<<i<<" "<<arr[i]<<endl;
		a[i]=arr[i];
	}
	sort(arr,arr+n,greater<int>());
	
	orr=order(arr,a,n);
	
	for(i=0;i<n;i++)
	{
//		cout<<"sorted comfort input variables for "<<i<<" "<<arr[i]<<endl;
		rr_c[i]=(100-(i/100)*n);
//		cout<<"comfort ranking for "<<i<<" "<<rr_c[i]<<endl;
		we_c[i]=tc*rr_c[i];
//			cout<<"comfort weighted ranking for "<<i<<" "<<we_c[i]<<endl;
	}
	for(i=0;i<n;i++)
	{
		final_c[i]=we_c[orr[i]];
//		cout<<"final confort orignal order wieghted ranking for "<<i<<" "<<final_c[i]<<endl;
	}
	return (final_c);
	
}

int main()
{
	cout<<"\nEnter the input parameter for cost in range of 1 to 10 "<<endl;
	cin>>tc;
	cout<<"\nEnter the input parameter for comfort in range of 1 to 10 "<<endl;
	cin>>tcf;
	cout<<"\nEnter the input parameter for time in range of 1 to 10 "<<endl;
	cin>>tt;
	int cs[5];
	int cf[5]={9,6,8,9,5};
	int tm[5];
	
	cout<<"\nEnter the time expected in order OLA, Auto, Car, Metro, Bus "<<endl;
	for(i=0;i<5;i++)
	cin>>tm[i];
	cout<<"\nEnter the cost expected in order OLA, Auto, Car, Metro, Bus "<<endl;
	for(i=0;i<5;i++)
	cin>>cs[i];	
	cout<<"\nThe comfort parameters after a survey are defined as "<<endl;
	cout<<"\nOLA :"<<cf[0];
	cout<<endl;	
	cout<<"\nAuto :"<<cf[1];
	cout<<endl;	
	cout<<"\nCar :"<<cf[2];
	
	cout<<endl;	
	cout<<"\nMetro :"<<cf[3];	
	cout<<endl;	
	cout<<"\nBus :"<<cf[4];
	cout<<endl;	
	int *final_cost;
	int *final_comfort;
	int *final_time;
	
	 n=5;
	final_cost=cost( cs, n, tc);
	final_comfort=comfort( cf, n, tcf);
	final_time=time( tm, n, tt);
	
	int fin[n];
	for(i=0;i<n;i++)
	{
		*(fin+i)=*(final_cost+i)+*(final_comfort+i)+*(final_time+i);
	}
	cout<<"\nFinal relative scores are "<<endl;
	cout<<"\nOLA :"<<*(fin+0);
	cout<<"\nAuto :"<<*(fin+1);
	cout<<"\nCar :"<<*(fin+2);
	cout<<"\nMetro :"<<*(fin+3);	
	cout<<"\nBus :"<<*(fin+4);
	return 0;
}
