//min heap
#include<stdio.h>

//dimulai dri 1
//left = 2*index
//right = 2*index+1
//parent = pos/2

//dimulai dri 0
//left = 2*index+1
//right = 2*index+2
//parent = pos/2


int size=0;


void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void heapify(int arr[],int size,int i){
	
	//data>1
	if(size>1){
		int small=i;
		int l=2*i+1;
		int r=2*i+2;
		
		if(l < size && arr[l] < arr[small]) small=l;
		
		if(r < size && arr[r] < arr[small]) small=r;
		
		if(small!=i){
			swap(&arr[i],&arr[small]);
			heapify(arr,size,small);
		}
		
		
		
	}
}

void insert(int arr[],int value){
	//data 0
	if(size==0){
		arr[0]=value;
		size++;
	}
	
	//data tidak kosong
	else{
		arr[size]=value;
		size++;
		
		//heapify
		for(int i=size/2;i>=0;i--){
			heapify(arr,size,i);
		}
	}
	
	
}

void removeSmallest(int arr[]){
	//swap index pertma -> akhir
	swap(&arr[0],&arr[size-1]);
	
	//inisialisasi index akhir = -1
	arr[size-1]=-1;
	
	//kurangin size
	size--;
	
	//heapify
	for(int i=size/2;i>=0;i--){
		heapify(arr,size,i);
	}
	
	
}

void view(int arr[]){
	
	if(size/2==0){
		printf("Parents:%d \n",arr[0]);
	}
	
	else{
	for(int i=0;i<size/2;i++){
		printf("Parents:%d , Left:%d , Right:%d \n",arr[i],arr[2*i+1],arr[2*i+2]);
	}
		
	}
	
	
}

int main(){
	
	int arr[100];
	//-1 = kosong
	for(int i=0;i<100;i++) arr[i] = -1 ;
	
	insert(arr,30);
	insert(arr,40);
	insert(arr,50);
	insert(arr,15);
	insert(arr,20);
	insert(arr,10);
	insert(arr,5);
	
	view(arr);
	
	
	printf("\n\n\n");
	removeSmallest(arr);
	view(arr);
	
	printf("\n\n\n");
	removeSmallest(arr);
	view(arr);
	
	printf("\n\n\n");
	removeSmallest(arr);
	view(arr);
	
	printf("\n\n\n");
	removeSmallest(arr);
	view(arr);
	
	printf("\n\n\n");
	removeSmallest(arr);
	view(arr);
	
	printf("\n\n\n");
	removeSmallest(arr);
	view(arr);
	
	printf("\n\n\n");
	removeSmallest(arr);
	view(arr);
	
	getchar();
	return 0;
}






















//max heap
#include<stdio.h>

//dimulai dri 1
//left = 2*index
//right = 2*index+1
//parent = pos/2

//dimulai dri 0
//left = 2*index+1
//right = 2*index+2
//parent = pos/2

//int size=0;
//
//void swap(int *a,int *b){
//	int temp=*a;
//	*a=*b;
//	*b=temp;
//}
//
//void heapify(int arr[],int size,int i){
//	
//	//data > 1
//	if(size !=1){
//		int la=i;
//		int le=2*i+1;
//		int ri=2*i+2;
//		
//		
//		if(le<size && arr[le]>arr[la]) la=le;
//		
//		if(ri<size && arr[ri]>arr[la]) la=ri;
//		
//		if(la!=i) {
//			swap(&arr[i],&arr[la]);
//			heapify(arr,size,la);	
//		}
//		
//	}
//}
//
//void removeLargest(int arr[]){
//	//swap index pertma -> terakhir
//	swap(&arr[0],&arr[size-1]);
//	
//	//inisialisasi index trakhir = -1
//	arr[size-1]=-1;
//	
//	//kurangin size
//	size--;
//	
//	//heapify
//	for(int i=size/2;i>=0;i--){
//			heapify(arr,size,i);
//		}
//}
//
//void insert(int arr[],int value){
//	
//	
//	//tidak ada data
//	if(size==0){
//		arr[0]=value;
//		size++;
//	}
//	//ada data
//	else{
//		arr[size]=value;
//		size++;
//		
//		//heapify
//		for(int i=size/2;i>=0;i--){
//			heapify(arr,size,i);
//		}
//		
//	}
//	
//}
//
//void view(int arr[]){
//	
//	if(size/2==0){
//		printf("parent = %d\n",arr[0]);
//	}
//	
//	else{
//		for(int i=0;i<size/2;i++){
//		printf("parent = %d , left = %d , right = %d\n",arr[i],arr[2*i+1],arr[2*i+2]);
//		}	
//	}
//	
//	
//}
//
//
//int main(){
//	
//	int arr[100];
//	//-1 = kosong
//	for(int i=0;i<100;i++) arr[i] = -1 ;
//	
//	insert(arr,30);
//	insert(arr,40);
//	insert(arr,50);
//	insert(arr,15);
//	insert(arr,20);
//	insert(arr,10);
//	insert(arr,5);
//	
//	view(arr);
//	
//	
//	printf("\n\n\n");
//	removeLargest(arr);
//	view(arr);
//	
//	printf("\n\n\n");
//	removeLargest(arr);
//	view(arr);
//	
//	printf("\n\n\n");
//	removeLargest(arr);
//	view(arr);
//	
//	printf("\n\n\n");
//	removeLargest(arr);
//	view(arr);
//	
//	printf("\n\n\n");
//	removeLargest(arr);
//	view(arr);
//	
//	printf("\n\n\n");
//	removeLargest(arr);
//	view(arr);
//	
//	printf("\n\n\n");
//	removeLargest(arr);
//	view(arr);
//	
//
//	
//	getchar();
//	return 0;
//}
