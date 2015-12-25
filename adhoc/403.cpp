#include <bits/stdc++.h>
using namespace std;

#define REC(i, a, b)	for(int i = int(a); i <= int(b); i++)
#define pb push_back
#define mp	make_pair
#define sz(v) int((v).size())

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef	vector<ii> vii;
typedef vector<vi> vvi;

char A[70][70];

void Inicializa();
void Imprime();
void _A(int linha, int coluna);
void _B(int linha, int coluna);
void _C(int linha, int coluna);
void _D(int linha, int coluna);
void _E(int linha, int coluna);
void _F(int linha, int coluna);
void _G(int linha, int coluna);
void _H(int linha, int coluna);
void _I(int linha, int coluna);
void _J(int linha, int coluna);
void _K(int linha, int coluna);
void _L(int linha, int coluna);
void _M(int linha, int coluna);
void _N(int linha, int coluna);
void _O(int linha, int coluna);
void _P(int linha, int coluna);
void _Q(int linha, int coluna);
void _R(int linha, int coluna);
void _S(int linha, int coluna);
void _T(int linha, int coluna);
void _U(int linha, int coluna);
void _V(int linha, int coluna);
void _W(int linha, int coluna);
void _X(int linha, int coluna);
void _Y(int linha, int coluna);
void _Z(int linha, int coluna);


