![WINC](./WINC.png)


WINC - it's a set of simple and convenient cross-platform libraries for C language. A 
large number of different libraries will be added soon, but now the set contains the following 
libraries for working with:

- File system
- Utils
  -  Collections
  -  Multithreading

## Short examples
   
One of the collection from the *Utils* library:    
    

    
    list_t list = init_list();
    push_back_list(list, "world");
    push_back_list(list, "!!!");
    push_front_list(list, "Hello ");
    
    FOR_EACH_LIST(iterator, list)
    {
        printf("%s", (char*) list_get(iterator));
    }
    
    destroy_list(list);
    
    
## How to build WINC


Clone a copy of the main WINC git repository by running:

    git clone https://github.com/VladimirBalun/WINC.git

For  UNIX-based systems you can use following script:

    ./build.sh  
    
Script for windows  will be supplemented over time, but you also   
can also build manually by running the following commands:

    mkdir build
    cd build
    cmake ..
___
Documentation will be supplemented over time, but if you 
have any questions, please contact: vladimirbalun@yandex.ru
    
