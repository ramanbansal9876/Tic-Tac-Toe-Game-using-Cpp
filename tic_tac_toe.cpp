#include<iostream>
using namespace std;

bool win_game_row(char arr[3][3]){
	for(int i=0;i<3;i++){
		bool res = true;
		char same = arr[i][0];
		if(same == '#'){
			continue; //This Row has empty spaces
		}
		for(int j=1;j<3;j++){
			if(arr[i][j] != same){
				res = false;
				break;
			}
		}
		if(res == true){
			return res;
		}
	}	
	return false;
}

bool win_game_col(char arr[3][3]){
	for(int i=0;i<3;i++){
		bool res = true;
		char same = arr[0][i];
		if(same == '#'){
			continue; //This Column has empty spaces
		}
		for(int j=1;j<3;j++){
			if(arr[j][i] != same){
				res = false;
				break;
			}
		}
		if(res == true){
			return res;
		}
	}	
	return false;
}

bool win_game_diag1(char arr[3][3]){
	char same = arr[0][0];
	if(same == '#'){
		return false;
	}
	for(int i=1;i<3;i++){
		if(arr[i][i] != same){
			return false;
		}
	}
	return true;
}

bool win_game_diag2(char arr[3][3]){
	char same = arr[0][2];
	if(same == '#'){
		return false;
	}
	for(int i=1;i<3;i++){
		if(arr[i][2-i] != same){
			return false;
		}
	}
	return true;
}

void display(char arr[3][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

void change(char arr[3][3],int row,int col,int turn){
	if(turn == 0){
		arr[row][col] = 'O';
	}
	else{
		arr[row][col] = 'X';
	}
}

bool filled(char arr[3][3],int row,int col){
	return (arr[row][col] == 'X' || arr[row][col] == 'O');
}

int main(){
	char arr[3][3];
	fill_n(arr[0],3,'#');
	fill_n(arr[1],3,'#');
	fill_n(arr[2],3,'#');
	int turn = 0;
	
	cout<<"Player-1 will play with \'X\' \n"; //turn = 1
	cout<<"Player-2 will play with \'O\' \n"; //turn = 0
	while(true){
		cout<<"Which Player will turn first (1 or 2): ";
		cin>>turn;
		if(turn == 1){
			break;
		}
		else if(turn == 2){
			turn = 0; //0 represents Player-2
			break;
		}
		else{
			cout<<"Wrong Input! Try Again"<<endl;
		}
	}
	
	int row,col;
	while(true){
		while(true){ //Checking whether the place is already filled or not
			cout<<"\nEnter a row number (1 or 2 or 3): ";
			cin>>row;
			cout<<"Enter a column number (1 or 2 or 3): ";
			cin>>col;
			if(filled(arr,row-1,col-1)){
				cout<<"Place Already Filled! Try Again"<<endl;
			}
			else{
				break;
			}
		}
		change(arr,row-1,col-1,turn); //Passing Player Input to TIC-TAC-TOE Board
		display(arr); //Displaying TIC-TAC-TOE Board
		if(win_game_col(arr) || win_game_row(arr) || win_game_diag1(arr) || win_game_diag2(arr)){
			cout<<(turn==0?"Player-2 has won!\n":"Player-1 has won!\n");
			break;
		}
		turn = (turn+1)%2;
	}
}
