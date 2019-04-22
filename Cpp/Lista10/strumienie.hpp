#ifndef strumienie_hpp
#define strumienie_hpp

#include <iostream>
#include <fstream>
#include <iomanip>
namespace strumienie{

    inline std::ostream& comma (std::ostream& os){
        os << ", ";
        return os;
    }

    inline std::ostream& colon (std::ostream& os){
        os << ": ";
        return os;
    }

    inline std::istream& clearline (std::istream& is){

        char c;

        do{
            c = is.peek();

            if (c == EOF){
                return is;
            }

            if (c == '\n'){
                is.get();
                return is;
            }


            is.get();

        }while(1);

    }

    class Index{
        int space;
        int num;

        friend std::ostream& operator << (std::ostream& os, const Index& ind){
            os << '[' << std::setw(ind.space) << ind.num << ']';
            return os;
        }

    public:
        Index(int spc, int nr) : space(spc), num(nr) {}

    };
    class Ignore{
        int to_ignore;

        friend std::istream& operator >> (std::istream& is, const Ignore& ign){

            char c;
            int to_ign = ign.to_ignore;

            c = is.peek();

            while (to_ign > 0){
                c = is.peek();
                if (c == EOF)
                    break;

                if (c == '\n'){
                    is.get();
                    break;
                }
                is.get();
                to_ign--;
            }
            return is;
        }
    public:
        Ignore(int to_ign) : to_ignore(to_ign) {}
    };



}
#endif // strumienie_hpp
