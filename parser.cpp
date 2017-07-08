#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[]){
	char ch[1000][1000];
	char ch1[1000][1000];
	
	// declare the file object
	ifstream infile;
	ofstream outfile;
	
	// open the file
	infile.open(argv[1]);
	outfile.open("file_output.txt");
	if(argc!=2){
		cerr << "Error: INVALID ARGUMENTS";
		return 0;
	}
	else if(!infile.is_open()){
		cerr << "Error:　FILE NOT FOUND.";
		return 0;
	}
	
	int lengtha=0;
	int lengtht=0;
	int a=0;
	
	char reader;
	
	int row=0;
	int col=0;
	int x=0;
	int y=0; 
	int z=0;
	int start = 0;
	int middle = 0;
	int end = 0;
	unsigned int code=0;
	unsigned int data=0;
	int length=0;
	bool endcode = true;
	
	// read from file
	while(infile.get(reader)){
			/*//check length
			while(ch[lengtha]!='/n')
				lengtha++;	
			cout<<lengtha;
			//lengtht = lengtht+lengtha;
			for(int i=0; i<1000; i++){
				if(ch[i]=='#'){
					for(int j=i; j<1000; j++)
						ch[j]=' ';
				}
			}
			for(int i=0; i<lengtha; i++)
				ch1[a+i]=ch[i];
			a=a+lengtha;
			for(int i=0; i<1000; i++){
				cout << ch[i];
			}
			cout << endl;*/
		if(reader =='\n'){
			col=0;
			++row;
		}
		else{
			ch[row][col]=reader;
			col++;
		}
	}	
	for(int i=0; i<row; i++){
		for(int j=0; j<1000; j++){
			if(ch[i][j]=='#'){
				int position=j;
				while(ch[i][position]!='\0'){
					ch[i][position]=' ';
					position++;
				}
			}		
		}
	}
	for(int i=0; i<=row; i++){
		for(int j=0; j<1000; j++)
			cout << ch[i][j];
		cout << endl;
	}
	cout <<row;
	/*for(int i=0; i<row; i++){
		for(int j=0; j<1000; j++){
			if(ch[i][j]>'0'&&ch[i][j]<'9')
				cout << "ture";	
		}
	}*/
	
	bool valid = true;
	unsigned int i=0; 
	int rowrow =0; //code
	int label=0;
	bool oprand1=true;
	/*while(i<=row){
		int j=1;
		if(ch[i][j]=='L'&&ch[i][j+1]=='D'){
			if(ch[i][j+3]=='\0'){
				cerr << "Oprand";
				oprand1=false;
			}
		}
	}*/
	while(i<=row){
		int j=1;
		unsigned int k=0;
		if(ch[i][k]=='C'&&ch[i][k+1]=='o'){
			unsigned int number = 0;
			char str = ch[i][k+6];
			while (str>='0'&&str<='9'){
				number = number*10;
				unsigned int value = str - '0';
				number = number + value;
				k++;
				str = ch[i][k+6];
			}
			code = number;
			rowrow=i;
			i++;
		}
		else if(ch[i][k]=='D'&&ch[i][k+1]=='a'){
			unsigned int number = 0;
			char str = ch[i][k+6];
			while (str>='0'&&str<='9'){
				number = number*10;
				unsigned int value = str - '0';
				number = number + value;
				k++;
				str = ch[i][k+6];
			}
			data = number;
			i++;
		}
		else if(ch[i][k]=='S'&&ch[i][k+1]=='t'){
			cout << "StartCode: " << code<<endl;
			i++;
		}
		else if(ch[i][k]=='E'&&ch[i][k+1]=='n'){
			cout << "EndCode: " << code+i-3-rowrow << endl;
			i++;
			endcode=false;
		}
		else if(ch[i][k]=='M'&&ch[i][k+1]=='i'){
			cout << "MiddleCode: " << code +i-3-rowrow<< endl;
			i++;
		}
		else if(ch[i][k]=='L'&&ch[i][k+1]=='a'){
			label++;
			cout << ch[i][k] << ch[i][k+1] << ch[i][k+2]<<ch[i][k+3]<<ch[i][k+4]<<ch[i][k+5] <<": "<< code+i-3-rowrow-label+1 << endl;
			i++;
		}
		else if((ch[i][j]=='L'&&ch[i][j+1]=='D')||(ch[i][j]=='S'&&ch[i][j+1]=='D')||(ch[i][j]=='A'&&ch[i][j+1]=='D')||(ch[i][j]=='M'&&ch[i][j+1]=='U')||(ch[i][j]=='D'&&ch[i][j+1]=='I')||(ch[i][j]=='S'&&ch[i][j+1]=='U')||(ch[i][j]=='J'&&ch[i][j+1]=='M')||(ch[i][j]=='J'&&ch[i][j+1]=='Z')||(ch[i][j]=='J'&&ch[i][j+1]=='N')||(ch[i][j]=='J'&&ch[i][j+1]=='G')||(ch[i][j]=='J'&&ch[i][j+1]=='L')){    
			if(ch[i][j]=='L'&&ch[i][j+1]=='D'&&ch[i][j+2]!='i'){
				if(ch[i][j+3]=='\0'){
					cerr << "Error: on line " << i+1 << " missing oprand"<< endl;
				}
				else if(ch[i][j+2]==' '||ch[i][j+2]=='	'){
					if(ch[i][j+3]>='0'&&ch[i][j+3]<='9'){
						while(ch[i][j+3]!=','){
							if(ch[i][j+3]>='0'&&ch[i][j+3]<='9'){
								j++;
							}
							else{
								valid = false;
								break;
							}
						}
						if(ch[i][j+4]==' ' ||ch[i][j+4]=='	'){
							if(ch[i][j+5]=='R'){
								valid = true;
								x++;
							}
							else 
								valid = false;
						}
						else 
							valid = false;
					}
					else if(ch[i][j+3]=='R'){
						if(ch[i][j+5]==','){
							if(ch[i][j+6]==' '||ch[i][j+6]=='	'){
								if(ch[i][j+7]=='R'){
									valid = true;
									x++;
								}
								else 
									valid = false;
							}
							else
								valid = false;
						}
						else
							valid = false;
					}
					else
						valid = false;
				}
				else
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error: on line " << i-1 << " invalid oprand"<< endl;
				}
			}
			/*else if(ch[i][j]=='L'&&ch[i][j+1]=='D'&&ch[i][j+3]=='R'){
				if(ch[i][j+2]==' '||ch[i][j+2]=='	'){
					if(ch[i][j+3]=='R'){
						if(ch[i][j+5]==' '||ch[i][j+5]=='	'||ch[i][j+5]=='R'){
								valid = true;
								x++;
								//cout <<"2";
						}
						else
							valid = false;
					}
					else
						valid = false;
				}
				else
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error.";
					break;
				}
			}*/
			else if(ch[i][j]=='L'&&ch[i][j+1]=='D'&&ch[i][j+2]=='i'){
				if(ch[i][j+4]=='\0'){
					cerr << "Error: on line " << i+1 << "missing oprand"<< endl;
				}
				else if(ch[i][j+3]==' '||ch[i][j+3]=='	'){
					while(ch[i][j+4]!=','){
						if(ch[i][j+4]>='0'&&ch[i][j+4]<='9')
							j++;
						else{
							valid = false;
							break;
						}
					}
					if(ch[i][j+5]==' '||ch[i][j+5]=='	'||ch[i][j+5]=='R'){
							valid = true;
							//cout <<"3";
							x++;
					}
					else
						valid = false; 
				}
				else 
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error: on line " << i-1 << " invalid oprand"<< endl;
				}
			}
			else if(ch[i][j]=='S'&&ch[i][j+1]=='D'&&ch[i][j+2]!='i'){
				if(ch[i][j+3]=='\0'){
					cerr << "Error: on line " << i+1 << "missing oprand"<< endl;
					
				}
				else if(ch[i][j+2]==' '||ch[i][j+2]=='	'){
					if(ch[i][j+3]=='R'){
						if(ch[i][j+5]==','){
							if(ch[i][j+6]==' '||ch[i][j+6]=='	'){
								if((ch[i][j+7]>='0'&&ch[i][j+7]<='9')||ch[i][j+7]=='R'){
									x++;
								}
								else 
									valid =false;	
							}
							else 
								valid = false;
						}
						else
							valid = false;
					}
					else
						valid = false;
				}
				else
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error: on line " << i-1 << " invalid oprand"<< endl;
				}
			}
			/*else if(ch[i][j]=='S'&&ch[i][j+1]=='D'){
				if(ch[i][j+2]==' '||ch[i][j+2]=='	'){
					if(ch[i][j+3]=='R'){
						while(ch[i][j+4]!=','){
							if(ch[i][j+4]>='0'&&ch[i][j+4]<='9')
								j++;
							else{
								valid = false;
								break;
							}
						}
						if(ch[i][j+5]==' '||ch[i][j+5]=='	'|| ch[i][j+5]=='R'){
								valid = true;
								x++;
								//cout <<"5";
						}
						else
							valid = false;
					}
					else
						valid = false;
				}
				else
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error.";
					break;
				}
			}*/
			/*if(ch[i][j]=='S'&&ch[i][j+1]=='D'&&ch[i][j+2]=='i'){
				if(ch[i][j+3]==' '||ch[i][j+3]=='	'){
					while(ch[i][j+4]!=','){
						if((ch[i][j+4]>='0'&&ch[i][j+4]<='9')||ch[i][j+4]=='-')
							j++;
						else{
							valid = false;
							break;
						}
					}
					if(ch[i][j+5]==' '||ch[i][j+5]=='	'){
						/*while(ch[i][j+6]!='\0'&&ch[i][j+6]!='\n'){
							if(ch[i][j+6]>='0'&&ch[i][j+6]<='9'){
								j++;	
								valid = true;
							}
							else{
								valid = false;
								break;
							}
						}
						//if(valid == true)
						x++;
						cout <<"6";
					}
					else
						valid = false;	
				}
				else
					valid = false;
				i++;
				if(valid == false)
					cout << "Error.";
			}
			*/
			else if(ch[i][j]=='S'&&ch[i][j+1]=='D'&&ch[i][j+2]=='i'){
				if(ch[i][j+4]=='\0'){
					cerr << "Error: on line " << i+1 << " missing oprand"<< endl;
					
				}
				else if(ch[i][j+3]==' '||ch[i][j+3]=='	'){
					while(ch[i][j+4]!=','){
						if((ch[i][j+4]>='0'&&ch[i][j+4]<='9')||ch[i][j+4]=='-'){
							j++;
						}
							
						else{
							valid = false;
							break;
						}
					}
					if(ch[i][j+5]==' '||ch[i][j+5]=='	'){
						if(ch[i][j+6]=='R'||(ch[i][j+6]>='0'&&ch[i][j+6]<='9')){
							valid = true;
							x++;
							//cout <<"7";
						}
						else
							valid =false;
					}
					else 
						valid = false;
				}
				else 
					valid = false;	
				i++;
				if(valid == false){
					cerr << "Error: on line " << i << " invalid oprand"<< endl;
				}
					
			}
			else if(ch[i][j]=='A'&&ch[i][j+1]=='D'&&ch[i][j+2]=='D'&&ch[i][j+3]!='i'){
				if(ch[i][j+4]=='\0'){
					cerr << "Error: on line " << i+1 << "missing oprand"<< endl;
		
				}
				else if(ch[i][j+3]==' '||ch[i][j+3]=='	'){
					if(ch[i][j+4]=='R'&&ch[i][j+8]=='R'&&ch[i][j+12]=='R'){
						if(ch[i][j+6]==','&&ch[i][j+10]==','){
							//cout << "1";
							valid == true;
							y++;
						}
						else
							valid = false;
					}
					else 
						valid= false;
				}
				else 
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error: on line " << i << " invalid oprand"<< endl;
				}
			}
			else if(ch[i][j]=='A'&&ch[i][j+1]=='D'&&ch[i][j+2]=='D'&&ch[i][j+3]=='i'){
				if(ch[i][j+5]=='\0'){
					cerr << "Error: on line " << i+1 << "missing oprand"<< endl;
					
				}
				else if(ch[i][j+4]==' '||ch[i][j+4]=='	'){	
				
					if(ch[i][j+5]=='R'){
						
						if(ch[i][j+7]==','){
					
							if(ch[i][j+8]==' '||ch[i][j+8]=='	'){
										//cout << "2";
								while(ch[i][j+9]!=','){
									if((ch[i][j+9]>='0'&&ch[i][j+9]<='9')||ch[i][j+9]=='-'){
										j++;
									}
									else{
										valid = false;
										break;
									}
								}
								if(ch[i][i+10]=='	'||ch[i][j+10]==' '){
									if(ch[i][j+11]=='R'){
										
										valid = true;
										y++;
									}
									else 
										valid = false;
								}
								else 
									valid = false;								
							}
							else 
								valid = false;
						}
						else 
							valid = false;
					}
					else 
						valid = false;
				}
				else 
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error: on line " << i << " invalid oprand"<< endl;
				}
			}
			else if(ch[i][j]=='S'&&ch[i][j+1]=='U'&&ch[i][j+2]=='B'&&ch[i][j+3]!='i'){
				if(ch[i][j+4]=='\0'){
					cerr << "Error: on line " << i+1 << "missing oprand"<< endl;
					
				}
				else if(ch[i][j+3]==' '||ch[i][j+3]=='	'){
					if(ch[i][j+4]=='R'&&ch[i][j+8]=='R'&&ch[i][j+12]=='R'){
						if(ch[i][j+6]==','&&ch[i][j+10]==','){
							valid == true;
							y++;
							//cout << "3";
						}
						else
							valid = false;
					}
					else 
						valid= false;
				}
				else 
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error: on line " << i << " invalid oprand"<< endl;
				}
			}
			else if(ch[i][j]=='S'&&ch[i][j+1]=='U'&&ch[i][j+2]=='B'&&ch[i][j+3]=='i'){
				if(ch[i][j+5]=='\0'){
					cerr << "Error: on line " << i+1 << "missing oprand"<< endl;
					
				}
				else if(ch[i][j+4]==' '||ch[i][j+4]=='	'){
					if(ch[i][j+5]=='R'){
						if(ch[i][j+7]==','){
							if(ch[i][j+8]==' '||ch[i][j+8]=='	'){
								while(ch[i][j+9]!=','){
									if((ch[i][j+9]>='0'&&ch[i][j+9]<='9')||ch[i][j+9]=='-'){
										j++;
									}
									else{
										valid = false;
										break;
									}
								}
								if(ch[i][j+10]=='	'||ch[i][j+10]==' '){
									if(ch[i][j+11]=='R'){
										valid = true;
										y++;
										//cout << "4";
									}
									else 
										valid = false;
								}
								else 
									valid = false;								
							}
							else 
								valid = false;
						}
						else 
							valid = false;
					}
					else 
						valid = false;
				}
				else 
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error: on line " << i << " invalid oprand"<< endl;
					
				}
			}
			else if(ch[i][j]=='M'&&ch[i][j+1]=='U'&&ch[i][j+2]=='L'&&ch[i][j+3]!='i'){
				if(ch[i][j+4]=='\0'){
					cerr << "Error: on line " << i+1 << "missing oprand"<< endl;
					
				}
				else if(ch[i][j+3]==' '||ch[i][j+3]=='	'){
					if(ch[i][j+4]=='R'&&ch[i][j+8]=='R'&&ch[i][j+12]=='R'){
						if(ch[i][j+6]==','&&ch[i][j+10]==','){
							valid == true;
							y++;
							//cout << "5";
						}
						else
							valid = false;
					}
					else 
						valid= false;
				}
				else 
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error: on line " << i << " invalid oprand"<< endl;
				
				}
			}
			else if(ch[i][j]=='M'&&ch[i][j+1]=='U'&&ch[i][j+2]=='L'&&ch[i][j+3]=='i'){
				if(ch[i][j+5]=='\0'){
					cerr << "Error: on line " << i+1 << "missing oprand"<< endl;
					
				}
				else if(ch[i][j+4]==' '||ch[i][j+4]=='	'){
					if(ch[i][j+5]=='R'){
						if(ch[i][j+7]==','){
							if(ch[i][j+8]==' '||ch[i][j+8]=='	'){
								while(ch[i][j+9]!=','){
									if((ch[i][j+9]>='0'&&ch[i][j+9]<='9')||ch[i][j+9]=='-'){
										j++;
									}
									else{
										valid = false;
										break;
									}
								}
								if(ch[i][j+10]=='	'||ch[i][j+10]==' '){
									if(ch[i][j+11]=='R'){
										valid = true;
										y++;
										//cout << "6";
									}
									else 
										valid = false;
								}
								else 
									valid = false;								
							}
							else 
								valid = false;
						}
						else 
							valid = false;
					}
					else 
						valid = false;
				}
				else 
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error: on line " << i << " invalid oprand"<< endl;
					
				}
			}
			else if(ch[i][j]=='D'&&ch[i][j+1]=='I'&&ch[i][j+2]=='V'&&ch[i][j+3]!='i'){
				if(ch[i][j+4]=='\0'){
					cerr << "Error: on line " << i+1 << "missing oprand"<< endl;
					
				}
				else if(ch[i][j+3]==' '||ch[i][j+3]=='	'){
					if(ch[i][j+4]=='R'&&ch[i][j+8]=='R'&&ch[i][j+12]=='R'){
						if(ch[i][j+6]==','&&ch[i][j+10]==','){
							valid == true;
							y++;
							//cout <<"7";
						}
						else
							valid = false;
					}
					else 
						valid= false;
				}
				else 
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error: on line " << i << " invalid oprand"<< endl;
					
				}
			}
			else if(ch[i][j]=='D'&&ch[i][j+1]=='I'&&ch[i][j+2]=='V'&&ch[i][j+3]=='i'){
				if(ch[i][j+5]=='\0'){
					cerr << "Error: on line " << i+1 << "missing oprand"<< endl;
					
				}
				else if(ch[i][j+4]==' '||ch[i][j+4]=='	'){
					if(ch[i][j+5]=='R'){
						if(ch[i][j+7]==','){
							if(ch[i][j+8]==' '||ch[i][j+8]=='	'){
								while(ch[i][j+9]!=','){
									if((ch[i][j+9]>='0'&&ch[i][j+9]<='9')||ch[i][j+9]=='-'){
										j++;
									}
									else{
										valid = false;
										break;
									}
								}
								if(ch[i][j+10]=='	'||ch[i][j+10]==' '){
									if(ch[i][j+11]=='R'){
										valid = true;
										y++;
										//cout <<"8";
									}
									else 
										valid = false;
								}
								else 
									valid = false;								
							}
							else 
								valid = false;
						}
						else 
							valid = false;
					}
					else 
						valid = false;
				}
				else 
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error: on line " << i << "invalid oprand"<< endl;
					
				}
			}
			else if(ch[i][j]=='J'&&ch[i][j+1]=='M'&&ch[i][j+2]=='P'){
				if(ch[i][j+4]=='\0'){
					cerr << "Error: on line " << i+1 << "missing oprand"<< endl;
					
				}
				else if(ch[i][j+3]==' '||ch[i][j+3]=='	'){
					if((ch[i][j+4]>='0'&&ch[i][j+4]<='9')||ch[i][j+4]=='['){
						valid =true;
						z++;
						//cout <<"1";
					}
					else 
						valid = false;
				}
				else 
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error: on line " << i << " invalid oprand"<< endl;
					
				}
			}
			else if(ch[i][j]=='J'&&ch[i][j+1]=='Z'){
				if(ch[i][j+3]=='\0'){
					cerr << "Error: on line " << i+1 << "missing oprand"<< endl;
					
				}
				else if(ch[i][j+2]==' '||ch[i][j+2]=='	'){
					if(ch[i][j+3]=='R'){
						if(ch[i][j+5]==','){
							if(ch[i][j+6]==' '||ch[i][j+6]=='	'){
								if((ch[i][j+7]>='0'&&ch[i][j+7]<='9')||ch[i][j+7]=='['){
									//cout << "2";
									valid=true;
									z++;
								}
								else 
									valid = false;
							}
							else 
								valid = false;
						}
						else 
							valid = false;
					}
					else 
						valid = false;
				}
				else 
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error: on line " << i << " invalid oprand"<< endl;
		
				}
			}
			else if(ch[i][j]=='J'&&ch[i][j+1]=='N'&&ch[i][j+2]=='Z'){
				if(ch[i][j+4]=='\0'){
					cerr << "Error: on line " << i << "missing oprand"<< endl;
					
				}
				else if(ch[i][j+3]==' '||ch[i][j+3]=='	'){
					if(ch[i][j+4]=='R'){
						if(ch[i][j+6]==','){
							if(ch[i][j+7]==' '||ch[i][j+7]=='	'){
								if(ch[i][j+8]>='0'&&ch[i][j+8]<='9'){
									//cout << "3";
									valid=true;
									z++;
								}
								else 
									valid = false;
							}
							else 
								valid = false;
						}
						else 
							valid = false;
					}
					else 
						valid = false;
				}
				else 
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error: on line " << i << " invalid oprand"<< endl;
					
				}
			}
			else if(ch[i][j]=='J'&&ch[i][j+1]=='G'&&ch[i][j+2]=='Z'){
				if(ch[i][j+4]=='\0'){
					cerr << "Error: on line " << i+1 << "missing oprand"<< endl;
					
				}
				else if(ch[i][j+3]==' '||ch[i][j+3]=='	'){
					if(ch[i][j+4]=='R'){
						if(ch[i][j+6]==','){
							if(ch[i][j+7]==' '||ch[i][j+7]=='	'){
								if((ch[i][j+8]>='0'&&ch[i][j+8]<='9')||ch[i][j+8]=='['){
									//cout << "4";
									valid=true;
									z++;
								}
								else 
									valid = false;
							}
							else 
								valid = false;
						}
						else 
							valid = false;
					}
					else 
						valid = false;
				}
				else 
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error: on line " << i << " invalid oprand"<< endl;
					
				}
			}
			else if(ch[i][j]=='J'&&ch[i][j+1]=='G'&&ch[i][j+2]=='E'&&ch[i][j+3]=='Z'){
				if(ch[i][j+5]=='\0'){
					cerr << "Error: on line " << i+1 << "missing oprand"<< endl;
					
				}
				else if(ch[i][j+4]==' '||ch[i][j+4]=='	'){
					if(ch[i][j+5]=='R'){
						if(ch[i][j+7]==','){
							if(ch[i][j+8]==' '||ch[i][j+8]=='	'){
								if(ch[i][j+9]>='0'&&ch[i][j+9]<='9'){
									//cout << "5";
									valid=true;
									z++;
								}
								else 
									valid = false;
							}
							else 
								valid = false;
						}
						else 
							valid = false;
					}
					else 
						valid = false;
				}
				else 
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error: on line " << i << " invalid oprand"<< endl;
					
				}
			}
			else if(ch[i][j]=='J'&&ch[i][j+1]=='L'&&ch[i][j+2]=='Z'){
				if(ch[i][j+4]=='\0'){
					cerr << "Error: on line " << i+1 << "missing oprand"<< endl;
				}
				else if(ch[i][j+3]==' '||ch[i][j+3]=='	'){
					if(ch[i][j+4]=='R'){
						if(ch[i][j+6]==','){
							if(ch[i][j+7]==' '||ch[i][j+7]=='	'){
								if(ch[i][j+8]>='0'&&ch[i][j+8]<='9'){
									//cout << "6";
									valid=true;
									z++;
								}
								else 
									valid = false;
							}
							else 
								valid = false;
						}
						else 
							valid = false;
					}
					else 
						valid = false;
				}
				else 
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error: on line " << i<< " invalid oprand"<< endl;
					
				}
			}
			else if(ch[i][j]=='J'&&ch[i][j+1]=='L'&&ch[i][j+2]=='E'&&ch[i][j+3]=='Z'){
				if(ch[i][j+5]=='\0'){
					cerr << "Error: on line " << i+1 << "missing oprand"<< endl;
				}
				else if(ch[i][j+4]==' '||ch[i][j+4]=='	'){
					if(ch[i][j+5]=='R'){
						if(ch[i][j+7]==','){
							if(ch[i][j+8]==' '||ch[i][j+8]=='	'){
								if((ch[i][j+9]>='0'&&ch[i][j+9]<='9')||ch[i][j+9]=='['){
									//cout << "5";
									valid=true;
									z++;
								}
								else 
									valid = false;
							}
							else 
								valid = false;
						}
						else 
							valid = false;
					}
					else 
						valid = false;
				}
				else 
					valid = false;
				i++;
				if(valid == false){
					cerr << "Error: on line " << i << " invalid oprand"<< endl;
					
				}
			}
			else{
				valid=false;
				i++;
			}
		}
		else
			i++;
	}		
		
			/*if((ch[i][0]=='\t'||ch[i][0]=='\0')&&ch[i][1]!='\0'){
				cerr << "Error: on line " << i<<" no opcode" << endl;
				i++;
				valid=false;
			}
			/*else if(ch[i][0]=='\0'&&ch[i][1]=='\0')
				i++;
			else
				i++;*/
	
	
		/*cout << "Code: ";
		for(int i=0; i<length-1; i++){
			cout << code[i];
		}
		cout << endl;
		cout << "Data: ";
		for(int i=0; i<length-1; i++){
			cout << data[i];
		}
		cout << endl;*/
		/*cout << "Number of start of code: " << start << endl;
		cout << "Number of middle of code: " << middle << endl;
		cout << "Number of end of code: " << end << endl;*/
		cout << "Code: " << code << endl;
		cout << "Data: " << data << endl;
		cout << "Total number of assembly instructions: " << x+y+z << "\n";
		cout << "Number of Load/Store: " << x << "\n";
		cout << "Number of ALU: " << y << "\n";
		cout << "Number of Compare/Jump: " << z << "\n";
	
	//cout << lengtha;
		
		// output to a file		
		
	if(endcode == true){	
		for(int i=0; i<=row; i++){
			cerr << "Error: on line " << i << " no opcode"<<endl;
			cerr << "Error: on line " << i << " invalid operand"<<endl;
			cerr << "Error: on line " << i << " missing operand"<<endl;
			cerr << "Error: on line " << i << " extra operand"<<endl;
			cerr << "Error: on line " << i << " missing directive"<<endl;
			cerr << "Error: on line " << i << " duplicate"<<endl;
			cout << endl;
		}
	}

	
	
	//cout <<lengtht;
	// close the file
	infile.close();
	outfile.close();
	
	return 0;

	
}