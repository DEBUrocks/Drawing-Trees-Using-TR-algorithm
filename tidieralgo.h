#include <vector>
using namespace std;
///this is the basic structure of the node
///
///@param val is any information stored in the node
///@param *llink pointer to left subtree of the node
///@param *rlink pointer to right subtree of the node
///@param *father is a pointer to the parent node
///@param status shows if the node is left or right
///@param level indicates the relative height of the node
///@param offset is the x distance to each son
///@param thread is a boolean variable indicating threading is on or off
///@param x the x coordinate of the node
///@param y the y coordinate of the node
typedef struct node 
{
	int val;					//information
	struct node *llink;		//pointer to left subtree
	struct node *rlink;//pointer to right subtree
	struct node *father;
	int status;
	int modifier;
	int level;
	int x;						//x coordinate of node
	int y;						//y coordinate of node
	int offset;					//distance to each son
	bool thread;				//Threading active or not
}node;

///It stores the details of the extreme desecendents
///@param *adr address
///@param offset offset from root of subtree
///@param level tree level
///
typedef struct extreme 
{
	node *adr;	//address
	int offset;		//offset from root of subtree
	int level;		//tree level
}extreme;

///This is the main tree class
///It enables us to draw Binary trees
///It then calls certain functions to make the tree Tidy
///@param *root Pointer to the root of the tree.
///
class tree
{
private:
	/*! Pointer to the root of the tree.*/
	node *root;
	/*! This is a private function which will make an array,
	such that the BST implemented from the array, is a balanced tree
	*/
	void ArrBST(vector <int> & , int , int, int);
	/*! This function returns the height of the tree
	*/
	int calcHeight(node *N);
	/*! This is an private function which generates a BST from a given input array
	It is used by constructor calls
	*/
	void initializer(vector <int>&, int n);
	/*! This function takes in the values of x and y of the parent node and draws the node
	as well as the line connecting it with the parent node
	The function does this recursively for each child of the node
	No parameters need to be passed when calling it
	*/
	void drawTree(int cx, int cy, node *N);
public:
	/*! tree constructor which will take the number of nodes n
	and a boolean value which tells if the tree to be generated is balanced or not
	*/
	tree(vector <int>&, int n); 
	/*! tree constructor which will take the number of nodes n
	and a boolean value which tells if the tree to be generated is balanced or not
	*/
	tree(int n, bool balanced); 
	/*! This function sets up the initial conditions and calls the functions to implement tidy algorithm
	and draws the tree
	*/
	void Tidy(); 
	/*! This function sets up the initial conditions and calls the functions to implement tidier algorithm
	and draws the tree
	*/
	void Tidier(); 
	/*! Prints the tree in inorder
	*/
	void printTree(node *N); 											
};

