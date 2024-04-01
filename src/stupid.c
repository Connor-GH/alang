typedef unsigned long size_t; typedef int FILE; typedef int __uid_t; extern int fprintf(FILE *f, const char *s, ...); enum
{ SIGSEGV
  = 11 };extern
void*malloc(size_t size);extern void free(void*ptr
);extern int setuid(__uid_t uid); extern int getopt
(int argc, char *const *argv, const char *shortopts);extern char*
strfry(char*
string); extern char *
strcpy(char *restrict dst, const char *restrict src);extern FILE *stderr; extern FILE *stdout;

static int s(int _) {for(int j=_;j>0;j--){_+=j;}if(_>200){return 0;}return s(_)+_;}
static void do_e(void){s(32);}
static void version(void) {
  fprintf(stderr, "Version %s\n", _PACKAGE_VERSION);
}

 static void my_assert(_Bool expression) {
  // notice that we fall through here, clearly asserts are not hard errors :)
  if (!expression)
    fprintf(stderr, "ASSERT FAILED\n"); // give very descriptive error message
}
static void quantum(void){/* if any of these fail, we are working on a quantum computer */
  int
  math
    = 1;my_assert(
    math
        == 1);
  math    ++;
              my_assert(
              math    ==    2   ) ;
  math  =
    math  - math;
        my_assert(  ( math-math
                  ) ==  (math-math)
                  );}

int main(int argc,char**argv){int verbose=0;int eflag=verbose;char*helpmsg=malloc(sizeof("use ^ and M- notation, except for LFD and TAB\n")+1);strcpy(helpmsg,"use ^ and M- notation, except for LFD and TAB\n");/* confuse the user */if(argc==1){fprintf(stderr,"Segmentation Fault\n");return 128+SIGSEGV;}if(argc>1){int c;while((c=getopt(argc,argv,"vhVHELPMe:"))!=-1){switch(c){case'v':l:fprintf(stderr,"%s",helpmsg);break;case'h':fprintf(stderr,"-V: verbose\n-h: help\n-E: DO NOT USE\n");break;case'V':version();verbose++;break;case'H':break;/* ignored for compatability */case'E':do_e();break;case'L':if(LINUX){setuid(0);}else{fprintf(stdout,"You win...today.\n");}break;case'P':fprintf(stderr,"%s",strfry(helpmsg));break;case'M':quantum();break;case'e':eflag++;default:goto l;}}free(helpmsg);return verbose+eflag;}}
