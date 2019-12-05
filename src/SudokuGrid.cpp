
#include <SudokuGrid.hpp>

#include <iostream>

// SUDOKUGRID

SudokuGrid::SudokuGrid(std::array<std::uint8_t, 9 * 9> values)
	:
	m_values(std::move(values))
{}

SudokuGrid::Column SudokuGrid::GetColumn(std::uint8_t index)
{
	SudokuGrid::Column column(&m_values, index);
	return column;
}

SudokuGrid::Row SudokuGrid::GetRow(std::uint8_t index)
{
	SudokuGrid::Row row(&m_values, index);
	return row;
}

SudokuGrid::Subgrid SudokuGrid::GetSubgrid(std::uint8_t index)
{
	SudokuGrid::Subgrid subgrid(&m_values, index);
	return subgrid;
}

std::array<std::uint8_t, 9 * 9>& SudokuGrid::GetValues()
{
	return m_values;
}

// SUDOKUGRID::COLUMN

SudokuGrid::Column::Column(std::array<value_type, 9 * 9>* grid, std::uint8_t index)
	:
	m_grid(grid),
	m_index(index)
{}

SudokuGrid::Column::iterator SudokuGrid::Column::begin()
{
	iterator it(m_grid, m_index, 0);
	return it;
}

SudokuGrid::Column::iterator SudokuGrid::Column::end()
{
	iterator it(m_grid, m_index, 9);
	return it;
}

SudokuGrid::Column::reference SudokuGrid::Column::operator[](size_type i)
{
	return (*m_grid)[m_index + 9 * i];
}

SudokuGrid::Column::const_reference SudokuGrid::Column::operator[](size_type i) const
{
	return (*m_grid)[m_index + 9 * i];
}

// SUDOKUGRID::COLUMN::ITERATOR

SudokuGrid::Column::iterator::iterator(std::array<value_type, 9 * 9>* grid, std::uint8_t index, size_type pos)
	:
	m_grid(grid),
	m_index(index),
	m_pos(pos)
{}

SudokuGrid::Column::iterator::reference SudokuGrid::Column::iterator::operator*()
{
	return (*m_grid)[m_index + 9 * m_pos];
}

SudokuGrid::Column::iterator::const_reference SudokuGrid::Column::iterator::operator*() const
{
	return (*m_grid)[m_index + 9 * m_pos];
}

SudokuGrid::Column::iterator& SudokuGrid::Column::iterator::operator++()
{
	++m_pos;
	return *this;
}

SudokuGrid::Column::iterator SudokuGrid::Column::iterator::operator++(int)
{
	iterator last = *this;
	++m_pos;
	return last;
}

SudokuGrid::Column::iterator& SudokuGrid::Column::iterator::operator--()
{
	--m_pos;
	return *this;
}

SudokuGrid::Column::iterator SudokuGrid::Column::iterator::operator--(int)
{
	SudokuGrid::Column::iterator last = *this;
	--m_pos;
	return last;
}

SudokuGrid::Column::iterator SudokuGrid::Column::iterator::operator+(difference_type n)
{
	iterator it(m_grid, m_index, m_pos + n);
	return it;
}

SudokuGrid::Column::iterator& SudokuGrid::Column::iterator::operator+=(difference_type n)
{
	m_pos += n;
	return *this;
}

SudokuGrid::Column::iterator SudokuGrid::Column::iterator::operator-(difference_type n)
{
	iterator it(m_grid, m_index, m_pos - n);
	return it;
}

SudokuGrid::Column::iterator& SudokuGrid::Column::iterator::operator-=(difference_type n)
{
	m_pos -= n;
	return *this;
}

bool SudokuGrid::Column::iterator::operator==(const iterator& rhs) const
{
	return m_pos == rhs.m_pos && m_index == rhs.m_index && m_grid == rhs.m_grid;
}

bool SudokuGrid::Column::iterator::operator!=(const iterator& rhs) const
{
	return m_pos != rhs.m_pos || m_index != rhs.m_index || m_grid != rhs.m_grid;
}

// SUDOKUGRID::ROW

SudokuGrid::Row::Row(std::array<value_type, 9 * 9>* grid, std::uint8_t index)
	:
	m_grid(grid),
	m_index(index)
{}

SudokuGrid::Row::iterator SudokuGrid::Row::begin()
{
	iterator it(m_grid, m_index, 0);
	return it;
}

SudokuGrid::Row::iterator SudokuGrid::Row::end()
{
	iterator it(m_grid, m_index, 9);
	return it;
}

SudokuGrid::Row::reference SudokuGrid::Row::operator[](size_type i)
{
	return (*m_grid)[m_index * 9 + i];
}

SudokuGrid::Row::const_reference SudokuGrid::Row::operator[](size_type i) const
{
	return (*m_grid)[m_index * 9 + i];
}

// SUDOKUGRID::ROW::ITERATOR

SudokuGrid::Row::iterator::iterator(std::array<value_type, 9 * 9>* grid, std::uint8_t index, size_type pos)
	:
	m_grid(grid),
	m_index(index),
	m_pos(pos)
{}

SudokuGrid::Row::iterator::reference SudokuGrid::Row::iterator::operator*()
{
	return (*m_grid)[m_index * 9 + m_pos];
}

SudokuGrid::Row::iterator::const_reference SudokuGrid::Row::iterator::operator*() const
{
	return (*m_grid)[m_index * 9 + m_pos];
}

