#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

//读取单词数目 
int WordCount(char *file){
	int count=0;
	int flag=0;
	char ch[1000];
	FILE *fp=fopen(file,"r");
	if(fp==NULL){
		printf("打不开对应文件！\n");
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

//读取字符数目 
int CharCount(char *file){
	int count=0;
	char ch;
	FILE *fp=fopen(file,"r");
	if(fp==NULL){
		printf("打不开对应文件！\n");
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
		printf("打不开对应文件！");
		scanf("%s%s%s", argv[0], argv[1], argv[2]);
	}
	if(strcmp(argv[1], "-w") && strcmp(argv[1], "-c")){
		printf("输入有误！\n") ;
		return 0;
	}
	else if(strcmp(argv[1], "-w")==0){
		printf("单词数：%d\n",WordCount(argv[2]));
	}
	else if(strcmp(argv[1], "-c")==0){
		printf("字符数：%d\n",CharCount(argv[2]));
	}
	return 0;
}


