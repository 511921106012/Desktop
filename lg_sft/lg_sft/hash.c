typedef Struct hash_table
{
    unsigned int index;
    int data;
    Struct hash_table *link;
}hash_t;

int create(hash_t *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i].index = i;
        arr[i].dat = data;
        arr[i].link = NULL; 
    }
}

int insert(hash_t *arr, int size, int data)
{
    int i = data % size;
    if(arr[i].data == -1)
    {
        arr[i].data = data;
        return success;
    }
    else
    {
        hash_t *new = malloc(sizeof(hash_t));
        new->data = data;
        new->index = i;
        new->link = NULL;
        if(arr[i].link == NULL)
        {
            arr[i].link = new;
            return success;
        }
        else
        {
            hash_t *temp = arr[i].link;
            while(tem->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = new;
            return success;
        }
    }

}