int main(){
	
	char c;
	int row, col;
	Inicializa();
	while(scanf( " %c", &c) != EOF){
		c = getchar();
		if(c == 'E'){
			c = getchar();c = getchar();c = getchar();
			Imprime();
			Inicializa();
		}
		else if(c == 'L'){
			scanf(" %c", &c);
			scanf("%c%d", &c, &row);
			if(c == '1'){
				scanf(" %c", &c);
				c = getchar();
				col = 1;
				while(c != '|'){
					if(col >= 1 && col <= 60 && !isspace(c))
						A[row][col] = c;
					col++;
					c = getchar();
				}
			}
			else{
				scanf(" %c", &c);
				c = getchar();
				col = 1;
				while(c != '|'){
					switch(c){
						case 'A':_A(row,col);break;
						case 'B':_B(row,col);break;
						case 'C':_C(row,col);break;
						case 'D':_D(row,col);break;
						case 'E':_E(row,col);break;
						case 'F':_F(row,col);break;
						case 'G':_G(row,col);break;
						case 'H':_H(row,col);break;
						case 'I':_I(row,col);break;
						case 'J':_J(row,col);break;
						case 'K':_K(row,col);break;
						case 'L':_L(row,col);break;
						case 'M':_M(row,col);break;
						case 'N':_N(row,col);break;
						case 'O':_O(row,col);break;
						case 'P':_P(row,col);break;
						case 'Q':_Q(row,col);break;
						case 'R':_R(row,col);break;
						case 'S':_S(row,col);break;
						case 'T':_T(row,col);break;
						case 'U':_U(row,col);break;
						case 'V':_V(row,col);break;
						case 'W':_W(row,col);break;
						case 'X':_X(row,col);break;
						case 'Y':_Y(row,col);break;
						case 'Z':_Z(row,col);break;
						
					}
					c = getchar();
					col += 6;
				}
				
			}
		}
		else if(c == 'P'){
			scanf(" %c", &c);
			scanf("%c%d%d", &c, &row, &col);
			if(c == '1'){
				scanf(" %c", &c);
				c = getchar();
				
				while(c != '|'){
					if(col >= 1 && col <= 60 && !isspace(c))
						A[row][col] = c;
					c = getchar();
					col++;
				}
				
			}
			else{
				scanf(" %c", &c);
				c = getchar();
				
				while(c != '|'){
					switch(c){
						case 'A':_A(row,col);break;
						case 'B':_B(row,col);break;
						case 'C':_C(row,col);break;
						case 'D':_D(row,col);break;
						case 'E':_E(row,col);break;
						case 'F':_F(row,col);break;
						case 'G':_G(row,col);break;
						case 'H':_H(row,col);break;
						case 'I':_I(row,col);break;
						case 'J':_J(row,col);break;
						case 'K':_K(row,col);break;
						case 'L':_L(row,col);break;
						case 'M':_M(row,col);break;
						case 'N':_N(row,col);break;
						case 'O':_O(row,col);break;
						case 'P':_P(row,col);break;
						case 'Q':_Q(row,col);break;
						case 'R':_R(row,col);break;
						case 'S':_S(row,col);break;
						case 'T':_T(row,col);break;
						case 'U':_U(row,col);break;
						case 'V':_V(row,col);break;
						case 'W':_W(row,col);break;
						case 'X':_X(row,col);break;
						case 'Y':_Y(row,col);break;
						case 'Z':_Z(row,col);break;
						
					}
					c = getchar();
					col += 6;
				}
				
			}
		}
		else if(c == 'R'){
			scanf(" %c", &c);
			scanf("%c%d", &c, &row);
			if(c == '1'){
				scanf(" %c", &c);
				c = getchar();
				char stri[100];
				int cont = 0, i = 0;
				while(c != '|'){
					stri[cont++] = c;
					c = getchar();
				}
				col = 60 - cont + 1;

				while(i < cont){
					if(col >= 1 && col <= 60 && !isspace(stri[i]) )
						A[row][col] = stri[i];
					i++;
					col++;
				}
				
			}
			else{
				scanf(" %c", &c);
				c = getchar();
				char stri[100];
				int cont = 0, i = 0;
				while(c != '|'){
					stri[cont++] = c;
					c = getchar();
				}
				col = 60 - cont*6 + 1;

				while(i < cont){
					
					switch(stri[i++]){
						case 'A':_A(row,col);break;
						case 'B':_B(row,col);break;
						case 'C':_C(row,col);break;
						case 'D':_D(row,col);break;
						case 'E':_E(row,col);break;
						case 'F':_F(row,col);break;
						case 'G':_G(row,col);break;
						case 'H':_H(row,col);break;
						case 'I':_I(row,col);break;
						case 'J':_J(row,col);break;
						case 'K':_K(row,col);break;
						case 'L':_L(row,col);break;
						case 'M':_M(row,col);break;
						case 'N':_N(row,col);break;
						case 'O':_O(row,col);break;
						case 'P':_P(row,col);break;
						case 'Q':_Q(row,col);break;
						case 'R':_R(row,col);break;
						case 'S':_S(row,col);break;
						case 'T':_T(row,col);break;
						case 'U':_U(row,col);break;
						case 'V':_V(row,col);break;
						case 'W':_W(row,col);break;
						case 'X':_X(row,col);break;
						case 'Y':_Y(row,col);break;
						case 'Z':_Z(row,col);break;
						
					}
					col += 6;
				}
				
			}
		}
		else if(c == 'C'){
			scanf(" %c", &c);
			scanf("%c%d", &c, &row);
			if(c == '1'){
				scanf(" %c", &c);
				c = getchar();
				char stri[100];
				int cont = 0, i = 0;
				while(c != '|'){
					stri[cont++] = c;
					c = getchar();
				}
				if(cont%2)
					col = 31 - cont/2;
				else
					col = 30 - cont/2 + 1;// Cuidado aqui!!!!

				while(i < cont){
					if(col >= 1 && col <= 60 && !isspace(stri[i]) )
						A[row][col] = stri[i];
					i++;
					col++;
				}
				
			}
			else {
				scanf(" %c", &c);
				c = getchar();
				char stri[100];
				int cont = 0, i = 0;
				while(c != '|'){
					stri[cont++] = c;
					c = getchar();
				}
				col = 30 - cont*3 + 1;

				while(i < cont){
					
					switch(stri[i++]){
						case 'A':_A(row,col);break;
						case 'B':_B(row,col);break;
						case 'C':_C(row,col);break;
						case 'D':_D(row,col);break;
						case 'E':_E(row,col);break;
						case 'F':_F(row,col);break;
						case 'G':_G(row,col);break;
						case 'H':_H(row,col);break;
						case 'I':_I(row,col);break;
						case 'J':_J(row,col);break;
						case 'K':_K(row,col);break;
						case 'L':_L(row,col);break;
						case 'M':_M(row,col);break;
						case 'N':_N(row,col);break;
						case 'O':_O(row,col);break;
						case 'P':_P(row,col);break;
						case 'Q':_Q(row,col);break;
						case 'R':_R(row,col);break;
						case 'S':_S(row,col);break;
						case 'T':_T(row,col);break;
						case 'U':_U(row,col);break;
						case 'V':_V(row,col);break;
						case 'W':_W(row,col);break;
						case 'X':_X(row,col);break;
						case 'Y':_Y(row,col);break;
						case 'Z':_Z(row,col);break;
						default:;
						
					}
					col += 6;
				}
				
			}
		}
	}

	
	return 0;
}

