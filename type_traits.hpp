/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:39:13 by asaboure          #+#    #+#             */
/*   Updated: 2022/05/27 15:06:58 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

template<bool B, class T = void>
struct enable_if{};

template<class T>
struct enable_if<true, T>
{
	typedef T type;
};

#endif