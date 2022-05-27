/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:11:32 by asaboure          #+#    #+#             */
/*   Updated: 2022/05/27 17:12:43 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

static class nullptr_t
{
public:
    template<class T>
    operator T*() const { return (0); }

    template<class C, class T>
    operator T C::*() const { return (0); }
		
private:
    void operator&() const;

} u_nullptr = {};

#endif