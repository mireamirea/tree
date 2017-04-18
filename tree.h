/* 
tree.h -- binary tree implementation
*/

/* each tree node is a struct w/ value and pointers to left and right subnodes */
struct node {
	int value;
	struct node *left;
	struct node *right;
};


/* destroy_tree -- destroys given tree, goes up from bottom nodes */

void destroy_tree(struct node* node) {
	if (node != 0) {
		/* recursively call destroy_tree on left and right subnodes */
		destroy_tree(node->left);
		destroy_tree(node->right);
		free(node);
	}
}

/* insert -- inserts given value into a given tree */

void insert(int value, struct node** node) {
	struct node *temp = NULL;
	if(!(*node)) {
		temp = (struct node*)malloc(sizeof(struct node));
		temp->left = NULL;
		temp->right = NULL;
		temp->value = value;
		*node = temp;
		return;
	}
	/* recursively call insert to go down on the tree until (int value) would be less than its parent
	 * this particular way leads to creating a heap, not just a binary tree
	 */
	else if (value < (*node)->value)
		insert(value, &(*node)->left);
	else if (value > (*node)->value)
		insert(value, &(*node)->right);
}

/* search -- searches for a given value in a given tree */

struct node* search(struct node** tree, int value) {
	if(!(*tree)) {
		/*tree doesn't exist or we've reached end of tree */
		return NULL;
	}
	if (value == (*tree)->value) {
		return *tree;
	}
	else if (value < (*tree)->value)
		search(&((*tree)->left), value);
	else if (value > (*tree)->value)
		search(&((*tree)->right), value);
	return NULL; /* something went wrong */
}