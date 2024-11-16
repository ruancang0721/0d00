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
     strbuf_init(sb,alloc);
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
    sb->buf = (char*)str;
    sb ->len =len;
    sb->buf[len] = '\0';
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
    if(len+1>sb->alloc-sb->len)
    strbuf_grow(sb,len);
    if(sb->buf==NULL)
    {
        fprintf(stderr,"NULL");
        return;
    }
    memcpy(sb->buf+sb->len,data,len);
    sb->len+=len;
    sb->buf[sb->len]='\0';
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
    
    strbuf_init(sb,len+1);
    sb->len = len;
    sb->buf[len]='\0';

}
size_t strbuf_avail(const struct strbuf *sb)
{
    return (sb->alloc-sb->len-1);
}
void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len)
{
  if(pos>sb->len)
  return;
  if(len+1>sb->alloc-sb->len)
  strbuf_grow(sb,len);
memmove(sb->buf+pos+len,sb->buf+pos,sb->len-pos);
memcpy(sb->buf+pos,data,len);
sb->len = sb->len+len;
sb->buf[sb->len]='\0';

}
void strbuf_ltrim(struct strbuf *sb)
{
    int i=0;
    while(sb->len!=0&&sb->buf[i]==' '||sb->buf[i]=='\t'||sb->buf[i]=='\n')
    {
        i++;
       sb->len--;
    }
    memmove(sb->buf,sb->buf+i,sb->len);
}
void strbuf_rtrim(struct strbuf *sb)
{
    int i =sb->len-1;
    while(sb->len!=0&&sb->buf[sb->len-1]==' '||sb->buf[sb->len-1]=='\t'||sb->buf[sb->len-1]=='\n')
    {
        i--;
        sb->len--;
    }
    memmove(sb->buf,sb->buf,sb->len);

}
void strbuf_remove(struct strbuf *sb, size_t pos, size_t len)
{
    if(pos>=len)
    return;
    if(len>sb->len-pos)  
    len=sb->len-pos;
    memmove(sb->buf+pos,sb->buf+pos+len,len);
    sb->len = sb->len-len;
}
ssize_t strbuf_read(struct strbuf *sb, int fd, size_t hint)
{
    size_t hintQAQ=hint?hint:8192;
    strbuf_grow(sb,hintQAQ+1);

    while(1)
    {
        size_t sz=read(fd,sb->buf+sb->len,hintQAQ);
        if(sz<=0)
        return sz;
        sb->len+=sz;
        strbuf_grow(sb,1);
        sb->buf[sb->len]='\0';
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
    size_t ilen =0;
    int count =0;
    struct strbuf **result = (struct strbuf**)malloc(sizeof(struct strbuf*)*(max+1));
    if (result==NULL)
    {
        return NULL;
    }
    for(int i= 0;i<len;i++)
    { 
         if(str[i]==terminator)
         {
            if(ilen==0)
            continue;
            if(ilen>0)
            {
            struct strbuf* sb = (struct strbuf*)malloc(sizeof(struct strbuf));
            if(sb==NULL)
            {
                 for(int j=0;j<count;j++)
                 {
                    strbuf_release(result[j]);
                 }
                 free(result);
                 return NULL;

            }

            strbuf_init(sb,ilen+1);
            strncpy(sb->buf,str+i-ilen,ilen);
            sb->len = ilen;
            sb->buf[ilen] = '\0';
            result[count++]=sb;
            ilen = 0;
           }
         }
         else
         {
            ilen++;
         }
    }
    if(ilen>0&&count<max)
    {
        struct strbuf* sb = (struct strbuf*)malloc(sizeof(struct strbuf));
        if(sb==NULL)
        {
             for(int j=0;j<count;j++)
             {
                strbuf_release(result[j]);
             }
             free(result);
             return NULL;
        }
        strbuf_init(sb,ilen+1);
        strncpy(sb->buf,str+(len-ilen),ilen);
        sb->buf[ilen] = '\0';
        sb->len = ilen;
        result[count++]=sb;
        result[count]=NULL;

    }
    result[count]=NULL;
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
