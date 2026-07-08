#include "PmergeMe.hpp"


static int	parsePositiveInt(const char *arg)
{
    char *end = NULL;
    long value = std::strtol(arg, &end, 10);

    if (arg[0] == '\0' || *end != '\0' || value < 0 || value > INT_MAX)
        throw std::runtime_error("Error: invalid input");
    return static_cast<int>(value);
}

static void	printBefore(const std::vector<int> &values)
{
    std::cout << "Before: ";
    for (std::vector<int>::const_iterator it = values.begin(); it != values.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;
}

int main(int ac, char **av)
{
    try
    {
        if (ac < 2)
            throw std::runtime_error("Error: no input provided");

        std::vector<int> input;
        for (int i = 1; i < ac; ++i)
            input.push_back(parsePositiveInt(av[i]));

        printBefore(input);

        std::vector<int> vectorValues = input;
        std::list<int> listValues(input.begin(), input.end());
        PmergeMe sorter;

        std::clock_t vectorStart = std::clock();
        sorter.sort(vectorValues);
        std::clock_t vectorEnd = std::clock();

        std::clock_t listStart = std::clock();
        sorter.sort(listValues);
        std::clock_t listEnd = std::clock();

        std::cout << "After: ";
        for (std::vector<int>::const_iterator it = vectorValues.begin(); it != vectorValues.end(); ++it)
            std::cout << *it << ' ';
        std::cout << std::endl;

        std::cout << "Time to process a range of " << input.size() << " elements with std::vector : "
            << static_cast<double>(vectorEnd - vectorStart)  / CLOCKS_PER_SEC << " us" << std::endl;
        std::cout << "Time to process a range of " << input.size() << " elements with std::list   : "
            << static_cast<double>(listEnd - listStart)  / CLOCKS_PER_SEC << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}