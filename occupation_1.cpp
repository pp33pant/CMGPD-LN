#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cmath>
#define maxn 10200

#ifdef _WIN32
    #include <Windows.h>
#endif

using namespace std;
string s[maxn];
char ct[maxn];
int tot;
int p[maxn];
int q[maxn];
string qu;
void get_data(){
	FILE* fd=fopen("data.txt","r");
	tot = 0;
	while(fscanf(fd,"%[^\n]%*c",ct)!=EOF){
		++tot;
	//	printf("%s\n",ct);
	//	if(tot==3)exit(0);
	//	exit(0);
		int now = 0;
		p[tot]=q[tot]=0;
		while(ct[now]<'0'||ct[now]>'9')++now;
		while(ct[now]>='0'&&ct[now]<='9'){
			p[tot]*=10;
			p[tot]+=ct[now]-'0';
			++now;
		}
		while(ct[now]<'0'||ct[now]>'9')++now;
		while(ct[now]>='0'&&ct[now]<='9'){
			q[tot]*=10;
			q[tot]+=ct[now]-'0';
			++now;
		}
		int n = strlen(ct);
		//if(tot==1)printf("%d %d %d %d\n",p[tot], q[tot] ,now , n);
		while(now < n){
		//	if(tot==1)printf("%c",ct[now]);
			if(ct[now]==' '){
				++now;
				continue;
			}else if(ct[now]>='a'&&ct[now]<='z'){
				s[tot]+=ct[now];
				++now;
			}else break;
		}		
		//if(tot==1)printf("%s\n",s[tot].c_str());
	}
	qu = "quit";
	printf("read file finish : %d\n",tot);
}

void query(){

	printf("input data:\n");
	scanf("%s",ct);

	if(ct == qu)exit(0);
//	printf("replace:\n");
	string st = ct;
//	printf("%d\n",strlen(ct));
	for(int i=1;i<=tot;++i){
		if(s[i].find(st)!=string::npos){
			printf("replace %s=1 if DATASET==%d & POSITION_CODE==%d\n",ct,p[i],q[i]);  // note: here is "POSITION_CODE"
		}
	}
//	system("pause");
}
int main(){
	

#ifdef _WIN32

    SetConsoleOutputCP (65001);
    CONSOLE_FONT_INFOEX info = { 0 }; //
    info.cbSize = sizeof(info);
    info.dwFontSize.Y = 16; // leave X as zero
    info.FontWeight = FW_NORMAL;
    wcscpy(info.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
#endif
	
	
	get_data();
	while(1){
		query();
	}
	return 0;
}
 
