#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 40
#define M 53
#define NAME 32

typedef struct { int id; char name[NAME]; float cgpa; } Student;
typedef struct Node {
    Student s;
    struct Node *left, *right;
    int h;
} Node;

Student data[N] = {
 {1001,"Aarav",8.1},{1002,"Diya",8.7},{1003,"Kavin",7.9},{1004,"Meera",9.0},
 {1005,"Arjun",8.3},{1006,"Nila",8.5},{1007,"Rahul",7.8},{1008,"Isha",9.1},
 {1009,"Vikram",8.0},{1010,"Ananya",8.8},{1011,"Pranav",7.7},{1012,"Kavya",8.9},
 {1013,"Sanjay",8.2},{1014,"Riya",9.2},{1015,"Hari",7.6},{1016,"Janani",8.4},
 {1017,"Surya",8.6},{1018,"Aditi",9.0},{1019,"Manoj",7.9},{1020,"Pooja",8.7},
 {1021,"Naveen",8.1},{1022,"Keerthi",8.8},{1023,"Ajay",7.5},{1024,"Divya",9.1},
 {1025,"Don",8.5},{1026,"Sathya",8.0},{1027,"Varun",8.4},{1028,"Priya",9.3},
 {1029,"Karthik",7.8},{1030,"Swetha",8.6},{1031,"Mithun",7.9},{1032,"Lavanya",8.9},
 {1033,"Gokul",8.2},{1034,"Harini",9.0},{1035,"Dinesh",7.7},{1036,"Nithya",8.5},
 {1037,"Rohan",8.3},{1038,"Sahana",9.2},{1039,"Bala",7.6},{1040,"Akhila",8.8}
};

int bstCmp, avlCmp, hashCmp, collisions;
int max(int a,int b){return a>b?a:b;}
int ht(Node *n){return n?n->h:0;}
Node *makeNode(Student s){
    Node *n=malloc(sizeof(Node));
    if(!n){puts("Memory allocation error");exit(1);}
    n->s=s;n->left=n->right=NULL;n->h=1;return n;
}
Node *bstInsert(Node *r,Student s){
    if(!r)return makeNode(s);
    if(s.id<r->s.id)r->left=bstInsert(r->left,s);
    else if(s.id>r->s.id)r->right=bstInsert(r->right,s);
    return r;
}
Node *bstSearch(Node *r,int id){
    while(r){bstCmp++;if(id==r->s.id)return r;r=id<r->s.id?r->left:r->right;}
    return NULL;
}
Node *rotateRight(Node *y){
    Node *x=y->left,*t=x->right;x->right=y;y->left=t;
    y->h=1+max(ht(y->left),ht(y->right));x->h=1+max(ht(x->left),ht(x->right));return x;
}
Node *rotateLeft(Node *x){
    Node *y=x->right,*t=y->left;y->left=x;x->right=t;
    x->h=1+max(ht(x->left),ht(x->right));y->h=1+max(ht(y->left),ht(y->right));return y;
}
int balance(Node *n){return n?ht(n->left)-ht(n->right):0;}
Node *avlInsert(Node *r,Student s){
    if(!r)return makeNode(s);
    if(s.id<r->s.id)r->left=avlInsert(r->left,s);
    else if(s.id>r->s.id)r->right=avlInsert(r->right,s);
    else return r;
    r->h=1+max(ht(r->left),ht(r->right));
    int b=balance(r);
    if(b>1&&s.id<r->left->s.id)return rotateRight(r);             /* LL */
    if(b< -1&&s.id>r->right->s.id)return rotateLeft(r);          /* RR */
    if(b>1&&s.id>r->left->s.id){r->left=rotateLeft(r->left);return rotateRight(r);} /* LR */
    if(b< -1&&s.id<r->right->s.id){r->right=rotateRight(r->right);return rotateLeft(r);} /* RL */
    return r;
}
Node *avlSearch(Node *r,int id){
    while(r){avlCmp++;if(id==r->s.id)return r;r=id<r->s.id?r->left:r->right;}
    return NULL;
}
void inorder(Node *r){
    if(r){inorder(r->left);printf("%-6d %-12s %.2f\n",r->s.id,r->s.name,r->s.cgpa);inorder(r->right);}
}
typedef struct {int used;Student s;} Slot;
Slot table[M];
void hashInsert(Student s){
    int start=s.id%M;
    for(int i=0;i<M;i++){
        int p=(start+i)%M;
        if(!table[p].used){table[p].used=1;table[p].s=s;return;}
        if(table[p].s.id==s.id){table[p].s=s;return;}
        collisions++;
    }
    puts("Hash table full");
}
Student *hashSearch(int id){
    int start=id%M;
    for(int i=0;i<M;i++){
        int p=(start+i)%M;hashCmp++;
        if(!table[p].used)return NULL;
        if(table[p].s.id==id)return &table[p].s;
    }
    return NULL;
}
void testSearch(Node *b,Node *a,int id,const char *title){
    bstCmp=avlCmp=hashCmp=0;
    Node *x=bstSearch(b,id),*y=avlSearch(a,id);Student *z=hashSearch(id);
    printf("\n%s — ID %d\n",title,id);
    if(x)printf("BST : Found %s, CGPA %.2f\n",x->s.name,x->s.cgpa);else puts("BST : Not found");
    if(y)printf("AVL : Found %s, CGPA %.2f\n",y->s.name,y->s.cgpa);else puts("AVL : Not found");
    if(z)printf("Hash: Found %s, CGPA %.2f\n",z->name,z->cgpa);else puts("Hash: Not found");
    printf("Comparisons / slots checked: BST=%d, AVL=%d, Hash=%d\n",bstCmp,avlCmp,hashCmp);
}
int main(void){
    Node *bst=NULL,*avl=NULL;
    for(int i=0;i<N;i++){bst=bstInsert(bst,data[i]);avl=avlInsert(avl,data[i]);hashInsert(data[i]);}
    puts("STUDENT RECORD SEARCH SYSTEM — DSA CLA-2");
    printf("Records loaded: %d | Hash table size: %d\n",N,M);
    printf("Linear-probing insertion collisions: %d\n",collisions);
    testSearch(bst,avl,1025,"SUCCESSFUL SEARCH");
    testSearch(bst,avl,1099,"UNSUCCESSFUL SEARCH");
    Student extra={1041,"NewStudent",8.75};
    bst=bstInsert(bst,extra);avl=avlInsert(avl,extra);hashInsert(extra);
    puts("\nINSERTION TEST: Added ID 1041, NewStudent, CGPA 8.75");
    testSearch(bst,avl,1041,"VERIFY INSERTION");
    puts("\nBST INORDER TRAVERSAL");inorder(bst);
    puts("\nAVL INORDER TRAVERSAL");inorder(avl);
    printf("\nTree height in levels: BST=%d, AVL=%d\n",ht(bst),ht(avl));
    puts("\nInteractive search (enter 0 to exit)");
    while(1){int id;printf("Enter student ID: ");if(scanf("%d",&id)!=1||id==0)break;testSearch(bst,avl,id,"SEARCH RESULT");}
    return 0;
}
