#include <cstdio>
#include <cstring>

void read_from(char* source, char* dest, size_t dest_size) {
    
    strncpy(dest, source, dest_size - 1);  
    dest[dest_size - 1] = '\0';  
}

void write_to(char* dest, const char* source, size_t dest_size) {  
    strncpy(dest, source, dest_size - 1);  
    dest[dest_size - 1] = '\0';  
}

int main() {
    char lower[6] = "abc?e";  
    char upper[6] = "ABC?E";  
    char* upper_ptr = upper;

    lower[3] = 'd';  
    upper_ptr[3] = 'D';  

    
    char dest[6];
    read_from(lower, dest, sizeof(dest));
    printf("Read from lower: %s\n", dest);

    
    const char* new_string = "Hello";
    write_to(upper, new_string, sizeof(upper));
    printf("Written to upper: %s\n", upper);

    printf("lower: %s\nupper: %s\n", lower, upper);

    return 0;
}

