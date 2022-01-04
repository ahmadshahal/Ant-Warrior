#pragma once
#include <iostream>
using namespace std;

static int border[3600][3600];

static void handleBorder(){

	// Fills the 2D array with 1.
	memset(border, 1, sizeof border);

	// Out of box
	for(int i = 0; i <= 3500; i++){
    
		// Z:
		border[140][i] = 0;
		border[3482][i] = 0;

		// X:
		border[i][140] = 0;
		border[i][3482] = 0;
	}

	// ========================================
	// GPU
	for(int i = 245; i < 2258; i++){
		border[i][1540] = 0;
		border[i][1960] = 0;
    
		// Outside
		border[i][1539] = 0;
		border[i][1961] = 0;

		// Inside
		border[i][1541] = 0;
		border[i][1959] = 0;
	}
	for(int j = 1522; j < 1977; j++){
		border[262][j] = 0;
		border[2240][j] = 0;

		// Outside
		border[261][j] = 0;
		border[2241][j] = 0;
    
		//Inside
		border[280][j] = 0;
		border[2239][j] = 0;
	}
	// GPU Door
	for(int i = 1750; i < 1977; i++){
		border[2241][i] = 1;
		border[2240][i] = 1;
		border[2239][i] = 1;
	}
	// ========================================
	// CPU
	for(int i = 2344; i < 3115; i++){
		for(int j = 384; j < 1155; j++){
			border[i][j] = 0;
		}
	}
	// CPU Glass
	for(int i = 2152; i < 3500; i++){
		border[i][1260] = 0;
		// Outside
		border[i][1261] = 0;
		// Inside
		border[i][1259] = 0;
	}
	for(int j = 122; j < 1277; j++){
		border[2170][j] = 0;
		// Outside
		border[2169][j] = 0;
		// Inside
		border[2171][j] = 0;
	}
	// CPU Door
	for(int i = 1120; i < 1277; i++){
		border[2169][i] = 1;
		border[2170][i] = 1;
		border[2171][i] = 1;
	}
	// ========================================
	// Fan
	for(int i = 122; i < 1137; i++){
		for(int j = 122; j < 1137; j++){
			border[i][j] = 2;
			//border[i][j] = 1;
		}
	}
	// Fan Glass
	for(int i = 122; i < 1347; i++){
		border[i][1260] = 0;
		// Outside
		border[i][1261] = 0;
		// Inside
		border[i][1259] = 0;
	}
	for(int j = 122; j < 1277; j++){
		border[1330][j] = 0;
		// Outside
		border[1331][j] = 0;
		// Inside
		border[1329][j] = 0;
	} 
	// Fan Door
	for(int i = 1120; i < 1277; i++){
		border[1329][i] = 1;
		border[1330][i] = 1;
		border[1331][i] = 1;
	}

	// ========================================
	// RAM
	for(int i = 2640; i < 3110; i ++){
		for(int j = 1630 ; j < 3130; j++){
			border[i][j] = 0 ;
		}	
	}
	// RAM Glass
	for(int i = 2432; i < 3500; i++){
		border[i][1400] = 0;
		// Outside
		border[i][1399] = 0;
		// Inside
		border[i][1401] = 0;
	}
	for(int j = 1382; j < 3500; j++){
		border[2450][j] = 0;
		// Outside
		border[2449][j] = 0;
		// Inside
		border[2451][j] = 0;
	}
	// Door
	for(int i = 2432; i < 2642; i++){
		border[i][1399] = 1;
		border[i][1400] = 1;
		border[i][1401] = 1;
	}

	// ========================================
	// SSDs
	for(int i = 402; i < 1820 ; i += 420){
		for(int j = i; j < i + 158; j++){
			border[j][2345] = 0;
			border[j][3237] = 0;
		}
		for(int j = 2345; j < 3237; j ++){
			border[i][j] = 0;
			border[i + 158][j] = 0;
		}
	}
	// SSD Glass
	for(int i = 122; i < 2117; i++){
		border[i][2240] = 0;
		// Outside
		border[i][2239] = 0;
		// Inside
		border[i][2241] = 0;
	}
	for(int j = 2222; j < 3500; j++){
		border[2100][j] = 0;
		// Outside
		border[2101][j] = 0;
		// Inside
		border[2099][j] = 0;
	}
	// SSD Door
	for(int i = 1890; i < 2117; i++){
		border[i][2239] = 1;
		border[i][2240] = 1;
		border[i][2241] = 1;
	}

	// ========================================
	// Transistor 1
	for(int i = 1802; i < 1977; i++){
		for(int j = 542; j < 717; j++){
			border[i][j] = 0;
		}
	}

	// ========================================
	// Transistor 2
	for(int i = 1522; i < 1697; i++){
		for(int j = 542; j < 717; j++){
			border[i][j] = 0;
		}
	}
	//Capacitor
	for(int i = 3300; i <= 3420 ; i ++ ){
		for(int j = 500 ; j <= 620 ; j++ ){
			border[i][j] = 0;
		}
	}

	for(int i = 3300 ; i <= 3420 ; i++ ) {
		for(int j = 1050 ; j <= 1180 ; j++) {
			border[i][j] = 0;
		}
	}
}