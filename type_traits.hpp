/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:39:13 by asaboure          #+#    #+#             */
/*   Updated: 2022/05/27 16:59:01 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft
{
	template<bool B, class T = void>
	struct enable_if{};

	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template<bool is_integral, typename T>
	struct is_integral_res{
		typedef T type;
		static const bool value = is_integral;	
	};

	template <typename>
    struct is_integral_type : public is_integral_res<false, bool> {};

	template<>
	struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int>{};
	
	template<>
	struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int>{};
	
	template<typename T>
	struct is_integral : public is_integral_type<T>{};
	
}

#endif