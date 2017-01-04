#include <iostream>
	#include <string>
	#include <algorithm>
	using namespace::std;
	void main(){int dest[4][5]; 
string cities[4];
	int cityindex[] = {0,1,2,3};
	int bestroute[4];
	int shortestpath = 99999;
	int currentpath = 0;
cout << "Please enter four city prefixes..." << endl;
	for(int i=0; i<4; i++){
	cout << i+1 << ".";
	cin >> cities[i];
	}
	cout << endl << "Now we need some distances..." <<endl;
	cout << "The first distance is from home to the first city."<<endl;
cout << "All other distances are from city A to city B.  When asked for the same city, please input 0 as the distance." << endl;
	for(int x=0; x<4; x++){
	cout << "Distances for "<< cities[x] << ":"<<endl;
for(int y=0; y<5; y++){
	if(y < 1){
	cout << "Home:";
	}else{
	cout << cities[y-1] << ":";
	}
	cin >> dest[x][y];
}sort(cityindex, cityindex+3);
do {
	currentpath = 0;
	currentpath = dest[cityindex[0]][0];
	for(int z=0; z<3; z++){
	int g = z + 1;
	currentpath += dest[cityindex[z]][cityindex[g]];
	}
	if(currentpath < shortestpath){
	shortestpath = currentpath;
	for(int a=0; a<4; a++){
	bestroute[a] = cityindex[a];
	}
	}
	} while ( next_permutation (cityindex,cityindex+3) );
	cout << "The Shortest Route is.." << endl;
	for(int b=0; b<4; b++){
	cout << cities[bestroute[b]] << " ";
	}
cin.ignore();
	cin.clear();
	cin.get();
	return;
	}
