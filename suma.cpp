#include <iostream>

using namespace std; 
int main()
{
	int i, j;
	cout << "inserta i: " ;
	cin >>  i ;
	cout << "inserta j: " ;
	cin >>  j;
		int n = 0;
		for(int k = min(i, j); k <= max(i, j); k++){
            int counter = 1, current = k;
            while(current!=1){
                if (current%2!=0){
                    current = current*3+1;
                    counter++;
                }
				else{
					current = current/2;
					counter++;
				}
            }
            n = max(n, counter);
		}
		cout << i << ' ' << j << ' ' << n << endl;

	return 0;
}