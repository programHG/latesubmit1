//dayOfYear ==> dayOfYearDynamicArray
//dPtr==>a


#include "dayOfYear.h"
namespace LEEHyeonGyeon2693251
{
    class dayOfYearDynamicArray
    {
        int n;
        dayOfYear* a;
    public:
        dayOfYearDynamicArray(int m = 10)  :n{m}, a{new dayOfYear[n]}{}
        ~dayOfYearDynamicArray(){delete[] a;}
        dayOfYearDynamicArray(const dayOfYearDynamicArray& copy)
        :n{copy.n}
        {//*a: a[0]
            if (copy.a) 
            {
                a = new dayOfYear[n];
                for (int i=0; i<n; ++i)
                    a[i] = copy.a[i]; // *(a+i) =  *(copy.a+i)
            } 
            else a = nullptr;
        }
        dayOfYearDynamicArray(dayOfYearDynamicArray&& move) noexcept
        {
            n = move.n; move.n =0;
            a = move.a; move.a = nullptr;
        }
        dayOfYearDynamicArray& operator=(const dayOfYearDynamicArray& copy) 
        {
            if ( this != &copy)
            {
                n = copy.n;
                delete[] a;
                if (copy.a) 
                {
                    a = new dayOfYear[n];
                    for (int i=0; i<n; ++i)
                        a[i] = copy.a[i]; // *(a+i) =  *(copy.a+i)
                } 
                else a = nullptr;
            }
            return *this;
        }
        dayOfYearDynamicArray& operator=(dayOfYearDynamicArray&& move) noexcept
        {
            if (this != &move)
            {
                delete[] a;
                n = move.n; move.n =0;
                a = move.a; move.a = nullptr;

            }
            return *this;
        }

        dayOfYear& operator[](int i)
        {// i ; 0,1,2, ....., n-1
            if (i<n) return a[i];
            else{
                std::cout << "illegal  index\n";
                std::exit(1);
            }
        }

        void printAll()const
        {
            if (a) 
                for (int i =0; i<n; ++i) 
                    std::cout << *(a+i);
            else std::cout << "no data (nullptr)\n";
            
        }
    };
}