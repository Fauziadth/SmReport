#define MATCH 0
#define INSERT 1
#define DELETE 2


typedef struct{
	int cost;
	int parent;
} cell;

cell m[MAXLEN+1][MAXLEN+1];

int match(char c, char d){
	if(c == d) return (0);
	else return(1);
}

int indel(char c){
	return(1);
}

row_init(int i){
	m[0][i].cost = i;
	if(i>0)
		m[0][i].parent = INSERT;
	else
		m[0][i].parent = -1;
}

column_init(int i){
	m[i][0].cost = i;
	if(i>0)
		m[i][0].parent = DELETE;
	else
		m[i][0].parent = -1;
}

goal_cell(char *s, char *t, int *i, int *j){
	*i = strlen(s) - 1;
	*j = strlen(t) - 1;
}


int string_compare(char *s, chare *t, int i, int j){
	int k;
	int opt[3];
	
	for(i=0; i<MAXLEN; i++){
		row_init(i);
		column_init(i);
	}
	
	for(i=1; i<strlen(s); i++){
		for(j=1; j<strlen(t); j++){
			opt[MATCH] = m[i-1][j-1].cost + match(s[i], t[j]);
			opt[INSERT] = m[i][j-1].cost + indel(t[j]);
			opt[DELETE] = m[i-1][j].cost + indel(s[i]);
			
			m[i][j].cost = opt[MATCH];
			m[i][j].parent = MATCH;
			for(k=INSET; k<=DELETE; k++){
				if(opt[k] < m[i][j].cost){
					m[i][j].cost = opt[k];
					m[i][j].parent = k;
				}
			}
		}
	}
	
	goal_cell(s, t, &i, &j);
	return (m[i][j].cost);
	
	
}