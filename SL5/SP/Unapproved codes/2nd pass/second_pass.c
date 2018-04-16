#include<stdio.h>
#include<string.h>

const int MOT_size = 4;
const int POT_size = 2;
const int DLT_size = 2;
const int REGTAB_size = 4;
const int CNDT_size = 5;

int SYMTAB_size = 2;
int LITTAB_size = 3;
int POOLTAB_size = 2;


// File pointer
FILE *fp_in, *fp_out;

typedef struct pair{
	char name[5];
	int code;
} pair;

typedef struct tuple{
	int id;
	char name[10];
	int addr;
} tuple;

pair MOT[4]={{"MOVR",1},
		  {"MOVM",2},
		  {"ADD",3},
		  {"SUB",4}};
		  
pair POT[2]={{"START",1},
		   {"END",2}};
		   
pair DLT[2]={{"DC",1},
             {"DS",2}};
             
pair REGTAB[4]={{"AREG", 1},
		      {"BREG", 2},
		      {"CREG", 3},
		      {"DREG", 4}};
		      
pair CNDT[5] ={{"LT", 1},
			{"GT", 2},
			{"LE", 3},
			{"GE", 4},
			{"ANY", 5}};
			
			
tuple SYMTAB[10] = {{1, "A", 206},
				{2, "B", 207},};
				
tuple LITTAB[10] = {{1, "1", 202},
				{2, "2", 208},
				{3, "1", 209}};
				
int POOLTAB[10] = {1, 2};


// Read next part of instruction
void read_block(char *temp){
	int i=0;
	char ch = fgetc(fp_in);
	while(ch != ' ' && ch != '\n' && !feof(fp_in)){
		temp[i] = ch;
		i++;
		ch = fgetc(fp_in);
	}
	temp[i] = '\0';
}

// Write output
void write_block(char *temp){
	fputs(temp, fp_out);
}


// Read input file
void pass(){
	char temp [30];
	int temp_size = 0;
	
	while(!feof(fp_in)){
		int no_out_flag = 0;
		
		//read and write address
		read_block(temp);
		strcat(temp, " ");
		write_block(temp);
		
		//read and write Part 1
		read_block(temp);
			if(temp[0] == '0'){
				// Do nothing
			}
			else if(temp[1] == 'A' || temp[1] == 'D'){
				no_out_flag = 1;
			}
			else if(temp[0] = '('){
				int len = strlen(temp);
				strncpy(temp, temp+4, 2);
			
				temp[2] = '\0';
			}
			strcat(temp, " ");
		if(no_out_flag == 0)
			write_block(temp);
		
		//read and write Part 2
		read_block(temp);
			if(temp[0] == '0'){
				// Do nothing
			}
			else if(temp[0] == '('){
				int len = strlen(temp);
				strncpy(temp, temp+1, 2);
			
				temp[2] = '\0';
			}
			strcat(temp, " ");
		if(no_out_flag == 0)
			write_block(temp);
		
		//read and write Part 3
		read_block(temp);
			if(temp[0] == '0'){
				// Do nothing
			}
			else if(temp[0] == '('){
				char num_str[5];
				strncpy(num_str, temp+3, 2);
				num_str[2] = '\0';
				
				int index = atoi(num_str);
				int addr;
				
				if(temp[1] == 'L'){
					addr = LITTAB[index-1].addr;
				}
				else if(temp[1] == 'S'){
					addr = SYMTAB[index-1].addr;
				}
				sprintf(temp, "%d", addr);
			
			}
			strcat(temp, " ");
		if(no_out_flag == 0)
			write_block(temp);
		
		// write newline
		temp[0] = '\n';	temp[1] = '\0';
		write_block(temp);
	}
}


void main(){
 	fp_in = fopen("second_pass_input.txt", "r");
 	fp_out = fopen("second_pass_output.txt", "w");
	pass();
}













