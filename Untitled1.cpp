#include<bits/stdc++.h>

using namespace std;
const int MAX=1e5;

int n,arr[MAX];
int posme,posma;

int mayor(int pos){
	int ma=-1000000000;
	for (int i=1;i<=pos;i++){
		if (ma<arr[i]){
			posma=i;
			ma=arr[i];
		}
	}
	return ma;
}

int menor(int pos){
	int mi=1000000000;
	for (int i=1;i<=pos;i++){
		if (mi>arr[i]){
			posme=i;
			mi=arr[i];
		}
	}
	return mi;
}

int suma(int ini,int fin){
	int suma=0;
	for (int i=ini;i<=fin;i++){
		suma+=arr[i];
	}
	return suma;
}

int main(){
	
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>arr[i];
	}		
	cout<<mayor(n)<<endl<<menor(n)<<endl;
	int i,j;
	i=min(posma,posme);
	j=max(posma,posme);
	cout<<suma(i,j)<<endl;
	
	
	return 0;
}