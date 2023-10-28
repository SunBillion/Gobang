#include<iostream> 
#include<windows.h>
#include <cstdlib> 
#include <ctime>   
#include <vector>

using namespace std;

struct pre{
	int f;
	int a;
	int b;
};
 
vector<pair<int,int> > V;


void player1();
void player2();
void print();
void computer();
void copy(int A[17][17],int B[17][17]);
pre predict(int A[17][17],int n,int wh);
int judge(int A[17][17],pair<int,int> Last);

int A[17][17]={0},B[17][17]={0};
pair<int,int> Last;

int main(){	
	//char ans;
	int first=0,Q=0;
	//cout<<"Do you want to be the offensive player?(Y/N)";
	//cin>>ans;
	//first=(ans=='Y')?0:1;
	print();
	for( int i=0;i<225&&Q==0;i++){
		if(i%2==first){
			player1();
		}else{
			computer();
		} 
		print();//print() must put in front of the judge() !!
		Q=judge(A,Last);		
	}	
	
	if(Q==1){
		cout<<"\n\nplayer1(you) win";		
	}else{
		if(Q==2){
			cout<<"\n\nplayer2(computer) win";
		}else{
			cout<<"\n\ntie";
		}
	}
	
	return 0;
}

void print(){
	
    SetConsoleOutputCP(437);
	unsigned char a;
    
	//system("cls");
    
    printf("   A B C D E F G H I J K L M N O"); //print A~O
    
	for(int i=1; i<16; i++){
		
		printf("\n%-2d", i); //print number
    	
	   	for(int j=1; j<16; j++){
	   		if(A[i][j] == 0){
	   			
		   		a=197;
		   		
		   		//side
		   		if(i==1 ) a=194; 
				else if(i == 15) a = 193; 
				else if(j == 1 ) a = 195;
				else if(j == 15) a = 180;
				
				//corner
				if(i==1 &&j==1 ) a=218;
				else if(i == 1 &&j == 15) a = 191;
				else if(i == 15&&j == 1 ) a = 192;
				else if(i == 15&&j == 15) a = 217;
				
				
    		}else{
    			
				if(A[i][j]==3) a = '@';
	   			else if(A[i][j]==4) a = '/';
				else if(A[i][j]==1) a = 'O';
				else if(A[i][j]==2) a = 'X';
				
			}
			printf("%c ",a);
		}
	}
	
	printf("\n");
	
}

vector V<pair<int,int> > player1(vector V<pair<int,int> >){
	int i;
	int j;
	char J;
	cout<<"\nIt's turn to player1! (sample:A 1)\ninput : ";
	cin>>J>>i;//input a letter and a number
	j=int(J)-64;//change the letter into the number
	if(A[i][j]==0){
		A[i][j]=1;
		V.push_back_back_back_back({i,j}); 
	}else{
		cout<<"error!";
		player1();	
	}
}

void player2(){
	int i;
	int j;
	char J;
	cout<<"\nIt's turn to player2! (sample:A 1)\ninput : ";
	cin>>J>>i;
	j=int(J)-64;
	if(A[i][j]==0){
		A[i][j]=2;
		Last.first=i;
		Last.second=j; 
	}else{
		cout<<"error!";
		player2();	
	}
}

void computer(){
	int s,f=0,a=8,b=8;
	predict(A,1,2);
	if(f!=1){
		srand( time(NULL) );
		do{
			a=rand()%15+1;
			b=rand()%15+1; 
		}while(A[a][b]!=0);
	}
	A[a][b]=4;
	Last.first+=a;
	Last.second+=b;
}

void copy(int A[17][17],int B[17][17]){ 
	//copy A to B
	for(int i=1;i<16;i++){
		for(int j=1;j<16;j++){
			B[i][j]=A[i][j];
		}
	}
} 

end ifend(int A[17][17],int wh){
	end ans;
	for(int i=1;i<=15;i++){
		for(int j=0;j<=15;j++){
			
		}
	}
}

pre predict(int A[17][17],int n,int wh){
	if(n>0){
		n--;
		pre ans;
		for(int i=1;i<=15&&ans.f==0;i++){
			for(int j=0;j<=15&&ans.f==0;j++){
				if(B[i][j]==0){
					B[i][j]=2;
					if(judge(B,Last)==2){
						ans.a=i;
						ans.b=j;
						ans.f=1;
					}
					B[i][j]=1;
					if(judge(B,Last)==1){
						ans.a=i;
						ans.b=j;
						ans.f=1;
					}
					B[i][j]=0;
				}
			}
		}
		return ans;
	}
}

int judge(int A[17][17],pair<int,int> last){
	int s,wh,a,b;
	
	wh=A[last.first][last.second];

	s=0;
	a=last.first;
	b=last.second;
	while(A[++a][b]==wh&&a<=15) s++;
	a=last.first;
	b=last.second;
	while(A[--a][b]==wh&&a>=1) s++;
	cout<<s<<endl;
	if(s>=4) return wh;
	
	s=0;
	a=last.first;
	b=last.second;
	while(A[a][++b]==wh&&a<=15) s++;
	a=last.first;
	b=last.second;
	while(A[a][--b]==wh&&b>=1) s++;
	cout<<s<<endl;
	
	if(s>=4) return wh;
	
	s=0;
	a=last.first;
	b=last.second;
	while(A[++a][++b]==wh&&a<=15&&a<=15) s++;
	a=last.first;
	b=last.second;
	while(A[--a][--b]==wh&&a>=1&&b>=1) s++;
	cout<<s<<endl;
	
	if(s>=4) return wh;
	
	s=0;
	a=last.first;
	b=last.second;
	while(A[++a][--b]==wh&&a<=15&&b>=1) s++;
	a=last.first;
	b=last.second;
	while(A[--a][++b]==wh&&a>=1&&a<=15) s++;
	cout<<s<<endl;
	
	if(s>=4) return wh;
	
	return 0;
}
	

