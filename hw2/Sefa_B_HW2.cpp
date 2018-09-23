#include "Sefa_B_HW2.h"


/*NOTE you don't necessarily need to he asserts 
 * in the function besides the one where data is inputted, 
 * but its good to have if any error may occur.*/

//Fill array with elements
void takeUserInputRetSize(char arr[], size_t& size){
	char c ;
	size = 0;
	while(size < MAXSIZE && cin >> c && isalpha(c)){
		arr[size] = c;
		size++;
	}	
	//return size;
}
size_t highestOccurances(char arr[ ], size_t size){
	//NOTE array is static 
	assert(size <= MAXSIZE && size > 0);
	size_t hOccurrance = 0;
	char letter = '{';
	size_t countingOccurrance = 0;
	for(size_t i = 0; i < size; i++){
		countingOccurrance= 0;
		//letter = arr[i];
		countingOccurrance++;
		for(size_t j = i+1; j < size; j++){
			if(arr[i] == arr[j]){
				countingOccurrance++;
				arr[j] = arr[size-1];
				size--;
				j--;
			}

		}
		if(countingOccurrance >= hOccurrance){
			if((int)letter > (int)arr[i]){
				letter = arr[i];
				hOccurrance = countingOccurrance; 
			}
		}
		//countingOccurrance = 0;
	}
	cout << letter << endl;
	return hOccurrance;
}
void shiftArray(char arr[], size_t size, int shift){
	assert(size<=MAXSIZE && size >0 );
	if(abs(shift)>size){
		shift = shift%size;
	}
	if(abs(shift)==(-shift)){
		shift = size + shift;
	}
	for(size_t i = 0; i < size/2; i++){
		char temp = arr[i];
		arr[i] = arr[size-1-i];
		arr[size-1-i] = temp;
	}
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	for(size_t i = 0; i <= (shift-1)/2; i++){
		char temp = arr[i];
		arr[i] = arr[shift-1-i];
		arr[shift-1-i] = temp;
	}
		for(int i = 0; i < size; i++){
					cout << arr[i] << " ";
						}
			cout << endl;
	size_t z =1;
	for(size_t i = shift; i < shift+((size-shift)/2); i++){
		char temp = arr[i];
		arr[i] = arr[size-z];
		arr[size-z] = temp;
		z++;
	}
		for(int i = 0; i < size; i++){
					cout << arr[i] << " ";
						}
			cout << endl;
}

//NOTE ar1 and ar2 are already pre-sorted. //Precondiiton 
char* appendAndSort(const char* arr1, const size_t arr1Size, const char* arr2, const size_t arr2Size, int& arrSize){
	assert((arr1Size + arr2Size) <= MAXSIZE);
	char* arr = new char[arr1Size+arr2Size]; /*NOTE its the size of both^ not necessarily MAXSIZE*/
	size_t arrI = 0, arr1I = 0, arr2I = 0;

	/*Fill in arr with order form arr1 and arr2. NOTE one of them will max out*/
	while(arr1I < arr1Size && arr2I < arr2Size){
		cout << arr1[arr1I] << " and " << arr2[arr2I] << endl;  
		if((int)arr1[arr1I] < (int)arr2[arr2I] ){
			arr[arrI++] = arr1[arr1I++];
			//arrI++;
			//arr1I++;
		}
		else{ //if((int)arr1[arr1I] > (int)arr2[arr2I]){
			arr[arrI++] = arr2[arr2I++];
			//arrI++;
			//arr2I++;
		}
		cout << arr[arrI] << " " << arrI << endl;
	}
	/*If one of them didn't max out, max it out here*/
	while(arr1I < arr1Size){
		arr[arrI++] = arr1[arr1I++];
		//arrI++;
		//arr1I++;
		//cout << arr[arrI] << " " << arrI << endl;
	}
	while(arr2I < arr2Size){
		arr[arrI++] = arr2[arr2I++];
		//arrI++;
		//arr2I++;
	}
	arrSize = arrI;
	cout << arrI;
	return arr;
}



/*NOTE this function does NOT work. Rewritting below.*/
#if 0
//char** mNMatrix(size_t& x, size_t& y){
void mNMatrix(char** arr, size_t& x, size_t& y){
	size_t m, n;
	cin >> m >> n;
	assert(m <= MAXSIZE && m > 0 && n <= MAXSIZE && n>0 );
	//char** arr;
	arr = new char*[m];
	char c;
	int i = 0, j=0;
	for(int a = 0; a < m; a++){
		arr[a] = new char[n];
	}
	
	//assert(m <= MAXSIZE && m > 0 && n <= MAXSIZE && n>0 ); //NOTE i said greater than 0 because a matirx must have a row/column to put into...
	/*for(size_t i = 0; i < m; i++){
		for(int j = 0; j < n; j++ ){
			cin >> c; 
			arr [i]
		}
	}*/
	while(i != m){
		j = 0;
		while(j != n){ //&& cin >> c){
			cin >> arr[i][j];
			j++;
		}
		//j = 0;
		i++;
	}
	x = m;
	y = n;
	//return arr;
}
#endif

void rotateMatrix(int position){
}
char**  enlargeMatrix(size_t scale, char** c, size_t m, size_t n){
	/*NOTE check if scale has to be bigger or smaller..*/
	char** arr = new char*[scale*m];
	for(size_t i = 0; i <(scale*m); i++){
		arr[i] = new char[scale*n];
	}
	//Assuming bigger...

	return arr;
}

char** mNMatrix(size_t& x, size_t& y){
	size_t m;
	size_t n;
	cin >> m;
	cin >> n;
	assert(m <= MAXSIZE && m > 0 && n <= MAXSIZE && n>0 );

	char **matrix;
	matrix = new char*[m];
	for(int i = 0; i < m; i++){
		matrix[i] = new char[n];
	}
	int row = 0;
	int column = 0;

	while(row!=m){
		column = 0;
		while(column!=n){
			cin >> matrix[row][column];
			column++;
		}
		row++;
	}

	x = m;
	y = n;
	return matrix;


}

