// ins inserts a number in the trie
// eras erases a number
// get output the number whose xor with x is maximum (can be easily extended to minimum)

int t[N][2];	
int fin[N];	
 	
int m = 1;	
 	
void ins(int x){	
	int u = 0;	
	++fin[0];	
	for(int i=30;i>=0;i--){	
		if(x&(1<<i)){	
			if(t[u][1] == 0){	
				t[u][1]=m++;	
			}	
			u=t[u][1];	
		}else{	
			if(t[u][0] == 0){	
				t[u][0]=m++;	
			}	
			u=t[u][0];	
		}	
		++fin[u];	
	}	
}	
 	
void eras(int x){	
	int u = 0;	
	--fin[0];	
	for(int i=30;i>=0;i--){	
		if(x&(1<<i)){	
			if(t[u][1] == 0){	
				return;	
			}	
			u=t[u][1];	
		}else{	
			if(t[u][0] == 0){	
				return;	
			}	
			u=t[u][0];	
		}	
		--fin[u];	
	}	
}	
 	
tint get(int x){	
	int u = 0;	
	tint ret = 0;	
	for(int i=30;i>=0;i--){	
		if(x&(1<<i)){	
			if(t[u][0] != 0 && fin[t[u][0]] > 0){	
				ret+=(1LL<<i);	
				u = t[u][0];	
			}else{	
				u = t[u][1];	
			}	
		}else{	
			if(t[u][1] != 0 && fin[t[u][1]] > 0){	
				ret+=(1LL<<i);	
				u = t[u][1];	
			}else{	
				u = t[u][0];	
			}	
		}	
	}	
	return ret;	
}	
