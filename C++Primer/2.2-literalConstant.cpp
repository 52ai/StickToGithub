#include <iostream>

int main(){
    s\
td::cout << "1"
                 "2"
                 "3"
              <<std::endl;

    /*************CHAR****************/
    'A';//char
    L'a';//wchar_t
    /*************INTRGER****************/
    int a=20;//decimal int
    int b=024;//octal int
    int c=0x14;//hexdecimal int
    std::cout << a << b << c <<std::endl;
    128u;//unsigned
    1024UL;//unsigned long
    1L;//long
    8Lu;//unsigned long
    /*dont have short literal constant*/
    /**************BOOL***************/
    bool test_bool = false;
    std::cout << test_bool <<std::endl;
    /**************FLOAT***************/
    3.14159F;
    3.14159E0f;
    .001f;
    1E-3F;
    12.345L;
    1.2345E1L;
    0.;
    0E0;
    /**************ESCAPE SEQUENCE***************/
    std::cout << "a\n"
                 "bcde\t"
                 "efg\v"
                 "hijkl\b"
                 "mn\r"
                 "opq\f"
                 "rst\a"
                 "uvw\\"
                 "x\?"
                 "y\'"
                 "z\""
                 "abc\7"
                 "\12efg"
                 "\40hijkl"
                 "\062\115\0"
                 <<std::endl;
    char _ = '1';
    std::cout << _ << std::endl;
    return 0;
}
