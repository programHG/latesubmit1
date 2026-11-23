#include "dayOfYearDynamicArray.h"
#include <vector>
namespace LEEHyeonGyeon2693251
{
    void printVectorDayOfYearDymanicArray(std::vector<dayOfYearDynamicArray> v)
    {
        for (const auto& vi : v)
            vi.printAll();
        std::cout << v.size() << "/" << v.capacity() << std::endl;
    }
}

int main()
{
    using namespace LEEHyeonGyeon2693251;
    dayOfYearDynamicArray a1{3}, a2, a3;
    a1[0] =dayOfYear{11,12};
    a2[1] =dayOfYear{12,12};
    a3[2] =dayOfYear{1,12};
    std::cout << "a1:\n"; a1.printAll();

    a2 = a1; 
    std::cout << "a2:\n"; a2.printAll();

    a3 = std::move(a2);
    std::cout << "a2:\n"; a2.printAll();

    std::vector<dayOfYearDynamicArray> v; printVectorDayOfYearDymanicArray(v);
    v.push_back(a1); printVectorDayOfYearDymanicArray(v); 
    v.push_back(std::move(a1));

    std::cout << "a1:\n"; a1.printAll();

    return 0;
}