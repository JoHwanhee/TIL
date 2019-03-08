
void dfs(Vertex* v)
{
    if(!v)
    {
        return;
    }
    if(v->visited)
    {
        return;        
    }

    printf("%c", v->data);
    Edge* e = v->adjacencyList;
    v->visited = 1;

    while (e)
    {
        dfs(e->to);
        e = e->next;
    }
}

void bfs(Vertex* root)
{
    if(!root)
    {
        return;
    }

    Queue* q = create_queue();
    enQueue(q, root);

    while(!isEmpty(q))
    {
        Vertex* v = deQueue(q);
        printf("%c", v->data);
        v->visited = 1;

        Edge* e = v->adjacencyList;
        while(e)
        {
            if(!e->to->visited)
            {
                enQueue(q, e->to);
            }

            e = e->next;
        }
    }

    destory_queue(q);
}
