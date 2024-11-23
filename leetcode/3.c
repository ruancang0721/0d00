int lengthOfLongestSubstring(char* s) {
   int l=0,r=0;
   int hash[666]={0};
   int len = strlen(s);
   int ilen=0;
   int max=1;
   if(len==0)
   return 0;
   for(r=0;r<len;r++)
   {
    hash[s[r]]++;
    ilen++;
      while(hash[s[r]]>1)
      {
         hash[s[l]]--;
         l++;
         ilen--;
      }
         max=max>ilen?max:ilen;
   }

return max;
}