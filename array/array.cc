#include "array.h"

template<int N, typename T>
Array<N, T>::Array() {}

template<int N, typename T>
Array<N, T>::Array(const char* in) {
	
	int i;
	
	for (i = 0; in[i]; i++) {
		
		a[i] = in[i]; 
	
	}
	
	a[i + 1] = '\n';
}

template<int N, typename T>
Array<N, T>::Array(T in[]) {
	int i;
	
	for (i = 0; i<N; i++) {
		a[i] = in[i]; 
	
	}
}

template<int N, typename T>
T& Array<N, T>::operator [] (int in) {
	return a[in];
}

template<int N, typename T>
void Array<N, T>::operator = (const char* in) {
	
	int i;
	
	for (i = 0; in[i]; i++) {
		
		a[i] = in[i]; 
	}
	
	a[i + 1] = '\n';
}

template<int N, typename T>
std::ostream& Array<N, T>::print(std::ostream& sout) {
	

	if (sizeof(a[0]) == 1) {
	
		for (int i = 0; a[i]; i++) {
			
			sout << a[i];
		
		}
	}
	
	else {

		sout << '[';

		for (int i = 0; i < N; i++) {
			
			sout << a[i];

			if (i != N - 1 )
				sout << ", "; 
		
		}

		sout << ']';
	}
	
	return sout;
}

int main() {
	
	using namespace std;

	Array<20, int> a = "baddy";
	a.print(cout);
}