class BinaryTree
{

	struct Node
	{
		int data;
		Node* left;
		Node* right;
		Node(int n);
	};

	Node *root;
	void remove(Node *root);
	Node*  copyTree(Node *src);
	void in_traverse(Node *root);
	void pre_traverse(Node *root);
	void post_traverse(Node *root);
	int tree_hight(Node* root);
	int max(int left, int right);
	void mirror_image(Node *root);
	void swap_child(Node *root);
	void mergeTree(Node *root);
public:

	// Constructors & Destructors
	BinaryTree();
	BinaryTree(const BinaryTree& );
	~BinaryTree();


	void insert(int data);
	bool search(int data);

	void inorder_traverse();
	void preorder_traverse();
	void postorder_traverse();

	int hight();
	void convert_to_mirror();
	void merge(BinaryTree &);
};
