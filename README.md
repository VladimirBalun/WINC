<p align="center">
    <img
      alt="WINC"
      src="https://downloader.disk.yandex.ru/preview/0383daf829045ac6e18f018fb959e47ce446412b4730ff30155678342baddcb7/5ba6b58e/QIu_UHwQI7Su_15ipwApzqJ1eYAnQJo8Hb4pgrYptYSM2WFuiVeUN_LkQVZ9Sy4EH8NDhSF1E2xCxrTUcxChjg%3D%3D?uid=0&filename=WINC.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&size=2048x2048"
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
   
One of the example collection from the *Utils* library:    
    
~~~C
int main(int argc, char** argv)
{
    list_t* list = init_list();
    push_back_list(list, "world");
    push_back_list(list, "!!!");
    push_front_list(list, "Hello ");
        
    FOR_EACH_LIST(iterator, list)
    {
        printf("%s", (char*) list_get(iterator));
    }
          
    destroy_list(list);
    return EXIT_SUCCESS;
}
~~~
   
 Example of the file system iterator from the *FileSystem* library:     
    
~~~C
void iteration_callback(const char* element)
{
    printf("%s\n", element);
}

int main(int argc, char** argv)
{
    char* user_dir = get_user_directory();
    printf("Iteration in the user directory:\n");
    path_iterate(user_dir, iteration_callback);   
          
    free(user_dir);
    return EXIT_SUCCESS;
}
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
