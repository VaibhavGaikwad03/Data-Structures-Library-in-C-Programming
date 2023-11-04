#define MAX_FIELD_NAME_SIZE 128
#define MAX_STRUCTURE_NAME_SIZE 128

typedef enum
{
    UINT8,
    UINT32,
    INT32,
    CHAR,
    OBJ_PTR,
    FLOAT,
    DOUBLE,
    OBJ_STRUCT
} data_type_t;

typedef struct field_info
{
    char fname[MAX_FIELD_NAME_SIZE];
    unsigned int size;
    unsigned int offset;
    data_type_t type;
    char nested_struct_name[MAX_STRUCTURE_NAME_SIZE];
} field_info_t;

struct data_base_rec
{
    struct data_base_rec *next;
    char struct_name[MAX_STRUCTURE_NAME_SIZE];
    unsigned int size;
    unsigned int n_fields;
    field_info_t *fields;
};