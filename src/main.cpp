#include<stdio.h>
#include<string.h>
#define booknumber 20
struct booktype{
	char name[10];
	char author[10];
	int price;
	int fileexist;
	char type[50];
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
	//bookstore.txt "book name" author price "is E-book exist?" type 
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
	printf("1.Search\n2.Add to shopping cart\n3.Checkout\n4.End\n");
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
		printf("1.Search\n2.Add to shopping cart\n3.Checkout\n4.End\n");
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
			printf("[E-book exist] ");
		}
		else{
			printf("[E-book not exist] ");
		}
		printf("%s\n\n",book[n[i]].type);	
	}
}
void search(){
	int n[booknumber],*getsearch;
	char s[10];
	int choice;
	int k=0;
	printf("1.Search by book name\n2.Search by author\n3.Search by type\n4.End\n");
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

