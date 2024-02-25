#ifndef _SALES_H
#define _SALES_H

namespace SALES
{
    class Sales
    {
    private:
        enum
        {
            QUARTERS = 4
        };
        double sales[QUARTERS];
        double average;
        double max;
        double min;

    public:
        Sales()
        {
            for (int i = 0; i < QUARTERS; i++)
            {
                sales[i] = 0;
            }
            average = 0;
            max = 0;
            min = 0;
        }
        Sales(const double ar[], int n);
        void showSales() const;
    };
}

#endif