#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

namespace hpx
{
	namespace flow{
    	class hpxflow{
        	public:
            
            string buffer, inter_buffer;
            char c;

            hpxflow(string filename) { //This constructor simply reades file input
                ifstream inf(filename);
                
                // Although and expensive operation, I appened buffer char by char to have new line or tab space character included.
                while (inf.get(c))
                    buffer += c;
            }

            hpxflow &characterOperation(char character, char replace_with){
                string app;
                for(int i = 0; i < strlen(buffer.c_str()); i++){
                    if(buffer[i] == character){

                        app = app + replace_with;

                    } else{

                        app = app + buffer[i];

                    }
                }
                // }
                buffer = app;
                return *this;
            }

            hpxflow &write_to_file(string filename){
                std::ofstream out(filename);
                out << buffer;
                out.close();
                return *this;
            }

        };

    }
}
//int main(){
//    hpxflow("text.txt").character_operation('\t', '\n').write_to_file("output.txt");
//    return 0;
//}
