#include<stdio.h>
#include<string.h>
#define booknumber 20
struct booktype{
	char name[10];
	char author[10];
	int price;
	int fileexist;
	char type[20];
	booktype();
};
booktype::booktype(){
	name[0]='\0';
	price=0;
	fileexist=0;
	type[0]='\0';
}
int login();
void prin(int*,int);
void search();
struct booktype book[booknumber]; 
int main() {
	int choice;
	FILE *fp;
	int n[booknumber];
	if(login()==0){
		return 0;
	}
	//bookstore.txt 書名 作者 價格 電子書是否存在 類型 
	if((fp=fopen("bookstore.txt","r"))!=NULL){
		for(int k=0;k<booknumber;k++){
			fscanf(fp,"%s %s %d %d %s ",&book[k].name,&book[k].author,&book[k].price,&book[k].fileexist,&book[k].type);
			n[k]=k;	
		}
	}
	else{
		printf("ERROR!\nbookstore.txt not exist");
		return 0;
	}
	fclose(fp);
	prin(n,booknumber);
	printf("1.搜尋\n2.加入購物車\n3.結帳\n4.結束\n");
	scanf("%d",&choice);
	while(choice!=4){
		prin(n,booknumber);
		switch(choice){
			case 1:
				search();
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				break;
		}
		printf("1.搜尋\n2.加入購物車\n3.結帳\n4.結束\n");
		scanf("%d",&choice);
	}
    return 0;
}
int login(){
	return 1;
}
void prin(int *n,int len){
	for(int i=0;i<len;i++){
		printf("%s %s %d ",book[n[i]].name,book[n[i]].author,book[n[i]].price);
		if(book[n[i]].fileexist==1){
			printf("有電子書 ");
		}
		else{
			printf("無電子書 ");
		}
		printf("%s\n",book[n[i]].type);	
	}
}
void search(){
	int n[booknumber],*getsearch;
	char s[10];
	int choice;
	int k=0;
	printf("1.以書名搜尋\n2.以作者搜尋\n3.以類型搜尋\n4.結束\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			scanf("%s",&s);
			for(int i=0;i<booknumber;i++){
				if(strcmp(s,book[i].name)==0){
					n[k++]=i;
				}
			}
			prin(n,k);
			printf("\n");
			break;
		case 2:
			scanf("%s",&s);
			for(int i=0;i<booknumber;i++){
				if(strcmp(s,book[i].author)==0){
					n[k++]=i;
				}
			}
			prin(n,k);
			printf("\n");
			break;
		case 3:
			scanf("%s",&s);
			break;
		default:
			break;
	}
}
