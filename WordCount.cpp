#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

//��ȡ������Ŀ 
int WordCount(char *file){
	int count=0;
	int flag=0;
	char ch[1000];
	FILE *fp=fopen(file,"r");
	if(fp==NULL){
		printf("�򲻿���Ӧ�ļ���\n");
		exit(0);
	}
	while(fgets(ch,1000,fp)!=NULL){
		for(int i=0;ch[i]!=NULL;i++){
			if(ch[i]==' '||ch[i]==','){
				flag=0;
			}
			else if(flag==0){
				count++;
				flag=1;
			}
		}
	}
	fclose(fp);
	return count;
}

//��ȡ�ַ���Ŀ 
int CharCount(char *file){
	int count=0;
	char ch;
	FILE *fp=fopen(file,"r");
	if(fp==NULL){
		printf("�򲻿���Ӧ�ļ���\n");
		exit(0);
	}
	while(ch=fgetc(fp)!=EOF){
		count++;
	}
	fclose(fp);
	return count;
}

int main(int argc , char *argv[]){
	FILE *fp = fopen(argv[2], "r");
	if (fp== NULL){
		printf("�򲻿���Ӧ�ļ���");
		scanf("%s%s%s", argv[0], argv[1], argv[2]);
	}
	if(strcmp(argv[1], "-w") && strcmp(argv[1], "-c")){
		printf("��������\n") ;
		return 0;
	}
	else if(strcmp(argv[1], "-w")==0){
		printf("��������%d\n",WordCount(argv[2]));
	}
	else if(strcmp(argv[1], "-c")==0){
		printf("�ַ�����%d\n",CharCount(argv[2]));
	}
	return 0;
}


