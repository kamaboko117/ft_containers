/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:11:32 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/07 15:17:09 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include "utility.hpp"
# include "map.hpp"

// static class nullptr_t
// {
// public:
//     template<class T>
//     operator T*() const { return (0); }

//     template<class C, class T>
//     operator T C::*() const { return (0); }
		
// private:
//     void operator&() const;

// } u_nullptr = {};

namespace ft
{
//BST
//https://www.youtube.com/watch?v=COZK7NATh4k
	template<class Key, typename T>
	struct BstNode
	{
		pair<Key, T> data;

		BstNode	*left;
		BstNode *right;
	};

	template<class Key, typename T, class Alloc>
	BstNode<Key, T>	*getNewNode(pair<Key, T> data, Alloc _alloc){
		BstNode<Key, T>	*newNode = _alloc.allocate(1);
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		return (newNode);
	}

	template<class Key, typename T, class Compare, class Alloc>
	BstNode<Key, T>	*BstInsert(BstNode<Key, T> *root, const pair<Key, T> &value,
		Compare keyComp, Alloc _alloc){
		if (!root)
			return (root = getNewNode(value, _alloc));
		else if (keyComp(value.first, root->data.first))
			root->left = BstInsert(root->left, value, keyComp, _alloc);
		else
			root->right = BstInsert(root->right, value, keyComp, _alloc);
		return (root);
	}

	template<class Key, typename T, class Compare>
	bool	BstSearch(BstNode<Key, T> *root, const pair<Key, T> &value, Compare keyComp){
		if (!root)
			return (false);
		else if (!keyComp(value.first, root->data.first && !keyComp(value.first, root->data.first)))
			return (true);
		else if (keyComp(value.first, root->data.first))
			return (BstSearch(root->left, value));
		else
			return (BstInsert(root->right, value));
	}

}

#endif