
#include <iostream>
#include <array>
#include <vector>
#include <cstdint>

#include <SudokuGrid.hpp>

int main()
{
	constexpr const std::uint8_t _ = 0;

	std::array<std::uint8_t, 9 * 9> gridVals
	{
		_, _, _, 3, 4, _, _, _, 1,
		3, 9, 8, _, _, 6, 7, 4, _,
		_, _, _, _, _, _, 9, _, 5,
		8, 7, _, _, 2, _, 3, _, 4,
		_, 2, 5, 4, 3, 7, 8, 1, _,
		1, _, 4, _, 6, _, _, 7, 9,
		6, _, 9, _, _, _, _, _, _,
		_, 8, 3, 2, _, _, 1, 6, 7,
		2, _, _, _, 5, 3, _, _, _
	};

	SudokuGrid grid(std::move(gridVals));

	const auto& values = grid.GetValues();

	std::array<std::uint8_t, 9 * 9> results = values;

	int i = 0;
	for (auto r : results)
	{
		if (i % 9 == 0)
			std::cout << std::endl;
		std::cout << int(r) << " ";
		++i;
	}
	std::cout << std::endl;

	while (std::find(results.begin(), results.end(), _) != results.end())
	{
		for (i = 0; i < values.size(); ++i)
		{
			if (results[i] > 0)
				continue;

			std::vector<std::uint8_t> possibleValues{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

			auto column = grid.GetColumn(i % 9);
			for (auto c : column)
			{
				auto it = std::find(possibleValues.begin(), possibleValues.end(), c);

				if (it != possibleValues.end())
					possibleValues.erase(it);
			}

			auto row = grid.GetRow(i / 9);
			for (auto r : row)
			{
				auto it = std::find(possibleValues.begin(), possibleValues.end(), r);

				if (it != possibleValues.end())
					possibleValues.erase(it);
			}

			auto subgrid = grid.GetSubgrid(((i / 9) / 3) * 3 + ((i % 9) / 3));
			for (auto s : subgrid)
			{
				auto it = std::find(possibleValues.begin(), possibleValues.end(), s);

				if (it != possibleValues.end())
					possibleValues.erase(it);
			}
			
			if (possibleValues.size() == 1)
			{
				results[i] = possibleValues.front();
			}
		}
	}

	i = 0;
	for (auto r : results)
	{
		if (i % 9 == 0)
			std::cout << std::endl;
		std::cout << int(r) << " ";
		++i;
	}
	std::cout << std::endl;
	std::getchar();

	return EXIT_SUCCESS;
}