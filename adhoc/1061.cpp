#include <bits/stdc++.h>
using namespace std;

/*
	Rh positivo: false
	Rh negativo: true
 */

int main(int argc, char const *argv[])
{
	
	string pai, mae, filho;
	bool trocou;
	int cont = 1;
	while(true){
		cin >> pai >> mae >> filho;
		if(pai == "E")	break;


		if(mae == "?" || pai == "?"){
			printf("Case %d: ", cont++);
			trocou = false;
			if(mae == "?")
				cout << pai << " ";
			else{
				trocou = true;
				swap(mae, pai);
			}

			if(pai == "A+"){
				if(filho == "A+") printf("{A+, A-, O+, O-, B+, B-, AB+, AB-}");
				if(filho == "A-") printf("{A+, A-, O+, O-, B+, B-, AB+, AB-}");
				if(filho == "B+") printf("{B+, B-, AB+, AB-}");
				if(filho == "B-") printf("{B+, B-, AB+, AB-}");
				if(filho == "AB+") printf("{B+, B-, AB+, AB-}");
				if(filho == "AB-") printf("{B+, B-, AB+, AB-}");
				if(filho == "O+") printf("{A+, A-, O+, O-, B+, B-}");
				if(filho == "O-") printf("{A+, A-, O+, O-, B+, B-}");
			}
			if(pai == "A-"){
				if(filho == "A+") printf("{A+, O+, B+, AB+}");
				if(filho == "A-") printf("{A+, A-, O+, O-, B+, B-, AB+, AB-}");
				if(filho == "B+") printf("{B+, AB+}");
				if(filho == "B-") printf("{B+, B-, AB+, AB-}");
				if(filho == "AB+") printf("{B+, AB+}");
				if(filho == "AB-") printf("{B+, B-, AB+, AB-}");
				if(filho == "O+") printf("{A+, O+, B+}");
				if(filho == "O-") printf("{A+, A-, O+, O-, B+, B-}");
			}
			if(pai == "B+"){
				if(filho == "A+") printf("{A+, A-, AB+, AB-}");
				if(filho == "A-") printf("{A+, A-, AB+, AB-}");
				if(filho == "B+") printf("{A+, A-, B+, B-, AB+, AB-, O+, O-}");
				if(filho == "B-") printf("{A+, A-, B+, B-, AB+, AB-, O+, O-}");
				if(filho == "AB+") printf("{A+, A-, AB+, AB-}");
				if(filho == "AB-") printf("{A+, A-, AB+, AB-}");
				if(filho == "O+") printf("{A+, A-, O+, O-, B+, B-}");
				if(filho == "O-") printf("{A+, A-, O+, O-, B+, B-}");
			}
			if(pai == "B-"){
				if(filho == "A+") printf("{A+, AB+}");
				if(filho == "A-") printf("{A+, A-, AB+, AB-}");
				if(filho == "B+") printf("{A+, B+, AB+, O+}");
				if(filho == "B-") printf("{A+, A-, B+, B-, AB+, AB-, O+, O-}");
				if(filho == "AB+") printf("{A+, AB+}");
				if(filho == "AB-") printf("{A+, A-, AB+, AB-}");
				if(filho == "O+") printf("{A+, O+, B+}");
				if(filho == "O-") printf("{A+, A-, O+, O-, B+, B-}");
			}
			if(pai == "AB+"){
				if(filho == "A+") printf("{A+, A-, B+, B-, O+, O-, AB+, AB-}");
				if(filho == "A-") printf("{A+, A-, B+, B-, O+, O-, AB+, AB-}");
				if(filho == "B+") printf("{A+, A-, B+, B-, AB+, AB-, O+, O-}");
				if(filho == "B-") printf("{A+, A-, B+, B-, AB+, AB-, O+, O-}");
				if(filho == "AB+") printf("{A+, A-, B+, B-, AB+, AB-}");
				if(filho == "AB-") printf("{A+, A-, B+, B-, AB+, AB-}");
				if(filho == "O+") printf("IMPOSSIBLE");
				if(filho == "O-") printf("IMPOSSIBLE");
			}
			if(pai == "AB-"){
				if(filho == "A+") printf("{A+, B+, O+, AB+}");
				if(filho == "A-") printf("{A+, A-, B+, B-, O+, O-, AB+, AB-}");
				if(filho == "B+") printf("{A+, B+, AB+, O+}");
				if(filho == "B-") printf("{A+, A-, B+, B-, AB+, AB-, O+, O-}");
				if(filho == "AB+") printf("{A+, B+, AB+}");
				if(filho == "AB-") printf("{A+, A-, B+, B-, AB+, AB-}");
				if(filho == "O+") printf("IMPOSSIBLE");
				if(filho == "O-") printf("IMPOSSIBLE");
			}
			if(pai == "O+"){
				if(filho == "A+") printf("{A+, A-, AB+, AB-}");
				if(filho == "A-") printf("{A+, A-, AB+, AB-}");
				if(filho == "B+") printf("{B+, B-, AB+, AB-}");
				if(filho == "B-") printf("{B+, B-, AB+, AB-}");
				if(filho == "AB+") printf("IMPOSSIBLE");
				if(filho == "AB-") printf("IMPOSSIBLE");
				if(filho == "O+") printf("{A+, A-, O+, O-, B+, B-}");
				if(filho == "O-") printf("{A+, A-, O+, O-, B+, B-}");
			}
			if(pai == "O-"){
				if(filho == "A+") printf("{A+, AB+}");
				if(filho == "A-") printf("{A+, A-, AB+, AB-}");
				if(filho == "B+") printf("{B+, AB+}");
				if(filho == "B-") printf("{B+, B-, AB+, AB-}");
				if(filho == "AB+") printf("IMPOSSIBLE");
				if(filho == "AB-") printf("IMPOSSIBLE");
				if(filho == "O+") printf("{A+, O+, B+}");
				if(filho == "O-") printf("{A+, A-, O+, O-, B+, B-}");
			}
			if(trocou){
				cout << " " << pai << " " << filho << endl;
			}
			else
				cout << " " << filho << endl;
		}
		else{
			printf("Case %d: ", cont++);
			if(pai == "O-" && mae == "O-")	cout << "O- O- O-\n";
			else{
			cout << pai << " " << mae << " {";

			if(pai == "A+"){
				if(mae == "A+")	printf("A+, A-, O+, O-");
				if(mae == "A-")	printf("A+, A-, O+, O-");
				if(mae == "AB+")	printf("A+, A-, B+, B-, AB+, AB-");
				if(mae == "AB-")	printf("A+, A-, B+, B-, AB+, AB-");
				if(mae == "B+")	printf("A+, A-, B+, B-, AB+, AB-, O+, O-");	
				if(mae == "B-")	printf("A+, A-, B+, B-, AB+, AB-, O+, O-");
				if(mae == "O+")	printf("A+, A-, O+, O-");
				if(mae == "O-")	printf("A+, A-, O+, O-");		
			}
			if(pai == "A-"){
				if(mae == "A+")	printf("A+, A-, O+, O-");
				if(mae == "A-")	printf("A-, O-");
				if(mae == "AB+")	printf("A+, A-, B+, B-, AB+, AB-");
				if(mae == "AB-")	printf("A-, B-, AB-");
				if(mae == "B+")	printf("A+, A-, B+, B-, AB+, AB-, O+, O-");	
				if(mae == "B-")	printf("A-, B-, AB-, O-");
				if(mae == "O+")	printf("A+, A-, O+, O-");
				if(mae == "O-")	printf("A-, O-");
			}
			if(pai == "B+"){
				if(mae == "A+")	printf("A+, A-, B+, B-, AB+, AB-, O+, O-");
				if(mae == "A-")	printf("A+, A-, B+, B-, AB+, AB-, O+, O-");
				if(mae == "AB+")	printf("A+, A-, B+, B-, AB+, AB-");
				if(mae == "AB-")	printf("A+, A-, B+, B-, AB+, AB-");
				if(mae == "B+")	printf("B+, B-, O+, O-");	
				if(mae == "B-")	printf("B+, B-, O+, O-");
				if(mae == "O+")	printf("B+, B-, O+, O-");
				if(mae == "O-")	printf("B+, B-, O+, O-");	
			}
			if(pai == "B-"){
				if(mae == "A+")	printf("A+, A-, B+, B-, AB+, AB-, O+, O-");
				if(mae == "A-")	printf("A-, B-, AB-, O-");
				if(mae == "AB+")	printf("A+, A-, B+, B-, AB+, AB-");
				if(mae == "AB-")	printf("A-, B-, AB-");
				if(mae == "B+")	printf("B+, B-, O+, O-");	
				if(mae == "B-")	printf("B-, O-");
				if(mae == "O+")	printf("B+, B-, O+, O-");
				if(mae == "O-")	printf("B-, O-");	
			}
			if(pai == "AB+"){
				if(mae == "A+")	printf("AB+, AB-, A+, A-, B+, B-");
				if(mae == "A-")	printf("AB+, AB-, A+, A-, B+, B-");
				if(mae == "AB+")	printf("A+, A-, B+, B-, AB+, AB-");
				if(mae == "AB-")	printf("A+, A-, B+, B-, AB+, AB-");
				if(mae == "B+")	printf("B+, B-, A+, A-, AB+, AB-");	
				if(mae == "B-")	printf("B+, B-, A+, A-, AB+, AB-");
				if(mae == "O+")	printf("B+, B-, A+, A-");
				if(mae == "O-")	printf("B+, B-, A+, A-");	
			}
			if(pai == "AB-"){
				if(mae == "A+")	printf("AB+, AB-, A+, A-, B+, B-");
				if(mae == "A-")	printf("AB-, A-, B-");
				if(mae == "AB+")	printf("A+, A-, B+, B-, AB+, AB-");
				if(mae == "AB-")	printf("A-, B-, AB-");
				if(mae == "B+")	printf("B+, B-, A+, A-, AB+, AB-");	
				if(mae == "B-")	printf("B-, A-, AB-");
				if(mae == "O+")	printf("B+, B-, A+, A-");
				if(mae == "O-")	printf("B-, A-");	
			}
			if(pai == "O+"){
				if(mae == "A+")	printf("O+, O-, A+, A-");
				if(mae == "A-")	printf("O+, O-, A+, A-");
				if(mae == "AB+")	printf("A+, A-, B+, B-");
				if(mae == "AB-")	printf("A+, A-, B+, B-");
				if(mae == "B+")	printf("B+, B-, O+, O-");	
				if(mae == "B-")	printf("B+, B-, O+, O-");
				if(mae == "O+")	printf("O+, O-");
				if(mae == "O-")	printf("O+, O-");	
			}
			if(pai == "O-"){
				if(mae == "A+")	printf("O+, O-, A+, A-");
				if(mae == "A-")	printf("O-, A-");
				if(mae == "AB+")	printf("A+, A-, B+, B-");
				if(mae == "AB-")	printf("A-, B-");
				if(mae == "B+")	printf("B+, B-, O+, O-");	
				if(mae == "B-")	printf("B-, O-");
				if(mae == "O+")	printf("O+, O-");
				if(mae == "O-")	printf("O-");	
			}

			printf("}\n");
			}
		}
	}

	return 0;
}
