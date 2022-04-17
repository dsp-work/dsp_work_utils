#include <DspWorkUtils/stack_backtrace>
#include <cstdlib>
#include <iostream>


void subsub_func()
{
    std::cout << "stack_trace\n";
    std::cout << boost::stacktrace::stacktrace();
    exit( EXIT_SUCCESS );
}

void sub_func( int level )
{
    if ( 0 < level )
    {
        sub_func( level - 1 );
        return;
    }
    subsub_func();
}