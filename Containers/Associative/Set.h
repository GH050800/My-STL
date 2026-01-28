#ifndef SET_H
#define SET_H

template <typename T>
class Set
{
private:
	struct Node
	{
		T m_data;
		Node* left;
		Node* right;

		Node(const T& value) : m_data(value), left(nullptr), right(nullptr) {}
	};

	Node* root;

public:
	Node* recurse_insert(Node* node, const T& value)
	{
		if (node == nullptr)
		{
			return new Node(value);
		}

		if (value < node->m_data)
		{
			node->left = recurse_insert(node->left, value);
		}			
		else if (value > node->m_data)
		{
			node->right = recurse_insert(node->right, value);
		}
		return node;
	}

	bool recurse_contains(Node* node, const T& value) const
	{
		if (node == nullptr)
		{
			return false;
		}

		if (value < node->m_data)
		{
			return recurse_contains(node->left, value);
		}
		else if (value > node->m_data)
		{
			return recurse_contains(node->right, value);
		}
		else
		{
			return true;
		}
	}

	void clear(Node* node)
	{
		if (node != nullptr)
		{
			clear(node->left);
			clear(node->right);
			delete node;
		}
	}

	void inorder(Node* node) const
	{
		if (node == nullptr) { return; }

		inorder(node->left);
		std::cout << node->m_data << " ";
		inorder(node->right);
	}

	void preorder(Node* node) const
	{
		if (node == nullptr) { return; }

		std::cout << node->m_data << " ";
		preorder(node->left);
		preorder(node->right);
	}

	void postorder(Node* node) const
	{
		if (node == nullptr) { return; }

		postorder(node->left);
		postorder(node->right);
		std::cout << node->m_data << " ";
	}
public:
	Set() : root(nullptr) {}
	Set(const Set& other) = delete;
	Set& operator=(const Set& other) = delete;
	~Set(){ clear(root); }

	void insert(const T& value)
	{
		root = recurse_insert(root, value);
	}

	bool contains(const T& value) const
	{
		return recurse_contains(root, value);
	}

	void inorder() const
	{
		inorder(root);
	}

	void preorder() const
	{
		preorder(root);
	}

	void postorder() const
	{
		postorder(root);
	}
};

#endif // SET_H