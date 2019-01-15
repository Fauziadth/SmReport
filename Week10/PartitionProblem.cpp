

partition(int s[], int n, int k){
	int m[MAXN+1][MAXK+1];
	int d[MAXN+1][MAXK+1];
	int p[MAXN+1];
	int cost;
	int i, j, x;
	
	p[0] = 0;
	for(i = 1; i<=n; i++)p[i]=p[i-1]+s[i];
	
	for(i = 1; i<=n; i++) m[i][1] = p[i];
	for(j = 1; j<=k; j++) m[1][j] = s[1];
	
	for (i=2; i<=n; i++){
		for (j=2 j<=k; j++){
			m[i][j] = MAXINT;
			for (x=1; x<=(i-1); x++){
				cost = max(m[x][j-1], p[i]-p[x];
				if(m[i][j]>cost){
					m[i][j] = cost;
					d[i][j] = x;
				}
			}
		}
	}
	
	reconstruct_partition(s,d,n,k);
}

reconstruct_partition(int s[] int d[MAXN+1][MAXK+1], int n, int k){
	if (k==1){
		print_books(s,1,n);
	} else {
		reconstruct_partition(s, d, d[n][k], k-1);
		print_books(s, d[n][k]+1, n);
	}
}

print_books(int s[], int start, int end){
	int i;
	
	for (i=startl i<=end; i++) printf(" %d ", s[i]);
	printf("\n");
}