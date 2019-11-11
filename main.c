#include <stdio.h> 
#include <stdlib.h> 
#include <jedi.h> 
#include <string.h> 



int main(){ 
    Dictionary test = NewDictionary(10); 
    add(&test, "Carlos", NewVarS("Miranda")); 
    add(&test, "Cristhel", NewVarS("Rubio")); 
    add(&test, "Nicolas", NewVarS("-------")); 
    add(&test, "Ian", NewVarS("Granados")); 
    add(&test, "TOM", NewVarS("........")); 
    add(&test, "solrac", NewVarS("--------")); 
    test.print(&test); 
    char* key = "Ian"; 
    Var lastname = lookup(&test, key); 
    char* aux; 
    aux = VarToString(lastname); 
    printf("\n%s: %s\n", key, aux);
    remove_entry(&test, "Ian"); 
    test.print(&test); 
    printf("\n"); 
    int size = 0; 
    char** keys = get_keys(&test, &size); 
    for(int n = 0; n<size; n++){
        printf("key:%s\n", keys[n]); 
    }
    Var* values = get_values(&test, &size); 
    for(int n = 0; n<size; n++){
        aux = VarToString(values[n]); 
        printf("value:%s\n", aux); 
    }
    free(values); 
    free(keys); 
    free(aux); 
    DestroyDictionary(&test); 
    return 0; 
}
