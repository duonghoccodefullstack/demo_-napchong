#include <iostream> 
#include <cmath>

using namespace std;

void canbachai (int n) {
	int sum = sqrt (n );
	cout << sum  << endl;
}
void tamgiacvuong (int n ) {
	for (int i = 0 ; i < n ; i ++ )  {
		for (int j = 0 ; j < i ; j++ )  {
			cout << "*";
			
		}
		cout << endl;
	}
}

void hinhvuong (int n ) {
	for ( int i = 0 ; i < n ; i ++ ) {
		for (int j = 1 ; j < n ; j ++ ) {
			cout << " *";
		}
		cout << endl;
	}
}

void tamgiacnguoc(int n) {
	  for( int i = 0; i < n; i++) {
      	for(int j=0; j<i; j++)
        	{
        	cout << " ";	
			} 
      for(int j=i; j < n; j++) {
      		cout << "*";
	  		}
	  	cout << endl;	
	  		 }
      
   }

void tamgiaccan (int n ) {
		for (int i = 0 ; i < n ; i ++ )  {
		for (int j = 0 ; j < i ; j++ )  {
			cout << "*";
			
		}
		
		
		cout << endl;
	}
	
		for (int i = n ; i > n -1  ; i ++ ) {
			for (int j = 1 ; j > i ; j--) {
				cout << " *" ;
			}
			cout << endl;
		}
}

int main () {
	int n = 5;
	//cin >> n;
	//canbachai(n);
	//cout << "tam giac vuong" << endl;
	//tamgiacvuong(n);
	//cout << " hinh vuong"<< endl;
	//hinhvuong(n);
	//cout << " tam giac nguoc"<< endl;
	//tamgiacnguoc(n);
	cout << "tam giac can";
	tamgiaccan(n);
}