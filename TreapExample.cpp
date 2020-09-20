struct node{
	node *left, *right;
	int weight, size, value;
	bool rev;
	node(int v) {
		left = right = NULL;
		weight = rand();
		rev = 0;
		size = 1;
		value = v;	
	}
};

int size(node *treap){
	if(treap == NULL) return 0;
	return treap->size;
}

void push (node *treap){
    if (treap && treap->rev) {
        treap->rev = false;
        swap(treap->left, treap->right);
        if(treap->left != NULL) treap->left->rev^=1;
        if(treap->right != NULL) treap->right->rev^=1;
    }
}

void split(node *treap, node *&left, node *&right, int k){
	if(treap == NULL){
		left = right = NULL;
	}else{
		push(treap);
		if(size(treap->left) < k){
			split(treap->right, treap->right, right, k-size(treap->left)-1);
			left = treap;
		}else{
			split(treap->left, left, treap->left, k);
			right = treap;
		}
		treap->size = size(treap->left)+size(treap->right)+1;
	}
}

void merge(node *&treap, node *left, node *right){
	push(left);
	push(right);
	if(left == NULL) treap = right;
	else if(right == NULL) treap = left;
	else{
		if(left->weight < right->weight) {
			merge(left->right, left->right, right);
			treap = left;
		}else{
			merge(right->left, left, right->left);
			treap = right;
		}
		treap->size = size(treap->left)+size(treap->right)+1;
	}
}

node *reverse (node *treap, int l, int r){
    node  *t1, *t2, *t3;
    split(treap, t1, t2, l);
    split(t2, t2, t3, r-l+1);
    t2->rev^=true;
    merge(treap, t1, t2);
    merge(treap, treap, t3);
    return treap;
}

node *cyclic_shift(node *treap, int l, int r){ //hacia la derecha, si es p la izq es similar
	node *L, *R;
	split(treap, L, R, l);
	node *ju;
	split(R, treap, ju, r-l+1);
	node *t1, *t2;
	split(treap, t1, t2, r-l);
	merge(treap, t2, t1);
	merge(R, L, treap);
	merge(treap, R, ju);
	return treap;
}

void output(node *treap){
    if(treap == NULL) return;
    push(treap);
    output(treap->left);
    cout << treap->value << " ";
    output(treap->right);
}

node *treap = NULL;
merge(treap, treap, new node(3));
