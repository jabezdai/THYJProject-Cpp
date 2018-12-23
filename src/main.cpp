#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
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
void color(short);
struct booktype book[booknumber]; 
int main() {
	int choice;
	FILE *fp;
	int n[booknumber];
	if(login()==0){
		return 0;
	}
	system("pause");
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
		prin(n,booknumber);
	}
    return 0;
}
int login(){
	return 1;
}
void prin(int *n,int len){//傳要顯示的結構的index還有要顯示幾個進來 
	if(len!=0)
		printf("name\tauthor\tprice\tE-book\ttype\n");
	for(int i=0;i<len;i++){
		printf("%s\t%s\t%d\t",book[n[i]].name,book[n[i]].author,book[n[i]].price);
		if(book[n[i]].fileexist==1){
			printf("O\t");
		}
		else{
			printf("X\t");
		}
		printf("%s\n",book[n[i]].type);
	}
}
void search(){
	int choice,k=0,st=0,match,th=0,tw=0;
	char *del = ",";
	char *pch,*pchsea,*pchsea2,*pchsea3,*pchsea4,*pchsea5,*pchsea6;
	char seatype[20][3],s[100],temp[20],searchtemp[20];
	int threematch[booknumber],twomatch[booknumber],n[booknumber];
	FILE *fp;
	printf("\n\n1.Search by book name\n2.Search by author\n3.Search by type\n4.End\n");
	scanf("%d",&choice);
	printf("if choose ");
	color(11);
	printf("3.Search by type ");
	color(7);
	printf("please use ',' to separated input\n");
	scanf("%s",&s);
	switch(choice){
		case 1:
			for(int i=0;i<booknumber;i++){
				if(strcmp(s,book[i].name)==0){
					n[k++]=i;
				}
			}
			if(k==0){
				printf("NO match\n");
				break;
			}
			prin(n,k);
			printf("\n");
			break;
		case 2:
			for(int i=0;i<booknumber;i++){
				if(strcmp(s,book[i].author)==0){
					n[k++]=i;
				}
			}
			if(k==0){
				printf("NO match\n\n");
				break;
			}
			prin(n,k);
			printf("\n");
			break;
		case 3:
			strcpy(searchtemp,s);
			pchsea=strtok(searchtemp,del);
			pchsea2=strtok(NULL,del);
			pchsea3=strtok(NULL,del);
			pchsea4=strtok(NULL,del);
			pchsea5=strtok(NULL,del);
			pchsea6=strtok(NULL,del);
			for(int i=0;i<booknumber;i++){
				strcpy(temp,book[i].type);
				match=0;
				pch=strtok(temp,del);
				while (pch != NULL){
					if(strcmp(pch,pchsea)==0){
						match+=1;
					}
					else if((pchsea2!=NULL)&&(strcmp(pch,pchsea2)==0)){
						match+=1;
					}
					else if(pchsea3!=NULL&&(strcmp(pch,pchsea3)==0)){
						match+=1;
					}
					else if(pchsea4!=NULL&&(strcmp(pch,pchsea4)==0)){
						match+=1;
					}
					else if(pchsea5!=NULL&&(strcmp(pch,pchsea5)==0)){
						match+=1;
					}
					else if(pchsea6!=NULL&&(strcmp(pch,pchsea6)==0)){
						match+=1;
					}
				    pch = strtok(NULL, del);
				}
				if(match==3){
					threematch[th++]=i;
				}
				else if(match==2){
					twomatch[tw++]=i;
				}
				else if(match==1){
					n[k++]=i;
				}
			}
			prin(threematch,th);
			prin(twomatch,tw);
			prin(n,k);
			break;
		default:
			break;
	}
	fp=fopen("SearchRecord.txt","a");
	fprintf(fp,"%s\n",s);
	fclose(fp);
}
void color(short textColor){      
	if(textColor>=0 && textColor<=15)
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);
    else
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
