
#ifndef SUDOKUGRID_HPP
#define SUDOKUGRID_HPP

#include <array>
#include <cstdint>

class SudokuGrid
{
	public:
		class Column;
		class Row;
		class Subgrid;

		SudokuGrid() = delete;
		SudokuGrid(std::array<std::uint8_t, 9 * 9> values);
		SudokuGrid(const SudokuGrid&) = default;
		SudokuGrid(SudokuGrid&&) = default;

		Column GetColumn(std::uint8_t index);
		Row GetRow(std::uint8_t index);
		Subgrid GetSubgrid(std::uint8_t index);

		const std::array<std::uint8_t, 9 * 9>& GetValues() const;

		SudokuGrid& operator=(const SudokuGrid&) = default;
		SudokuGrid& operator=(SudokuGrid&&) = default;

	private:

		std::array<std::uint8_t, 9 * 9> m_values;
};

class SudokuGrid::Column
{
	friend SudokuGrid;

	public:
		class iterator;

		using value_type = std::uint8_t;
		using pointer = value_type*;
		using const_pointer = const value_type*;
		using reference = value_type&;
		using const_reference = const value_type&;
		using size_type = std::size_t;
		using difference_type = std::size_t;

		Column() = delete;
		Column(const Column&) = delete;
		Column(Column&&) = default;

		iterator begin();
		iterator end();

		reference operator[](size_type i);
		const_reference operator[](size_type i) const;

		Column& operator=(const Column&) = default;
		Column& operator=(Column&&) = default;

	private:

		Column(std::array<value_type, 9 * 9>* grid, std::uint8_t index);

		std::array<value_type, 9 * 9>* m_grid;
		std::uint8_t m_index;
};

class SudokuGrid::Column::iterator
{
	friend Column;

	public:
		using value_type = std::uint8_t;
		using pointer = value_type *;
		using const_pointer = const value_type*;
		using reference = value_type & ;
		using const_reference = const value_type&;
		using size_type = std::size_t;
		using difference_type = std::size_t;

		iterator() = delete;
		iterator(const iterator&) = default;
		iterator(iterator&&) = default;

		reference operator*();
		const_reference operator*() const;

		iterator& operator++();
		iterator operator++(int);
		iterator& operator--();
		iterator operator--(int);
		iterator operator+(difference_type n);
		iterator& operator+=(difference_type n);
		iterator operator-(difference_type n);
		iterator& operator-=(difference_type n);

		bool operator==(const iterator& rhs) const;
		bool operator!=(const iterator& rhs) const;

		iterator& operator=(const iterator&) = default;
		iterator& operator=(iterator&&) = default;

	private:

		iterator(std::array<value_type, 9 * 9>* grid, std::uint8_t index, size_type pos);

		std::array<value_type, 9 * 9>* m_grid;
		std::uint8_t m_index;
		size_type m_pos;
};

class SudokuGrid::Row
{
	friend SudokuGrid;

	public:
		class iterator;

		using value_type = std::uint8_t;
		using pointer = value_type * ;
		using const_pointer = const value_type*;
		using reference = value_type & ;
		using const_reference = const value_type&;
		using size_type = std::size_t;
		using difference_type = std::size_t;

		Row() = delete;
		Row(const Row&) = delete;
		Row(Row&&) = default;

		iterator begin();
		iterator end();

		reference operator[](size_type i);
		const_reference operator[](size_type i) const;

		Row& operator=(const Row&) = default;
		Row& operator=(Row&&) = default;

	private:

		Row(std::array<value_type, 9 * 9>* grid, std::uint8_t index);

		std::array<value_type, 9 * 9>* m_grid;
		std::uint8_t m_index;
};

class SudokuGrid::Row::iterator
{
	friend Row;

	public:
		using value_type = std::uint8_t;
		using pointer = value_type * ;
		using const_pointer = const value_type*;
		using reference = value_type & ;
		using const_reference = const value_type&;
		using size_type = std::size_t;
		using difference_type = std::size_t;

		iterator() = delete;
		iterator(const iterator&) = default;
		iterator(iterator&&) = default;

		reference operator*();
		const_reference operator*() const;

		iterator& operator++();
		iterator operator++(int);
		iterator& operator--();
		iterator operator--(int);
		iterator operator+(difference_type n);
		iterator& operator+=(difference_type n);
		iterator operator-(difference_type n);
		iterator& operator-=(difference_type n);

		bool operator==(const iterator& rhs) const;
		bool operator!=(const iterator& rhs) const;

		iterator& operator=(const iterator&) = default;
		iterator& operator=(iterator&&) = default;

	private:

		iterator(std::array<value_type, 9 * 9>* grid, std::uint8_t index, size_type pos);

		std::array<value_type, 9 * 9>* m_grid;
		std::uint8_t m_index;
		size_type m_pos;
};

class SudokuGrid::Subgrid
{
	friend SudokuGrid;

	public:
		class iterator;

		using value_type = std::uint8_t;
		using pointer = value_type * ;
		using const_pointer = const value_type*;
		using reference = value_type & ;
		using const_reference = const value_type&;
		using size_type = std::size_t;
		using difference_type = std::size_t;

		Subgrid() = delete;
		Subgrid(const Subgrid&) = delete;
		Subgrid(Subgrid&&) = default;

		iterator begin();
		iterator end();

		reference operator[](size_type i);
		const_reference operator[](size_type i) const;

		Subgrid& operator=(const Subgrid&) = default;
		Subgrid& operator=(Subgrid&&) = default;

	private:

		Subgrid(std::array<value_type, 9 * 9>* grid, std::uint8_t index);

		std::array<value_type, 9 * 9>* m_grid;
		std::uint8_t m_index;
};

class SudokuGrid::Subgrid::iterator
{
	friend Subgrid;

	public:
		using value_type = std::uint8_t;
		using pointer = value_type * ;
		using const_pointer = const value_type*;
		using reference = value_type & ;
		using const_reference = const value_type&;
		using size_type = std::size_t;
		using difference_type = std::size_t;

		iterator() = delete;
		iterator(const iterator&) = default;
		iterator(iterator&&) = default;

		reference operator*();
		const_reference operator*() const;

		iterator& operator++();
		iterator operator++(int);
		iterator& operator--();
		iterator operator--(int);
		iterator operator+(difference_type n);
		iterator& operator+=(difference_type n);
		iterator operator-(difference_type n);
		iterator& operator-=(difference_type n);

		bool operator==(const iterator& rhs) const;
		bool operator!=(const iterator& rhs) const;

		iterator& operator=(const iterator&) = default;
		iterator& operator=(iterator&&) = default;

	private:

		iterator(std::array<value_type, 9 * 9>* grid, std::uint8_t index, size_type pos);

		std::array<value_type, 9 * 9>* m_grid;
		std::uint8_t m_index;
		size_type m_pos;
};

#endif // !SUDOKUGRID_HPP
