#include <stdbool.h> 
#include <stdio.h> 
void printsol(int b[8][8]) 
{ 
    for (int i = 0; i < 8; i++) { 
        for (int j = 0; j < 8; j++) 
            printf(" %d ", b[i][j]); 
        printf("\n"); 
    } 
} 
bool safe_to_place(int b[8][8], int r, int c) 
{ 
    int i, j; 
    for (i = 0; i < c; i++) 
        if (b[r][i]) 
            return false; 
 
    for (i = r, j = c; i >= 0 && j >= 0; i--, j--) 
        if (b[i][j]) 
            return false; 
    for (i = r, j = c; j >= 0 && i < 8; i++, j--) 
        if (b[i][j]) 
            return false; 
   
    return true; 
} 
 
bool NQueenSolution(int b[8][8], int c){
    if (c >= 8) 
        return true; 
   
    
    for (int i = 0; i < 8; i++) { 
       if (safe_to_place(b, i, c)) { 
          
            b[i][c] = 1; 
   
          
            if (NQueenSolution(b, c + 1)) 
                return true; 
 
            b[i][c] = 0;
        } 
    } 
   
    
    return false; 
}
void main(){
    int b[8][8]={ { 0, 0, 0, 0,0, 0, 0, 0 },
                        {0, 0, 0, 0,0, 0, 0, 0 },
                        {0, 0, 0, 0,0, 0, 0, 0 },
                        { 0, 0, 0, 0,0, 0, 0, 0 },{0, 0, 0, 0,0, 0, 0, 0 },
                        {0, 0, 0, 0,0, 0, 0, 0 },
                        {0, 0, 0, 0,0, 0, 0, 0 },
                        { 0, 0, 0, 0,0, 0, 0, 0} };
     if (NQueenSolution(b, 0) == false) { 
        printf("Could not find any solution"); 
        return 0; 
    }                    
    printsol(b);
}
