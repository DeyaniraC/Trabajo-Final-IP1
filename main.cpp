#include <iostream>
using namespace std;
int nave_mas_productiva(int granja[][30],int cant_naves){
	int mayor=0;
	int nave=0;
	for(int i=0;i<cant_naves; i++){
		int suma=0;
		for(int j=0;j<30; j++){
			suma+=granja[i][j];
		}	
		if(mayor<suma*1.05){
			mayor=suma*1.05;
			nave=i+1;
		}
	}
	return nave;
}

string total_promedio(int granja[][30],int cant_naves){
	int suma=0;
	double prom=0.0;
	for(int i=0;i<cant_naves;i++){
		suma+=granja[i][5];
	}
	for(int i=0;i<cant_naves;i++){
		for(int j=0;j<30;j++){
			prom+=granja[i][j];
		}
	}
	cout<<"El total de huevos el dia 6 fue "<<suma<<" y el promedio de produccion general fue: "<<prom/cant_naves<<endl;
}

string gastos_ganancias(int granja[][30],int cant_naves){

	for(int i=0;i<cant_naves;i++){
		int suma=0;
		for(int j=0;j<30;j++){
			suma+=granja[i][j];
		}
		cout<<"Los gastos para la produccion de la nave "<<i+1<<" fueron "<<suma*0.305<<" y las ganancias fueron de "<<suma*1.05<<endl;
	}
}

string mayor_menor(int granja[][30],int cant_naves){
	int mayor=0, menor=999, max=0, min=0;

		for(int i=0;i<cant_naves;i++){
			int suma=0;
			for(int j=0;j<30;j++){
			suma+=granja[i][j];
			}
			if(suma>mayor){
				mayor=suma;
				max=i;
			}
			else if(suma<menor){
				menor=suma;
				min=i;
			}
		}
		cout<<"La nave con mayor produccion fue la nave: "<<max+1<<" y la nave con menor produccion fue la nave: "<<min+1<<endl;
}

string quincena_productiva(int granja[][30],int cant_naves, int nave){
	int primera=0, segunda=0;
	for(int i=0;i<2;i++){
		primera+=granja[nave][i];
	}
	for(int i=2;i<30;i++){
		segunda+=granja[nave][i];
	}
	if(primera>segunda){
		cout<<"La primera quincena fue la mas productiva"<<endl;
	}
	else{
		cout<<"La segunda quincena fue la mas productiva"<<endl;
	}
}

string cant_pienso(int granja[][30],int cant_naves){
	int suma=0;
		for(int i=0;i<cant_naves;i++){
			for(int j=0;j<30;j++){
			suma+=granja[i][j];
			}
		}
		cout<<"Se necesitaron "<<0.01*(suma/100)<<" toneladas de pienso "<<endl;
}

string dia_menos_productivo(int granja[][30],int cant_naves){
	int menor=9999, dia=0;
	for(int i=0;i<30;i++){
		int suma=0;
		for(int j=0;j<cant_naves;j++){
			suma+=granja[j][i];
		}
		if(menor>suma){
			menor=suma;
			dia=i;
		}
	}
	cout<<"El dia menos productivo fue el dia: "<<dia+1<<endl;
}

int produccion_x_granja(int granja[][30],int cant_naves){
	int nave=0;
	cout<<"Que nave desea analizar?"<<endl;
	cin>>nave;
	for(int i=0;i<30;i++){
		cout<<"La produccion de la nave "<<nave<<" el dia "<<i<<" fue "<<granja[nave][i];
	}
}

void eliminarNavesImproductivas(int granja[][30], int cant_naves) {
    for (int i = 0; i < cant_naves; ++i) {
        int diasBajos = 0;
        for (int j = 0; j < 30; ++j) {
            if (granja[i][j] <= 150) {
                diasBajos++;
            }
        }

        if (diasBajos >= 3) {
            cout << "La nave " << i + 1 << " ha sido eliminada por improductiva." << endl;

            for (int j = 0; j < 30; ++j) {
                granja[i][j] = 0;
            }
        }
    }
}


int main() {
	int cant_naves=0, nave=0, opcion=-1;
	cout<<"Cuantas naves hay en la granja"<<endl;
	cin>>cant_naves;
	int granja[cant_naves][30];
	
	for(int i=0;i<cant_naves;i++){
		for(int j=0;j<30;j++){
			cout<<"Introduzca la produccion de la nave: "<<i+1<<" en el dia "<<j+1<<endl;
			cin>>granja[i][j];
		}
	}
	
	eliminarNavesImproductivas(granja, cant_naves);
	
	while(opcion!=0){
	
	cout<<"Que desea realizar? \n 1)Concocer la nave mas productiva \n 2)saber el promedio general y el total de la produccion del dia 6 \n 3)Concer gastos y ganancias \n 30)Conocer la nave mas y menos productora \n 5)Conocer la quincena mas productiva de una nave dada \n 6)Conocer la cantidad de toneladas de pienso utilizadas \n 7)Conocer el dia menos productivo \n 8)Conocer la produccion de una nave todo el mes 0)Salir"<<endl;
	cin>>opcion;
	if(opcion==1){
		cout<<"La nave mas productiva es: "<<nave_mas_productiva(granja,cant_naves)<<endl;
	}
	else if(opcion==2){
		total_promedio(granja, cant_naves);
	}
	else if(opcion==3){
		gastos_ganancias(granja, cant_naves);
	}
	else if(opcion==4){
		mayor_menor(granja, cant_naves);
	}
	else if(opcion==5){
		cout<<"Que nave desea ver"<<endl;
		cin>>nave;
		quincena_productiva(granja,cant_naves,nave-1);
	}
	else if(opcion==6){
		cant_pienso(granja, cant_naves);
	}
	else if(opcion==7){
		dia_menos_productivo(granja,cant_naves);
	}
	else if(opcion==8){
		produccion_x_granja(granja,cant_naves);
	}
	
}
	return 0;
}