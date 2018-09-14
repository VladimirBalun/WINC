<p align="center">
    <img
      alt="WINC"
      src="https://downloader.disk.yandex.ru/preview/53f91952a196156792dce7a6813a208da3c579194dca7312e29eb0e7182c19af/5b9c2e78/QIu_UHwQI7Su_15ipwApzqJ1eYAnQJo8Hb4pgrYptYSM2WFuiVeUN_LkQVZ9Sy4EH8NDhSF1E2xCxrTUcxChjg%3D%3D?uid=0&filename=WINC.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&size=1680x938"
      width="250"
     />
</p>
## General information

WINC - it's a set of simple and convenient cross-platform libraries for C language. A 
large number of different libraries will be added soon, but now the set contains the following 
libraries for working with:

- File system
- Utils
  -  Collections
  -  Multithreading

## Short examples
   
One of the collection from the *Utils* library:    
    
~~~C
list_t list = init_list();
push_back_list(list, "world");
push_back_list(list, "!!!");
push_front_list(list, "Hello ");
    
FOR_EACH_LIST(iterator, list)
{
    printf("%s", (char*) list_get(iterator));
}
    
destroy_list(list);
~~~
    
## How to build WINC

Clone a copy of the main WINC git repository by running:

    git clone https://github.com/VladimirBalun/WINC.git

For building libraries you can use following script:

    build.bat  // for Windows
    ./build.sh // for UNIX-based
  
You also can  build manually by running the following commands:

    mkdir build
    cd build
    cmake ..
    // run with your compiler 
    
___
Documentation will be supplemented over time, but if you 
have any questions, please contact: vladimirbalun@yandex.ru
