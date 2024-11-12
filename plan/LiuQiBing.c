#include "strbuf.h"
void strbuf_init(struct strbuf *sb, size_t alloc)
{
    sb->len =0;
    sb->alloc = alloc;
    sb->buf = malloc(alloc);
    if(sb->buf == NULL)
    {
        perror("malloc failed");
        exit(1);
    }
}
void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t alloc)
{
    strbuf_init(sb,alloc);
    sb ->len =len;
    memcpy(sb->buf,str,len);

}
void strbuf_release(struct strbuf *sb)
{
    free(sb->buf);
    sb->buf = NULL;

}
void strbuf_swap(struct strbuf *a, struct strbuf *b)
{
    struct strbuf tem = *a;
    *a = *b;
    *b = tem;
}
char *strbuf_detach(struct strbuf *sb, size_t *sz)
{    
    *sz = sb->alloc;
    return  sb->buf;
}
int strbuf_cmp(const struct strbuf *first, const struct strbuf *second)
{
      if(first->buf==second->buf)
        return 0;
        if(first->buf ==NULL || second->buf ==NULL)
        return 1;
        if(first->len!=second->len)
        return 1;
        return memcmp(first ->buf,second->buf,first->len)?1:0;
}
void strbuf_reset(struct strbuf *sb)
{
    sb->len =0;
    sb->alloc = 0;
    free(sb->buf);
    sb->buf = NULL;
}
void strbuf_grow(struct strbuf *sb, size_t extra)
{
    sb->buf = realloc(sb->buf,sb->alloc+extra);
}
void strbuf_add(struct strbuf *sb, const void *data, size_t len)
{
    strbuf_grow(sb,len);
    strcat(sb->buf,data);
}
void strbuf_addch(struct strbuf *sb, int c)
{
    strbuf_add(sb,c,1);
}
void strbuf_addstr(struct strbuf *sb, const char *s)
{
    
    strbuf_add(sb,s,sizeof(s));

}
void strbuf_addbuf(struct strbuf *sb, const struct strbuf *sb2)
{
    strbuf_add(sb,sb2->buf,sb2->alloc);
}
void strbuf_setlen(struct strbuf *sb, size_t len)
{
    sb->len =len;
}
size_t strbuf_avail(const struct strbuf *sb)
{
    return (sb->alloc-sb->len);
}
void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len)
{
  
}