void Inicializa(){
	REC(i, 1, 60){
		REC(j, 1, 60)
			A[i][j] = '.';
	}
}
void Imprime(){
	REC(i, 1, 60){
		REC(j, 1, 60){
			printf("%c",A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	REC(i,1,60)	printf("-");
	printf("\n\n");
}

void _A(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
			if(i == linha){
				if(!(j == coluna || j >= coluna+4))	A[i][j] = '*';
			}
			else if(i != linha+2){
				if(j == coluna || j == coluna+4)	A[i][j] = '*';
			}
			else{
				if(j != coluna+5)	A[i][j] = '*';
			}
		}
		}
	}
}
void _B(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
			if(i == linha || i == linha+2 || i == linha+4){
				if(!(j >= coluna+4)) A[i][j] = '*';
			}
			else{
				if(j == coluna || j == coluna+4)	A[i][j] = '*';
			}
		}
		}
	}
}
void _C(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(i == linha+1 && j == coluna+4)	A[i][j] = '*';
				else if(i == linha || i == linha+4){
					if(j == coluna)	;
					else A[i][j] = '*';
				}
				else{
					if(j == coluna)	A[i][j] = '*';
					else	;
				}
			}
		}
	}
}
void _D(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(i == linha || i == linha+4){
					if(j == coluna+4);
					else	A[i][j] = '*';
				}
				else{
					if(j == coluna || j == coluna+4)	A[i][j] = '*';
					else	;
				}
			}
		}
	}
}
void _E(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
			if(i == linha || i == linha+4){
				A[i][j] = '*';
			}
			else if(i == linha+2){
				if (j <= coluna+2)	A[i][j] = '*';
				else	;
			}
			else{
				if(j == coluna)	A[i][j] = '*';
				else	;
			}
		}
		}
	}
}
void _F(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
			if(i == linha){
				A[i][j] = '*';
			}
			else if(i == linha+2){
				if (j <= coluna+2)	A[i][j] = '*';
				else	;
			}
			else{
				if(j == coluna)	A[i][j] = '*';
				else	;
			}
		}
		}
	}
}
void _G(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(i == linha){
					if(j > coluna)	A[i][j] = '*';
					else	;
				}
				if(i == linha+1){
						if(j > coluna)	;
						else	A[i][j] = '*';
				}
				if(i == linha+2){
						if(j == coluna + 1 || j == coluna+2)	;
						else	A[i][j] = '*';
				}
				if(i == linha+3){
					if(j == coluna || j == coluna+4)	A[i][j] = '*';
					else	;				
				}
				if(i == linha+4){
					if(j == coluna || j == coluna+4)	;
					else	A[i][j] = '*';
				}
			}
			
		}
	}
}
void _H(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(j == coluna || j == coluna+4 || i == linha+2)	A[i][j] = '*';
				else	;
			}
			
		}
	}
}
void _I(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(i == linha || i == linha+4 || j == coluna+2)	A[i][j] = '*';
				else	;
			}
			
		}
	}
}
void _J(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(j == coluna+ 3)	{
					if(i != linha+4)	A[i][j] = '*';
					else	;
				}
				else if(i == linha && j > coluna+1)	A[i][j] = '*';
				else if(i == linha+4 && (j == coluna+1 || j == coluna+2))	A[i][j] = '*';
				else if(i == linha+3 && j == coluna)	A[i][j] = '*';
				else	;
			}
			
		}
	}
}
void _K(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(j == coluna)	A[i][j] = '*';
				else if(i == linha+2 && j <= coluna+2)	A[i][j] = '*';
				else if(j > coluna+2 && (i-linha == j-coluna || i-linha+j-coluna == 4)) A[i][j] = '*';
				else ;
			}
			
		}
	}
}
void _L(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(j == coluna || i == linha+4)	A[i][j] = '*';
				else ;			}
			
		}
	}
}
void _M(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(j == coluna || j == coluna+4)	A[i][j] = '*';
				else if(i <= linha+2 && (i-linha == j-coluna || i-linha+j-coluna == 4)) A[i][j] = '*';
				else ;			
			}
			
		}
	}
}
void _N(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(j == coluna || j == coluna+4)	A[i][j] = '*';
				else if(i-linha == j-coluna ) A[i][j] = '*';
				else ;			
			}
			
		}
	}
}
void _O(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if((j == coluna || j == coluna+4 || i == linha || i == linha+4) && i-linha != j-coluna && i-linha + j-coluna != 4)	A[i][j] = '*';
				else ;			
			}
			
		}
	}
}
void _P(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(j == coluna || ((i == linha || i == linha+2) && j < coluna+4) || (i == linha+1 && j == coluna+4))	A[i][j] = '*';
				else ;			
			}
			
		}
	}
}
void _Q(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if((j == coluna || j == coluna+4 || i == linha || i == linha+4) && i-linha != j-coluna && i-linha + j-coluna != 4)	A[i][j] = '*';
				else if((i == linha+3 && j == coluna+3) || (i == linha+4 && j == coluna+4))	A[i][j] = '*';
				else ;			
			}
			
		}
	}
}
void _R(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(j == coluna || ((i == linha || i == linha+2) && j < coluna+4) || (i == linha+1 && j == coluna+4) || (i-linha == j-coluna &&  i>linha+1))	A[i][j] = '*';
				else ;			
			}
			
		}
	}
}
void _S(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(i == linha && j > coluna) A[i][j] = '*';
				else if (i == linha+4 && j < coluna+4)	A[i][j] = '*';
				else if(i == linha+2 && (j != coluna && j != coluna+4))	A[i][j] = '*';
				else if((j == coluna && i == linha+1) || (i == linha+3 && j == coluna+4))	A[i][j] = '*';
				else	;		
			}
			
		}
	}
}
void _T(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(i == linha || j == coluna+2 || (i == linha+4 && (j == coluna+1 || j == coluna+3)) || (i==(linha+1) && (j == coluna || j ==coluna+4)))	A[i][j] = '*';
				else	;	
			}
			
		}
	}
}
void _U(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(((j == coluna || j == coluna+4) && i != linha+4) || (i == linha+4 && (j != coluna && j != coluna+4)))A[i][j] = '*';
				else ;
			}
			
		}
	}
}
void _V(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if((j == coluna || j == coluna+4) && i <= linha+1) A[i][j] = '*';
				else if((j == coluna+1 || j == coluna+3) && (i >= linha+2 && i <= linha+3))	A[i][j] = '*';
				else if(i == linha+4 && j == coluna+2)A[i][j] = '*';
				else	;
			}
			
		}
	}
}
void _W(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(j == coluna || j == coluna+4) A[i][j] = '*';
				else if(i >= linha+2 && (i-linha == j-coluna || i-linha+j-coluna == 4))A[i][j] = '*';
				else	;
			}
			
		}
	}
}
void _X(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(i-linha == j-coluna || i-linha+j-coluna == 4) A[i][j] = '*';
				else	;
			}
			
		}
	}
}
void _Y(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(((i-linha == j-coluna || i-linha+j-coluna == 4) && i <= linha+2) || (i >= linha+2 && j == coluna+2)) A[i][j] = '*';
				else	;
			}
			
		}
	}
}
void _Z(int linha, int coluna){
	REC(i, linha, linha + 4){
		REC(j, coluna, coluna + 4){
			if(i <= 60 && i >= 1 && j >= 1 && j <= 60){
				if(i == linha || i == linha+4 || i-linha+j-coluna == 4) A[i][j] = '*';
				else	;
			}
			
		}
	}
}

