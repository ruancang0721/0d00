#include "strbuf.h"
void strbuf_init(struct strbuf *sb, size_t alloc)
{
    sb->len =0;
    sb->alloc = alloc;
    sb->buf = (char*)malloc(alloc);
    if(sb->buf == NULL)
    {
       fprintf(stderr,"NULL");
       return;
    }
}
void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t alloc)
{
     
        if(str==NULL)
    {
      fprintf(stderr,"NULL");
        return;
    }
   
    if(len>alloc)
    {
        fprintf(stderr,"len>alloc");
        return;
      
    }
    sb->buf = (char*)malloc(alloc);
    sb ->len =len;
    memcpy(sb->buf,str,len);
    sb->alloc = alloc;
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
    char *result=sb->buf;
    sb->buf=NULL;
    
    return  result;
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
    free(sb->buf);
    sb->buf = NULL;
}
void strbuf_grow(struct strbuf *sb, size_t extra)
{
    sb->buf = (char*)realloc(sb->buf,sb->alloc+extra);
    if(sb->buf == NULL)
    {
        perror("realloc failed");
        exit(1);
    }
    sb->alloc += extra;

}
void strbuf_add(struct strbuf *sb, const void *data, size_t len)
{
    strbuf_grow(sb,len);
    memcpy(sb->buf+sb->len,data,len);
    sb->len+=len;
}
void strbuf_addch(struct strbuf *sb, int c)
{
    strbuf_add(sb,&c,1);
}
void strbuf_addstr(struct strbuf *sb, const char *s)
{
    
    strbuf_add(sb,s,strlen(s));

}
void strbuf_addbuf(struct strbuf *sb, const struct strbuf *sb2)
{
    strbuf_add(sb,sb2->buf,sb2->len);
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
  if(pos>sb->len)
  return;
  strbuf_grow(sb,len);
  struct strbuf temp;
  strbuf_init(&temp,sb->len-pos);
  memcpy(temp.buf,sb->buf+pos,sb->len-pos);
  strbuf_add(sb,data,len);
  strbuf_addbuf(sb,&temp);
  strbuf_release(&temp);

}
void strbuf_ltrim(struct strbuf *sb)
{
    int i=0;
    while(sb->len!=0&&sb->buf[i]==' '||sb->buf[i]=='\t'||sb->buf[i]=='\n')
    {
        i++;
        sb->len--;
    }
    for(int j=0;j<sb->len;j++)
    memmove(sb->buf,sb->buf+i,sb->len);
}
void strbuf_rtrim(struct strbuf *sb)
{
    int i=sb->len-1;
    while(i>=0&&(sb->buf[i]==' '||sb->buf[i]=='\t'||sb->buf[i]=='\n'))
    {
        i--;
        sb->len--;
    }
    if(sb->len<sb->alloc)
    {
    char *temp =(char*)realloc(sb->buf,sb->len);
    if(temp==NULL)
    {
        perror("realloc failed");
        exit(1);
    }
    sb->buf=temp;
    sb->alloc=sb->len;
    }
}
void strbuf_remove(struct strbuf *sb, size_t pos, size_t len)
{
    if(len>sb->len-pos)
    len=sb->len-pos;
    struct strbuf temp;
    strbuf_init(&temp,len);
    memmove(temp.buf,sb->buf+pos+len,sb->len-pos-len);
    strbuf_release(&temp);
}
ssize_t strbuf_read(struct strbuf *sb, int fd, size_t hint)
{
    int hintQAQ=hint?hint:8192;
    strbuf_grow(sb,hintQAQ);

    while(1)
    {
        int sz=read(fd,sb->buf+sb->len,hintQAQ);
        if(sz<=0)
        return sz;
        sb->len+=sz;
    }
}
int strbuf_getline(struct strbuf *sb, FILE *fp)
{
    size_t n=0;
    char* line=NULL;
    int read;
    read = getline(&line,&n,fp);
    if(line[read-1]=='\n')
    {
    
     read--;
        
    }
    strbuf_add(sb,line,read);
    free(line);
    return read;
}
struct strbuf** strbuf_split_buf(const char* str, size_t len, int terminator, int max)
{
    if(str == NULL)
    {
        return NULL;
    }
    int ilen =0;
    int count =0;
    struct strbuf **result = (struct strbuf**)malloc(sizeof(struct strbuf*)*(max+1));
    result[0]=NULL;
    char * istr =NULL;
    for(int i= 0;i<len;i++)
    { 
       
        if(str[i]==terminator)
        {
            max--;
            if(ilen == 0)
            continue;
            istr = (char *)str +i+1;
        }
        ilen++;
        if(str[i+1]==terminator)
        {
          struct strbuf  *sb;
          strbuf_init(sb,ilen+1);
          strbuf_attach(sb,istr,ilen,ilen+1);
          result[count]=sb;
          count++;
          ilen = 0;
        }
        
    
    }
    return result;

}
bool strbuf_begin_judge(char* target_str, const char* str, int strlen)
{
    int istrlen = sizeof(*str)-1;
    if(istrlen>strlen)
    {
        return false;
    }
    for(int i = 0;i<strlen;i++)
    {
        if(i = istrlen)
        {
         return true;
        }
        if(str[i]!=target_str[i])
        return false;
    }
    return true;
    

}
char* strbuf_get_mid_buf(char* target_buf, int begin, int end, int len)
{
   int ilen = end - begin;
   int count  = 0;
   if(end>len)
   {
    return NULL;
   }
   char * istr = (char*)malloc(ilen+1);
   for(int i = begin;i<end;i++)
   {
        istr[count]=target_buf[i];
        count++;
   }
   istr[count] = '\0';
    return istr;
}
