/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:11:32 by asaboure          #+#    #+#             */
/*   Updated: 2022/08/18 20:37:57 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include "utility.hpp"
# include <sstream>
# include <iostream>

//forced to use a RBT. using https://www.programiz.com/dsa/deletion-from-a-red-black-tree#:~:text=Red%2DBlack%20tree%20is%20a,of%20a%20red%2Dblack%20tree as reference
namespace ft
{
	template<class Key, class T>
	struct BstNode {
		ft::pair<const Key, T> data;
		BstNode *parent;
		BstNode *left;
		BstNode *right;
		int color;

		BstNode(){}
		BstNode(ft::pair<const Key, T> data) : data(data){}
	};

	template<class Key, class T, class Compare, class Alloc>
	class RedBlackTree {
	private:
		BstNode<Key, T> *root;
		BstNode<Key, T> *TNULL;
		BstNode<Key, T>	*last;
		Compare				compare;
		Alloc				alloc;

		void initializeNULLBSTNode(BstNode<Key, T> *node, BstNode<Key, T> *parent) {
			node->data = ft::pair<const Key, T>();
			node->parent = parent;
			node->left = nullptr;
			node->right = nullptr;
			node->color = 0;
		}

		// Preorder
		void preOrderHelper(BstNode<Key, T> *node) {
			if (node != TNULL) {
				std::cout << node->data.first << " ";
				preOrderHelper(node->left);
				preOrderHelper(node->right);
			}
		}

		// Inorder
		void inOrderHelper(BstNode<Key, T> *node) {
			if (node != TNULL) {
				inOrderHelper(node->left);
				std::cout << node->data.first << " ";
				inOrderHelper(node->right);
			}
		}

		// Post order
		void postOrderHelper(BstNode<Key, T> *node) {
			if (node != TNULL) {
				postOrderHelper(node->left);
				postOrderHelper(node->right);
				std::cout << node->data.first << " ";
			}
		}

		BstNode<Key, T> *searchTreeHelper(BstNode<Key, T> *node, Key key) {
			if (node == TNULL || (!compare(key, node->data.first) && !compare(node->data.first, key)))
				return node;
			if (compare(key, node->data.first))
				return searchTreeHelper(node->left, key);
			return searchTreeHelper(node->right, key);
		}

		// For balancing the tree after deletion
		void deleteFix(BstNode<Key, T> *x) {
			BstNode<Key, T> *s;
			while (x != root && x->color == 0) {
				if (x == x->parent->left) {
					s = x->parent->right;
					if (s->color == 1) {
						s->color = 0;
						x->parent->color = 1;
						leftRotate(x->parent);
						s = x->parent->right;
					}
					if (s->left->color == 0 && s->right->color == 0) {
						s->color = 1;
						x = x->parent;
					} else {
						if (s->right->color == 0) {
							s->left->color = 0;
							s->color = 1;
							rightRotate(s);
							s = x->parent->right;
						}
						s->color = x->parent->color;
						x->parent->color = 0;
						s->right->color = 0;
						leftRotate(x->parent);
						x = root;
					}
				} else {
					s = x->parent->left;
					if (s->color == 1) {
						s->color = 0;
						x->parent->color = 1;
						rightRotate(x->parent);
						s = x->parent->left;
					}
					if (s->right->color == 0 && s->right->color == 0) {
						s->color = 1;
						x = x->parent;
					} else {
						if (s->left->color == 0) {
							s->right->color = 0;
							s->color = 1;
							leftRotate(s);
							s = x->parent->left;
						}
						s->color = x->parent->color;
						x->parent->color = 0;
						s->left->color = 0;
						rightRotate(x->parent);
						x = root;
					}
				}
			}
			x->color = 0;
		}

		void rbTransplant(BstNode<Key, T> *u, BstNode<Key, T> *v) {
			if (u->parent == nullptr)
				root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

		void deleteBSTNodeHelper(BstNode<Key, T> *node, Key key) {
			BstNode<Key, T> *z = TNULL;
			BstNode<Key, T> *x, y;

			while (node != TNULL) {
				if (!compare(node->data.first, key) && !compare(key, node->data.first))
					z = node;
				if (!compare(key, node->data.first)) 
					node = node->right;
				else
					node = node->left;
			}
			if (z == TNULL) {
				std::cout << "Key not found in the tree" << std::endl;
				return ;
			}
			y = z;
			int y_original_color = y->color;
			if (z->left == TNULL) {
				x = z->right;
				rbTransplant(z, z->right);
			} else if (z->right == TNULL) {
				x = z->left;
				rbTransplant(z, z->left);
			} else {
				y = minimum(z->right);
				y_original_color = y->color;
				x = y->right;
				if (y->parent == z)
					x->parent = y;
				else {
					rbTransplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				rbTransplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			alloc.deallocate(z, 1);
			if (y_original_color == 0)
				deleteFix(x);
		}

		// For balancing the tree after insertion
		void insertFix(BstNode<Key, T> *k) {
			BstNode<Key, T> *u;
			while (k->parent->color == 1) {
				if (k->parent == k->parent->parent->right) {
					u = k->parent->parent->left;
					if (u->color == 1) {
						u->color = 0;
						k->parent->color = 0;
						k->parent->parent->color = 1;
						k = k->parent->parent;
					} else {
						if (k == k->parent->left) {
							k = k->parent;
							rightRotate(k);
						}
						k->parent->color = 0;
						k->parent->parent->color = 1;
						leftRotate(k->parent->parent);
					}
				} else {
					u = k->parent->parent->right;
					if (u->color == 1) {
						u->color = 0;
						k->parent->color = 0;
						k->parent->parent->color = 1;
						k = k->parent->parent;
					} else {
						if (k == k->parent->right) {
							k = k->parent;
							leftRotate(k);
						}
						k->parent->color = 0;
						k->parent->parent->color = 1;
						rightRotate(k->parent->parent);
					}
				}
				if (k == root)
					break;
			}
			root->color = 0;
		}

		void printHelper(BstNode<Key, T> *root, std::string indent, bool last) {
			if (root != TNULL) {
				std::cout << indent;
				if (last) {
					std::cout << "R----";
					indent += "   ";
				} else {
					std::cout << "L----";
					indent += "|  ";
				}

				std::string sColor = root->color ? "RED" : "BLACK";
				std::cout << root->data.first << "(" << sColor << ")" << std::endl;
				printHelper(root->left, indent, false);
				printHelper(root->right, indent, true);
			}
		}

		public:
		RedBlackTree(Compare compare, Alloc alloc) : compare(compare), alloc(alloc) {
			TNULL = alloc.allocate(1);
			alloc.construct(TNULL, BstNode<Key, T>());
			last = alloc.allocate(1);
			alloc.construct(last, BstNode<Key, T>());
			last->color = 2;
			TNULL->color = 0;
			TNULL->left = nullptr;
			TNULL->right = nullptr;
			root = TNULL;
			root->parent = last;
		}

		void preorder() {
			preOrderHelper(this->root);
		}

		void inorder() {
			inOrderHelper(this->root);
		}

		void postorder() {
			postOrderHelper(this->root);
		}

		BstNode<Key, T> *searchTree(Key k) {
			return searchTreeHelper(this->root, k);
		}

		BstNode<Key, T> *minimum(BstNode<Key, T> *node) {
			while (node->left != TNULL)
				node = node->left;
			return node;
		}

		BstNode<Key, T> *maximum(BstNode<Key, T> *node) {
			while (node->right != TNULL)
				node = node->right;
			return node;
		}

		BstNode<Key, T> *successor(BstNode<Key, T> *x) {
			if (x->right != TNULL)
				return minimum(x->right);
			BstNode<Key, T> *y = x->parent;
			while (y != TNULL && x == y->right) {
				x = y;
				y = y->parent;
			}
			return y;
		}

		BstNode<Key, T> *predecessor(BstNode<Key, T> *x) {
			if (x->left != TNULL)
				return maximum(x->left);
			BstNode<Key, T> *y = x->parent;
			while (y != TNULL && x == y->left) {
				x = y;
				y = y->parent;
			}
			return y;
		}

		void leftRotate(BstNode<Key, T> *x) {
			BstNode<Key, T> *y = x->right;
			x->right = y->left;
			if (y->left != TNULL)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == nullptr)
				this->root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		}

		void rightRotate(BstNode<Key, T> *x) {
			BstNode<Key, T> *y = x->left;
			x->left = y->right;
			if (y->right != TNULL)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == nullptr)
				this->root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}

		// Inserting a node
		void insert(pair<const Key, T> value) {
			BstNode<Key, T> *node = alloc.allocate(1);
			alloc.construct(node, BstNode<Key, T>(value));
			node->parent = nullptr;
			node->left = TNULL;
			node->right = TNULL;
			node->color = 1;

			BstNode<Key, T> *y = nullptr;
			BstNode<Key, T> *x = this->root;

			while (x != TNULL) {
				y = x;
				if (compare(node->data.first, x->data.first))
					x = x->left;
				else
					x = x->right;
			}
			node->parent = y;
			if (y == nullptr)
				root = node;
			else if (compare(node->data.first, y->data.first))
				y->left = node;
			else
				y->right = node;
			if (node->parent == nullptr) {
				node->color = 0;
				return ;
			}
			if (node->parent->parent == nullptr)
				return ;
			insertFix(node);
		}

		BstNode<Key, T> *getRoot() {
			return this->root;
		}

		void deleteBSTNode(Key data) {
			deleteBSTNodeHelper(this->root, data);
		}

		void printTree() {
			if (root)
				printHelper(this->root, "", true);
		}
	};
}

#endif