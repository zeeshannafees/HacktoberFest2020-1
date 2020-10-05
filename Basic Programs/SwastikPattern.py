// C++ implementation to 
// print swastika pattern 
#include <bits/stdc++.h> 
using namespace std; 

// function to print swastika 
void swastika(int row, int col) 
{ 
for (int i = 0; i < row; i++) { 
	for (int j = 0; j < col; j++) { 
    if (i < row / 2) {  
		if (j < col / 2) { 
		if (j == 0) 
			cout << "*"; 
		else
			cout << " " << " "; 
		} 
		
		else if (j == col / 2) 
		cout << " *"; 
		else
		{ 
		if (i == 0) 
			cout << " *"; 
		} 
	} 
	else if (i == row / 2) 
		cout << "* "; 
	else { 
		
		if (j == col / 2 || j == col - 1) 
		cout << "* "; 
		
		else if (i == row - 1) { 
			
		if (j <= col / 2 || j == col - 1) 
			cout << "* "; 
		else
			cout << " " << " "; 
		} 
		else
		cout << " " << " "; 
	} 
	} 
	cout << "\n"; 
} 
} 

int main() 
{ 
  int row = 7, col = 7; 
  swastika(row, col); 	
  return 0; 
} 
