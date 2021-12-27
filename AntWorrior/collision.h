#pragma once
#include <iostream>
using namespace std;

static int border[201][201];

static void handleBorder(){

	// Fills the 2D array with 1.
	memset(border, 1, sizeof border);

	// Out of box
	for(int i = 0; i < 201; i++){
    
		// Z:
		border[8][i] = 0;
		border[199][i] = 0;

		// X:
		border[i][8] = 0;
		border[i][199] = 0;
	}

	// ========================================
	// GPU
	for(int i = 14; i < 129; i++){
		border[i][88] = 0;
		border[i][112] = 0;
    
		// Outside
		border[i][87] = 0;
		border[i][113] = 0;

		// Inside
		border[i][89] = 0;
		border[i][111] = 0;
	}
	for(int j = 87; j < 113; j++){
		border[15][j] = 0;
		border[128][j] = 0;

		// Outside
		border[14][j] = 0;
		border[129][j] = 0;
    
		//Inside
		border[16][j] = 0;
		border[127][j] = 0;
	}
	// GPU Door
	for(int i = 100; i < 113; i++){
		border[129][i] = 1;
		border[128][i] = 1;
		border[127][i] = 1;
	}

	// ========================================
	// CPU
	for(int i = 135; i < 177; i++){
		for(int j = 23; j < 65; j++){
			border[i][j] = 0;
		}
	}
	// CPU Glass
	for(int i = 123; i < 200; i++){
		border[i][72] = 0;
		// Outside
		border[i][73] = 0;
		// Inside
		border[i][71] = 0;
	}
	for(int j = 7; j < 73; j++){
		border[124][j] = 0;
		// Outside
		border[123][j] = 0;
		// Inside
		border[125][j] = 0;
	}
	// CPU Door
	for(int i = 64; i < 73; i++){
		border[123][i] = 1;
		border[124][i] = 1;
		border[125][i] = 1;
	}

	// ========================================
	// Fan
	for(int i = 7; i < 65; i++){
		for(int j = 7; j < 65; j++){
			//border[i][j] = 2;
			border[i][j] = 1;
		}
	}
	// Fan Glass
	for(int i = 7; i < 77; i++){
		border[i][72] = 0;
		// Outside
		border[i][73] = 0;
		// Inside
		border[i][71] = 0;
	}
	for(int j = 7; j < 73; j++){
		border[76][j] = 0;
		// Outside
		border[77][j] = 0;
		// Inside
		border[75][j] = 0;
	} 
	// Fan Door
	for(int i = 64; i < 73; i++){
		border[75][i] = 1;
		border[76][i] = 1;
		border[77][i] = 1;
	}

	// ========================================
	// RAM
	for(int i = 151; i < 189; i += 12){
		for(int j = i; j < i + 6; j++){
			border[j][87] = 0 ;
			border[j][185] = 0 ;
		}
		for(int j = 87; j < 185; j++){
			border[i][j] = 0;
			border[i + 6][j] = 0;
		}
	}
	// RAM Glass
	for(int i = 139; i < 200; i++){
		border[i][80] = 0;
		// Outside
		border[i][79] = 0;
		// Inside
		border[i][81] = 0;
	}
	for(int j = 79; j < 200; j++){
		border[140][j] = 0;
		// Outside
		border[139][j] = 0;
		// Inside
		border[141][j] = 0;
	}
	// Door
	for(int i = 139; i < 151; i++){
		border[i][79] = 1;
		border[i][80] = 1;
		border[i][81] = 1;
	}

	// ========================================
	// SSDs
	for(int i = 23; i < 104 ; i += 24){
		for(int j = i; j < i + 9; j++){
			border[j][134] = 0;
			border[j][185] = 0;
		}
		for(int j = 134; j < 185; j ++){
			border[i][j] = 0;
			border[i + 9][j] = 0;
		}
	}
	// SSD Glass
	for(int i = 7; i < 121; i++){
		border[i][128] = 0;
		// Outside
		border[i][127] = 0;
		// Inside
		border[i][129] = 0;
	}
	for(int j = 127; j < 200; j++){
		border[120][j] = 0;
		// Outside
		border[121][j] = 0;
		// Inside
		border[119][j] = 0;
	}
	// SSD Door
	for(int i = 108; i < 121; i++){
		border[i][129] = 1;
		border[i][128] = 1;
		border[i][127] = 1;
	}

	// ========================================
	// Transistor 1
	for(int i = 103; i < 113; i++){
		for(int j = 31; j < 41; j++){
			border[i][j] = 0;
		}
	}

	// ========================================
	// Transistor 2
	for(int i = 87; i < 97; i++){
		for(int j = 31; j < 41; j++){
			border[i][j] = 0;
		}
	}
}