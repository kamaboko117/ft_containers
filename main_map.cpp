/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:54:06 by asaboure          #+#    #+#             */
/*   Updated: 2022/07/16 09:15:11 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <functional>
#include <string>
#include "map.hpp"
#include <list>

#ifndef PAIR
# define PAIR ft::pair
#endif 
#ifndef NAME
# define NAME ft
#endif 

// static int iter = 0;

template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}

#define T1 int
#define T2 foo<int>
typedef NAME::map<T1, T2>::iterator ft_iterator;
typedef NAME::map<T1, T2>::const_iterator ft_const_iterator;

typedef NAME::map<T1, T2>::value_type T3;

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

// template <typename MAP>
// void	ft_const_bound(const MAP &mp, const T1 &param)
// {
// 	ft_const_iterator ite = mp.end(), it[2];
// 	PAIR<ft_const_iterator, ft_const_iterator> ft_range;

// 	std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
// 	std::cout << "with key [" << param << "]:" << std::endl;
// 	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
// 	ft_range = mp.equal_range(param);
// 	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
// 	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
// 	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
// }

// template <typename MAP>
// void	ft_bound(MAP &mp, const T1 &param)
// {
// 	ft_iterator ite = mp.end(), it[2];
// 	PAIR<ft_iterator, ft_iterator> ft_range;

// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	std::cout << "with key [" << param << "]:" << std::endl;
// 	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
// 	ft_range = mp.equal_range(param);
// 	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
// 	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
// 	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
// }

bool fncomp (char lhs, char rhs){
	return lhs<rhs;
}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const{
		return lhs<rhs;
	}
};

typedef NAME::map<T1, T2> _map;
typedef _map::const_iterator const_it;

static unsigned int i = 0;

void	ft_comp(const _map &mp, const const_it &it1, const const_it &it2)
{
	bool res[2];

	std::cout << "\t-- [" << ++i << "] --" << std::endl;
	res[0] = mp.key_comp()(it1->first, it2->first);
	res[1] = mp.value_comp()(*it1, *it2);
	std::cout << "with [" << it1->first << " and " << it2->first << "]: ";
	std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
}

//check bst allocation
int	main(){
	std::cout << std::endl << "****pair*****" << std::endl;{
		std::pair <std::string,double> product1;                     // default constructor
		std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
		std::pair <std::string,double> product3 (product2);          // copy constructor

		product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

		product2.first = "shoes";                  // the type of first is string
		product2.second = 39.90;                   // the type of second is double

		std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
		std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
		std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
	}

	std::cout << std::endl << "****Construct*****" << std::endl;{
		NAME::map<char,int> first;

		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;
		std::cout << "default constructor with insert" << std::endl;
		for (NAME::map<char,int>::iterator it = first.begin(); it != first.end(); ++it){
			std::cout << it->first << " => " << it->second << '\n';
		}

		NAME::map<char,int> second (first.begin(),first.end());
		std::cout << "range constructor with first" << std::endl;
		for (NAME::map<char,int>::iterator it = second.begin(); it != second.end(); ++it){
			std::cout << it->first << " => " << it->second << '\n';
		}
		
		NAME::map<char,int> third (second);
		std::cout << "copy constructor with second" << std::endl;
		for (NAME::map<char,int>::iterator it = third.begin(); it != third.end(); ++it){
			std::cout << it->first << " => " << it->second << '\n';
		}
		NAME::map<char,int,classcomp> fourth;                 // class as Compare

		bool(*fn_pt)(char,char) = fncomp;
		NAME::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	}

	std::cout << std::endl << "****size()*****" << std::endl;{
		NAME::map<char,int> mymap;

		mymap['a'] = 101;
		mymap['b'] = 202;
		mymap['c'] = 302;

		std::cout << "mymap.size() is " << mymap.size() << '\n';

	}

	std::cout << std::endl << "****clear()*****" << std::endl;{
		NAME::map<char,int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		std::cout << "mymap contains:\n";
		for (NAME::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		mymap.clear();
		mymap['a'] = 1101;
		mymap['b'] = 2202;

		std::cout << "mymap contains:\n";
		for (NAME::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}

	std::cout << std::endl << "****operator=*****" << std::endl;{
		NAME::map<char,int> first;
		NAME::map<char,int> second;

		first['x'] = 8;
		first['y'] = 16;
		first['z'] = 32;

		second = first;                // second now contains 3 ints
		first = NAME::map<char,int>();  // and first is now empty

		std::cout << "Size of first: " << first.size() << '\n';
		std::cout << "Size of second: " << second.size() << '\n';
	}

	std::cout << std::endl << "****map iterators*****" << std::endl;{
		NAME::map<char,int> mymap;
		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;
		// show content:
		for (NAME::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it){
			std::cout << it->first << " => " << it->second << '\n';
		}
	}

	std::cout << std::endl << "****map reverse_iterators*****" << std::endl;{
		NAME::map<char,int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		// show content:
		NAME::map<char,int>::reverse_iterator rit;
		for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit){
			std::cout << rit->first << " => " << rit->second << '\n';
		}
	}

	std::cout << std::endl << "****find()*****" << std::endl;{
		NAME::map<char,int> mymap;
		NAME::map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);

		// print content:
		std::cout << "elements in mymap:" << '\n';
		std::cout << "a => " << mymap.find('a')->second << '\n';
		std::cout << "c => " << mymap.find('c')->second << '\n';
		std::cout << "d => " << mymap.find('d')->second << '\n';
	}
	
	std::cout << std::endl << "****insert()*****" << std::endl;{
		NAME::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( NAME::pair<char,int>('a',100) );
		mymap.insert ( NAME::pair<char,int>('z',200) );

		NAME::pair<NAME::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( NAME::pair<char,int>('z',500) );
		if (ret.second==false) {
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}

		// second insert function version (with hint position):
		NAME::map<char,int>::iterator it = mymap.begin();

		mymap.insert (it, NAME::pair<char,int>('b',300));  // max efficiency inserting (no difference in FT)
		mymap.insert (it, NAME::pair<char,int>('c',400));  // no max efficiency inserting

		// third insert function version (range insertion):
		NAME::map<char,int> anothermap;
		std::cout << "find: " << mymap.find('c')->first << std::endl;
		anothermap.insert(mymap.begin(),mymap.find('c'));
		// showing contents:
		std::cout << "mymap contains:\n";
		for (it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	
		std::cout << "anothermap contains:\n";
		for (it = anothermap.begin(); it != anothermap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}

	std::cout << std::endl << "****erase()*****" << std::endl;{
		NAME::map<char,int> mymap;
		NAME::map<char,int>::iterator it;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator

		mymap.erase ('c');                  // erasing by key

		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range

		// show content:
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}

	std::cout << std::endl << "****empty()*****" << std::endl;{
		NAME::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		while (!mymap.empty())
		{
			std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}
	}

	std::cout << std::endl << "****max_size()*****" << std::endl;{
		NAME::map<char, char> q;
		std::cout.imbue(std::locale("en_US.UTF-8"));    
		std::cout << "Maximum size of a map is " << q.max_size() << '\n';
	}
	
	std::cout << std::endl << "****operator[]*****" << std::endl;{
		NAME::map<char, std::string> mymap;
		
		mymap['a'] = "an element";
		mymap['b'] = "another element";
		mymap['c']=mymap['b'];

		std::cout << "mymap['a'] is " << mymap['a'] << '\n';
		std::cout << "mymap['b'] is " << mymap['b'] << '\n';
		std::cout << "mymap['c'] is " << mymap['c'] << '\n';
		std::cout << "mymap['d'] is " << mymap['d'] << '\n';

		std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	}

	std::cout << std::endl << "****swap*****" << std::endl;{
		NAME::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		foo.swap(bar);

		std::cout << "foo contains:\n";
		for (NAME::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "bar contains:\n";
		for (NAME::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}

	std::cout << std::endl << "****key_comp*****" << std::endl;{
		NAME::map<char,int> mymap;

		NAME::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;

		std::cout << "mymap contains:\n";

		char highest = mymap.rbegin()->first;     // key value of last element

		NAME::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );

		std::cout << '\n';
	}

	std::cout << std::endl << "****value_comp*****" << std::endl;{
		NAME::map<char,int> mymap;

		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;

		std::cout << "mymap contains:\n";

		NAME::pair<char,int> highest = *mymap.rbegin();          // last element

		NAME::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
	}

	std::cout << std::endl << "****count*****" << std::endl;{
		NAME::map<char,int> mymap;
		char c;

		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;

		for (c = 'a'; c < 'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c)>0)
				std::cout << " is an element of mymap.\n";
			else 
				std::cout << " is not an element of mymap.\n";
		}
	}

	std::cout << std::endl << "****lower_bound/upper_bound*****" << std::endl;{
		NAME::map<char,int> mymap;
		NAME::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		for (NAME::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}

	std::cout << std::endl << "****equal range*****" << std::endl;{
		NAME::map<char,int> mymap;

		mymap['a']=10;
		mymap['c']=20;
		mymap['d']=30;

		NAME::pair<NAME::map<char,int>::iterator,NAME::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';

	}

	std::cout << std::endl << "****get_allocator*****" << std::endl;{
		int psize;
		NAME::map<char,int> mymap;
		NAME::pair<const char,int> *p;

		// allocate an array of 5 elements using mymap's allocator:
		p = mymap.get_allocator().allocate(5);

		// assign some values to array
		psize = sizeof(NAME::map<char,int>::value_type)*5;

		std::cout << "The allocated array has a size of " << psize << " bytes.\n";

		mymap.get_allocator().deallocate(p,5);
	}

	std::cout << std::endl << "****relational operators*****" << std::endl;{
		NAME::map<char,int> a,b,c;

		a['x']=100;
		a['y']=200;
		a['z']=300;
		
		b['a']=11;
		b['b']=22;
		b['c']=33;

		std::cout << std::boolalpha;
		std::cout << "a == b: " << (a == b) << std::endl;
		std::cout << "a == a: " << (a == a) << std::endl;
		std::cout << std::endl;
		std::cout << "a != b: " << (a != b) << std::endl;
		std::cout << "a != a: " << (a != a) << std::endl;
		std::cout << std::endl;
		std::cout << "a < b: " << (a < b) << std::endl;
		std::cout << "a < a: " << (a < a) << std::endl;
		std::cout << "b < a: " << (b < a) << std::endl;
		std::cout << std::endl;
		std::cout << "a <= b: " << (a <= b) << std::endl;
		std::cout << "a <= a: " << (a <= a) << std::endl;
		std::cout << "b <= a: " << (b <= a) << std::endl;
		std::cout << std::endl;
		std::cout << "a > b: " << (a > b) << std::endl;
		std::cout << "a > a: " << (a > a) << std::endl;
		std::cout << "b > a: " << (b > a) << std::endl;
		std::cout << std::endl;
		std::cout << "a >= b: " << (a >= b) << std::endl;
		std::cout << "a >= a: " << (a >= a) << std::endl;
		std::cout << "b >= a: " << (b >= a) << std::endl;
		std::cout << std::endl;
	}
	// std::cout << std::endl << "****etc*****" << std::endl;{
	// 	std::list<T3> lst;
	// 	unsigned int lst_size = 10;
	// 	for (unsigned int i = 0; i < lst_size; ++i)
	// 		lst.push_back(T3(i + 1, (i + 1) * 3));
	// 	NAME::map<T1, T2> mp(lst.begin(), lst.end());
	// 	printSize(mp);

	// 	ft_const_bound(mp, -10);
	// 	ft_const_bound(mp, 1);
	// 	ft_const_bound(mp, 5);
	// 	ft_const_bound(mp, 10);
	// 	ft_const_bound(mp, 50);

	// 	printSize(mp);

	// 	mp.lower_bound(3)->second = 404;
	// 	mp.upper_bound(7)->second = 842;
	// 	ft_bound(mp, 5);
	// 	ft_bound(mp, 7);

	// 	printSize(mp);
	// }

	
	// {
	// 	NAME::map<char, foo<float> >	mp;

	// 	mp['a'] = 2.3;
	// 	mp['b'] = 1.4;
	// 	mp['c'] = 0.3;
	// 	mp['d'] = 4.2;
	// 	printSize(mp);

	// 	for (const_it it1 = mp.begin(); it1 != mp.end(); ++it1)
	// 		for (const_it it2 = mp.begin(); it2 != mp.end(); ++it2)
	// 			ft_comp(mp, it1, it2);

	// 	printSize(mp);
	// }

	{
		std::list<NAME::pair<const int, std::string> > lst;
		unsigned int lst_size = 6;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(NAME::pair<const int, std::string>(i, std::string((lst_size - i), i + 65)));
		NAME::map<int, std::string> mp(lst.begin(), lst.end());
		printSize(mp);

		for (int i = 2; i < 4; ++i){
			mp.erase(i);
			printSize(mp);
		}

		mp.erase(mp.begin()->first);
		printSize(mp);
		mp.erase((--mp.end())->first);
		printSize(mp);

		mp[-1] = "Hello";
		mp[10] = "Hi there";
		mp[10] = "Hi there";
		printSize(mp);

		mp.erase(0);
		printSize(mp);
		mp.erase(1);
		printSize(mp);

		std::list<NAME::pair<int, char> > lst2;
		lst_size = 7;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst2.push_back(T3('a' + i, lst_size - i));
		NAME::map<int, char> foo(lst2.begin(), lst2.end());

		lst2.clear(); lst_size = 4;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst2.push_back(T3('z' - i, i * 5));
		NAME::map<int, char> bar = foo;
		NAME::map<int, char>::iterator it_foo = foo.begin();
		NAME::map<int, char>::iterator it_bar = bar.begin();

		std::cout << "Iterator validity:" << std::endl;
		std::cout << (it_foo == bar.begin()) << std::endl;
		std::cout << (it_bar == foo.begin()) << std::endl;
	}
}