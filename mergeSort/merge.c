void intercala (int v[], int ini, int mid, int fim) {
    int i;
    int j = mid + 1;
    int k = ini;
	int Vaux[fim];
	for (i = ini; i <= fim; i++) {
		Vaux[i] = v[i];
	}
	i = ini;
	while (i <= mid && j <= fim) {
		if (Vaux[i] <= Vaux[j]) {
			v[k] = Vaux[i];
			i++;
		} 
		else {
			v[k] = Vaux[j];
			j++;
		}
		k++;
	}
	while (i <= mid) {
		v[k] = Vaux[i];
		k++;
		i++;
	}
} 
