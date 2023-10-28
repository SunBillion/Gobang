#include<bits/stdc++.h> 
#include<windows.h>

#define white_chess 1
#define black_chess 2
using namespace std;

class Gobang{
	public:
		Gobang(int size){
			for(int i=0;i<500;i++) for(int j=0;j<500;j++) chessboard[i][j] = 0;
			chessboard_size = size;
		}
		
		Gobang(vector<pair<int,int> > maneuvers, int size){
			for(int i=0;i<500;i++) for(int j=0;j<500;j++) chessboard[i][j] = 0;
			chessboard_size = size;
			chess_maneuvers = maneuvers;		
			for(int i=0,size=maneuvers.size();i<size;i++){
				chessboard[maneuvers[i].first+100][maneuvers[i].second+100]
				 = ((i+1)%2)?white_chess:black_chess;
			}
		}
		
		void print(){
			SetConsoleOutputCP(437);
			unsigned char a;
		    
			//system("cls");
		    
		    printf("step %d\n ", chess_maneuvers.size());
		    char s ='A';
		    for(int i=0;i<chessboard_size;i++,s++) printf(" %c", s); //print alphabet
		    
			for(int i=1; i<chessboard_size+1; i++){				
				printf("\n%-2d", i); //print number		    	
			   	for(int j=1; j<chessboard_size+1; j++){
			   		if(chessboard[i+100][j+100] == 0){			   			
				   		a=197;				   		
				   		//side
				   		if(i==1 ) a=194; 
						else if(i == chessboard_size) a = 193; 
						else if(j == 1 ) a = 195;
						else if(j == chessboard_size) a = 180;					
						//corner
						if(i==1 &&j==1 ) a=218;
						else if(i == 1 &&j == chessboard_size) a = 191;
						else if(i == chessboard_size&&j == 1 ) a = 192;
						else if(i == chessboard_size&&j == chessboard_size) a = 217;											
		    		}else if(chessboard[i+100][j+100]==white_chess){ 
						if(i==chess_maneuvers.back().first && j==chess_maneuvers.back().second ) a = '@';
						else a = 'O';
					}else{ 
						if(i==chess_maneuvers.back().first && j==chess_maneuvers.back().second ) a = '/';	
						else a = 'X';		   			 					
					}
					printf("%c ",a);
				}
			}			
			printf("\n\n\n");
		}
		
		bool push_back(char a,int b){
			int x = b;
			int y = a - 'A' +1;
			if(x<1 || y<1 || x>chessboard_size || y>chessboard_size || chessboard[x+100][y+100] != 0)
				return 0;//incorrect input
			chess_maneuvers.push_back({x,y});
			chessboard[x+100][y+100] = (chess_maneuvers.size()%2)?white_chess:black_chess;
			return 1;
		}
		
		bool push_back(int a,int b){
			int x = b;
			int y = a;
			if(x<1 || y<1 || x>chessboard_size || y>chessboard_size || chessboard[x+100][y+100] != 0)
				return 0;//incorrect input
			chess_maneuvers.push_back({x,y});
			chessboard[x+100][y+100] = (chess_maneuvers.size()%2)?white_chess:black_chess;
			return 1;
		}
		
		void pop(){
			chessboard[chess_maneuvers.back().first+100][chess_maneuvers.back().second+100] = 0;
			chess_maneuvers.pop_back();
		}
		
		pair<int,int>          back()             		    {return chess_maneuvers.back();} 
		vector<pair<int,int> > get_maneuvers()					{ return chess_maneuvers;}
		int                    get_size()                       {return chess_maneuvers.size();}  
		int                    get_chessboard(int x,int y)  {return chessboard[y+100][x+100]; }
		 
		int quik_judge(){
			bool ok =true;
			for(int i=chess_maneuvers.back().first+100-4;i<chess_maneuvers.back().first+100+4;i++){
				for(int j=chess_maneuvers.back().second+100-4;j<chess_maneuvers.back().second+100+4;j++){
					if(chessboard[i][j] != 0){
						ok =true;
						for(int k=1;k<5;k++) if(chessboard[i+k][j] != chessboard[i][j]) ok = false;
						if(ok) return chessboard[i][j];
						ok =true;
						for(int k=1;k<5;k++) if(chessboard[i][j+k] != chessboard[i][j]) ok = false;
						if(ok) return chessboard[i][j];
						ok =true;
						for(int k=1;k<5;k++) if(chessboard[i+k][j+k] != chessboard[i][j]) ok = false;
						if(ok) return chessboard[i][j];
						ok =true;
						for(int k=1;k<5;k++) if(chessboard[i+k][j-k] != chessboard[i][j]) ok = false;
						if(ok) return chessboard[i][j];
					}
				}
			}
			if(chess_maneuvers.size() == chessboard_size*chessboard_size) return 3;
			return 0;
			//nothing return 0
			//white win return 1
			//black win return 2
			//tie return 3
		}		
	
		int judge(){
			bool ok =true;
			for(int i=1+100;i<chessboard_size+1+100;i++){
				for(int j=1+100;j<chessboard_size+1+100;j++){
					if(chessboard[i][j] != 0){
						ok =true;
						for(int k=1;k<5;k++) if(chessboard[i+k][j] != chessboard[i][j]) ok = false;
						if(ok) return chessboard[i][j];
						ok =true;
						for(int k=1;k<5;k++) if(chessboard[i][j+k] != chessboard[i][j]) ok = false;
						if(ok) return chessboard[i][j];
						ok =true;
						for(int k=1;k<5;k++) if(chessboard[i+k][j+k] != chessboard[i][j]) ok = false;
						if(ok) return chessboard[i][j];
						ok =true;
						for(int k=1;k<5;k++) if(chessboard[i+k][j-k] != chessboard[i][j]) ok = false;
						if(ok) return chessboard[i][j];
					}
				}
			}
			if(chess_maneuvers.size() == chessboard_size*chessboard_size) return 3;
			return 0;
			//nothing return 0  
			//white win return 1
			//black win return 2
			//tie return 3
		}
		
	private:
		vector<pair<int,int> > chess_maneuvers;
		int chessboard[500][500];
		int chessboard_size;
};

