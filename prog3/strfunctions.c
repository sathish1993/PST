#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char first_name[]="Sathish Kumar";
char last_name[]= "Santhanagopalan";
int myStrStr(char haystack[],char needle[],char buffer[]){
	int i,j,count=0;
	int checked = 0;
	memset(buffer,0,255);
	for(j=0;j<strlen(needle);j++){
		checked=0;
		for(i=0;i<strlen(haystack);i++){
		if(!checked){
			if(haystack[i]==needle[j]){
				count++;
				checked = 1;
				buffer[j]=haystack[i];
			}		
		}
		}	
	}	
	if(count==strlen(needle)){
	return 1;
	}
	else{
	return 0;
	}
}

void findJediName(char* first, char* last, char buffer[]){
	int ptr;
	char fnbuffer[3]={0};
	char jediName[5]={0};
	memset(buffer,0,255);
	jediName[0]=toupper(last[0]);
	fnbuffer[0]=tolower(first[0]);
	if(first[1]!='\0'){
		fnbuffer[1]=tolower(first[1]);
	}else{
		fnbuffer[1]='t';
	}
	fnbuffer[2]='\0';
	for(ptr=1;ptr<3;ptr++){
		if(last[ptr]!='\0'){
			jediName[ptr]=last[ptr];
		}else{
			jediName[ptr]='o';
		}		
	}
	strcat(jediName,fnbuffer);
	strcat(buffer,jediName);
}

int findAllJediNames(char * filename, char buffer[50][10]){
	FILE *f; 
	int i=0,count=0;
	char *fname,*lname;
	f = fopen("names.txt","rt");
	char line[128],fnbuf[20],lnbuf[30],name[100];
	if(f){
		while(fgets(line,sizeof line,f)!=NULL){
		memset(name,0,100);
		memset(fnbuf,0,20);
		memset(lnbuf,0,30);
		lname=strtok(line,",");
		fname = strtok(NULL,",");
		for(i=0;i<3;i++){
			lnbuf[i]=lname[i];
			if(i!=2){
				fnbuf[i]=tolower(fname[i]);
			}
		}
		strcat(name,lnbuf);
		strcat(name,fnbuf);
		strcpy(buffer[count],name);
		count++;
		}
	}	
	fclose(f);
	return count;
}