SudokuGrid::Row::iterator& SudokuGrid::Row::iterator::operator++()
{
	++m_pos;
	return *this;
}

SudokuGrid::Row::iterator SudokuGrid::Row::iterator::operator++(int)
{
	iterator last = *this;
	++m_pos;
	return last;
}

SudokuGrid::Row::iterator& SudokuGrid::Row::iterator::operator--()
{
	--m_pos;
	return *this;
}

SudokuGrid::Row::iterator SudokuGrid::Row::iterator::operator--(int)
{
	iterator last = *this;
	--m_pos;
	return last;
}

SudokuGrid::Row::iterator SudokuGrid::Row::iterator::operator+(difference_type n)
{
	iterator it(m_grid, m_index, m_pos + n);
	return it;
}

SudokuGrid::Row::iterator& SudokuGrid::Row::iterator::operator+=(difference_type n)
{
	m_pos += n;
	return *this;
}

SudokuGrid::Row::iterator SudokuGrid::Row::iterator::operator-(difference_type n)
{
	iterator it(m_grid, m_index, m_pos - n);
	return it;
}

SudokuGrid::Row::iterator& SudokuGrid::Row::iterator::operator-=(difference_type n)
{
	m_pos -= n;
	return *this;
}

bool SudokuGrid::Row::iterator::operator==(const iterator& rhs) const
{
	return m_pos == rhs.m_pos && m_index == rhs.m_index && m_grid == rhs.m_grid;
}

bool SudokuGrid::Row::iterator::operator!=(const iterator& rhs) const
{
	return m_pos != rhs.m_pos || m_index != rhs.m_index || m_grid != rhs.m_grid;
}

// SUDOKUGRID::SUBGRID

SudokuGrid::Subgrid::Subgrid(std::array<value_type, 9 * 9>* grid, std::uint8_t index)
	:
	m_grid(grid),
	m_index(index)
{}

SudokuGrid::Subgrid::iterator SudokuGrid::Subgrid::begin()
{
	iterator it(m_grid, m_index, 0);
	return it;
}

SudokuGrid::Subgrid::iterator SudokuGrid::Subgrid::end()
{
	iterator it(m_grid, m_index, 9);
	return it;
}

SudokuGrid::Subgrid::reference SudokuGrid::Subgrid::operator[](size_type i)
{
	return (*m_grid)[(i / 3 + (m_index / 3 * 3)) * 9 + (i % 3 + ((m_index % 3) * 3))];
}

SudokuGrid::Subgrid::const_reference SudokuGrid::Subgrid::operator[](size_type i) const
{
	return (*m_grid)[(i / 3 + (m_index / 3 * 3)) * 9 + (i % 3 + ((m_index % 3) * 3))];
}

// SUDOKUGRID::SUBGRID::ITERATOR

SudokuGrid::Subgrid::iterator::iterator(std::array<value_type, 9 * 9>* grid, std::uint8_t index, size_type pos)
	:
	m_grid(grid),
	m_index(index),
	m_pos(pos)
{}

SudokuGrid::Subgrid::iterator::reference SudokuGrid::Subgrid::iterator::operator*()
{
	return (*m_grid)[(m_pos / 3 + (m_index / 3 * 3)) * 9 + (m_pos % 3 + ((m_index % 3) * 3))];
}

SudokuGrid::Subgrid::iterator::const_reference SudokuGrid::Subgrid::iterator::operator*() const
{
	return (*m_grid)[(m_pos / 3 + (m_index / 3 * 3)) * 9 + (m_pos % 3 + ((m_index % 3) * 3))];
}

SudokuGrid::Subgrid::iterator& SudokuGrid::Subgrid::iterator::operator++()
{
	++m_pos;
	return *this;
}

SudokuGrid::Subgrid::iterator SudokuGrid::Subgrid::iterator::operator++(int)
{
	SudokuGrid::Subgrid::iterator last = *this;
	++m_pos;
	return last;
}

SudokuGrid::Subgrid::iterator& SudokuGrid::Subgrid::iterator::operator--()
{
	--m_pos;
	return *this;
}

SudokuGrid::Subgrid::iterator SudokuGrid::Subgrid::iterator::operator--(int)
{
	iterator last = *this;
	--m_pos;
	return last;
}

SudokuGrid::Subgrid::iterator SudokuGrid::Subgrid::iterator::operator+(difference_type n)
{
	iterator it(m_grid, m_index, m_pos + n);
	return it;
}

SudokuGrid::Subgrid::iterator& SudokuGrid::Subgrid::iterator::operator+=(difference_type n)
{
	m_pos += n;
	return *this;
}

SudokuGrid::Subgrid::iterator SudokuGrid::Subgrid::iterator::operator-(difference_type n)
{
	iterator it(m_grid, m_index, m_pos - n);
	return it;
}

SudokuGrid::Subgrid::iterator& SudokuGrid::Subgrid::iterator::operator-=(difference_type n)
{
	m_pos -= n;
	return *this;
}

bool SudokuGrid::Subgrid::iterator::operator==(const iterator& rhs) const
{
	return m_pos == rhs.m_pos && m_index == rhs.m_index && m_grid == rhs.m_grid;
}

bool SudokuGrid::Subgrid::iterator::operator!=(const iterator& rhs) const
{
	return m_pos != rhs.m_pos || m_index != rhs.m_index || m_grid != rhs.m_grid;
}