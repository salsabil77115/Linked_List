#include <iostream>

using namespace std;
class linkedlist{
struct node{
int item;
node *next;
};

node *head;
node *tail;
int length;
public:
    linkedlist(){
        head=tail=0;
        length=0;
    }


    bool isEmpty(){
    return length==0;

    }
void insertfirst(int item){
node* newNode;
newNode =new node();
newNode->item=item;
if(length==0){
head=tail=newNode;
newNode->next=0;
}
else{
    newNode->next=head;
    head=newNode;

}
length++;
}
void insertend(int item){
node* newNode;
newNode =new node();
newNode->item=item;
if(length==0){
head=tail=newNode;
newNode->next=0;
}
else{
tail->next=newNode;
newNode->next=0;
tail=newNode;}
    length++;
}
void insertatposition(int pos,int item){
node* newNode;
newNode =new node();
newNode->item=item;
if(pos==0){

insertfirst(item);
}
else if(pos==length){
    insertend(item);
}
else{
node *current;
current=head;
for(int i=1;i<pos;i++){

  current=current->next;
}
newNode->next=current->next;
current->next=newNode;
length++;
}
}
void print(){

node*cur=head;
while (cur!=NULL){
    cout<<cur->item<<endl;

    cur=cur->next;

}

}
int search(int item){
node*cur=head;
int pos=0;
while (cur!=0){
        if(item==cur->item){return pos;}

    cur=cur->next;
    pos++;}
return -1;
}


void delfirst(){
    if(isEmpty()){
    return ;
    }
else if(length==1){
    delete head;
    head=tail=0;
    length--;
}
else{
node*curr=head;
head=head->next;
delete curr;
length--;
}


}
void delend(){
    if(isEmpty()){
    return ;
    }
else if(length==1){
    delete head;
    head=tail=0;
    length--;
}
else{
node*curr=head->next;;
node*pre=head;

while(curr!=tail){//why?????????????????/=

    pre=curr;
    curr=curr->next;
}
delete curr;
pre->next=NULL;
tail=pre;
length--;
}


}
void del_atele(int item){
 if(isEmpty()){
    return ;
    }
    else if(head->item==item){
        delfirst();
    }
    else if(tail->item==item){
        delend();
    }
    else{
node*curr=head->next;
node*pre=head;
 while(curr!=0&&curr->item!=item){
    pre=curr;
    curr=curr->next;
}
if(curr==0){
    return;
}
else{
pre->next=curr->next;
delete curr;
length--;}


    }

}
void reverse1(){

node*curr,*pre,*link;
curr=head;
pre=NULL;
link=curr->next;

while(link!=0){
    link=curr->next;
    curr->next=pre;
    pre=curr;
    curr=link;

}
head=pre;
}

int middle(){
node *he=head;
int pos=length/2;

for(int i=1;i<pos;i++){

  he=he->next;
}
if(pos%2==0){
 he=he->next;
    return he->item;
}
else{
   return he->item;
}



    }
};


//order liked list???
//unorder linkrd list
int main()
{

linkedlist l;
l.insertend(5);
l.insertend(7);
l.insertend(20);
l.insertend(19);
cout<<l.middle()<<endl;;
//cout<<l.search(1)<<endl;
//cout<<l.length<<endl;
l.print();

    return 0;
}
