/*
Solutions, notes from 2.31-2.
*/

#include <stdbool.h>
#include <stdio.h>

int main()
{
}

/*
Addition forms an abelian group, s.t. x+y-y=x regardless, So can't be tested by (sum - y)==x
*/

bool tadd_ok(int x, int y)
{
    int sum = x + y;
    bool posflow = sum < 0 && x > 0 && y > 0;
    bool negflow = sum > 0 && x < 0 && y < 0;
    return !posflow & !negflow;
}

/*
bool invalid_tsub_ok(int x,int y){
    return tadd_ok(x, -y);
}
// consider y =T_Min, 0x80000000
by 2's complement, -y will also be T_Min, causing problems
*/

bool tsub_ok(int x, int y)
{
    if (y == 0x80000000 && x >= 0) return false;
    return tadd_ok(x, -y);
}

/*
bool invalid_tmult_ok(int x, int y)
{
    int p = x * y;
    return !x || p / x == y;
}
When x*y = p + t*2^w, it will return.
*/

bool tmult_ok(int x, int y)
{
    __int64_t result = x * y;
    return !x || result / x == y;
}

bool malloc_able(int ele_cnt, int ele_size)
{
    if (ele_size > 0xFFFFFFFF / ele_cnt)
    {
        return false;
    }
    return true;
    /*
    Also possible to use the tmult_ok?
    */
}
