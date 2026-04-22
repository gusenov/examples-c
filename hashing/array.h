#define LEN 8
#define SIZE 1000

/*
struct Human {
    char name[LEN];
};
*/

//struct Human g_people[SIZE];

/*
struct Human g_people[SIZE] = 
{
    {"Alina"},
    {"Alisa"},
    {"Ayla"},
    {"Bonnie"},
    {"Alice"},
    {"Dolores"},
    {"Ebba"},
    {"Eileen"},
    {"Elvina"},
    {"Eteri"},
    {"Eva"},
    {"Eve"},
    {"Lily"},
    {"Tair"},
    {"Timur"},
    {"Bob"}
};
*/

/*
struct Human g_people[SIZE] = 
{
    {.name = "Alina"},
    {.name = "Alisa"},
    {.name = "Ayla"},
    {.name = "Bonnie"},
    {.name = "Alice"},
    {.name = "Dolores"},
    {.name = "Ebba"},
    {.name = "Eileen"},
    {.name = "Elvina"},
    {.name = "Eteri"},
    {.name = "Eva"},
    {.name = "Eve"},
    {.name = "Lily"},
    {.name = "Tair"},
    {.name = "Timur"},
    {.name = "Bob"}
};
*/

typedef struct {
    char name[LEN];
} Human;

//Human g_people[SIZE];

/*
Human g_people[SIZE] = 
{
    {"Alina"},
    {"Alisa"},
    {"Ayla"},
    {"Bonnie"},
    {"Alice"},
    {"Dolores"},
    {"Ebba"},
    {"Eileen"},
    {"Elvina"},
    {"Eteri"},
    {"Eva"},
    {"Eve"},
    {"Lily"},
    {"Tair"},
    {"Timur"},
    {"Bob"}
};
*/

Human g_people[SIZE] = 
{
    {.name = "Alina"},
    {.name = "Alisa"},
    {.name = "Ayla"},
    {.name = "Bonnie"},
    {.name = "Alice"},
    {.name = "Dolores"},
    {.name = "Ebba"},
    {.name = "Eileen"},
    {.name = "Elvina"},
    {.name = "Eteri"},
    {.name = "Eva"},
    {.name = "Eve"},
    {.name = "Lily"},
    {.name = "Tair"},
    {.name = "Timur"},
    {.name = "Bob"}
};

Human g_array[SIZE];
