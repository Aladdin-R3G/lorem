#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define CHAR_S 1
#define LINE_S 32
#define PAR_S 445
#define ERR_L "invalid flag or input\n"
#define ERR_S 22

//custem type for lorem objects since i need both pointer to lorem and the size to output it

typedef struct {
	char *l;
	int s;
} lorem;

// this function turn the user size input from char to int

int getSizeOfLore(char *c){
	int s = 0;

	for(int i = 0; i < 1000;i++){
		if( '0' <= c[i] && c[i] <= '9'){
			if(c[i] == '0') s = s * 10;
			else{
				s = s * 10;
				s = s + (c[i] - '0');
			}
		}else{
			break;
		}
	}
	return s;
}

// this function fills the allocated memory with lorem

void fillWithLore(char *p,int s,char *lore){
	int itr = 0;
	char *ptr = p;
	char *ptr2 = lore;
	for(int i = 0; i < s;i++){
		memcpy(ptr++,ptr2++,1);
		itr++;
		if(itr == PAR_S){
			itr = 0;
			ptr2 = lore;
		}
	}


}

//i made this function just for the sake of keeping the main function simple

lorem makeLore(int c,char *a[]){

	char *lore = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
	lorem L;

	if(c == 1) {
		L.l = lore;
		L.s = PAR_S;
		return L;
	}
	if(c == 2) {
		if(a[1][0] != '-') {
			L.l = ERR_L;
			L.s = ERR_S;
			return L;
		}else{
			switch(a[1][1]){
				case 'c':
					L.l = lore;
					L.s = CHAR_S;
					return L;
				case 'l':
					L.l = lore;
					L.s = LINE_S;
					return L;
				case 'p':
					L.l = lore;
					L.s = PAR_S;
					return L;
			}
			L.l = ERR_L;
			L.s = ERR_S;
			return L;
		}
	}
	if(c == 3){
		if(a[1][0] != '-') {
			L.l = ERR_L;
			L.s = ERR_S;
			return L;
		}else{
			switch(a[1][1]){
				case 'c':
					L.s = getSizeOfLore(a[2]);
					L.l = malloc(L.s);
					fillWithLore(L.l,L.s,lore);
					return L;
				case 'l':
					L.s = getSizeOfLore(a[2]) * LINE_S;
					L.l = malloc(L.s);
					fillWithLore(L.l,L.s,lore);
					return L;
				case 'p':
					L.s = getSizeOfLore(a[2]) * PAR_S;
					L.l = malloc(L.s); // definition of memory inefficiency here lol
					fillWithLore(L.l,L.s,lore); // hey i made it to work not to be memory efficiant 
					return L;	

			} 
		}		
	}
	
        L.l = ERR_L;
        L.s = ERR_S;
        return L;
}

int main(int argc,char *argv[]){
	
	lorem lor;
	lor = makeLore(argc,argv);
	write(STDOUT_FILENO,lor.l,lor.s);
			
	return 0;
}
