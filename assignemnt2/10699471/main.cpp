#include <iostream>
#include "loader.hpp"


int main() {
    
    loadFactory();
    auto &factory = MyObjectFactory::Instance();
    auto  list = factory.registered();
    
    std::cout << "These are the possible solvers:" << std::endl;
    for(std::size_t i = 0; i < list.size(); ++i)
    {
        std::cout << list[i] << std::endl;
    }
    std::cout<<std::endl;
    
 
    while(true){
    std::cout << "Pick a solver (type the name as shown or type quit to exit)" << std::endl;
    std::string s;
    std::cin>>s;
    std::cout<<std::endl;
    if(s=="quit") break;
    bool valid=false;
    for(std::size_t i = 0; i < list.size(); ++i) {
    						 if(list[i]==s) {valid=true;
    						 break;
    						 }
    						 }
    if(valid==true){
    auto C=factory.create(s);
    C->read_parameters("parameters_"+s+".pot");
    C->solve();
    C->write_error_on_file();  
    }
    }



    return 0;
}
